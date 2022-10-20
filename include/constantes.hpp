#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

const std::string OPERACAO_CADASTRAR = "CADASTRA";
const std::string OPERACAO_REMOVER = "REMOVE";
const std::string OPERACAO_CONSULTA = "CONSULTA";
const std::string OPERACAO_ENTREGA = "ENTREGA";
const std::string OPERACAO_FIM = "FIM";

/**
 * @brief Struct que representa um no encadeado de uma lista/fila generica
 */
template <typename T> struct No {  
    T item; 
    No* proximo; 
}; 

#endif
