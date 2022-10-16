#include "filaPorPrioridadeEmails.hpp"

FilaPorPrioridadeEmails::FilaPorPrioridadeEmails(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
}

bool FilaPorPrioridadeEmails::vazia(){
    return this->primeiro_ == nullptr;
}

void FilaPorPrioridadeEmails::adicionar(int prioridade, std::string mensagem){
    Celula *novo_item = new Celula{Email(prioridade, mensagem), nullptr, nullptr};
    erroAssert(!(novo_item == NULL), "Erro ao alocar memoria para mensagem de email");
    
    if(this->vazia()){
        this->primeiro_ = novo_item;
        this->ultimo_ = novo_item;
    } else if(!this->ultimo_->anterior) {
        if(this->ultimo_->item.getPrioridade() < prioridade){
            novo_item->proximo = this->ultimo_;
            this->ultimo_->anterior = novo_item;
            this->primeiro_ = novo_item;
        } else {
            novo_item->proximo = this->ultimo_->proximo;
            this->ultimo_->proximo = novo_item;
            novo_item->anterior = this->ultimo_;
            this->ultimo_ = novo_item;
        }
    } else {
        Celula *aux = this->ultimo_;

        while(aux->anterior && prioridade > aux->anterior->item.getPrioridade()){
            aux = aux->anterior;
        }
        if(aux->item.getPrioridade() < prioridade){
            novo_item->anterior = aux->anterior;
            if(aux->anterior){
                aux->anterior->proximo = novo_item;
            }
            novo_item->proximo = aux;
            aux->anterior = novo_item;
            if(!novo_item->anterior) this->primeiro_ = novo_item;
        } else {
            novo_item->anterior = aux;
            aux->proximo = novo_item;
            this->ultimo_ = novo_item;
        }
    }
}

void FilaPorPrioridadeEmails::consultarRemoverPrimeiroEmail(){
    if(this->vazia()){
        std::cout << "CAIXA DE ENTRADA VAZIA" << std::endl;
        return;
    }

    Celula *remover = this->primeiro_;
    std::cout << "CONSULTA " << remover->item.getPrioridade() << ": " << remover->item.getMensagem() << std::endl;
    
    if(this->primeiro_->proximo){
        this->primeiro_ = this->primeiro_->proximo;
    }
    delete remover;    

    this->primeiro_->anterior = nullptr;
}

void FilaPorPrioridadeEmails::imprimir(){
    Celula* aux = this->primeiro_;

    while (aux){
        std::cout << aux->item.getPrioridade() << " " << aux->item.getMensagem() << std::endl;
        aux = aux->proximo;
    }
}

FilaPorPrioridadeEmails::~FilaPorPrioridadeEmails(){
    while (this->primeiro_ != nullptr){
        this->consultarRemoverPrimeiroEmail();
    }
}