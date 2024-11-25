#pragma once
#include <iostream>
#include <iomanip>
#include "Pessoa.cpp"
#include "Data.cpp"
#include "Endereco.cpp"
using namespace std;

class Cliente: public Pessoa{
    protected:
        long cpf;
        int idade;
        Data nascimento;
        Endereco endereco;

    public:
        Cliente(string nome, string sobrenome, long cpf, int idade, int dia, int mes, int ano, Endereco endereco):
            Pessoa(nome, sobrenome), cpf{cpf}, idade{idade}, nascimento{dia, mes, ano}, endereco{endereco} {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setSobrenome(string sobrenome){
            this -> sobrenome = sobrenome;
        }

        void setCPF(long cpf){
            this -> cpf = cpf;
        }

        void setIdade(int idade){
            this -> idade = idade;
        }

        string getNome(){
            return nome;
        }

        string getSobrenome(){
            return sobrenome;
        }

        long getCPF(){
            return cpf;
        }

        int getIdade(){
            return idade;
        }

        string getNascimento(){
            return this -> nascimento.getData();
        }

        string getEndereco(){
            return this -> endereco.getEndereco();
        }

        virtual void print(){ 
            cout << "Dados do cliente" << endl;
            cout << "Nome: " << this -> getNome() << " " << this -> getSobrenome() << endl;
            cout << "CPF: " << this -> getCPF() << endl;
            cout << "Data de nascimento: " << this -> getNascimento() << endl;
            cout << "Idade: " << this -> getIdade() << endl;
            cout << "Endereço: " << this -> getEndereco() << endl;
            cout << endl;
        }

        virtual void printLog(ostream &saida){ 
            //saida << "Dados do cliente" << endl;
            saida << "Nome: " << this -> getNome() << " " << this -> getSobrenome() << endl;
            saida << "CPF: " << this -> getCPF() << endl;
            saida << "Data de nascimento: " << this -> getNascimento() << endl;
            saida << "Idade: " << this -> getIdade() << endl;
            saida << "Endereço: " << this -> getEndereco() << endl << endl;
        }
};