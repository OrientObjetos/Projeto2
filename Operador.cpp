#pragma once
#include "Pessoa.cpp"
using namespace std;

class Operador: public Pessoa{
    private:
        string cargo;
        float salarioHora;

    public:
        Operador(string nome, string sobrenome, string cargo, float salarioHora):
            Pessoa(nome, sobrenome), cargo{cargo}, salarioHora{salarioHora}{}        

        virtual void print(){ 
            cout << "Dados do funcionário" << endl;
            cout << "Nome: " << this -> getNome() << " " << this -> getSobrenome() << endl;
            cout << "Cargo: " << this -> cargo << endl;
            cout << "Salário-hora: " << this -> salarioHora << endl;
            cout << endl;
        }
}