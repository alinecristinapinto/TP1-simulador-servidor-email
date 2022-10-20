#include "leitorLinhaComando.hpp"

bool LeitorLinhaComando::verificarParametroPresente(int argc, char* argv[], std::string parametro){
    for(int i=0; i<argc; i++){
        if(argv[i] == parametro) return true;
    }

    return false;
}

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

bool LeitorLinhaComando::verificarRegistroAcesso(int argc, char* argv[]){
    return verificarParametroPresente(argc, argv, L_PADRAO_ACESSO_LOCALIDADE);
}
