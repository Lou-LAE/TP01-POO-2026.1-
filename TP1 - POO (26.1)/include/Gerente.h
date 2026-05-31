#ifndef GERENTE_H_
#define GERENTE_H_

#include "Pessoa.h"
#include "Cliente.h"
#include <string>
#include <vector>

using namespace std;
class Cliente;

// Declaração da classe Gerente, que herda da classe Pessoa
class Gerente : public Pessoa {
    private:
        vector<Cliente*> clientes; // coleção de clientes associados ao gerente
    public:
        Gerente(string nome, string trabalho, string login, string senha);
        vector<Cliente*> getClientes();
        void setClientes(Cliente clientes);
        void exibirDados() override;
        bool adicionarGerenteCliente(Cliente* cliente);
        static Gerente* criarGerente();
        static void exibirGerentes(std::vector<Gerente*>& gerentes);
};

#endif