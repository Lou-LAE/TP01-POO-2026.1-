#ifndef CARTAOCREDITO_H
#define CARTAOCREDITO_H

#include <string>
#include <vector>

// ============================================================
// Struct ParcelaCartao
// Representa uma compra parcelada no cartão de crédito.
// ============================================================
struct ParcelaCartao {
    std::string descricao;   // Descrição da compra
    double      valorTotal;  // Valor total da compra
    int         numParcelas; // Número de parcelas
    double      valorParcela;// Valor de cada parcela
    int         parcelasPagas; // Quantas parcelas já foram pagas
};

// ============================================================
// Classe CartaoCredito
// Representa o cartão de crédito de um cliente.
// Permite compras parceladas, consulta de fatura e bloqueio.
// ============================================================
class CartaoCredito {
private:
    double limite;           // Limite total do cartão
    double limiteDisponivel; // Limite ainda disponível
    bool   bloqueado;        // Se o cartão está bloqueado
    std::vector<ParcelaCartao> compras; // Lista de compras parceladas

public:
    // Construtor: recebe o limite inicial
    CartaoCredito(double limite = 0.0);

    // Getters
    double getLimite()           const;
    double getLimiteDisponivel() const;
    bool   isBloqueado()         const;

    // Setters / ações
    void setLimite(double novoLimite);
    void bloquear();
    void desbloquear();

    // Realiza uma compra parcelada no cartão
    // Retorna false se não houver limite ou cartão bloqueado
    bool realizarCompra(const std::string& descricao, double valor, int parcelas);

    // Calcula o total da fatura atual (soma de todas as parcelas pendentes)
    double calcularFatura() const;

    // Exibe a fatura detalhada no terminal
    void exibirFatura() const;

    // Paga a fatura: desconta do saldo do cliente (retorna o valor pago)
    double pagarFatura();
};

#endif
