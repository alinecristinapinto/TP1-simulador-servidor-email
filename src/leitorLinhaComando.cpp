#include "leitorLinhaComando.hpp"

std::string LeitorLinhaComando::buscarNomeArquivo(int argc, char* argv[]) {
    Log::erroAssert((argc < 2 || strcmp(argv[1], "") == 0), "Arquivo de entrada obrigatorio");
    return argv[1]; 
}

std::string LeitorLinhaComando::buscarMensagem(std::stringstream *linha){
    std::string mensagem = "", aux = "";

    while(aux != OPERACAO_FIM){
        if(mensagem.empty()) mensagem += aux;
        else mensagem += (" " + aux);
        *linha >> aux;
    }

    return mensagem;
}
