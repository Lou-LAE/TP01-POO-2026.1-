#include "Cliente.h"
#include <iostream>
#include <iomanip>

// ── Construtor padrão ────────────────────────────────────────
Cliente::Cliente()
    : Pessoa(), dataNascimento(""), remuneracao(0.0),
      tipoConta("corrente"), taxaRendimento(0.0),
      saldo(0.0), cartao(nullptr) {}

// ── Construtor completo ──────────────────────────────────────
Cliente::Cliente(const std::string& nome, const std::string& dataNascimento,
                 const std::string& trabalho, double remuneracao,
                 const std::string& tipoConta, double taxaRendimento,
                 double saldo, const std::string& login,
                 const std::string& senha)
    : Pessoa(nome, trabalho, login, senha),
      dataNascimento(dataNascimento), remuneracao(remuneracao),
      tipoConta(tipoConta), taxaRendimento(taxaRendimento),
      saldo(saldo), cartao(nullptr) {}

// ── Destrutor ────────────────────────────────────────────────
// Libera a memória do cartão se ele existir
Cliente::~Cliente() {
    if (cartao != nullptr) {
        delete cartao;
        cartao = nullptr;
    }
}

// ── Getters ──────────────────────────────────────────────────
std::string Cliente::getDataNascimento() const { return dataNascimento; }
double      Cliente::getRemuneracao()    const { return remuneracao; }
std::string Cliente::getTipoConta()      const { return tipoConta; }
double      Cliente::getTaxaRendimento() const { return taxaRendimento; }
double      Cliente::getSaldo()          const { return saldo; }
CartaoCredito* Cliente::getCartao()      const { return cartao; }

std::vector<Transacao> Cliente::getTransacoes() const { return transacoes; }

// ── Setters ──────────────────────────────────────────────────
void Cliente::setDataNascimento(const std::string& d) { dataNascimento = d; }
void Cliente::setRemuneracao(double r)                 { remuneracao = r; }
void Cliente::setTipoConta(const std::string& t)       { tipoConta = t; }
void Cliente::setTaxaRendimento(double t)              { taxaRendimento = t; }
void Cliente::setSaldo(double s)                       { saldo = s; }

// ── adicionarTransacao ───────────────────────────────────────
// Adiciona uma transação ao histórico (extrato) do cliente
void Cliente::adicionarTransacao(const Transacao& t) {
    transacoes.push_back(t);
}

// ── aplicarRendimento ────────────────────────────────────────
// Aplica a taxa de rendimento ao saldo (somente poupança)
void Cliente::aplicarRendimento() {
    if (tipoConta == "poupanca" && taxaRendimento > 0) {
        double rendimento = saldo * (taxaRendimento / 100.0);
        saldo += rendimento;
        std::cout << "  Rendimento aplicado: R$ "
                  << std::fixed << std::setprecision(2)
                  << rendimento << "\n";
    } else {
        std::cout << "  Esta conta nao e do tipo poupanca.\n";
    }
}

// ── criarCartao ──────────────────────────────────────────────
// Cria um cartão de crédito com limite = 3x a remuneração
void Cliente::criarCartao() {
    if (cartao != nullptr) {
        std::cout << "  Cliente ja possui cartao de credito.\n";
        return;
    }
    double limite = remuneracao * 3.0; // Limite = 3x o salário
    cartao = new CartaoCredito(limite);
    std::cout << "  Cartao criado com limite de R$ "
              << std::fixed << std::setprecision(2)
              << limite << "\n";
}

// ── exibirDados ──────────────────────────────────────────────
// Exibe todas as informações do cliente no terminal
void Cliente::exibirDados() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n  ====== DADOS DO CLIENTE ======\n";
    std::cout << "  Nome          : " << nome           << "\n";
    std::cout << "  Nascimento    : " << dataNascimento << "\n";
    std::cout << "  Trabalho      : " << trabalho       << "\n";
    std::cout << "  Remuneracao   : R$ " << remuneracao << "\n";
    std::cout << "  Login         : " << login          << "\n";
    std::cout << "  Tipo de conta : " << tipoConta      << "\n";

    // Mostra taxa de rendimento só se for poupança
    if (tipoConta == "poupanca") {
        std::cout << "  Taxa rendimento: " << taxaRendimento << "%\n";
    }

    std::cout << "  Saldo         : R$ " << saldo << "\n";
    std::cout << "  Cartao        : "
              << (cartao != nullptr ? "Sim" : "Nao") << "\n";
    std::cout << "  ==============================\n";
}

// ── exibirExtrato ────────────────────────────────────────────
// Lista todas as transações do cliente
void Cliente::exibirExtrato() const {
    std::cout << "\n  ====== EXTRATO DE " << nome << " ======\n";
    if (transacoes.empty()) {
        std::cout << "  Nenhuma transacao registrada.\n";
    } else {
        for (const auto& t : transacoes) {
            t.exibirTransacao();
        }
    }
    std::cout << "  Saldo atual: R$ "
              << std::fixed << std::setprecision(2)
              << saldo << "\n";
    std::cout << "  =================================\n";
}
