#ifndef TRANSACAO_H_
#define TRANSACAO_H_

#include <string>
#include <vector>
#include "Cliente.h"
using namespace std;

class Cliente;

/// Classe Transacao representa uma transação financeira realizada por um cliente
class Transacao{
    private:
        string tipo, data, horario;
        double valor;
        vector<Cliente*> clientesEnvolvidos; 
    public: 
        Transacao(string tipo, string data, string horario, double valor);
        string getTipo();
        string getData();
        string getHorario();
        Cliente* getClientes();
        double getValor();
        void setTipo(string tipo);
        void setData(string data);  
        void setHorario(string horario);
        void setValor(double valor);
        void setClientes(Cliente* cliente);
        void exibirTransacao();
        static Transacao* criarTransacao(vector<Cliente*>& clientes);
        
};

#endif