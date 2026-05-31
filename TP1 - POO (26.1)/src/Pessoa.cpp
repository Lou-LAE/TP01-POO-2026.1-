#include "../include/Pessoa.h"

Pessoa::Pessoa(string nome, string trabalho, string login, string senha): nome(nome), trabalho(trabalho), login(login), senha(senha) {}

void Pessoa::exibirDados() {
    cout << "Nome: " << nome << endl << "Trabalho: " << trabalho << endl << "Login: " << login << endl;
}

string Pessoa::getTrabalho() {
    return trabalho;
}

void Pessoa::setTrabalho(string trabalho) {
    this->trabalho = trabalho;
}

string Pessoa::getNome() {
    return nome;
}

string Pessoa::getLogin() {
    return login;
}

string Pessoa::getSenha() {
    return senha;
}