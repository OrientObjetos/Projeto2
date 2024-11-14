#pragma once
#include <iostream>
#include <iomanip>
#include "Ingrediente.cpp"
#include "Processo.cpp"
using namespace std;

class Produto{
    protected:
        string nome;
        Ingrediente* ingredientes;
        int tamanhoIngredientes;
        Processo* processos;
        int tamanhoProcessos;
        float custo;

    public:
        Produto(string nome, Ingrediente *ingr, int tam_ingr, Processo *proc, int tam_proc):
            nome{nome} {
                *ingredientes = *ingr;
                *processos = *proc;
                tamanhoIngredientes = tam_ingr;
                tamanhoProcessos = tam_proc;
                Ingrediente* ingredientes[tamanhoIngredientes];
                Processo* processos[tamanhoProcessos];
            }

        float calculaCusto(Ingrediente *ingredientes, int tamanhoIngredientes, Processo *processos, int tamanhoProcessos){
            float precoIngrediente = 0;
            float precoProcesso = 0;
            for (int i = 0; i < tamanhoIngredientes; i++){
                precoIngrediente = precoIngrediente + (ingredientes[i].getPreco()) * (ingredientes[i].getQuantidade());
            }
            for (int i = 0; i < tamanhoProcessos; i++){
                precoProcesso = precoProcesso + processos[i].getCusto();
            }
            custo = precoIngrediente + precoProcesso;
            setCusto(custo);
            return custo;
        }

        void setNome(string nome){
            this -> nome = nome;
        }

        void setCusto(int custo){
            this -> custo = custo;
        }

        string getNome(){
            return nome;
        }

        float getCusto(){
            return custo;
        }
        
        void print(){
            cout << "Dados do produto" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Ingredientes utilizados: ";
            for (int i = 0; i < tamanhoIngredientes; i++){
                cout << "  - " << ingredientes[i].getNome() << endl;
            }
            cout << "Processos realizados: " << endl;
            for (int i = 0; i < tamanhoProcessos; i++){
                cout << "  - " << processos[i].getNome() << endl;
            }
            cout << "Custo: R$" << fixed << setprecision(2) << this -> calculaCusto(ingredientes, tamanhoIngredientes, processos, tamanhoProcessos) << endl;
            cout << "Teste de custo: R$" << fixed << setprecision(2) << this -> custo << endl;
            cout << endl;
        }
};