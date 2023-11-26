#include <iostream>
#include <vector>

class Cliente{
    private:
        static int _nextId;
        int _id;
        std::string _nome;
        float _totalComprado;
        static std::vector<Cliente*> clientes;
    public:

        
        Cliente(std::string nome);

        static Cliente* getClienteById(int id);
        static void insertCliente(Cliente* cliente);

        static int nextId();

        void realizarCompra(float valor);
        void atualizarNivelCliente();

        int getID();

        std::string getNome();

        float getTotalComprado();

        virtual float calculaDesconto();
};