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

    static std::string buscarMensagem(std::stringstream *linha);
};

#endif
