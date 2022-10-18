#ifndef LEITORLINHACOMANDO_H
#define LEITORLINHACOMANDO_H

#include "log.hpp"
#include "constantes.hpp"
#include <cstring>
#include <sstream>

/**
 * @brief Classe responsavel pela leitura dos dados por linha de comando
 */
class LeitorLinhaComando {
public:
    static std::string buscarNomeArquivo(int argc, char* argv[]);

    static std::string buscarNomeMemlog(int argc, char* argv[]);

    static bool verificarRegistroAcesso(int argc, char* argv[]);

    static std::string buscarMensagem(std::stringstream *linha);

private:
    static std::string buscarArgumento(int argc, char* argv[], std::string opcao);

    static bool verificarParametroPresente(int argc, char* argv[], std::string parametro); 
};

#endif
