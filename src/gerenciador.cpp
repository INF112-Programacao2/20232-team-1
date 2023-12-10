#include "../include/gerenciador.hpp"

Gerenciador::~Gerenciador(){
    for(Cliente* cliente : clientes){
        delete cliente;
    }
    for(Produto* produto : produtos){
        delete produto;
    }
    for(Venda* venda : vendas){
        delete venda;
    }
    for(Vendedor* vendedor : vendedores){
        delete vendedor;
    }

}

const char* IdInexistente::what() const noexcept {
    return "ID inexistente";
}



void Gerenciador::carregarRegistros() {
    // Ler registros de clientes do arquivo de texto "clientes.txt"
    std::ifstream clientesFile("clientes.txt");
    int idCliente;
    std::string nomeCliente;
    while (clientesFile >> idCliente >> nomeCliente) {
        inserirCliente(new Cliente(idCliente, nomeCliente));
    }
    clientesFile.close();

    // Ler registros de vendedores do arquivo de texto "vendedores.txt"
    std::ifstream vendedoresFile("vendedores.txt");
    int idVendedor;
    std::string nomeVendedor;
    while (vendedoresFile >> idVendedor >> nomeVendedor) {
        inserirVendedor(new Vendedor(idVendedor, nomeVendedor));
    }
    vendedoresFile.close();

    // Ler registros de produtos do arquivo de texto "produtos.txt"
    std::ifstream produtosFile("produtos.txt");
    int idProduto;
    std::string nomeProduto;
    float precoProduto;
    float estoqueProduto;
    int diaInicio;
    int mesInicio;
    int anoInicio;
    int diaFim;
    int mesFim;
    int anoFim;
    while (produtosFile >> idProduto >> nomeProduto >> precoProduto >> estoqueProduto >> diaInicio >> mesInicio >> anoInicio >> diaFim >> mesFim >> anoFim) {
        inserirProduto(new Produto(idProduto, nomeProduto, precoProduto, estoqueProduto, diaInicio, mesInicio, anoInicio, diaFim, mesFim, anoFim));
    }
    produtosFile.close();

    // Ler registros de vendas do arquivo de texto "vendas.txt"
    std::ifstream vendasFile("vendas.txt");
    int idVenda;
    float valorVenda;
    int dia, mes, ano;
    while (vendasFile >> idVenda >> idCliente >> idVendedor >> valorVenda >> dia >> mes >> ano) {
        Cliente* cliente = cliente->getClienteById(idCliente, clientes);
        Vendedor* vendedor = vendedor->getVendedorById(idVendedor, vendedores);
        if (cliente && vendedor) {
            realizarVenda(idVenda, cliente, vendedor, dia, mes, ano, valorVenda);
        }
    }
    vendasFile.close();
}


void Gerenciador::realizarVenda(int id, Cliente* cliente, Vendedor* vendedor, int dia, int mes, int ano, float valorVenda){
    Venda* venda = new Venda(id, cliente, vendedor, dia, mes, ano, valorVenda);
    vendedor->realizarVenda(venda->getValor());
    cliente->realizarCompra(venda->getValor(), clientes);
    inserirVenda(venda);
}

void Gerenciador::salvarRegistros(){
    // Gravar registros de clientes no arquivo de texto "clientes.txt"
    std::ofstream clientesFile("clientes.txt");
    for(Cliente* cliente : clientes){
        clientesFile << cliente->getID() << " " << cliente->getNome() << std::endl;
    }
    clientesFile.close();

    std::ofstream vendedoresFile("vendedores.txt");
    for(Vendedor* vendedor : vendedores){
        vendedoresFile << vendedor->getID() << " " << vendedor->getNome() << std::endl;
    }
    vendedoresFile.close();

    std::ofstream produtosFile("produtos.txt");
    for(Produto* produto : produtos){
        produtosFile << produto->getID() << " " << produto->getNome() << " " << produto->getPrecoSemDesconto() << " " << produto->getEstoque() << " " << produto->getPeriodoPromocao() << std::endl;
    }
    produtosFile.close();

    std::ofstream vendasFile("vendas.txt");
    for(Venda* venda : vendas){
        vendasFile << venda->getId() << " " << venda->getCliente()->getID() << " " << venda->getVendedor()->getID() << " " << venda->getValor() << " " << venda->getData() << std::endl;
    }
    vendasFile.close();

}

void Gerenciador::inserirVendedor(Vendedor* vendedor){
    if(vendedor == nullptr)
        throw std::invalid_argument("Vendedor inválido!");
    vendedores.push_back(vendedor);
}


void Gerenciador::inserirVenda(Venda* venda){
    if(venda == nullptr)
        throw std::invalid_argument("Venda inválida!");
    vendas.push_back(venda);
}


void Gerenciador::inserirCliente(Cliente* cliente){
    // Verifica se o cliente é inválido
    if(cliente == nullptr) {
        throw std::invalid_argument("Cliente inválido!");
    }

    // Adiciona o cliente à lista
    clientes.push_back(cliente);
}

void Gerenciador::inserirProduto(Produto* produto){
    // Verifica se o cliente é inválido
    if(produto == nullptr) {
        throw std::invalid_argument("Produto inválido!");
    }

    // Adiciona o cliente à lista
    produtos.push_back(produto);
}


void Gerenciador::criarMenu(){
    while(true){
        int menuSelect;
        std::cout << "1 - Menu Produtos" << std::endl;
        std::cout << "2 - Menu Clientes" << std::endl;
        std::cout << "3 - Menu Vendedores" << std::endl;
        std::cout << "4 - Menu Vendas" << std::endl;
        std::cout << "5 - Sair" << std::endl;

        std::cout << "Selecione uma opção: ";
        std::cin >> menuSelect;
        switch(menuSelect){
            case 1:
                menuProdutos();
                break;
            case 2:
                menuClientes();
                break;
            case 3:
                menuVendedores();
                break;
            case 4:
                menuVendas();
                break;
            case 5:
                fecharPrograma();
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }
    }
    
}

void Gerenciador::menuProdutos(){
    int menuSelect;
    std::cout << "1 - Cadastrar Produto" << std::endl;
    std::cout << "2 - Remover Produto" << std::endl;
    std::cout << "3 - Relatório de Produtos" << std::endl;
    std::cout << "4 - Voltar" << std::endl;

    std::cout << "Selecione uma opção: ";
    std::cin >> menuSelect;
    switch(menuSelect){
        case 1:
            menuProdutosCadastrar();
            break;
        case 2:
            menuProdutosRemover();
            break;
        case 3:
            menuProdutosRelatorios();
            break;
        case 4:
            criarMenu();
            break;
        default:
            menuProdutos();
    }
}


void Gerenciador::menuProdutosRelatorios(){
    Data dataHoje;
    Produto::relatorioProdutos(produtos, dataHoje.dataHoje());
}

void Gerenciador::menuProdutosCadastrar(){
    Produto* produto = Produto::cadastrarProduto();
    inserirProduto(produto);
}

void Gerenciador::menuProdutosRemover(){
    int id;
    std::cout << "ID do produto: ";
    std::cin >> id;
    removerProduto(id);
}

void Gerenciador::menuClientes(){
    int menuSelect;
    std::cout << "1 - Cadastrar Cliente" << std::endl;
    std::cout << "2 - Remover Cliente" << std::endl;
    std::cout << "3 - Relatório de Clientes" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
    
    std::cout << "Selecione uma opção: ";
    std::cin >> menuSelect;
    switch(menuSelect){
        case 1:
            menuClientesCadastrar();
            break;
        case 2:
            menuClientesRemover();
            break;
        case 3:
            menuClientesRelatorios();
            break;
        case 4:
            criarMenu();
            break;
        default:
            menuProdutos();
    }
    
}

void Gerenciador::menuClientesRelatorios(){
    Cliente::relatorioClientes(clientes);
}

void Gerenciador::menuClientesCadastrar(){
    Cliente* cliente = Cliente::cadastrarCliente();
    inserirCliente(cliente);
}

void Gerenciador::menuClientesRemover(){
    int id;
    std::cout << "ID do cliente: ";
    std::cin >> id;
    removerCliente(id);
}

void Gerenciador::menuVendedores(){
    int menuSelect;
    std::cout << "1 - Cadastrar Vendedor" << std::endl;
    std::cout << "2 - Remover Vendedor" << std::endl;
    std::cout << "3 - Relatório de Vendedores" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
    std::cout << "Selecione uma opção: ";
    std::cin >> menuSelect;
    switch(menuSelect){
        case 1:
            menuVendedoresCadastrar();
            break;
        case 2:
            menuVendedoresRemover();
            break;
        case 3:
            menuVendedoresRelatorios();
            break;
        case 4:
            criarMenu();
            break;
        default:
            menuVendedores();
    }
}

void Gerenciador::menuVendedoresRelatorios(){
    Vendedor::relatorioVendedores(vendedores);
}

void Gerenciador::menuVendedoresCadastrar(){
    Vendedor* vendedor = Vendedor::cadastrarVendedor();
    inserirVendedor(vendedor);
}

void Gerenciador::menuVendedoresRemover(){
    int id;
    std::cout << "ID do vendedor: ";
    std::cin >> id;
    removerVendedor(id);
}


void Gerenciador::menuVendas(){
    int menuSelect;
    std::cout << "1 - Cadastrar Venda" << std::endl;
    std::cout << "2 - Remover Venda" << std::endl;
    std::cout << "3 - Relatório de Vendas" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
    std::cout << "Selecione uma opção: ";
    std::cin >> menuSelect;
    switch(menuSelect){
        case 1:
            menuVendasCadastrar();
            break;
        case 2:
            menuVendasRemover();
            break;
        case 3:
            menuVendasRelatorios();
            break;
        case 4:
            criarMenu();
            break;
        default:
            menuVendas();
    }
}

void Gerenciador::menuVendasRelatorios(){
    Venda::relatorioVendas(vendas);
}

void Gerenciador::menuVendasCadastrar(){
    Venda* venda;
    venda = venda->cadastrarVenda(produtos, clientes, vendedores);
    inserirVenda(venda);
}

void Gerenciador::menuVendasRemover(){
    int id;
    std::cout << "ID da venda: ";
    std::cin >> id;
    removerVenda(id);
}








void Gerenciador::fecharPrograma(){
    salvarRegistros();
    std::cout << "Programa encerrado!" << std::endl;
    delete this;
    exit(0);
}




void Gerenciador::removerCliente(int id){
    int i = 0;
    for(Cliente* cliente : clientes){
        i++;
        if(cliente->getID() == id){
            delete cliente;
            clientes.erase(clientes.begin() + i);
            return;
        }
    }
    throw IdInexistente();
}

void Gerenciador::removerVendedor(int id){
    int i = 0;
    for(Vendedor* vendedor : vendedores){
        i++;
        if(vendedor->getID() == id){
            delete vendedor;
            vendedores.erase(vendedores.begin() + i);
            return;
        }
    }
    throw IdInexistente();
}

void Gerenciador::removerProduto(int id){
    int i = 0;
    for(Produto* produto : produtos){
        i++;
        if(produto->getID() == id){
            delete produto;
            produtos.erase(produtos.begin() + i);
            return;
        }
    }
    throw IdInexistente();
}

void Gerenciador::removerVenda(int id){
    int i = 0;
    for(Venda* venda : vendas){
        i++;
        if(venda->getId() == id){
            delete venda;
            vendas.erase(vendas.begin() + i);
            return;
        }
    }
    throw IdInexistente();
}
