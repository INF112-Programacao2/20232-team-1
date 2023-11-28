#include "../include/cliente.hpp"
#include "../include/clienteouro.hpp"
#include "../include/clienteprata.hpp"
#include "../include/gerenciador.hpp"
#include "../include/produto.hpp"
#include <iostream>


int main(){

    Produto* produto = Produto::cadastrarProduto();
    Gerenciador gerenciador;
    gerenciador.inserirProduto(produto);
    gerenciador.getProdutoById(0)->cadastrarPromocao();
    Data dataHoje(26, 11, 2023);
    std::cout << gerenciador.getProdutoById(0)->getPreco(dataHoje) << std::endl;
    

    return 0;
}