#ifndef BANCO_H
#define BANCO_H

#include "Cliente.h"
#include "Gerente.h"
#include <vector>
#include <string>

// ============================================================
// Classe Banco
// Classe principal do sistema. Armazena todos os clientes
// e gerentes, e oferece os métodos para cada operação do menu.
// ============================================================
class Banco {
private:
    std::vector<Cliente> clientes;  // Lista de todos os clientes
    std::vector<Gerente> gerentes;  // Lista de todos os gerentes

    // ── Métodos auxiliares privados ──────────────────────────

    // Retorna ponteiro para o cliente com o login informado (nullptr se não achar)
    Cliente* buscarClientePorLogin(const std::string& login);

    // Retorna ponteiro para o gerente com o login informado
    Gerente* buscarGerentePorLogin(const std::string& login);

    // Obtém data e hora atual do sistema como strings
    std::string obterDataAtual()    const;
    std::string obterHorarioAtual() const;

public:
    Banco();

    // ── Operações principais (chamadas pelo menu) ─────────────

    // Cadastra um novo cliente via entrada do terminal
    void cadastrarCliente();

    // Cadastra um novo gerente via entrada do terminal
    void cadastrarGerente();

    // Cria uma transação (depósito, saque ou transferência)
    void criarTransacao();

    // Exibe o extrato de um cliente
    void exibirExtrato();

    // Associa um gerente a um cliente
    void associarGerenteACliente();

    // Lista todos os clientes ou busca por nome
    void listarClientes();

    // Lista todos os gerentes ou busca por nome
    void listarGerentes();

    // ── Módulo Cartão de Crédito (ponto extra) ────────────────

    // Exibe o submenu do cartão de crédito
    void menuCartao();

    // Cria cartão para um cliente (ação do gerente)
    void criarCartaoParaCliente();

    // Altera o limite do cartão de um cliente
    void alterarLimiteCartao();

    // Realiza uma compra parcelada no cartão
    void compraParcelada();

    // Exibe a fatura do cartão
    void exibirFaturaCartao();

    // Bloqueia ou desbloqueia o cartão
    void bloquearCartao();

    // Paga a fatura do cartão (desconta do saldo)
    void pagarFaturaCartao();

    // ── Persistência de dados ─────────────────────────────────

    // Salva todos os clientes em clientes.csv
    void salvarClientes(const std::string& arquivo) const;

    // Salva todos os gerentes em gerentes.csv
    void salvarGerentes(const std::string& arquivo) const;

    // Carrega clientes do arquivo CSV
    void carregarClientes(const std::string& arquivo);

    // Carrega gerentes do arquivo CSV
    void carregarGerentes(const std::string& arquivo);

    // Salva e carrega ambos os arquivos de uma vez
    void salvarDados()   const;
    void carregarDados();
};

#endif
