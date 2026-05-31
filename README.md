# TP01-POO-2026.1-
Este projeto tem como objetivo desenvolver um sistema de gerenciamento bancário em C++, com interface via linha de comando, capaz de administrar informações de clientes e gerentes, bem como realizar e registrar transações financeiras.

O sistema permite o cadastro de usuários, criação de transações (depósitos, saques e transferências), associação entre gerentes e clientes, além da visualização de dados como saldo e extrato. Também contempla o uso de contas poupança com cálculo de rendimento.

A aplicação foi desenvolvida com base nos conceitos de Programação Orientada a Objetos, incluindo encapsulamento, herança, polimorfismo e associação entre classes, além da utilização da biblioteca STL e persistência de dados em arquivos no formato CSV.


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
