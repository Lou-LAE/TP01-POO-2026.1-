# 🏦 Sistema de Gerenciamento de Banco

## Descrição

Este projeto consiste no desenvolvimento de um sistema de gerenciamento bancário em C++, com interface via linha de comando. O sistema permite administrar clientes, gerentes e transações financeiras, com persistência de dados em arquivos CSV.

O objetivo é aplicar conceitos de Programação Orientada a Objetos (POO), como encapsulamento, herança, polimorfismo, associação entre classes e utilização da biblioteca STL.

---

## Funcionalidades

- Cadastro de clientes  
- Cadastro de gerentes  
- Criação de transações:
  - Depósito  
  - Saque  
  - Transferência  
- Associação entre gerente e cliente  
- Exibição de extrato de clientes  
- Listagem de clientes e gerentes  
- Persistência de dados em arquivos CSV  

---

## Estrutura do Projeto

TP1-POO(26.1)/
│
├── include/ # Arquivos de cabeçalho (.h)
├── src/ # Arquivos de implementação (.cpp)
├── data/ # Arquivos CSV
│ ├── clientes.csv
│ ├── gerentes.csv
│
├── obj/ # Arquivos objeto (gerados automaticamente)
├── Makefile
└── README.md

## Compilação

No terminal, dentro da pasta do projeto:

make

##  Execução
make run

ou:

./banco