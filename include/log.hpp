#ifndef LOG_H
#define LOG_H

#include <iostream>

/**
 * @brief Classe responsavel por logar erros e avisos de sucesso
 */
class Log {
public:
    static void info(std::string mensagem){
        std::cout << mensagem << std::endl;
    }

    static void erro(std::string mensagem){
        std::cout << "ERRO: " << mensagem << std::endl;
    }
};

#endif