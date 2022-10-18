#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

const std::string NOME_MEMLOG_DEFAULT = "log.out";
const std::string P_REGISTRO_DESEMPENHO = "-p";
const std::string L_PADRAO_ACESSO_LOCALIDADE = "-l";

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
