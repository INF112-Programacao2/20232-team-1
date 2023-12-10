#include "../include/cliente.hpp"
#include "../include/clienteouro.hpp"
#include "../include/clienteprata.hpp"
#include "../include/gerenciador.hpp"
#include "../include/produto.hpp"
#include "../include/venda.hpp"
#include "../include/vendedor.hpp"

#include <iostream>


int main(){

    Gerenciador* gerenciador = new Gerenciador();

    gerenciador->carregarRegistros();
    gerenciador->criarMenu();
    

    return 0;
}