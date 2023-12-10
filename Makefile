# Variáveis para o compilador e as opções de compilação
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Variável para o nome do executável final
TARGET = gerenciador

# Diretório de saída para os arquivos objeto
BUILD_DIR = build

# Lista de arquivos fonte do seu projeto
SRCS = src/periodo.cpp src/produto.cpp src/data.cpp src/venda.cpp src/cliente.cpp src/clienteouro.cpp src/clienteprata.cpp src/vendedor.cpp src/gerenciador.cpp src/main.cpp

# Lista de objetos gerados a partir dos arquivos fonte
OBJS = $(addprefix $(BUILD_DIR)/,$(notdir $(SRCS:.cpp=.o)))

# Regra para compilar cada arquivo objeto
$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para compilar o executável final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para criar o diretório de build
$(shell mkdir -p $(BUILD_DIR))

# Regra padrão para compilar o executável final
all: $(BUILD_DIR)/$(TARGET)

# Regra para limpar os arquivos objeto e o executável
clean:
	rm -rf $(BUILD_DIR) $(TARGET)