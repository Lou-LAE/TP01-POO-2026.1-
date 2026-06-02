#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include "Transacao.h"
#include "CartaoCredito.h"
#include <vector>
#include <string>

// ============================================================
// Classe Cliente (herda de Pessoa)
// Representa um cliente do banco.
// Possui conta (corrente ou poupança), saldo, extrato e
// opcionalmente um cartão de crédito.
// ============================================================
class Cliente : public Pessoa {
private:
    std::string dataNascimento;  // Formato DD/MM/AAAA
    double      remuneracao;     // Salário / renda mensal
    std::string tipoConta;       // "corrente" ou "poupanca"
    double      taxaRendimento;  // Taxa de rendimento (apenas poupança)
    double      saldo;           // Saldo atual da conta

    // Histórico das últimas transações (extrato)
    std::vector<Transacao> transacoes;

    // Ponteiro para o cartão de crédito (nullptr se não tiver)
    CartaoCredito* cartao;

public:
    // Construtor padrão
    Cliente();

    // Construtor completo
    Cliente(const std::string& nome, const std::string& dataNascimento,
            const std::string& trabalho, double remuneracao,
            const std::string& tipoConta, double taxaRendimento,
            double saldo, const std::string& login, const std::string& senha);

    // Destrutor: libera memória do cartão se existir
    ~Cliente();

    // Getters
    std::string getDataNascimento() const;
    double      getRemuneracao()    const;
    std::string getTipoConta()      const;
    double      getTaxaRendimento() const;
    double      getSaldo()          const;
    CartaoCredito* getCartao()      const;

    // Retorna uma cópia do vetor de transações (extrato)
    std::vector<Transacao> getTransacoes() const;

    // Setters
    void setDataNascimento(const std::string& data);
    void setRemuneracao(double remuneracao);
    void setTipoConta(const std::string& tipo);
    void setTaxaRendimento(double taxa);
    void setSaldo(double saldo);

    // Adiciona uma transação ao extrato
    void adicionarTransacao(const Transacao& t);

    // Aplica rendimento da poupança sobre o saldo atual
    void aplicarRendimento();

    // Cria um cartão de crédito para este cliente
    // O limite é calculado como 3x a remuneração
    void criarCartao();

    // Exibe todas as informações do cliente
    void exibirDados() const override;

    // Exibe o extrato (lista de transações)
    void exibirExtrato() const;
};

#endif
