#include "Banco.h"
#include "utils.h"
#include <iostream>

// ============================================================
// main.cpp — Ponto de entrada do programa
// Exibe o menu principal e chama as funções do Banco.
// ============================================================

// Exibe o menu principal com as opções numeradas
void exibirMenu() {
    std::cout << "\n====== SISTEMA DE GERENCIAMENTO DE BANCO ======\n";
    std::cout << "  1. Cadastrar cliente\n";
    std::cout << "  2. Cadastrar gerente\n";
    std::cout << "  3. Criar transacao\n";
    std::cout << "  4. Exibir extrato de um cliente\n";
    std::cout << "  5. Associar gerente a cliente\n";
    std::cout << "  6. Listar clientes\n";
    std::cout << "  7. Listar gerentes\n";
    std::cout << "  8. Cartao de credito (extra)\n";
    std::cout << "  9. Salvar dados e sair\n";
    std::cout << "================================================\n";
    std::cout << "  Escolha uma opcao: ";
}

int main() {
    Banco banco;

    // Carrega os dados salvos anteriormente (se existirem)
    banco.carregarDados();
    std::cout << "  Dados carregados.\n";

    int opcao = 0;

    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                banco.cadastrarCliente();
                break;
            case 2:
                banco.cadastrarGerente();
                break;
            case 3:
                banco.criarTransacao();
                break;
            case 4:
                banco.exibirExtrato();
                break;
            case 5:
                banco.associarGerenteACliente();
                break;
            case 6:
                banco.listarClientes();
                break;
            case 7:
                banco.listarGerentes();
                break;
            case 8:
                banco.menuCartao();
                break;
            case 9:
                banco.salvarDados();
                std::cout << "  Encerrando o sistema. Ate logo!\n";
                break;
            default:
                std::cout << "  Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 9);

    return 0;
}
