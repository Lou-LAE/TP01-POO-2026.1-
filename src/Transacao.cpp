#include "Transacao.h"
#include "../include/Cliente.h"

Transacao::Transacao(string tipo, string data, string horario, double valor) {
    this->tipo = tipo;
    this->data = data;
    this->horario = horario;
    this->valor = valor;
}

string Transacao::getTipo() {
    return tipo;
}

string Transacao::getData() {
    return data;
}

string Transacao::getHorario() {
    return horario;
}

double Transacao::getValor() {
    return valor;
}

Cliente*Transacao::getClientes() {
    if (!clientesEnvolvidos.empty()) {
        return clientesEnvolvidos[0]; 
    }
    return nullptr; 
}

void Transacao::setTipo(string tipo) {
    this->tipo = tipo;
}

void Transacao::setData(string data) {
    this->data = data;
}

void Transacao::setHorario(string horario) {
    this->horario = horario;
}

void Transacao::setValor(double valor) {
    this->valor = valor;
}

void Transacao::setClientes(Cliente* cliente) {
    clientesEnvolvidos.push_back(cliente);
}

void Transacao::exibirTransacao() {
    cout << "=== Detalhes da Transação ===" << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Data: " << data << endl;
    cout << "Horario: " << horario << endl;
    cout << "Valor: R$" << valor << endl;
    cout << "Clientes Envolvidos: " << endl;
    for (Cliente* cliente : clientesEnvolvidos) {
        cout << "- " << cliente->getNome() << endl; 
    }
}

Transacao* Transacao::criarTransacao(vector<Cliente*>& clientes) {
    string tipo, data, horario;
    double valor;

    cout << "Tipo (deposito/saque/transferencia): ";
    cin >> tipo;

    cout << "Valor: ";
    cin >> valor;

    cout << "Data: ";
    cin >> data;

    cout << "Horario: ";
    cin >> horario;

    Transacao* t = new Transacao(tipo, data, horario, valor);

    // associar cliente
    cout << "Escolha cliente (indice): " << endl;
    for (size_t i = 0; i < clientes.size(); i++) {
        cout << i << " - " << clientes[i]->getNome() << endl;
    }

    size_t idx;
    cin >> idx;

    if (idx < clientes.size()) {
        t->setClientes(clientes[idx]);
    }

    return t;
}


