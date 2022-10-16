#include <iostream>
#include <fstream>
#include <cstring>

#include "msgassert.hpp" 
#include "servidor.hpp"
#include "filaPorPrioridadeEmails.hpp"

using namespace std;

int main(int argc, char* argv[]){
    // erroAssert((argc == 2 && strcmp(argv[1], "") != 0), "Arquivo obrigatorio!");
    // string nome_arquivo = argv[1]; 

    // ifstream arquivo(nome_arquivo);
    // erroAssert(arquivo.is_open(), "Erro ao ler arquivo!");

    // for(string linha; getline(arquivo, linha);){
    //     cout << linha << endl;
    // }

    // Servidor *servidor = new Servidor();
    // servidor->cadastrarUsuario(1);
    // servidor->cadastrarUsuario(2);
    // servidor->cadastrarUsuario(2);
    // servidor->cadastrarUsuario(3);
    // servidor->cadastrarUsuario(4);
    // servidor->cadastrarUsuario(5);
    // servidor->imprimir();
    // servidor->removerUsuario(2);
    // servidor->removerUsuario(4);
    // servidor->removerUsuario(5);
    // servidor->removerUsuario(7);
    // servidor->imprimir();

    // FilaPorPrioridadeEmails *fila = new FilaPorPrioridadeEmails();
    // fila->adicionar(3, "oi");
    // fila->adicionar(2, "ola");
    // fila->adicionar(9, "mas eu tenho mais prioridade");
    // fila->adicionar(2, "tudo bem?");
    // fila->adicionar(1, "tudo e vc?");
    // fila->adicionar(8, "quero ser o primeiro");
   

    // fila->imprimir();
    
    return 0;
}