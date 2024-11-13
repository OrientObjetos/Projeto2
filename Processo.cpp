#pragma once
#include <iostream>
#include <iomanip>
#include "Operador.cpp"
#include "Equipamento.cpp"
using namespace std;

class Processo{
    protected:
        string nome;
        float custo;
        float tempoOperador;
        float tempoEquipamento;
        float custoOperador;
        float custoEquipamento;

    public:
        Processo(string nome, float tempoOperador, float tempoEquipamento, float custoOperador, float custoEquipamento):
            nome{nome}, tempoOperador{tempoOperador}, tempoEquipamento{tempoEquipamento}, custoOperador{custoOperador}, custoEquipamento{custoEquipamento} {}

        float calculaCusto(float tOp, float cOp, float tEq, float cEq){
            custo = tOp*cOp + tEq*cEq;
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
            cout << fixed << setprecision(2);
            cout << "Dados do processo" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Custo: R$" << this -> calculaCusto(tempoOperador, custoOperador, tempoEquipamento, custoEquipamento) << endl;
            cout << "Teste de custo: R$" << this -> custo << endl;
            cout << endl;
        }
};