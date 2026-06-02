#include "Gerente.h"
#include <iostream>
#include <algorithm> // para std::find

// ── Construtor padrão ────────────────────────────────────────
Gerente::Gerente() : Pessoa() {}

// ── Construtor completo ──────────────────────────────────────
Gerente::Gerente(const std::string& nome, const std::string& trabalho,
                 const std::string& login, const std::string& senha)
    : Pessoa(nome, trabalho, login, senha) {}

// ── getLoginsClientes ────────────────────────────────────────
std::vector<std::string> Gerente::getLoginsClientes() const {
    return loginsClientes;
}

// ── adicionarCliente ─────────────────────────────────────────
// Vincula um cliente ao gerente (pelo login do cliente)
void Gerente::adicionarCliente(const std::string& loginCliente) {
    // Evita duplicatas
    if (!temCliente(loginCliente)) {
        loginsClientes.push_back(loginCliente);
    }
}

// ── removerCliente ───────────────────────────────────────────
void Gerente::removerCliente(const std::string& loginCliente) {
    auto it = std::find(loginsClientes.begin(), loginsClientes.end(), loginCliente);
    if (it != loginsClientes.end()) {
        loginsClientes.erase(it);
    }
}

// ── temCliente ───────────────────────────────────────────────
// Verifica se um cliente já está na lista deste gerente
bool Gerente::temCliente(const std::string& loginCliente) const {
    return std::find(loginsClientes.begin(), loginsClientes.end(), loginCliente)
           != loginsClientes.end();
}

// ── exibirDados ──────────────────────────────────────────────
void Gerente::exibirDados() const {
    std::cout << "\n  ====== DADOS DO GERENTE ======\n";
    std::cout << "  Nome     : " << nome     << "\n";
    std::cout << "  Trabalho : " << trabalho << "\n";
    std::cout << "  Login    : " << login    << "\n";
    std::cout << "  Clientes vinculados (" << loginsClientes.size() << "):\n";

    if (loginsClientes.empty()) {
        std::cout << "    (nenhum)\n";
    } else {
        for (const auto& lc : loginsClientes) {
            std::cout << "    - " << lc << "\n";
        }
    }
    std::cout << "  ==============================\n";
}
