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
                totalPedido = totalPedido + round(produtos[i].getPreco());
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
            cout << "Cliente: " << cliente -> getNome() << " " << cliente -> getSobrenome() << endl;
            cout << "Endereço de entrega: " << endl;
            cout << cliente -> getEndereco() << endl;
            cout << "Data do pedido: " << this -> data.getData() << endl;
            cout << "Dados do Pedido: " << endl;
            for (int i = 0; i < produtos.size(); i++){
                produtos[i].print();
            }
            cout << "Total do pedido: R$" << fixed << setprecision(2) << this -> calculaPreco(produtos) << endl;
            cout << endl;
        }

        void printLog(ostream &saida){
            //saida << "Informações do pedido:" << endl;
            saida << "Pedido n.° " << setw(3) << setfill('0') << this -> numero << endl;
            saida << "Cliente: " << cliente -> getNome() << " " << cliente -> getSobrenome() << endl;
            saida << "Endereço de entrega: " << endl;
            saida << cliente -> getEndereco() << endl;
            saida << "Data do pedido: " << this -> data.getData() << endl;
            saida << "Dados do Pedido: " << endl;
            for (int i = 0; i < produtos.size(); i++){
                produtos[i].printLog(saida);
            }
            saida << "Total do pedido: R$" << fixed << setprecision(2) << this -> calculaPreco(produtos) << endl;
            saida << endl;
        }
};