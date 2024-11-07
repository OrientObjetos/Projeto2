#pragma once
#include <iostream>
using namespace std;

class Equipamento{
    private:
        string nome;
        float depreciacaoHora;

    public:
        Equipamento(string nome, float depreciacaoHora):
            nome{nome}, depreciacaoHora{depreciacaoHora}{}

        void print(){
            cout << "Dados do equipamento" << endl;
            cout << "Nome: " << this -> nome << endl;
            cout << "Depreciacao/hora: " << this -> depreciacaoHora << endl;
            cout << endl;
        }
}