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
        vector<string> tokens;
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 8) {
            string nome = tokens[0];
            string trabalho = tokens[1];
            string login = tokens[2];
            string senha = tokens[3];
            string tipo = tokens[4];
            string remuneracaoStr = tokens[5];
            string saldoStr = tokens[6];
            string taxaStr = tokens[7];

            try {
                double remuneracao = remuneracaoStr.empty() ? 0.0 : stod(remuneracaoStr);
                double saldo = saldoStr.empty() ? 0.0 : stod(saldoStr);
                double taxa = taxaStr.empty() ? 0.0 : stod(taxaStr);

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
            } catch (const invalid_argument&) {
                cout << "Aviso: linha invalida em clientes.csv ignorada." << endl;
            }
        } else if (tokens.size() == 5) {
            string nome = tokens[0];
            string trabalho = tokens[1];
            string login = tokens[2];
            string senha = tokens[3];
            string saldoStr = tokens[4];

            try {
                double saldo = saldoStr.empty() ? 0.0 : stod(saldoStr);

                Cliente* c = new Cliente(
                    nome,
                    trabalho,
                    login,
                    senha,
                    "corrente",
                    0.0,
                    saldo,
                    0.0
                );

                clientes.push_back(c);
            } catch (const invalid_argument&) {
                cout << "Aviso: linha invalida em clientes.csv ignorada." << endl;
            }
        } else {
            cout << "Aviso: formato desconhecido em clientes.csv ignorado." << endl;
        }
    }

    arquivo.close();
}

void salvarClientes(vector<Cliente*>& clientes) {
    ofstream arquivo("data/clientes.csv");

    if (!arquivo.is_open()) {
        cout << "Erro ao salvar clientes!\n";
        return;
    }

    arquivo << "nome,trabalho,login,senha,tipo,remuneracao,saldo,taxa\n";

    for (Cliente* c : clientes) {
        arquivo 
            << c->getNome() << ","
            << c->getTrabalho() << ","
            << c->getLogin() << ","
            << c->getSenha() << ","
            << c->getTipoDeConta() << ","
            << c->getRemuneracao() << ","
            << c->getSaldo() << ","
            << c->getTaxaDeRendimento() << "\n";
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