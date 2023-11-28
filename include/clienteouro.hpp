#ifndef CLINETE_OURO_HPP
#define CLIENTE_OURO_HPP

#include "cliente.hpp"
#include "clienteprata.hpp"

class ClienteOuro : public Cliente{
    public:
        ClienteOuro(Cliente* cliente);
        ClienteOuro(ClientePrata* cliente);
        virtual float calculaDesconto(float valor) override;
        virtual std::string getNome() override;
};

#endif