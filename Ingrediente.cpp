#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Ingrediente{
    protected:
        string nome;
        double preco;
        int quantidade = 0;
        string unidade;

    public:
        Ingrediente(string nome, double preco):
            nome{nome}, preco{preco} {}

        Ingrediente(string nome, double preco, int quantidade, string unidade):
            nome{nome}, preco{preco}, quantidade{quantidade}, unidade{unidade} {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setPreco(double preco){
            this -> preco = preco;
        }

        void setQuantidade(int quantidade){
            this -> quantidade = quantidade;
        }
        
        void setUnidade(string unidade){
            this -> unidade = unidade;
        }

        string getNome(){
            return nome;
        }

        double getPreco(){
            return preco;
        }
       
        int getQuantidade(){
            return quantidade;
        }

        string getUnidade(){
            return unidade;
        }      

        void print(){
            cout << "Dados do ingrediente" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Preço: R$" << fixed << setprecision(5) << this -> preco << endl;
            cout << "Quantidade: " << this -> quantidade << " " << this -> unidade << endl;
            cout << endl;
        }
};