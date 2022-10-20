#include "listaUsuarios.hpp"

ListaUsuarios::ListaUsuarios(){
    this->primeiro_ = nullptr;
}

bool ListaUsuarios::lista_vazia() {
    return this->primeiro_ == nullptr;
}

bool ListaUsuarios::presente(int id, int idMemlog){
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
    if(this->presente(id, ID_MEMLOG_OPERACAO_CADASTRAR)){
        Log::erro("CONTA " + std::to_string(id) + " JA EXISTENTE");
        return;
    } 

    No<Usuario>* novoItem = new No<Usuario>{Usuario(id), nullptr};
    Log::erroAssert(novoItem == NULL, "Erro ao alocar memoria para usuario id: " + std::to_string(id));
    
    novoItem->proximo = this->primeiro_;
    this->primeiro_ = novoItem;

    Log::info("OK: CONTA " + std::to_string(id) + " CADASTRADA");
}

void ListaUsuarios::remover(int id){
    No<Usuario> *aux = this->primeiro_, *anterior = nullptr;

    while(aux){
        if(aux->item.getId() == id && !anterior){
            this->primeiro_ = this->primeiro_->proximo;

            delete aux;
            return;
        } else if (aux->item.getId() == id && anterior){
            anterior->proximo = aux->proximo;

            delete aux;
            return;
        }

        anterior = aux;
        aux = aux->proximo;
    }

    Log::erro("CONTA " + std::to_string(id) + " NAO EXISTE");
}

void ListaUsuarios::enviarEmail(int idUsuario, int prioridade, std::string mensagem){
    if(!this->presente(idUsuario, ID_MEMLOG_OPERACAO_ENTREGA)){
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
    if(!this->presente(idUsuario, ID_MEMLOG_OPERACAO_CONSULTA)){
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
