#include "Pessoa.h"

// ── Construtor padrão ────────────────────────────────────────
Pessoa::Pessoa() : nome(""), trabalho(""), login(""), senha("") {}

// ── Construtor com parâmetros ────────────────────────────────
Pessoa::Pessoa(const std::string& nome, const std::string& trabalho,
               const std::string& login, const std::string& senha)
    : nome(nome), trabalho(trabalho), login(login), senha(senha) {}

// ── Destrutor virtual ────────────────────────────────────────
Pessoa::~Pessoa() {}

// ── Getters ──────────────────────────────────────────────────
std::string Pessoa::getNome()     const { return nome; }
std::string Pessoa::getTrabalho() const { return trabalho; }
std::string Pessoa::getLogin()    const { return login; }
std::string Pessoa::getSenha()    const { return senha; }

// ── Setters ──────────────────────────────────────────────────
void Pessoa::setNome(const std::string& n)     { nome = n; }
void Pessoa::setTrabalho(const std::string& t) { trabalho = t; }
void Pessoa::setLogin(const std::string& l)    { login = l; }
void Pessoa::setSenha(const std::string& s)    { senha = s; }
