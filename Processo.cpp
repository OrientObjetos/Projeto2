#pragma once
#include <iostream>
#include <iomanip>
#include "Operador.cpp"
#include "Equipamento.cpp"
using namespace std;

class Processo{
    protected:
        string nome;
        double tempoOperador = 0;
        double tempoEquipamento = 0;
        double custoOperador = 0;
        double custoEquipamento = 0;
        double custo = 0;

    public:
        Processo(string nome, double tempoOperador, double tempoEquipamento, double custoOperador, double custoEquipamento):
            nome{nome}, tempoOperador{tempoOperador}, tempoEquipamento{tempoEquipamento}, custoOperador{custoOperador}, custoEquipamento{custoEquipamento} {}

        double calculaCusto(double tOp, double cOp, double tEq, double cEq){
            custo = tOp*cOp + tEq*cEq;
            setCusto(custo);
            return custo;
        }        

        void setNome(string nome){
            this -> nome = nome;
        }

        void setCusto(double custo){
            this -> custo = custo;
        }

        string getNome(){
            return nome;
        }

        double getCusto(){
            return custo;
        }

        double getTO(){
            return tempoOperador;
        }

        double getCO(){
            return custoOperador;
        }

        double getTE(){
            return tempoEquipamento;
        }

        double getCE(){
            return custoEquipamento;
        }
        
        void print(){
            cout << "Dados do processo" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Custo: R$" << fixed << setprecision(2) << this -> calculaCusto(tempoOperador, custoOperador, tempoEquipamento, custoEquipamento) << endl;
            cout << "Teste de custo: R$" << fixed << setprecision(2) << this -> custo << endl;
            cout << endl;
        }
};