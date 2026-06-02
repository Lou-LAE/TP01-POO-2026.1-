# ============================================================
# Makefile — Sistema de Gerenciamento de Banco
# Como usar:
#   make        -> compila o projeto
#   make run    -> compila e executa
#   make clean  -> remove os arquivos compilados
# ============================================================

# Compilador e flags
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include

# Nome do executável gerado
TARGET = banco

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Lista todos os arquivos .cpp na pasta src automaticamente
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Gera a lista de .o correspondente em obj/
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# ── Regra padrão: compila tudo ────────────────────────────────
all: $(OBJDIR) $(TARGET)

# Cria a pasta obj/ se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Cria a pasta data/ se não existir (para os arquivos CSV)
data:
	mkdir -p data

# Linka todos os .o e gera o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Compilacao concluida! Execute com: ./$(TARGET)"

# Compila cada .cpp em seu .o correspondente
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ── Compila e executa ─────────────────────────────────────────
run: all data
	./$(TARGET)

# ── Remove arquivos compilados ────────────────────────────────
clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "Arquivos removidos."

# Declara que 'all', 'run' e 'clean' não são arquivos reais
.PHONY: all run clean
