#pragma once
#include <iostream>
#include <iomanip>
#include "Pessoa.cpp"
using namespace std;

class Operador: public Pessoa{
    protected:
        string cargo;
        float salarioHora;

    public:
        /*Operador(string nome, string sobrenome, string cargo, float salarioHora):
            Pessoa(nome, sobrenome), cargo{cargo}, salarioHora{salarioHora} {}*/

        Operador(string nome, string sobrenome, long cpf, int idade, int dia, int mes, int ano, Endereco endereco, string cargo, float salarioHora):
            Pessoa(nome, sobrenome, cpf, idade, dia, mes, ano, endereco), cargo{cargo}, salarioHora{salarioHora} {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setSobrenome(string sobrenome){
            this -> sobrenome = sobrenome;
        }

        void setCargo(string cargo){
            this -> cargo = cargo;
        }

        void setSalarioH(int salarioHora){
            this -> salarioHora = salarioHora;
        }

        string getNome(){
            return nome;
        }

        string getSobrenome(){
            return sobrenome;
        }

        string getCargo(){
            return cargo;
        }

        int getSalarioH(){
            return salarioHora;
        }

        virtual void print(){ 
            cout << fixed << setprecision(2);
            cout << "Dados do funcionário" << endl;
            cout << "Nome: " << this -> getNome() << " " << this -> getSobrenome() << endl;
            cout << "Cargo: " << this -> cargo << endl;
            cout << "Salário-hora: " << this -> salarioHora << endl;
            cout << endl;
        }
};