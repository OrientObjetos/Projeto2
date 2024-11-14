#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Ingrediente{
    protected:
        string nome;
        float preco;
        int quantidade = 0;

    public:
        Ingrediente(string nome, float preco):
            nome{nome}, preco{preco} {}

        Ingrediente(string nome, float preco, int quantidade):
            nome{nome}, preco{preco}, quantidade{quantidade} {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setPreco(float preco){
            this -> preco = preco;
        }

        void setQuantidade(int quantidade){
            this -> quantidade = quantidade;
        }

        string getNome(){
            return nome;
        }

        float getPreco(){
            return preco;
        }
       
        int getQuantidade(){
            return quantidade;
        }        

        void print(){
            cout << "Dados do ingrediente" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Preço: R$" << fixed << setprecision(2) << this -> preco << endl;
            cout << "Quantidade: " << this -> quantidade << endl;
            cout << endl;
        }
};