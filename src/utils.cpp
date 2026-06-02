#include "utils.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

// ── split ────────────────────────────────────────────────────
// Divide uma string pelo delimitador e retorna um vetor de partes
std::vector<std::string> split(const std::string& linha, char delimitador) {
    std::vector<std::string> partes;
    std::stringstream ss(linha);
    std::string parte;

    while (std::getline(ss, parte, delimitador)) {
        partes.push_back(parte);
    }
    return partes;
}

// ── trim ─────────────────────────────────────────────────────
// Remove espaços em branco do início e do fim de uma string
std::string trim(const std::string& s) {
    size_t inicio = s.find_first_not_of(" \t\r\n");
    size_t fim    = s.find_last_not_of(" \t\r\n");
    if (inicio == std::string::npos) return "";
    return s.substr(inicio, fim - inicio + 1);
}

// ── toDouble ─────────────────────────────────────────────────
// Converte string para double; retorna 0.0 se falhar
double toDouble(const std::string& s) {
    try {
        return std::stod(s);
    } catch (...) {
        return 0.0;
    }
}

// ── toInt ────────────────────────────────────────────────────
// Converte string para int; retorna 0 se falhar
int toInt(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return 0;
    }
}

// ── limparTela ───────────────────────────────────────────────
// Limpa o terminal (compatível com Linux/Mac e Windows)
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ── pausar ───────────────────────────────────────────────────
// Aguarda o usuário pressionar Enter para continuar
void pausar() {
    std::cout << "\n  Pressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}
