#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

// ============================================================
// Classe Transacao
// Representa uma movimentação financeira no sistema:
// depósito, saque ou transferência.
// ============================================================
class Transacao {
private:
    std::string tipo;           // "deposito", "saque" ou "transferencia"
    double      valor;          // Valor da transação
    std::string data;           // Data no formato DD/MM/AAAA
    std::string horario;        // Horário no formato HH:MM
    std::string loginOrigem;    // Login do cliente que realizou
    std::string loginDestino;   // Login do destinatário (só em transferência)

public:
    // Construtor padrão
    Transacao();

    // Construtor completo
    Transacao(const std::string& tipo, double valor,
              const std::string& data, const std::string& horario,
              const std::string& loginOrigem,
              const std::string& loginDestino = "");

    // Getters
    std::string getTipo()         const;
    double      getValor()        const;
    std::string getData()         const;
    std::string getHorario()      const;
    std::string getLoginOrigem()  const;
    std::string getLoginDestino() const;

    // Setters
    void setTipo(const std::string& tipo);
    void setValor(double valor);
    void setData(const std::string& data);
    void setHorario(const std::string& horario);
    void setLoginOrigem(const std::string& login);
    void setLoginDestino(const std::string& login);

    // Exibe os dados da transação no terminal
    void exibirTransacao() const;
};

#endif
