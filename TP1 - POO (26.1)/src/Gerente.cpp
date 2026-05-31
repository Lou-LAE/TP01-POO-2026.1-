#include "../include/Gerente.h"
#include "../include/Cliente.h"

Gerente::Gerente(string nome, string trabalho, string login, string senha) : Pessoa(nome, trabalho, login, senha) {
    // Construtor do gerente
}

vector<Cliente*> Gerente::getClientes() {
    return clientes;
}

void Gerente::setClientes(Cliente clientes) {
    this->clientes.push_back(&clientes);
}

void Gerente::exibirDados() {
    cout << "Nome: " << nome << endl;
    cout << "Trabalho: " << trabalho << endl;
    cout << "Login: " << login << endl;
    cout << "Clientes associados: " << clientes.size() << endl;
}

bool Gerente::adicionarGerenteCliente(Cliente* cliente) {
    if (cliente != nullptr) {
        clientes.push_back(cliente);
        return true; // Cliente adicionado com sucesso
    }
    return false; // Falha ao adicionar cliente
}

Gerente* Gerente::criarGerente() {
    string nome, trabalho, login, senha;

    cout << "Nome: ";
    cin >> nome;

    cout << "Trabalho: ";
    cin >> trabalho;

    cout << "Login: ";
    cin >> login;

    cout << "Senha: ";
    cin >> senha;

    return new Gerente(nome, trabalho, login, senha);
}

void Gerente::exibirGerentes(vector<Gerente*>& gerentes) {
    cout << "=== Lista de Gerentes ===" << endl;
    for (size_t i = 0; i < gerentes.size(); i++) {
        cout << "Gerente " << i << ":\n";
        gerentes[i]->exibirDados();
        cout << "-------------------\n";
    }
}
