#include "filaPorPrioridadeEmails.hpp"

FilaPorPrioridadeEmails::FilaPorPrioridadeEmails(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
}

bool FilaPorPrioridadeEmails::vazia(){
    return this->primeiro_ == nullptr && this->ultimo_ == nullptr;
}

void FilaPorPrioridadeEmails::adicionar(int prioridade, std::string mensagem){
    No<Email> *novoItem = new No<Email>{Email(prioridade, mensagem), nullptr, nullptr};
    Log::erroAssert(novoItem == NULL, "Erro ao alocar memoria para mensagem de email");

    // ESCREVEMEMLOG((long int) &novoItem->item.getPrioridade(), sizeof (int), ID_MEMLOG_OPERACAO_ENTREGA);
    // ESCREVEMEMLOG((long int) &novoItem->item.getMensagem(), sizeof (std::string), ID_MEMLOG_OPERACAO_ENTREGA);
    
    if(this->vazia()){
        this->primeiro_ = novoItem;
        this->ultimo_ = novoItem;
    } else if(!this->ultimo_->anterior) {
        if(this->ultimo_->item.getPrioridade() < prioridade){
            novoItem->proximo = this->ultimo_;
            this->ultimo_->anterior = novoItem;
            this->primeiro_ = novoItem;
        } else {
            novoItem->proximo = this->ultimo_->proximo;
            this->ultimo_->proximo = novoItem;
            novoItem->anterior = this->ultimo_;
            this->ultimo_ = novoItem;
        }
    } else {
        No<Email> *aux = this->ultimo_;

        while(aux->anterior && prioridade > aux->anterior->item.getPrioridade()){
            // LEMEMLOG((long int) &aux->item.getPrioridade(), sizeof (int), ID_MEMLOG_OPERACAO_ENTREGA);
            aux = aux->anterior;
        }
        if(aux->item.getPrioridade() < prioridade){
            novoItem->anterior = aux->anterior;
            if(aux->anterior){
                aux->anterior->proximo = novoItem;
            }
            novoItem->proximo = aux;
            aux->anterior = novoItem;
            if(!novoItem->anterior) this->primeiro_ = novoItem;
        } else {
            novoItem->anterior = aux;
            aux->proximo = novoItem;
            this->ultimo_ = novoItem;
        }
    }
}

void FilaPorPrioridadeEmails::consultarRemoverPrimeiroEmail(int idUsuario, int idMemlog){
    if(this->vazia()){
        Log::erro("CAIXA DE ENTRADA VAZIA");
        return;
    }

    No<Email> *remover = this->primeiro_;
    Log::info(("CONSULTA " + std::to_string(idUsuario) + ": " + remover->item.getMensagem()));
    
    if(this->primeiro_->proximo){
        this->primeiro_ = this->primeiro_->proximo;
        this->primeiro_->anterior = nullptr;
    } else {
        this->primeiro_ = nullptr;
        this->ultimo_ = nullptr;
    }

    // ESCREVEMEMLOG((long int) &remover->item.getPrioridade(), sizeof (int), idMemlog);
    // ESCREVEMEMLOG((long int) &remover->item.getMensagem(), sizeof (std::string), idMemlog);
    delete remover;    
}

void FilaPorPrioridadeEmails::imprimir(){
    No<Email>* aux = this->primeiro_;

    while (aux){
        std::cout << aux->item.getPrioridade() << " " << aux->item.getMensagem() << std::endl;
        aux = aux->proximo;
    }
}

FilaPorPrioridadeEmails::~FilaPorPrioridadeEmails(){
    while (this->primeiro_ != nullptr){
        this->consultarRemoverPrimeiroEmail(-1, ID_MEMLOG_OPERACAO_REMOVER);
    }
}