#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "Ingrediente.cpp"
#include "Processo.cpp"
using namespace std;

class Produto{
    protected:
        string nome;
        vector <Ingrediente> &ingredientes;
        vector <Processo> &processos;
        Ingrediente sabor;
        //static const int tamanhoIngredientes = 3;
        //static const int tamanhoProcessos = 1;
        //Ingrediente* ingredientes[tamanhoIngredientes];
        //Processo* processos[tamanhoProcessos];
        double custoProduto = 0;
        double precoProduto = 0;

    public:
        Produto(string nome, vector <Ingrediente> &ingr, vector <Processo> &proc, Ingrediente sabor):
            nome{nome}, ingredientes{ingr}, processos{proc}, sabor{sabor} {}

        double calculaCusto(vector <Ingrediente> ingredientes, vector <Processo> processos, Ingrediente sabor){
            ingredientes.push_back(sabor);
            double custoIngrediente = 0;
            double custoProcesso = 0;
            double preco = 0;
            //cout << endl;
            for (int i = 0; i < ingredientes.size(); i++){
                custoIngrediente = custoIngrediente + (ingredientes[i].getPreco()) * (ingredientes[i].getQuantidade());
                //cout << "Preço ingrediente: " << precoIngrediente << endl;
            }
            for (int i = 0; i < processos.size(); i++){
                custoProcesso = custoProcesso + processos[i].calculaCusto(processos[i].getTO(), processos[i].getCO(), processos[i].getTE(), processos[i].getCE());
                //cout << "Preço processo: " << precoProcesso << endl;
            }
            custoProduto = custoIngrediente + custoProcesso;
            //cout << "Ingrediente total: " << precoIngrediente << endl;
            //cout << "Processo total: " << precoProcesso << endl;
            //cout << "Custo total: " << custoProduto << endl;
            setCusto(custoProduto);
            preco = calculaPreco(custoProduto);
            return preco;
        }

        double calculaPreco(double custoProduto){
            precoProduto = 1.5*custoProduto;
            setPreco(precoProduto);
            return precoProduto;
        }

        void setNome(string nome){
            this -> nome = nome;
        }

        void setCusto(double custoProduto){
            this -> custoProduto = custoProduto;
        }

        void setPreco(double precoProduto){
            this -> precoProduto = precoProduto;
        }

        void setSabor(Ingrediente sabor){
            this -> sabor = sabor;
        }

        string getNome(){
            return nome;
        }

        double getCusto(){
            return custoProduto;
        }

        double getPreco(){
            return precoProduto;
        }
        
        void print(){
            //cout << "Dados do produto:" << endl;
            cout << "  Nome: " << this -> nome << endl;
            cout << "  Preço: R$" << fixed << setprecision(2) << round(this -> calculaCusto(ingredientes, processos, sabor)) << endl;
            cout << "  Ingredientes utilizados: " << endl;
            for (int i = 0; i < ingredientes.size(); i++){
                cout << "    - " << ingredientes[i].getNome() << endl;
            }
            cout << "  Processos realizados: " << endl;
            for (int i = 0; i < processos.size(); i++){
                cout << "    - " << processos[i].getNome() << endl;
            }
            //cout << "  Teste de custo: R$" << fixed << setprecision(2) << this -> custoProduto << endl;
            cout << endl;
        }
};