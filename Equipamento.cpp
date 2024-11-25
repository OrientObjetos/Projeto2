#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Equipamento{
    protected:
        string nome;
        float depreciacaoHora;

    public:
        Equipamento(string nome, float depreciacaoHora):
            nome{nome}, depreciacaoHora{depreciacaoHora} {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setDepreciacaoH(int depreciacaoHora){
            this -> depreciacaoHora = depreciacaoHora;
        }

        string getNome(){
            return nome;
        }

        float getDepreciacaoH(){
            return depreciacaoHora;
        }

        void print(){
            cout << "Dados do equipamento" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Depreciacao/hora: R$" << fixed << setprecision(2) << this -> depreciacaoHora << endl;
            cout << endl;
        }

        void printLog(ostream &saida){
            //saida << "Dados do equipamento" << endl;
            saida << "Nome: " << this -> nome << endl;
            saida << "Depreciacao/hora: R$" << fixed << setprecision(2) << this -> depreciacaoHora << endl;
            saida << endl;
        }
};