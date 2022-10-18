#include "leitorLinhaComando.hpp"

std::string LeitorLinhaComando::buscarArgumento(int argc, char* argv[], std::string opcao) {
    std::string argumento = "";

    for(int i=0; i<argc; i++){
        if(argv[i] == opcao && (i+1)< argc) {
            argumento = argv[i + 1];
            return argumento;
        }; 
    }

    return argumento;
}

bool LeitorLinhaComando::verificarParametroPresente(int argc, char* argv[], std::string parametro){
    for(int i=0; i<argc; i++){
        if(argv[i] == parametro) return true;
    }

    return false;
}

std::string LeitorLinhaComando::buscarNomeArquivo(int argc, char* argv[]) {
    Log::erroAssert((argc != 2 || strcmp(argv[1], "") == 0), "Arquivo de entrada obrigatorio");
    return argv[1]; 
}

std::string LeitorLinhaComando::buscarNomeMemlog(int argc, char* argv[]){
    std::string nomeMemLog = buscarArgumento(argc, argv, P_REGISTRO_DESEMPENHO);
    return nomeMemLog == "" ? NOME_MEMLOG_DEFAULT : nomeMemLog;
}

bool LeitorLinhaComando::verificarRegistroAcesso(int argc, char* argv[]){
    return verificarParametroPresente(argc, argv, L_PADRAO_ACESSO_LOCALIDADE);
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
