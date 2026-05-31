#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/Cliente.h"
#include "../include/Gerente.h"
#include "../include/Transacao.h"
#include "../include/ArquivoUtils.h"
#include "../include/menu.h"

using namespace std;

int main() {
    int escolha;

    vector<Cliente*> clientes;
    vector<Gerente*> gerentes;
    vector<Transacao*> transacoes;

    // carregar dados dos arquivos
    carregarClientes(clientes);
    carregarGerentes(gerentes);

    do {
        escolha = menu();

        switch (escolha) {

            case 1://  criar cliente
                clientes.push_back(Cliente::criarCliente());
            break;

            case 2://  criar gerente
                gerentes.push_back(Gerente::criarGerente());
            break;

            case 3://  criar transação
                transacoes.push_back(Transacao::criarTransacao(clientes));
            break;

            case 4: { // exibir extrato de um cliente
                int i;
                cout << "Escolha cliente: ";
                cin >> i;
                clientes[i]->exibirExtrato();
            break;
            }

            case 5: // associar gerente a cliente
                associarGerenteCliente(gerentes, clientes);
            break;

            case 6:// listar clientes
                Cliente::exibirClientes(clientes);
            break;

            case 7: // listar gerentes
                Gerente::exibirGerentes(gerentes);
            break;

            default:
                cout << "Opção inválida!" << endl;
        }

    } while (escolha != 8);  
    
    salvarClientes(clientes);
    salvarGerentes(gerentes);

    return 0;
}