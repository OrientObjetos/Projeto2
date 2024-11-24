#pragma once
#include <iostream>
using namespace std;

class Endereco{
    protected:
        string estado, cidade, bairro, endereco;
        int numero;

    public:
        Endereco(string estado, string cidade, string bairro, string endereco, int numero):
            estado{estado}, cidade{cidade}, bairro{bairro}, endereco{endereco}, numero{numero} {};

        void setEstado(string estado){
            this -> estado = estado;
        }

        void setCidade(string cidade){
            this -> cidade = cidade;
        }

        void setBairro(string bairro){
            this -> bairro = bairro;
        }

        void setEndereco(string endereco){
            this -> endereco = endereco;
        }

        void setNumero(int numero){
            this -> numero = numero;
        }

        string getEndereco(){
            return endereco + ", " + to_string(numero) + " - " + bairro + ", " + cidade + " - " + estado;
        }
};