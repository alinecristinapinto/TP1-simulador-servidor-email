#include "listaUsuarios.hpp"

ListaUsuarios::ListaUsuarios(): Lista<Usuario>(){}

bool ListaUsuarios::presente(int id){
    No<Usuario>* aux = this->primeiro_;

    while (aux){
        if(aux->item.getId() == id){
            return true;
        }
        aux = aux->proximo;
    }

    return false;
}

void ListaUsuarios::inserirInicio(int id){
    if(this->presente(id)){
        std::cout << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;
        return;
    } 

    No<Usuario>* novo_item = new No<Usuario>{Usuario(id), nullptr};
    erroAssert(!(novo_item == NULL), "Erro ao alocar memoria para usuario");

    if(this->lista_vazia()){
        novo_item->proximo = nullptr;
        this->primeiro_ = novo_item;
    } else {
        novo_item->proximo = this->primeiro_;
        this->primeiro_ = novo_item;
    }

    std::cout << "OK: CONTA " << id << " CADASTRADA" << std::endl;
}

void ListaUsuarios::remover(int id){
    No<Usuario> *usuario_deletado, *aux;

    if(this->primeiro_->item.getId() == id){
        usuario_deletado = this->primeiro_;
        this->primeiro_ = this->primeiro_->proximo;

        std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
        delete usuario_deletado; 

        return;
    } else {
        aux = this->primeiro_;

        while (aux->proximo && aux->proximo->item.getId() != id) {
            aux = aux->proximo;
        }
        if(aux->proximo){
            usuario_deletado = aux->proximo;
            aux->proximo = usuario_deletado->proximo;
  
            std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
            delete usuario_deletado; 

            return;
        }
    }

    std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
}

void ListaUsuarios::enviarEmail(int idUsuario, int prioridade, std::string mensagem){
    if(!this->presente(idUsuario)){
        std::cout << "ERRO: CONTA " << idUsuario << " NAO EXISTENTE" << std::endl;
        return;
    } 

    No<Usuario>* aux = this->primeiro_;

    while(aux){
        if(aux->item.getId() == idUsuario){
            aux->item.getCaixaDeEntrada()->adicionar(prioridade, mensagem);
        }
        aux = aux->proximo;
    }

    std::cout << "OK: MENSAGEM PARA " << idUsuario << " ENTREGUE" << std::endl;
}

void ListaUsuarios::consultarRemoverEmail(int idUsuario){
    if(!this->presente(idUsuario)){
        std::cout << "ERRO: CONTA " << idUsuario << " NAO EXISTENTE" << std::endl;
        return;
    } 

    No<Usuario>* aux = this->primeiro_;

    while(aux){
        if(aux->item.getId() == idUsuario){
            aux->item.getCaixaDeEntrada()->consultarRemoverPrimeiroEmail();
        }
        aux = aux->proximo;
    }
}

void ListaUsuarios::imprimir() {
    No<Usuario>* aux = this->primeiro_;

    while (aux){
        std::cout << aux->item.getId() << std::endl;
        aux = aux->proximo;
    }
}