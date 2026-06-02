#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// ============================================================
// Funções utilitárias usadas em todo o projeto
// ============================================================

// Divide uma string pelo delimitador e retorna um vetor de partes
// Exemplo: split("a,b,c", ',') -> {"a", "b", "c"}
std::vector<std::string> split(const std::string& linha, char delimitador);

// Remove espaços em branco do início e fim de uma string
std::string trim(const std::string& s);

// Converte string para double com segurança (retorna 0.0 em erro)
double toDouble(const std::string& s);

// Converte string para int com segurança (retorna 0 em erro)
int toInt(const std::string& s);

// Limpa a tela do terminal (funciona em Linux/Mac e Windows)
void limparTela();

// Pausa a execução até o usuário pressionar Enter
void pausar();

#endif
