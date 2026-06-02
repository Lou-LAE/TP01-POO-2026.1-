#include "Banco.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>

// ── Construtor ───────────────────────────────────────────────
Banco::Banco() {}

// ============================================================
// MÉTODOS AUXILIARES PRIVADOS
// ============================================================

// Busca um cliente pelo login; retorna nullptr se não encontrar
Cliente* Banco::buscarClientePorLogin(const std::string& login) {
    for (auto& c : clientes) {
        if (c.getLogin() == login) return &c;
    }
    return nullptr;
}

// Busca um gerente pelo login; retorna nullptr se não encontrar
Gerente* Banco::buscarGerentePorLogin(const std::string& login) {
    for (auto& g : gerentes) {
        if (g.getLogin() == login) return &g;
    }
    return nullptr;
}

// Retorna a data atual no formato DD/MM/AAAA
std::string Banco::obterDataAtual() const {
    time_t agora = time(nullptr);
    struct tm* t = localtime(&agora);
    char buf[11];
    strftime(buf, sizeof(buf), "%d/%m/%Y", t);
    return std::string(buf);
}

// Retorna o horário atual no formato HH:MM
std::string Banco::obterHorarioAtual() const {
    time_t agora = time(nullptr);
    struct tm* t = localtime(&agora);
    char buf[6];
    strftime(buf, sizeof(buf), "%H:%M", t);
    return std::string(buf);
}

// ============================================================
// CADASTRO DE CLIENTE
// ============================================================
void Banco::cadastrarCliente() {
    std::string nome, dataNasc, trabalho, tipoConta, login, senha;
    double remuneracao, taxa = 0.0, saldo = 0.0;

    std::cout << "\n  === CADASTRAR CLIENTE ===\n";

    std::cin.ignore();
    std::cout << "  Nome: ";
    std::getline(std::cin, nome);

    std::cout << "  Data de nascimento (DD/MM/AAAA): ";
    std::getline(std::cin, dataNasc);

    std::cout << "  Trabalho/Profissao: ";
    std::getline(std::cin, trabalho);

    std::cout << "  Remuneracao (R$): ";
    std::cin >> remuneracao;

    std::cin.ignore();
    std::cout << "  Tipo de conta (corrente/poupanca): ";
    std::getline(std::cin, tipoConta);

    // Pede taxa de rendimento apenas para conta poupança
    if (tipoConta == "poupanca") {
        std::cout << "  Taxa de rendimento (%): ";
        std::cin >> taxa;
        std::cin.ignore();
    }

    std::cout << "  Saldo inicial (R$): ";
    std::cin >> saldo;

    std::cin.ignore();
    std::cout << "  Login: ";
    std::getline(std::cin, login);

    // Verifica se o login já existe
    if (buscarClientePorLogin(login) != nullptr) {
        std::cout << "  Erro: login ja existe!\n";
        return;
    }

    std::cout << "  Senha: ";
    std::getline(std::cin, senha);

    // Cria e adiciona o cliente à lista
    Cliente novo(nome, dataNasc, trabalho, remuneracao,
                 tipoConta, taxa, saldo, login, senha);
    clientes.push_back(novo);

    std::cout << "  Cliente cadastrado com sucesso!\n";
}

// ============================================================
// CADASTRO DE GERENTE
// ============================================================
void Banco::cadastrarGerente() {
    std::string nome, trabalho, login, senha;

    std::cout << "\n  === CADASTRAR GERENTE ===\n";

    std::cin.ignore();
    std::cout << "  Nome: ";
    std::getline(std::cin, nome);

    std::cout << "  Trabalho/Cargo: ";
    std::getline(std::cin, trabalho);

    std::cout << "  Login: ";
    std::getline(std::cin, login);

    // Verifica duplicata de login
    if (buscarGerentePorLogin(login) != nullptr) {
        std::cout << "  Erro: login ja existe!\n";
        return;
    }

    std::cout << "  Senha: ";
    std::getline(std::cin, senha);

    Gerente novo(nome, trabalho, login, senha);
    gerentes.push_back(novo);

    std::cout << "  Gerente cadastrado com sucesso!\n";
}

// ============================================================
// CRIAR TRANSAÇÃO
// ============================================================
void Banco::criarTransacao() {
    std::cout << "\n  === CRIAR TRANSACAO ===\n";
    std::cout << "  Tipos: 1-Deposito  2-Saque  3-Transferencia\n";
    std::cout << "  Escolha: ";

    int opcao;
    std::cin >> opcao;

    if (opcao < 1 || opcao > 3) {
        std::cout << "  Opcao invalida!\n";
        return;
    }

    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string loginOrigem;
    std::getline(std::cin, loginOrigem);

    Cliente* origem = buscarClientePorLogin(loginOrigem);
    if (origem == nullptr) {
        std::cout << "  Cliente nao encontrado!\n";
        return;
    }

    std::cout << "  Valor (R$): ";
    double valor;
    std::cin >> valor;

    if (valor <= 0) {
        std::cout << "  Valor invalido!\n";
        return;
    }

    std::string tipo;
    std::string loginDestino = "";

    if (opcao == 1) {
        // ── Depósito ──────────────────────────────────────
        tipo = "deposito";
        origem->setSaldo(origem->getSaldo() + valor);
        std::cout << "  Deposito realizado! Novo saldo: R$ "
                  << std::fixed << std::setprecision(2)
                  << origem->getSaldo() << "\n";

    } else if (opcao == 2) {
        // ── Saque ─────────────────────────────────────────
        tipo = "saque";
        if (origem->getSaldo() < valor) {
            std::cout << "  Saldo insuficiente!\n";
            return;
        }
        origem->setSaldo(origem->getSaldo() - valor);
        std::cout << "  Saque realizado! Novo saldo: R$ "
                  << std::fixed << std::setprecision(2)
                  << origem->getSaldo() << "\n";

    } else {
        // ── Transferência ──────────────────────────────────
        tipo = "transferencia";
        std::cin.ignore();
        std::cout << "  Login do destinatario: ";
        std::getline(std::cin, loginDestino);

        Cliente* destino = buscarClientePorLogin(loginDestino);
        if (destino == nullptr) {
            std::cout << "  Destinatario nao encontrado!\n";
            return;
        }
        if (origem->getSaldo() < valor) {
            std::cout << "  Saldo insuficiente!\n";
            return;
        }

        // Debita da origem e credita no destino
        origem->setSaldo(origem->getSaldo() - valor);
        destino->setSaldo(destino->getSaldo() + valor);

        // Registra transação no extrato do destinatário também
        Transacao tDest("recebimento", valor, obterDataAtual(),
                        obterHorarioAtual(), loginDestino, loginOrigem);
        destino->adicionarTransacao(tDest);

        std::cout << "  Transferencia realizada!\n";
    }

    // Registra a transação no extrato do cliente de origem
    Transacao t(tipo, valor, obterDataAtual(), obterHorarioAtual(),
                loginOrigem, loginDestino);
    origem->adicionarTransacao(t);
}

// ============================================================
// EXIBIR EXTRATO
// ============================================================
void Banco::exibirExtrato() {
    std::cin.ignore();
    std::cout << "\n  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr) {
        std::cout << "  Cliente nao encontrado!\n";
        return;
    }
    c->exibirExtrato();
}

// ============================================================
// ASSOCIAR GERENTE A CLIENTE
// ============================================================
void Banco::associarGerenteACliente() {
    std::cin.ignore();
    std::cout << "\n  === ASSOCIAR GERENTE A CLIENTE ===\n";
    std::cout << "  Login do gerente: ";
    std::string loginG;
    std::getline(std::cin, loginG);

    Gerente* g = buscarGerentePorLogin(loginG);
    if (g == nullptr) {
        std::cout << "  Gerente nao encontrado!\n";
        return;
    }

    std::cout << "  Login do cliente: ";
    std::string loginC;
    std::getline(std::cin, loginC);

    Cliente* c = buscarClientePorLogin(loginC);
    if (c == nullptr) {
        std::cout << "  Cliente nao encontrado!\n";
        return;
    }

    g->adicionarCliente(loginC);
    std::cout << "  Associacao realizada com sucesso!\n";
}

// ============================================================
// LISTAR CLIENTES
// ============================================================
void Banco::listarClientes() {
    std::cout << "\n  === LISTAR CLIENTES ===\n";
    std::cout << "  (deixe em branco para listar todos)\n";
    std::cout << "  Nome do cliente: ";

    std::cin.ignore();
    std::string nome;
    std::getline(std::cin, nome);
    nome = trim(nome);

    bool encontrou = false;
    for (const auto& c : clientes) {
        // Se nome vazio, mostra todos; senão filtra por nome
        if (nome.empty() ||
            c.getNome().find(nome) != std::string::npos) {
            c.exibirDados();
            encontrou = true;
        }
    }

    if (!encontrou) {
        std::cout << "  Nenhum cliente encontrado.\n";
    }
}

// ============================================================
// LISTAR GERENTES
// ============================================================
void Banco::listarGerentes() {
    std::cout << "\n  === LISTAR GERENTES ===\n";
    std::cout << "  (deixe em branco para listar todos)\n";
    std::cout << "  Nome do gerente: ";

    std::cin.ignore();
    std::string nome;
    std::getline(std::cin, nome);
    nome = trim(nome);

    bool encontrou = false;
    for (const auto& g : gerentes) {
        if (nome.empty() ||
            g.getNome().find(nome) != std::string::npos) {
            g.exibirDados();
            encontrou = true;
        }
    }

    if (!encontrou) {
        std::cout << "  Nenhum gerente encontrado.\n";
    }
}

// ============================================================
// MÓDULO CARTÃO DE CRÉDITO — SUBMENU
// ============================================================
void Banco::menuCartao() {
    int op = 0;
    do {
        std::cout << "\n  ====== CARTAO DE CREDITO ======\n";
        std::cout << "  1. Criar cartao para cliente\n";
        std::cout << "  2. Alterar limite do cartao\n";
        std::cout << "  3. Realizar compra parcelada\n";
        std::cout << "  4. Exibir fatura\n";
        std::cout << "  5. Pagar fatura\n";
        std::cout << "  6. Bloquear / Desbloquear cartao\n";
        std::cout << "  0. Voltar ao menu principal\n";
        std::cout << "  ===============================\n";
        std::cout << "  Escolha: ";
        std::cin >> op;

        switch (op) {
            case 1: criarCartaoParaCliente(); break;
            case 2: alterarLimiteCartao();    break;
            case 3: compraParcelada();        break;
            case 4: exibirFaturaCartao();     break;
            case 5: pagarFaturaCartao();      break;
            case 6: bloquearCartao();         break;
            case 0: break;
            default: std::cout << "  Opcao invalida!\n";
        }
    } while (op != 0);
}

// ── Cria cartão para um cliente ──────────────────────────────
void Banco::criarCartaoParaCliente() {
    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr) {
        std::cout << "  Cliente nao encontrado!\n";
        return;
    }
    c->criarCartao();
}

// ── Altera o limite do cartão ────────────────────────────────
void Banco::alterarLimiteCartao() {
    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr || c->getCartao() == nullptr) {
        std::cout << "  Cliente nao encontrado ou sem cartao!\n";
        return;
    }

    std::cout << "  Novo limite (R$): ";
    double novoLimite;
    std::cin >> novoLimite;

    c->getCartao()->setLimite(novoLimite);
    std::cout << "  Limite atualizado para R$ "
              << std::fixed << std::setprecision(2)
              << novoLimite << "\n";
}

// ── Realiza compra parcelada ──────────────────────────────────
void Banco::compraParcelada() {
    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr || c->getCartao() == nullptr) {
        std::cout << "  Cliente nao encontrado ou sem cartao!\n";
        return;
    }

    std::cout << "  Descricao da compra: ";
    std::string desc;
    std::getline(std::cin, desc);

    std::cout << "  Valor (R$): ";
    double valor;
    std::cin >> valor;

    std::cout << "  Numero de parcelas: ";
    int parcelas;
    std::cin >> parcelas;

    if (c->getCartao()->realizarCompra(desc, valor, parcelas)) {
        std::cout << "  Compra registrada com sucesso!\n";
    }
}

// ── Exibe a fatura do cartão ──────────────────────────────────
void Banco::exibirFaturaCartao() {
    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr || c->getCartao() == nullptr) {
        std::cout << "  Cliente nao encontrado ou sem cartao!\n";
        return;
    }
    c->getCartao()->exibirFatura();
}

// ── Bloqueia ou desbloqueia o cartão ─────────────────────────
void Banco::bloquearCartao() {
    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr || c->getCartao() == nullptr) {
        std::cout << "  Cliente nao encontrado ou sem cartao!\n";
        return;
    }

    CartaoCredito* cartao = c->getCartao();
    if (cartao->isBloqueado()) {
        cartao->desbloquear();
        std::cout << "  Cartao desbloqueado com sucesso!\n";
    } else {
        cartao->bloquear();
        std::cout << "  Cartao bloqueado com sucesso!\n";
    }
}

// ── Paga a fatura e desconta do saldo ────────────────────────
void Banco::pagarFaturaCartao() {
    std::cin.ignore();
    std::cout << "  Login do cliente: ";
    std::string login;
    std::getline(std::cin, login);

    Cliente* c = buscarClientePorLogin(login);
    if (c == nullptr || c->getCartao() == nullptr) {
        std::cout << "  Cliente nao encontrado ou sem cartao!\n";
        return;
    }

    double fatura = c->getCartao()->calcularFatura();
    if (fatura <= 0) {
        std::cout << "  Nao ha fatura a pagar.\n";
        return;
    }

    std::cout << "  Total da fatura: R$ "
              << std::fixed << std::setprecision(2) << fatura << "\n";

    if (c->getSaldo() < fatura) {
        std::cout << "  Saldo insuficiente para pagar a fatura!\n";
        return;
    }

    // Paga a fatura e desconta do saldo
    double pago = c->getCartao()->pagarFatura();
    c->setSaldo(c->getSaldo() - pago);

    // Registra no extrato
    Transacao t("pagamento_fatura", pago, obterDataAtual(),
                obterHorarioAtual(), login);
    c->adicionarTransacao(t);

    std::cout << "  Fatura paga! Valor descontado: R$ "
              << std::fixed << std::setprecision(2) << pago << "\n";
    std::cout << "  Saldo atual: R$ " << c->getSaldo() << "\n";
}

// ============================================================
// PERSISTÊNCIA — SALVAR CLIENTES
// ============================================================
// Formato CSV: nome;dataNasc;trabalho;remuneracao;tipoConta;taxa;saldo;login;senha
void Banco::salvarClientes(const std::string& arquivo) const {
    std::ofstream f(arquivo);
    if (!f.is_open()) {
        std::cout << "  Erro ao abrir " << arquivo << "\n";
        return;
    }

    for (const auto& c : clientes) {
        f << c.getNome()          << ";"
          << c.getDataNascimento()<< ";"
          << c.getTrabalho()      << ";"
          << c.getRemuneracao()   << ";"
          << c.getTipoConta()     << ";"
          << c.getTaxaRendimento()<< ";"
          << c.getSaldo()         << ";"
          << c.getLogin()         << ";"
          << c.getSenha()         << "\n";
    }
    f.close();
}

// ============================================================
// PERSISTÊNCIA — SALVAR GERENTES
// ============================================================
// Formato CSV: nome;trabalho;login;senha;cliente1|cliente2|...
void Banco::salvarGerentes(const std::string& arquivo) const {
    std::ofstream f(arquivo);
    if (!f.is_open()) {
        std::cout << "  Erro ao abrir " << arquivo << "\n";
        return;
    }

    for (const auto& g : gerentes) {
        f << g.getNome()    << ";"
          << g.getTrabalho()<< ";"
          << g.getLogin()   << ";"
          << g.getSenha()   << ";";

        // Salva os logins dos clientes separados por '|'
        const auto& logins = g.getLoginsClientes();
        for (size_t i = 0; i < logins.size(); i++) {
            f << logins[i];
            if (i + 1 < logins.size()) f << "|";
        }
        f << "\n";
    }
    f.close();
}

// ============================================================
// PERSISTÊNCIA — CARREGAR CLIENTES
// ============================================================
void Banco::carregarClientes(const std::string& arquivo) {
    std::ifstream f(arquivo);
    if (!f.is_open()) return; // Arquivo pode não existir ainda

    std::string linha;
    while (std::getline(f, linha)) {
        if (linha.empty()) continue;

        auto p = split(linha, ';');
        if (p.size() < 9) continue; // Linha incompleta

        Cliente c(trim(p[0]),           // nome
                  trim(p[1]),           // dataNascimento
                  trim(p[2]),           // trabalho
                  toDouble(trim(p[3])), // remuneracao
                  trim(p[4]),           // tipoConta
                  toDouble(trim(p[5])), // taxaRendimento
                  toDouble(trim(p[6])), // saldo
                  trim(p[7]),           // login
                  trim(p[8]));          // senha
        clientes.push_back(c);
    }
    f.close();
}

// ============================================================
// PERSISTÊNCIA — CARREGAR GERENTES
// ============================================================
void Banco::carregarGerentes(const std::string& arquivo) {
    std::ifstream f(arquivo);
    if (!f.is_open()) return;

    std::string linha;
    while (std::getline(f, linha)) {
        if (linha.empty()) continue;

        auto p = split(linha, ';');
        if (p.size() < 4) continue;

        Gerente g(trim(p[0]),  // nome
                  trim(p[1]),  // trabalho
                  trim(p[2]),  // login
                  trim(p[3])); // senha

        // Carrega os logins dos clientes vinculados (separados por '|')
        if (p.size() >= 5 && !trim(p[4]).empty()) {
            auto logins = split(trim(p[4]), '|');
            for (const auto& lc : logins) {
                g.adicionarCliente(trim(lc));
            }
        }

        gerentes.push_back(g);
    }
    f.close();
}

// ── Salva e carrega os dois arquivos de uma vez ──────────────
void Banco::salvarDados() const {
    salvarClientes("data/clientes.csv");
    salvarGerentes("data/gerentes.csv");
    std::cout << "  Dados salvos com sucesso!\n";
}

void Banco::carregarDados() {
    carregarClientes("data/clientes.csv");
    carregarGerentes("data/gerentes.csv");
}
