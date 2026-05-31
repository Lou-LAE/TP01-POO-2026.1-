#include <iostream>
using namespace std;

int menu(){

    int escolha;

    cout << "====== SISTEMA DE GERENCIAMENTO DE BANCO ======" << endl <<
        "1. Cadastrar cliente" << endl << 
        "2. Cadastrar gerente" << endl << 
        "3. Criar transação" << endl << 
        "4. Exibir extrato de um cliente" << endl << 
        "5. Associar gerente a cliente" << endl << 
        "6. Listar clientes" << endl << 
        "7. Listar gerentes" << endl << 
        "8. Salvar dados e sair" << endl << 
        "==================================================" << endl<< 
        "Escolha uma opção: ";

    cin >> escolha;

    return escolha;
}

