#include "../include/Cliente.h"
#include "../include/Transacao.h"
#include "../include/Gerente.h"

#include <iostream>

using namespace std;

Cliente::Cliente(string nome, string trabalho, string login, string senha, string tipoDeConta, double remuneracao, double saldo, double taxaDeRendimento) : Pessoa(nome, trabalho, login, senha) {
    this->tipoDeConta = tipoDeConta;
    this->remuneracao = remuneracao;
    this->saldo = saldo;
    this->taxaDeRendimento = taxaDeRendimento;
}

string Cliente::getTipoDeConta() {
    return tipoDeConta;
}

double Cliente::getRemuneracao() {
    return remuneracao;
}

double Cliente::getSaldo() {
    return saldo;
}

double Cliente::getTaxaDeRendimento() {
    return taxaDeRendimento;
}

Transacao* Cliente::getTransacoes() {
    if (!transacoes.empty()) {
        return transacoes[0]; 
    }
    return nullptr; 
}

void Cliente::setTipoDeConta(string tipoDeConta) {
    this->tipoDeConta = tipoDeConta;
}

void Cliente::setRemuneracao(double remuneracao) {
    this->remuneracao = remuneracao;
}

void Cliente::setSaldo(double saldo) {
    this->saldo = saldo;
}

void Cliente::setTaxaDeRendimento(double taxaDeRendimento) {
    this->taxaDeRendimento = taxaDeRendimento;
}

void Cliente::setTransacoes(Transacao* transacao) {
    transacoes.push_back(transacao);
}

void Cliente::exibirDados() {
    cout << "=== Dados do Cliente ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Trabalho: " << trabalho << endl;
    cout << "Login: " << login << endl;
    cout << "Tipo de Conta: " << tipoDeConta << endl;
    cout << "Remuneração: R$" << remuneracao << endl;
    cout << "Saldo: R$" << saldo << endl;
    cout << "Taxa de Rendimento: " << taxaDeRendimento * 100 << "%" << endl;
}

Cliente* Cliente::criarCliente() {
    string nome, trabalho, login, senha;
    string tipoDeConta;
    double saldo, remuneracao, taxaDeRendimento;

    cout << "Nome: ";
    cin >> ws; // esvazia o buffer de entrada antes de prosseguir usando std::getline()
    std::getline(std::cin, nome);

    cout << "Trabalho: ";
    std::getline(std::cin, trabalho);

    cout << "Login: ";
    cin >> login;

    cout << "Senha: ";
    cin >> senha;

    cout << "Saldo inicial: ";
    cin >> saldo;

    cout << "Tipo de conta (corrente/poupanca): ";
    cin >> tipoDeConta;

    cout << "Remuneracao: ";
    cin >> remuneracao;

    if (tipoDeConta == "poupanca") {
        cout << "Taxa de rendimento: ";
        cin >> taxaDeRendimento;
    } else {
        taxaDeRendimento = 0.0;
    }

    Cliente* cliente = new Cliente(
        nome,
        trabalho,
        login,
        senha,
        tipoDeConta,
        remuneracao,
        saldo,
        taxaDeRendimento
    );

    return cliente;
}

void Cliente::exibirExtrato() {
    cout << "=== Extrato de " << getNome() << " ===" << endl;

    for (Transacao* t : transacoes) {
        t->exibirTransacao();
    }
}

void Cliente::exibirClientes(vector<Cliente*>& clientes) {
    for (Cliente* c : clientes) {
        cout << "Nome: " << c->getNome() << endl;
        cout << "Saldo: R$ " << c->getSaldo() << endl;
        cout << "---------------------" << endl;
    }
}

bool associarGerenteCliente(vector<Gerente*>& gerentes, vector<Cliente*>& clientes) {
    long unsigned int g, c;

    cout << "Escolha gerente: " << endl;
    for (long unsigned int i = 0; i < gerentes.size(); i++) {
        cout << i << " - " << gerentes[i]->getNome() << endl;
    }
    cin >> g;

    cout << "Escolha cliente: " << endl;
    for (long unsigned int i = 0; i < clientes.size(); i++) {
        cout << i << " - " << clientes[i]->getNome() << endl;
    }
    cin >> c;

    if (g >= 0 && g < gerentes.size() && c >= 0 && c < clientes.size()) {
        gerentes[g]->adicionarGerenteCliente(clientes[c]);
        return true;
    }

    return false;
}