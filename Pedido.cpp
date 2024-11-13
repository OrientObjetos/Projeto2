#pragma once
#include <iostream>
#include <iomanip>
#include "Pessoa.cpp"
#include "Data.cpp"
#include "Produto.cpp"
using namespace std;

class Pedido{
    protected:
        int numero;
        Pessoa cliente;
        Data data;
        Produto* produtos;
        int tamanhoProdutos;
        float totalPedido;

    public:
        Pedido(int numero, Pessoa cliente, Data data, Produto *prod, int tam_prod):
            numero{numero}, cliente{cliente}, data{data} {
                tamanhoProdutos = tam_prod;
                *produtos = *prod;
                Produto* produtos[tamanhoProdutos];
            }

        float calculaPreco(Produto *produtos, int tamanhoProdutos){
            for (int i = 0; i < tamanhoProdutos; i++){
                totalPedido = totalPedido + produtos[i].getCusto();
            }
            totalPedido = totalPedido * 1.5;
            setPedido(totalPedido);
            return totalPedido;
        }

        void setNumero(int numero){
            this -> numero = numero;
        }

        void setData(Data data){
            this -> data = data;
        }

        void setPedido(int totalPedido){
            this -> totalPedido = totalPedido;
        }

        int getNumero(){
            return numero;
        }

        Data getData(){
            return data;
        }

        int getPedido(){
            return totalPedido;
        }
        
        void print(){
            cout << "Pedido n°" << setw(3) << setfill('0') << this -> numero << endl;
            cout << "Cliente: " << this -> cliente.getNome() << endl;
            cout << "Data: " << this -> data.getData() << endl;
            cout << "Dados do Pedido: ";
            for (int i = 0; i < tamanhoProdutos; i++){
                produtos[i].print();
                cout << endl;
            }
            cout << fixed << setprecision(2);
            cout << "Total do pedido: R$" << this -> calculaPreco(produtos, tamanhoProdutos) << endl;
            cout << "Teste de custo: R$" << this -> getPedido() << endl;
            cout << endl;
        }
};

//-------------------------------------------------------------------------------------------------------------
/*    
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
*/