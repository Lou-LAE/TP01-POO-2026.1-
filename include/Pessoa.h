#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
#include <iostream>

using namespace std;

// Classe base para Cliente e Gerente
class Pessoa{
    protected:
        string nome, trabalho, login, senha; 
    public:
        Pessoa(string nome, string trabalho, string login, string senha);
        virtual void exibirDados();
        string getTrabalho();
        void setTrabalho(string trabalho); 
        string getNome();
        string getLogin();
        string getSenha();
};

#endif