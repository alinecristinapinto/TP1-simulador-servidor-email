#include "listaUsuarios.hpp"

ListaUsuarios::ListaUsuarios(){
    this->primeiro_ = nullptr;
}

bool ListaUsuarios::lista_vazia() {
    return this->primeiro_ == nullptr;
}

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
        Log::erro("CONTA " + std::to_string(id) + " JA EXISTENTE");
        return;
    } 

    No<Usuario>* novo_item = new No<Usuario>{Usuario(id), nullptr};
    Log::erroAssert(novo_item == NULL, "Erro ao alocar memoria para usuario id: " + std::to_string(id));

    if(this->lista_vazia()){
        novo_item->proximo = nullptr;
        this->primeiro_ = novo_item;
    } else {
        novo_item->proximo = this->primeiro_;
        this->primeiro_ = novo_item;
    }

    Log::info("OK: CONTA " + std::to_string(id) + " CADASTRADA");
}

void ListaUsuarios::remover(int id){
    No<Usuario> *usuario_deletado, *aux;

    if(this->primeiro_->item.getId() == id){
        usuario_deletado = this->primeiro_;
        this->primeiro_ = this->primeiro_->proximo;

        Log::info("OK: CONTA " + std::to_string(id) + " REMOVIDA");
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
  
            Log::info("OK: CONTA " + std::to_string(id) + " REMOVIDA");
            delete usuario_deletado; 

            return;
        }
    }

    Log::erro("CONTA " + std::to_string(id) + " NAO EXISTE");
}

void ListaUsuarios::enviarEmail(int idUsuario, int prioridade, std::string mensagem){
    if(!this->presente(idUsuario)){
        Log::erro("CONTA " + std::to_string(idUsuario) + " NAO EXISTENTE");
        return;
    } 

    No<Usuario>* aux = this->primeiro_;

    while(aux){
        if(aux->item.getId() == idUsuario){
            aux->item.getCaixaDeEntrada()->adicionar(prioridade, mensagem);
        }
        aux = aux->proximo;
    }

    Log::info("OK: MENSAGEM PARA " + std::to_string(idUsuario) + " ENTREGUE");
}

void ListaUsuarios::consultarRemoverEmail(int idUsuario){
    if(!this->presente(idUsuario)){
        Log::erro("CONTA " + std::to_string(idUsuario) + " NAO EXISTENTE");
        return;
    } 

    No<Usuario>* aux = this->primeiro_;

    while(aux){
        if(aux->item.getId() == idUsuario){
            aux->item.getCaixaDeEntrada()->consultarRemoverPrimeiroEmail(idUsuario);
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

ListaUsuarios::~ListaUsuarios(){
    No<Usuario>* aux = this->primeiro_;

    while (aux){
        this->remover(aux->item.getId());
    }
}
