#pragma once
#include <iostream>
using namespace std;

class Endereco{
    private:
        string estado, cidade, bairro, rua;
        int numero;

    public:
        Endereco(string estado, string cidade, string bairro, string rua, int numero):
            estado{estado}, cidade{cidade}, bairro{bairro}, rua{rua}, numero{numero} {};

        void setEstado(string estado){
            this -> estado = estado;
        }

        void setCidade(string cidade){
            this -> cidade = cidade;
        }

        void setBairro(string bairro){
            this -> bairro = bairro;
        }

        void setRua(string rua){
            this -> rua = rua;
        }

        void setNumero(int numero){
            this -> numero = numero;
        }

        string getEndereco(){
            return rua + ", " + to_string(numero) + "\t" + bairro;
        }
};