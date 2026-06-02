# Sistema de Gerenciamento de Banco

Trabalho Prático — BCC 221 Programação Orientada a Objetos  
Desenvolvido em C++ com uso da biblioteca STL.

---

## Requisitos

- Compilador `g++` com suporte a C++17
- `make` instalado no sistema
- Sistema Linux, macOS ou Windows (com MinGW)

---

## Como compilar e executar

```bash
# 1. Entre na pasta do projeto
cd banco

# 2. Compile o projeto
make

# 3. Execute o programa
./banco

# Ou compile e execute de uma vez
make run
```

Para limpar os arquivos compilados:

```bash
make clean
```

---

## Estrutura do Projeto

```
banco/
├── include/           # Arquivos de cabeçalho (.h)
│   ├── Pessoa.h
│   ├── Cliente.h
│   ├── Gerente.h
│   ├── Transacao.h
│   ├── CartaoCredito.h
│   ├── Banco.h
│   └── utils.h
├── src/               # Implementações (.cpp)
│   ├── main.cpp
│   ├── Pessoa.cpp
│   ├── Cliente.cpp
│   ├── Gerente.cpp
│   ├── Transacao.cpp
│   ├── CartaoCredito.cpp
│   ├── Banco.cpp
│   └── utils.cpp
├── data/              # Arquivos CSV (criado automaticamente)
│   ├── clientes.csv
│   └── gerentes.csv
├── obj/               # Objetos compilados (criado pelo make)
├── Makefile
└── README.md
```

---

## Funcionalidades

### Menu Principal

| Opção | Descrição |
|-------|-----------|
| 1 | Cadastrar cliente (nome, nascimento, conta, saldo, etc.) |
| 2 | Cadastrar gerente |
| 3 | Criar transação (depósito, saque ou transferência) |
| 4 | Exibir extrato de um cliente |
| 5 | Associar gerente a cliente |
| 6 | Listar clientes (todos ou por nome) |
| 7 | Listar gerentes (todos ou por nome) |
| 8 | Módulo cartão de crédito (ponto extra) |
| 9 | Salvar dados e sair |

### Submenu — Cartão de Crédito

| Opção | Descrição |
|-------|-----------|
| 1 | Criar cartão para cliente (limite = 3× remuneração) |
| 2 | Alterar limite do cartão |
| 3 | Realizar compra parcelada |
| 4 | Exibir fatura |
| 5 | Pagar fatura (desconta do saldo do cliente) |
| 6 | Bloquear / desbloquear cartão |

---

## Persistência de Dados

Os dados são salvos automaticamente ao escolher a opção **9 — Salvar e sair**, e carregados automaticamente ao iniciar o programa.

- `data/clientes.csv` — armazena todos os clientes
- `data/gerentes.csv` — armazena todos os gerentes e seus vínculos

---

## Conceitos de POO Aplicados

- **Classes e objetos**: `Pessoa`, `Cliente`, `Gerente`, `Transacao`, `CartaoCredito`
- **Encapsulamento**: atributos privados com getters/setters
- **Herança**: `Cliente` e `Gerente` herdam de `Pessoa`
- **Polimorfismo**: método virtual `exibirDados()` sobrescrito em cada subclasse
- **STL**: `std::vector` para listas, `std::string`, `std::ifstream`/`std::ofstream` para arquivos
