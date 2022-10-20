#include <iostream>
#include <fstream>

#include "servidor.hpp"
#include "constantes.hpp"
#include "log.hpp"
#include "leitorLinhaComando.hpp"
#include "memlog.hpp"

using namespace std;

void processarComando(stringstream *linha, Servidor* servidor){
    int idUsuario;
    string comando = "";

    *linha >> comando >> idUsuario;

    if(comando == OPERACAO_CADASTRAR){
        servidor->cadastrarUsuario(idUsuario);
    } else if(comando == OPERACAO_REMOVER){
        servidor->removerUsuario(idUsuario);
    } else if(comando == OPERACAO_CONSULTA){
        servidor->consultarEmail(idUsuario);
    } else if(comando == OPERACAO_ENTREGA){
        int prioridade;
        *linha >> prioridade;
        servidor->enviarEmail(idUsuario, prioridade, LeitorLinhaComando::buscarMensagem(linha));
    } else {
        Log::erro("Comando nao reconhecido");
    }
}

int main(int argc, char* argv[]){
    string nomeArquivo = LeitorLinhaComando::buscarNomeArquivo(argc, argv);
    bool ativarRegistroAcesso = LeitorLinhaComando::verificarRegistroAcesso(argc, argv);

    iniciaMemLog((char *) NOME_MEMLOG_DEFAULT.c_str());
   
    if (ativarRegistroAcesso){ 
        ativaMemLog();
    } else {
        desativaMemLog();
    }

    ifstream arquivo(nomeArquivo);
    Log::erroAssert(!arquivo.is_open(), "Nao foi possivel ler o arquivo");

    Servidor *servidor = new Servidor();

    defineFaseMemLog(0);
    for(string linha; getline(arquivo, linha);){
        stringstream streamLinha(linha);
        processarComando(&streamLinha, servidor);
    }

    arquivo.close();
    delete servidor;
    return finalizaMemLog();
}