#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "servidor.hpp"
#include "filaPorPrioridadeEmails.hpp"
#include "constantes.hpp"
#include "log.hpp"
#include "memlog.hpp"

using namespace std;

string getMensagem(stringstream *linha){
    string mensagem = "", aux = "";

    while(aux != OPERACAO_FIM){
        if(mensagem.empty()) mensagem += aux;
        else mensagem += (" " + aux);
        *linha >> aux;
    }

    return mensagem;
}

void processarComando(stringstream *linha, Servidor* servidor){
    string comando = "";
    int idUsuario;

    *linha >> comando >> idUsuario;

    if(comando == OPERACAO_CADASTRAR){
        servidor->cadastrarUsuario(idUsuario);
    } else if(comando == OPERACAO_CONSULTA){
        servidor->consultarEmail(idUsuario);
    } else if(comando == OPERACAO_ENTREGA){
        int prioridade;
        string mensagem;
        *linha >> prioridade;
        servidor->enviarEmail(idUsuario, prioridade, getMensagem(linha));
    } else {
        Log::erro("Comando nao reconhecido");
    }
}

int main(int argc, char* argv[]){
    Log::erroAssert((argc != 2 || strcmp(argv[1], "") == 0), "Arquivo de entrada obrigatorio");
    string nome_arquivo = argv[1]; 

    ifstream arquivo(nome_arquivo);
    Log::erroAssert(!arquivo.is_open(), "Nao foi possivel ler o arquivo");

    Servidor *servidor = new Servidor();

    string nome_memlog = "log.out"; 
    iniciaMemLog((char *) nome_memlog.c_str());

    if (true){ 
        ativaMemLog();
    } else {
        desativaMemLog();
    }

    for(string linha; getline(arquivo, linha);){
        stringstream streamLinha(linha);
        processarComando(&streamLinha, servidor);
    }

    arquivo.close();

    return finalizaMemLog();
}