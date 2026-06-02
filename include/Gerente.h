#ifndef GERENTE_H
#define GERENTE_H

#include "Pessoa.h"
#include <vector>
#include <string>

// ============================================================
// Classe Gerente (herda de Pessoa)
// Representa um gerente do banco.
// Mantém uma lista com os logins dos clientes vinculados.
// ============================================================
class Gerente : public Pessoa {
private:
    // Lista de logins dos clientes que este gerente gerencia
    std::vector<std::string> loginsClientes;

public:
    // Construtor padrão
    Gerente();

    // Construtor completo
    Gerente(const std::string& nome, const std::string& trabalho,
            const std::string& login, const std::string& senha);

    // Retorna a lista de logins dos clientes vinculados
    std::vector<std::string> getLoginsClientes() const;

    // Vincula um novo cliente ao gerente pelo login
    void adicionarCliente(const std::string& loginCliente);

    // Remove um cliente da lista pelo login
    void removerCliente(const std::string& loginCliente);

    // Verifica se um cliente já está vinculado
    bool temCliente(const std::string& loginCliente) const;

    // Exibe os dados do gerente e seus clientes vinculados
    void exibirDados() const override;
};

#endif
