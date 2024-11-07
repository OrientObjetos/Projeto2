#pragma once
#include <iostream>
using namespace std;

class Processo{
    private:
        string nome;
        float custo;
        float tempoOperador;
        float tempoEquipamento;
        float custoOperador;
        float custoEquipamento;

    public:
        Processo(string nome, float tempoOperador, float tempoEquipamento, float custoOperador, float custoEquipamento):
            nome{nome}, tempoOperador{tempoOperador}, tempoEquipamento{tempoEquipamento}, custoOperador{custoOperador}, custoEquipamento{custoEquipamento}{}

        float calculaCusto(float tOp, float cOp, float tEq, float cEq){
            return tOp*cOp + tEq*cEq;
        }
        
        void print(){
            cout << "Dados do processo" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Custo: " << this -> calculaCusto(tempoOperador, custoOperador, tempoEquipamento, custoEquipamento) << endl;
            cout << endl;
        }
}