#include "listaUsuarios.hpp"

ListaUsuarios::ListaUsuarios(): Lista<Usuario>(){}

bool ListaUsuarios::presente(int id){
    No<Usuario>* aux = this->primeiro_;

    while (aux){
        if(aux->item->getId() == id){
            return true;
        }
        aux = aux->proximo;
    }

    return false;
}

void ListaUsuarios::remover(int id){
    No<Usuario> *usuario_deletado, *aux;

    if(this->primeiro_->item->getId() == id){
        usuario_deletado = this->primeiro_;
        this->primeiro_ = this->primeiro_->proximo;
        this->primeiro_->anterior = nullptr;

        if(this->primeiro_ == nullptr) this->ultimo_ = nullptr;   
        
        std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
        delete usuario_deletado; 

        return;
    } else if (this->ultimo_->item->getId() == id){
        usuario_deletado = this->ultimo_;
        this->ultimo_ = this->ultimo_->anterior;
        this->ultimo_->proximo = nullptr;
        
        if(this->ultimo_ == nullptr) this->primeiro_ = nullptr;

        std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
        delete usuario_deletado; 

        return;
    } else {
        aux = this->primeiro_;

        while (aux->proximo && aux->proximo->item->getId() != id) {
            aux = aux->proximo;
        }
        if(aux->proximo){
            usuario_deletado = aux->proximo;
            aux->proximo = usuario_deletado->proximo;
            if(aux->proximo){
                aux->proximo->anterior = aux;
            }

            std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
            delete usuario_deletado; 

            return;
        }
    }

    std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
}

void ListaUsuarios::imprimir() {
    No<Usuario>* aux = this->primeiro_;

    while (aux){
        std::cout << aux->item->getId() << std::endl;
        aux = aux->proximo;
    }
}