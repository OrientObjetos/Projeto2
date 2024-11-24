#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "Cliente.cpp"
#include "Data.cpp"
#include "Produto.cpp"
using namespace std;

class Pedido{
    protected:
        int numero;
        Cliente *cliente;
        Data data;
        vector <Produto> &produtos;
        float totalPedido = 0;

    public:
        Pedido(Cliente *cliente, Data data, vector <Produto> &prod):
            cliente{cliente}, data{data}, produtos(prod) {}

        float calculaPreco(vector <Produto> produtos){
            for (int i = 0; i < produtos.size(); i++){
                totalPedido = totalPedido + produtos[i].getPreco();
            }
            setPedido(totalPedido);
            return totalPedido;
        }

        void setNumero(int numero){
            this -> numero = numero;
        }

        void setData(Data data){
            this -> data = data;
        }

        void setPedido(double totalPedido){
            this -> totalPedido = totalPedido;
        }

        int getNumero(){
            return numero;
        }

        Data getData(){
            return data;
        }

        double getPedido(){
            return totalPedido;
        }

        // fazer ele receber uma string, se a string for null imprime no terminal, se tiver algum conteúdo, imprime no arquivo
        void print(){
            cout << "Informações do pedido:" << endl;
            //cout << "\tPedido n.° " << setw(3) << setfill('0') << this -> numero << endl;
            cout << "Cliente: " << cliente -> getNome() << " " << cliente -> getSobrenome() << endl;
            cout << "Endereço de entrega: " << cliente -> getEndereco() << endl;
            cout << "Data do pedido: " << this -> data.getData() << endl;
            cout << "Dados do Pedido: " << endl;
            for (int i = 0; i < produtos.size(); i++){
                produtos[i].print();
                //cout << endl;
            }
            cout << "Total do pedido: R$" << fixed << setprecision(2) << round(this -> calculaPreco(produtos)) << endl;
            //cout << "Teste de custo: R$" << fixed << setprecision(2) << this -> getPedido() << endl;
            cout << endl;
        }
};