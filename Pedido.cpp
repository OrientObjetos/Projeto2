#pragma once
#include <iostream>
#include "Pessoa.cpp"
#include "Data.cpp"
#include "Produto.cpp"
using namespace std;

class Pedido{
    private:
    int num;
    Pessoa cliente;
    Data data;
    vector<Produto> produtos;
    float totalPedido;

    
    //Construtores da classe Pedido
    public Pedido() {
    }

    public Pedido(int num, Pessoa cliente, Data data, Produto produtos[], float totalPedido) {
        this->num = num;
        this->cliente = cliente;
        this->data = data;
        this->produto = produto;
        this->totalPedido = totalPedido;
    }

    public Pedido(int num, Pessoa cliente, Data data, float totalPedido) {
        this->num = num;
        this->cliente = cliente;
        this->data = data;
        this->produto = new ArrayList<>();
        this->totalPedido = totalPedido;
    }

    //Sets e gets que o projeto pede
    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this->num = num;
    }

    public Pessoa getCliente() {
        return cliente;
    }

    public void setCliente(Pessoa cliente) {
        this->cliente = cliente;
    }

    public Data getData() {
        return data;
    }

    public void setData(Data data) {
        this->data = data;
    }

    public ArrayList<Produto> getProdutos() {
        return produto;
    }

    public void setProdutos(ArrayList<Produto> produto) {
        this->produto = produto;
    }

    public float getTotalPedido() {
        return totalPedido;
    }

    public void setTotalPedido(float totalPedido) {
        this->totalPedido = totalPedido;
    }

    //Funcao que calcula o custo do Pedido
    private float calculaPedido() {
        float preco = 0;
        for (Produto produto : produto) {
            preco = preco + produto->getCusto();
        }
        return totalPedido = preco;
    }

    virtual void print(){ 
    cout << "Numero do pedido: " << this->num << endl;
    cout << "\nNome do cliente: " << cliente->getNome() << endl;
    cout << "\nData do pedido: " << data->getDia() << "/" << data->getMes() << "/" << data->getAno() << endl;
    cout << "\nValor do pedido: R$" << this->totalPedido << endl;
    cout << endl;
    }
};

