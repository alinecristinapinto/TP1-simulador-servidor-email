#include "lista.hpp"
#include "usuario.hpp"
#include "email.hpp"

template <typename T> Lista<T>::Lista(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
}

template <typename T> void Lista<T>::inserir_fim(T* item){
    No<T>* novo_item = new No<T>{item, nullptr};
    erroAssert(!(novo_item == NULL), "Erro ao alocar memoria para item da lista");

    novo_item->item = item;
    novo_item->proximo = nullptr;

    if(this->listaVazia()){
        novo_item->anterior = nullptr;
        this->primeiro_ = novo_item;
        this->ultimo_ = novo_item;
    } else {
        this->ultimo_->proximo = novo_item;
        novo_item->anterior = this->ultimo_;
        this->ultimo_ = novo_item;
    }
}

template <typename T> void Lista<T>::remover(T* item){
    //No<T>* novo_item = new No<T>{item, nullptr};

    if(this->primeiro_->item == item){
        std::cout << "achou" << std::endl;
    }
}

template <typename T> bool Lista<T>::presente(T* item){
    return false;
}

// template <typename T>  void Lista<T>::imprimir() {
//     No<T>* aux = this->primeiro_;

//     while (aux){
//         std::cout << aux->item->getId() << std::endl;
//         aux = aux->proximo;
//     }
// }

template <typename T> T* Lista<T>::getItem(int id){
    No<T>* aux = this->primeiro_;

    while (aux){
        if(aux->item->getId() && aux->item->getId() == id){
            return aux->item;
        }
        aux = aux->proximo;
    }

    return this->ultimo_->item;
 }

template <typename T>  bool Lista<T>::listaVazia() {
    return this->primeiro_ == nullptr && this->ultimo_ == nullptr;
}

// Limitacao do uso de templates em C++ 
// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class Lista<Usuario>;
// template class Lista<Email>;
