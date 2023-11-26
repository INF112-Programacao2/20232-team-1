#ifndef CLINETE_PRATA_HPP
#define CLIENTE_PRATA_HPP

#include "cliente.hpp"

class ClientePrata : public Cliente{
    public:
        ClientePrata(std::string nome);
        virtual float calculaDesconto() override;
};

#endif