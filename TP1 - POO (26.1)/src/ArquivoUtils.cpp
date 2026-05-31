#include "../include/ArquivoUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void carregarClientes(vector<Cliente*>& clientes) {
    ifstream arquivo("data/clientes.csv");

    if (!arquivo.is_open()) {
        cout << "clientes.csv não encontrado.\n";
        return;
    }

    string linha;
    getline(arquivo, linha); // pula cabeçalho

    while (getline(arquivo, linha)) {
        stringstream ss(linha);

        string nome, trabalho, login, senha, tipo;
        string remuneracaoStr, saldoStr, taxaStr;

        getline(ss, nome, ',');
        getline(ss, trabalho, ',');
        getline(ss, login, ',');
        getline(ss, senha, ',');
        getline(ss, tipo, ',');
        getline(ss, remuneracaoStr, ',');
        getline(ss, saldoStr, ',');
        getline(ss, taxaStr, ',');

        double remuneracao = stod(remuneracaoStr);
        double saldo = stod(saldoStr);
        double taxa = stod(taxaStr);

        Cliente* c = new Cliente(
            nome,
            trabalho,
            login,
            senha,
            tipo,
            remuneracao,
            saldo,
            taxa
        );

        clientes.push_back(c);
    }

    arquivo.close();
}

void salvarClientes(vector<Cliente*>& clientes) {
    ofstream arquivo("data/clientes.csv");

    if (!arquivo.is_open()) {
        cout << "Erro ao salvar clientes!\n";
        return;
    }

    arquivo << "nome,trabalho,login,senha,saldo\n";

    for (Cliente* c : clientes) {
        arquivo 
            << c->getNome() << ","
            << c->getTrabalho() << ","
            << c->getLogin() << ","
            << c->getSenha() << ","
            << c->getSaldo() << "\n";
    }

    arquivo.close();
}

void carregarGerentes(vector<Gerente*>& gerentes) {
    ifstream arquivo("data/gerentes.csv");

    if (!arquivo.is_open()) {
        cout << "gerentes.csv não encontrado. Iniciando vazio.\n";
        return;
    }

    string linha;
    getline(arquivo, linha); // cabeçalho

    while (getline(arquivo, linha)) {
        stringstream ss(linha);

        string nome, trabalho, login, senha;

        getline(ss, nome, ',');
        getline(ss, trabalho, ',');
        getline(ss, login, ',');
        getline(ss, senha, ',');

        Gerente* g = new Gerente(nome, trabalho, login, senha);

        gerentes.push_back(g);
    }

    arquivo.close();
}

void salvarGerentes(vector<Gerente*>& gerentes) {
    ofstream arquivo("data/gerentes.csv");

    if (!arquivo.is_open()) {
        cout << "Erro ao salvar gerentes!\n";
        return;
    }

    arquivo << "nome,trabalho,login,senha\n";

    for (Gerente* g : gerentes) {
        arquivo 
            << g->getNome() << ","
            << g->getTrabalho() << ","
            << g->getLogin() << ","
            << g->getSenha() << "\n";
    }

    arquivo.close();
}