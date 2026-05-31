# Nome do executável
EXEC = banco

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Diretórios
SRC = src
OBJ = obj

# Arquivos fonte
SRCS = $(wildcard $(SRC)/*.cpp)

# Arquivos objeto
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

# Regra principal
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Compilação dos arquivos .cpp
$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ) $(EXEC)

# Executar o programa
run: $(EXEC)
	./$(EXEC)