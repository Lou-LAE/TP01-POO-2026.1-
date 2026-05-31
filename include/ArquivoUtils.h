#ifndef ARQUIVO_UTILS_H_
#define ARQUIVO_UTILS_H_

#include <vector>
#include "Cliente.h"
#include "Gerente.h"

void carregarClientes(std::vector<Cliente*>& clientes);
void salvarClientes(std::vector<Cliente*>& clientes);

void carregarGerentes(std::vector<Gerente*>& gerentes);
void salvarGerentes(std::vector<Gerente*>& gerentes);

#endif