#pragma once
#include <iostream>
using namespace std;

class Data{
    private:
        int dia, mes, ano;

    public:
        Data(int dia, int mes, int ano):
            dia{dia}, mes{mes}, ano{ano}{};

        void setDia(int dia){
            this -> dia = dia;
        }

        void setMes(int mes){
            this -> mes = mes;
        }

        void setAno(int ano){
            this -> ano = ano;
        }

        int getDia(){
            return dia;
        }

        int getMes(){
            return mes;
        }

        int getAno(){
            return ano;
        }
};