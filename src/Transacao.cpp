#include "Transacao.h"
#include <iostream>
#include <iomanip>

// ── Construtor padrão ────────────────────────────────────────
Transacao::Transacao()
    : tipo(""), valor(0.0), data(""), horario(""),
      loginOrigem(""), loginDestino("") {}

// ── Construtor completo ──────────────────────────────────────
Transacao::Transacao(const std::string& tipo, double valor,
                     const std::string& data, const std::string& horario,
                     const std::string& loginOrigem,
                     const std::string& loginDestino)
    : tipo(tipo), valor(valor), data(data), horario(horario),
      loginOrigem(loginOrigem), loginDestino(loginDestino) {}

// ── Getters ──────────────────────────────────────────────────
std::string Transacao::getTipo()         const { return tipo; }
double      Transacao::getValor()        const { return valor; }
std::string Transacao::getData()         const { return data; }
std::string Transacao::getHorario()      const { return horario; }
std::string Transacao::getLoginOrigem()  const { return loginOrigem; }
std::string Transacao::getLoginDestino() const { return loginDestino; }

// ── Setters ──────────────────────────────────────────────────
void Transacao::setTipo(const std::string& t)         { tipo = t; }
void Transacao::setValor(double v)                     { valor = v; }
void Transacao::setData(const std::string& d)          { data = d; }
void Transacao::setHorario(const std::string& h)       { horario = h; }
void Transacao::setLoginOrigem(const std::string& l)   { loginOrigem = l; }
void Transacao::setLoginDestino(const std::string& l)  { loginDestino = l; }

// ── exibirTransacao ──────────────────────────────────────────
// Mostra os detalhes da transação de forma formatada
void Transacao::exibirTransacao() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  [" << data << " " << horario << "] "
              << tipo << " - R$ " << valor;

    // Se houver destinatário, mostra para quem foi a transferência
    if (!loginDestino.empty()) {
        std::cout << " -> " << loginDestino;
    }
    std::cout << std::endl;
}
