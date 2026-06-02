#ifndef PESSOA_H
#define PESSOA_H

#include <string>

// ============================================================
// Classe base Pessoa
// Representa qualquer pessoa no sistema (cliente ou gerente).
// Contém os atributos e métodos comuns a ambos os tipos.
// ============================================================
class Pessoa {
protected:
    std::string nome;
    std::string trabalho;
    std::string login;
    std::string senha;

public:
    // Construtor padrão
    Pessoa();

    // Construtor com parâmetros
    Pessoa(const std::string& nome, const std::string& trabalho,
           const std::string& login, const std::string& senha);

    // Destrutor virtual (necessário para herança com polimorfismo)
    virtual ~Pessoa();

    // Getters
    std::string getNome()     const;
    std::string getTrabalho() const;
    std::string getLogin()    const;
    std::string getSenha()    const;

    // Setters
    void setNome(const std::string& nome);
    void setTrabalho(const std::string& trabalho);
    void setLogin(const std::string& login);
    void setSenha(const std::string& senha);

    // Método virtual puro: obriga as subclasses a implementar exibirDados()
    virtual void exibirDados() const = 0;
};

#endif
