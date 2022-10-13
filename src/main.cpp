#include <iostream>
#include <fstream>
#include <cstring>

#include "msgassert.hpp" 

using namespace std;

int main(int argc, char* argv[]){
    erroAssert((argc == 2 && strcmp(argv[1], "") != 0), "Arquivo obrigatorio!");
    string nome_arquivo = argv[1]; 

    ifstream arquivo(nome_arquivo);
    erroAssert(arquivo.is_open(), "Erro ao ler arquivo!");

    for(string linha; getline(arquivo, linha);){
        cout << linha << endl;
    }

    return 0;
}