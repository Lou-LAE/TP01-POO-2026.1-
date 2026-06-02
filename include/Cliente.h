#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Pessoa.h"
#include <vector>
#include <string>
using namespace std;

class Gerente;
class Transacao;

// Declaração da classe Cliente, que herda da classe Pessoa
class Cliente : public Pessoa{
    private:
        string tipoDeConta;
        double remuneracao, saldo, taxaDeRendimento;
        vector<Transacao*> transacoes;
    public:
        Cliente(string nome, string trabalho, string login, string senha, string tipoDeConta, double remuneracao, double saldo, double taxaDeRendimento);

        string getTipoDeConta();
        double getRemuneracao();    
        double getSaldo();
        double getTaxaDeRendimento();
        Transacao* getTransacoes();
        void setTipoDeConta(string tipoDeConta);
        void setRemuneracao(double remuneracao);
        void setSaldo(double saldo);
        void setTaxaDeRendimento(double taxaDeRendimento);
        void setTransacoes(Transacao* transacao);
        void exibirDados() override;
        static Cliente* criarCliente();
        void exibirExtrato();
        static void exibirClientes(vector<Cliente*>& clientes);
        friend bool associarGerenteCliente(vector<Gerente*>& gerentes, vector<Cliente*>& clientes);
};

#endif