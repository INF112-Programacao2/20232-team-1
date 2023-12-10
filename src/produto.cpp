#include "../include/produto.hpp"

int Produto::_nextId = 0;

Produto::Produto(std::string nome, float preco, float estoque) : 
        _id(_nextId), _nome(nome), _preco(preco), _estoque(estoque), _percentualDesconto(0.1) {};


int Produto::nextId(){
    return _nextId++;
}


void Produto::diminuirEstoque(float qnt){
    if(qnt > _estoque){
        throw EstoqueInsuficienteException();
    } else {
        _estoque -= qnt;
    }
    
}

Produto* Produto::getProdutoById(int id, std::vector<Produto*> &produtos){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i]->getID() == id)
            return produtos[i];
    }
    return nullptr;
}


void Produto::relatorioProdutos(std::vector<Produto*> &produtos, Data data){
    int i = 0;
    while( i < 36){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::setw(6) << "Id" << std::setw(15) << "Nome" << std::setw(15) << "Preço" << std::endl;
    for(Produto* produto : produtos){
        std::cout << std::setw(6) << produto->getID() << std::setw(15) << produto->getNome() << std::setw(15) << produto->getPreco(data) << std::endl;
    }
    i = 0;
    while( i < 36){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
}

std::string Produto::getNome(){
    return _nome;
}

Produto* Produto::cadastrarProduto(){
    int id;
    std::string nome;
    float preco;
    float estoque;
    std::cout << "Nome do produto: ";
    std::cin >> nome;
    std::cout << "Preço: ";
    std::cin >> preco;
    std::cout << "Estoque: ";
    std::cin >> estoque;
    return new Produto(nome, preco, estoque);
}

void Produto::cadastrarPromocao(){
    Periodo novoPeriodo = _periodoPromocao.cadastroPeriodo();
    setPeriodoPromocao(novoPeriodo);
    float desconto;
    std::cout << "Desconto (%): ";
    std::cin >> desconto;
    setDesconto(desconto / 100);
}



void Produto::setPeriodoPromocao(Periodo periodoPromocao){
    _periodoPromocao = periodoPromocao;
}

std::string Produto::getPeriodoPromocao(){
    return this->_periodoPromocao.getPeriodo();
}

void Produto::setDesconto(float valor){
    _percentualDesconto = valor;
}

float Produto::getPreco(Data dataCompra){
    if(_periodoPromocao.contem(dataCompra)){
        return _preco * (1-_percentualDesconto);
    } else {
        return _preco;
    }
}

int Produto::getID(){
    return _id;
}




const char* EstoqueInsuficienteException::what() const noexcept{
    return "Estoque insuficiente";
}