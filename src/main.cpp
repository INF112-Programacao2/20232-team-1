#include "../include/cliente.hpp"
#include "../include/clienteouro.hpp"
#include "../include/clienteprata.hpp"
#include "../include/gerenciador.hpp"
#include "../include/produto.hpp"
#include <iostream>


int main(){

    Gerenciador* gerenciador = new Gerenciador();

    gerenciador->criarMenu();
    

    return 0;
}