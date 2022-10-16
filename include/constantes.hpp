#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

const std::string OPERACAO_CADASTRAR = "CADASTRA";
const std::string OPERACAO_CONSULTA = "CONSULTA";
const std::string OPERACAO_ENTREGA = "ENTREGA";
const std::string OPERACAO_FIM = "FIM";

/**
 * @brief Struct que representa um no de uma lista generica
 */
template <typename T> struct No {  
    T item;
    No* anterior; 
    No* proximo; 
}; 

#endif
