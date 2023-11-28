#ifndef CLIENTE_PRATA_HPP
#define CLIENTE_PRATA_HPP

#include "cliente.hpp"

class ClientePrata : public Cliente{
    public:
        ClientePrata(Cliente* cliente);
        virtual float calculaDesconto(float valor) override;
        virtual std::string getNome() override;
};

#endif