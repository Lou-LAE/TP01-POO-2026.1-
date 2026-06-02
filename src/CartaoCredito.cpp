#include "CartaoCredito.h"
#include <iostream>
#include <iomanip>

// ── Construtor ───────────────────────────────────────────────
CartaoCredito::CartaoCredito(double limite)
    : limite(limite), limiteDisponivel(limite), bloqueado(false) {}

// ── Getters ──────────────────────────────────────────────────
double CartaoCredito::getLimite()           const { return limite; }
double CartaoCredito::getLimiteDisponivel() const { return limiteDisponivel; }
bool   CartaoCredito::isBloqueado()         const { return bloqueado; }

// ── setLimite ────────────────────────────────────────────────
// Atualiza o limite total e recalcula o disponível proporcionalmente
void CartaoCredito::setLimite(double novoLimite) {
    double usado = limite - limiteDisponivel; // quanto já foi gasto
    limite = novoLimite;
    limiteDisponivel = novoLimite - usado;
    if (limiteDisponivel < 0) limiteDisponivel = 0;
}

// ── bloquear / desbloquear ───────────────────────────────────
void CartaoCredito::bloquear()    { bloqueado = true; }
void CartaoCredito::desbloquear() { bloqueado = false; }

// ── realizarCompra ───────────────────────────────────────────
// Registra uma compra parcelada no cartão.
// Retorna false se o cartão estiver bloqueado ou sem limite.
bool CartaoCredito::realizarCompra(const std::string& descricao,
                                   double valor, int parcelas) {
    // Verifica se o cartão está bloqueado
    if (bloqueado) {
        std::cout << "  Cartao bloqueado! Operacao cancelada.\n";
        return false;
    }
    // Verifica se há limite disponível
    if (valor > limiteDisponivel) {
        std::cout << "  Limite insuficiente! Disponivel: R$ "
                  << std::fixed << std::setprecision(2)
                  << limiteDisponivel << "\n";
        return false;
    }

    // Cria a parcela e registra
    ParcelaCartao compra;
    compra.descricao     = descricao;
    compra.valorTotal    = valor;
    compra.numParcelas   = parcelas;
    compra.valorParcela  = valor / parcelas;
    compra.parcelasPagas = 0;

    compras.push_back(compra);
    limiteDisponivel -= valor; // Reduz o limite disponível
    return true;
}

// ── calcularFatura ───────────────────────────────────────────
// Soma o valor das parcelas ainda não pagas de todas as compras
double CartaoCredito::calcularFatura() const {
    double total = 0.0;
    for (const auto& c : compras) {
        int parcelasRestantes = c.numParcelas - c.parcelasPagas;
        total += parcelasRestantes * c.valorParcela;
    }
    return total;
}

// ── exibirFatura ─────────────────────────────────────────────
// Mostra detalhes de cada compra parcelada pendente
void CartaoCredito::exibirFatura() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n  ====== FATURA DO CARTAO ======\n";
    std::cout << "  Limite total    : R$ " << limite << "\n";
    std::cout << "  Limite disponivel: R$ " << limiteDisponivel << "\n";
    std::cout << "  Status: " << (bloqueado ? "BLOQUEADO" : "ATIVO") << "\n";
    std::cout << "  ------------------------------\n";

    if (compras.empty()) {
        std::cout << "  Nenhuma compra registrada.\n";
    } else {
        for (const auto& c : compras) {
            int restantes = c.numParcelas - c.parcelasPagas;
            if (restantes > 0) {
                std::cout << "  - " << c.descricao
                          << " | R$ " << c.valorParcela
                          << " x " << restantes
                          << " parcelas restantes"
                          << " (total: R$ " << restantes * c.valorParcela << ")\n";
            }
        }
    }

    std::cout << "  ------------------------------\n";
    std::cout << "  TOTAL DA FATURA: R$ " << calcularFatura() << "\n";
    std::cout << "  ==============================\n";
}

// ── pagarFatura ──────────────────────────────────────────────
// Paga todas as parcelas pendentes do mês atual.
// Retorna o valor total pago (para descontar do saldo do cliente).
double CartaoCredito::pagarFatura() {
    double totalPago = 0.0;

    for (auto& c : compras) {
        if (c.parcelasPagas < c.numParcelas) {
            // Paga uma parcela de cada compra
            totalPago += c.valorParcela;
            c.parcelasPagas++;

            // Se acabaram as parcelas, devolve o valor ao limite
            if (c.parcelasPagas == c.numParcelas) {
                limiteDisponivel += c.valorTotal;
            }
        }
    }

    return totalPago;
}
