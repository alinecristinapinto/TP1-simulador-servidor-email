#include <iostream>
#include <fstream>

#include "servidor.hpp"
#include "constantes.hpp"
#include "log.hpp"
#include "memlog.hpp"
#include "leitorLinhaComando.hpp"

using namespace std;

void processarComando(stringstream *linha, Servidor* servidor){
    int idUsuario;
    string comando = "";

    *linha >> comando >> idUsuario;

    if(comando == OPERACAO_CADASTRAR){
        servidor->cadastrarUsuario(idUsuario);
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
    LeitorLinhaComando linha_comando;

    string nomeArquivo = linha_comando.buscarNomeArquivo(argc, argv);
    string nomeMemlog = linha_comando.buscarNomeMemlog(argc, argv); 
    bool ativarRegistroAcesso = linha_comando.verificarRegistroAcesso(argc, argv); 

    iniciaMemLog((char *) nomeMemlog.c_str());

    if (ativarRegistroAcesso){ 
        ativaMemLog();
    } else {
        desativaMemLog();
    }

    ifstream arquivo(nomeArquivo);
    Log::erroAssert(!arquivo.is_open(), "Nao foi possivel ler o arquivo");

    Servidor *servidor = new Servidor();

    for(string linha; getline(arquivo, linha);){
        stringstream streamLinha(linha);
        processarComando(&streamLinha, servidor);
    }

    arquivo.close();
    delete servidor;
    return finalizaMemLog();
}