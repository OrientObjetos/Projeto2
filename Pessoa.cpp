#pragma once
#include <iostream>
#include "Data.cpp"
#include "Endereco.cpp"
using namespace std;

class Pessoa{
    protected:
        string nome;
        string sobrenome;

    public:
        Pessoa(string nome, string sobrenome):
            nome{nome}, sobrenome{sobrenome} {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setSobrenome(string sobrenome){
            this -> sobrenome = sobrenome;
        }

        string getNome(){
            return nome;
        }

        string getSobrenome(){
            return sobrenome;
        }

        virtual void print(){ 
            cout << "Dados da pessoa" << endl;
            cout << "Nome: " << this -> getNome() << " " << this -> getSobrenome() << endl;
            cout << endl;
        }
};