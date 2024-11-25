/*
Nome: Gabrielle Magalhães Veras Braga
R.A: 11.121.557-0
Nome: Gustavo Rosell Collado
R.A: 11.121.526-5
8° ciclo do curso de Engenharia de Automação e Controle
Projeto 2 da disciplina CCP140 - Orientação a Objetos, 
do Departamento de Ciência da Computação, ministrada pelo
Professor Dr. Leonardo Anjoletto
Data de apresentação do projeto: 24/11/2024
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <climits>
#include <fstream>
#include <cstring>
#include <ctime>
#include <chrono>
#include <thread>
#include "Cliente.cpp"
#include "Data.cpp"
#include "Endereco.cpp"
#include "Equipamento.cpp"
#include "Ingrediente.cpp"
#include "Operador.cpp"
#include "Pedido.cpp"
#include "Pessoa.cpp"
#include "Processo.cpp"
#include "Produto.cpp"
using namespace std;

// ================================================================================================================
// Definição das variáveis globais

// Definição dos operadores
Operador Cozinheiro("Eric", "Jacquin", "cozinheiro", 18.66);        // salário-hora baseado no salário mensal de R$2.873.64

// Array que salvará os operadores e os clientes
Pessoa *pessoas[100] = {&Cozinheiro};


// Definição dos equipamentos
Equipamento Forno("Forno", 2.55);       // depreciação-hora baseada no preço R$3.924,00 e depreciação anual de 10%
vector <Equipamento> equip = {Forno};

// Definição dos processos
Processo Assar("Assar", 1.58, 0.67, Cozinheiro.getSalarioH(), Forno.getDepreciacaoH()); // 95 min de preparo total e 40 min para assar
vector <Processo> processos = {Assar};

// Definição dos ingredientes
Ingrediente Ovo("Ovo", 0.63, 3, "unidades");                // 3 ovos
Ingrediente Farinha("Farinha", 0.00549, 150, "gramas");     // 150g de farinha
Ingrediente Leite("Leite", 0.00539, 360, "mililitros");     // 3/2 xícara de chá de leite (360ml)
vector <Ingrediente> ingredientes = {Ovo, Farinha, Leite};

// Definição dos sabores
Ingrediente Abacaxi("Abacaxi", 1, 1, "unidades");
Ingrediente Banana("Banana", 1, 1, "unidades");
Ingrediente Chocolate("Chocolate em pó", 0.1, 200, "gramas");
Ingrediente Fuba("Fubá", 0.1, 360, "gramas");
Ingrediente Laranja("Laranja", 1, 1, "unidades");
Ingrediente Nada("Nada", 0, 0, "nada");
vector <Ingrediente> sabores = {Abacaxi, Banana, Chocolate, Fuba, Laranja, Nada};

// Define os produtos que o cliente pode pedir
Produto boloAbacaxi("Bolo de abacaxi", ingredientes, processos, sabores[0]);
Produto boloBanana("Bolo de banana", ingredientes, processos, sabores[1]);
Produto boloChocolate("Bolo de chocolate", ingredientes, processos, sabores[2]);
Produto boloFuba("Bolo de fubá", ingredientes, processos, sabores[3]);
Produto boloLaranja("Bolo de laranja", ingredientes, processos, sabores[4]);
Produto boloSimples("Bolo simples", ingredientes, processos, sabores[5]);
vector <Produto> bolos = {boloAbacaxi, boloBanana, boloChocolate, boloFuba, boloLaranja, boloSimples};

// Vetor para salvar os pedidos
vector <Pedido> pedidos;
// ================================================================================================================

// Função para gerar um arquivo de log da execução
void Log() {
    cout << endl << "Gerando log da execução..." << endl;

    string nome;
    string sobrenome;
    long cpf;
    int dia;
    int mes;
    int ano;
    int idade;
    string endereco;
    int numero;
    string bairro;
    string cidade;
    string estado;

    char nom[20];
    char sobrenom[40];
    char end[100];
    char bai[50];
    char cid[30];
    char est[3];
    char lixo[1];

    // Abre o arquivo de texto no modo somente leitura
    FILE *arquivo = fopen("Clientes.txt", "r");
    vector <Cliente> cli;

    // Caso o arquivo não possa ser aberto, exibe uma mensagem de erro
    if (arquivo == nullptr) {
        cout << endl << "Não foi possível acessar os dados dos clientes cadastrados!" << endl;
    }

    else {
        // O loop lê os dados contidos no arquivo de texto e tranfere para variáveis do tipo char. Caso a leitura de nome e sobrenome do cliente falhe (caso fscanf retornar um valor inválido), o loop é interrompido imediatamente, pois não há mais clientes no arquivo
        int i = 1;
        while (true) {
            if (fscanf(arquivo, "%s %[^\n]", nom, sobrenom) != 2) break;
            fscanf(arquivo, "%ld [^\n]", &cpf);
            fscanf(arquivo, "%d/%d/%d [^\n]", &dia, &mes, &ano);
            fscanf(arquivo, "%d [^\n]", &idade);
            fgets(end, sizeof(end), arquivo);
            fscanf(arquivo, "%d [^\n]", &numero);
            fgets(lixo, sizeof(lixo), arquivo);
            fgets(bai, sizeof(bai), arquivo);
            fgets(cid, sizeof(cid), arquivo);
            fgets(est, sizeof(est), arquivo);

            // Remove '\n' das strings lidas com fgets
            end[strcspn(end, "\n")] = '\0';
            bai[strcspn(bai, "\n")] = '\0';
            cid[strcspn(cid, "\n")] = '\0';
            est[strcspn(est, "\n")] = '\0';

            // Converte as strings lidas para strings do C++
            nome = nom;
            sobrenome = sobrenom;
            endereco = end;
            bairro = bai;
            cidade = cid;
            estado = est;

            // Cria dinamicamente os objetos endereço, data e cliente, e armazena no array global de pessoas
            Endereco *e = new Endereco(estado, cidade, bairro, endereco, numero);
            Cliente *c = new Cliente{nome, sobrenome, cpf, idade, dia, mes, ano, *e};
            pessoas[i] = c;
            i++;
        }
        fclose(arquivo);
    }

    fstream log;
    log.open("Log.txt", ios::out);
    if (log.is_open()) {
        log << "=============================================================" << endl << endl;
        log << "                       Log da execução                       " << endl << endl;
        log << "=============================================================" << endl << endl;

        // Operadores
        log << "Operadores:" << endl << endl;
        for (int i = 0; i < 1; i++) {
            pessoas[i] -> printLog(log);
        }
        
        log << "-------------------------------------------------------------" << endl << endl;

        // Equipamentos
        log << "Equipamentos:" << endl << endl;
        for (int i = 0; i < equip.size(); i++) {
            equip[i].printLog(log);
        }
        
        log << "-------------------------------------------------------------" << endl << endl;

        // Equipamentos
        log << "Processos:" << endl << endl;
        for (int i = 0; i < processos.size(); i++) {
            processos[i].printLog(log);
        }
        
        log << "-------------------------------------------------------------" << endl << endl;

        // Ingredientes
        log << "Ingredientes:" << endl << endl;
        for (int i = 0; i < ingredientes.size(); i++) {
            ingredientes[i].printLog(log);
        }
        for (int i = 0; i < sabores.size(); i++) {
            //log << sabores[i].getNome() << endl;
            if (sabores[i].getNome() != "Nada"){
                sabores[i].printLog(log);
            }
        }
        
        log << "-------------------------------------------------------------" << endl << endl;

        // Produtos
        log << "Produtos:" << endl << endl;
        for (int i = 0; i < bolos.size(); i++) {
            bolos[i].printLog(log);
        }
        
        log << "-------------------------------------------------------------" << endl << endl;

        // Clientes
        log << "Clientes:" << endl << endl;
        for (int i = 1; i < sizeof(pessoas); i++) {
            if (pessoas[i] == nullptr) {
                break;
            }
            pessoas[i] -> printLog(log);
        }
        
        log << "-------------------------------------------------------------" << endl << endl;

        // Pedidos
        log << "Pedidos realizados:" << endl << endl;
        for (int i = 0; i < pedidos.size(); i++) {
            pedidos[i].setNumero(i + 1);
            //pedidos[i].print();
            pedidos[i].printLog(log);
        }
        
        log << "=============================================================";

        log.close();
    }

    else{
        cout << endl << "Erro na criação do log" << endl;
    }
    
    cout << endl << "Fechando o programa..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

// Função para cadastro de um novo cliente
void Cadastrar() {
    string nome;
    string sobrenome;
    long cpf;
    int dia;
    int mes;
    int ano;
    int idade;
    string endereco;
    int numero;
    string bairro;
    string cidade;
    string estado;

    system("clear");
    cout << endl << "=============================================================" << endl << endl;
    cout << "                  Cadastro do novo cliente                   " << endl;
    cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;
    
    // Pede todos os dados necessários para cadastrar o cliente
    cout << "Nome: ";
    cin >> nome;
    cout << "Sobrenome: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, sobrenome);
    cout << "CPF: ";
    cin >> cpf;
    cout << "Data de nascimento (DD/MM/AAAA): ";
    scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    cout << "Idade: ";
    cin >> idade;
    cout << endl << "Local para entrega: " << endl;
    cout << "Endereço (rua ou avenida): ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, endereco);
    cout << "Número: ";
    cin >> numero;
    cout << "Bairro: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, bairro);
    cout << "Cidade: ";
    getline(cin, cidade);
    cout << "Estado (sigla): ";
    getline(cin, estado);
    cout << endl << "=============================================================" << endl << endl;

    // Abre o aquivo e adiciona os dados do cliente no arquivo
    fstream arquivo;
    arquivo.open("Clientes.txt", std::ios_base::app);
    if (arquivo.is_open()) {
        arquivo << nome << endl;
        arquivo << sobrenome << endl;
        arquivo << cpf << endl;
        arquivo << dia << "/" << mes << "/" << ano << endl;
        arquivo << idade << endl;
        arquivo << endereco << endl;
        arquivo << numero << endl;
        arquivo << bairro << endl;
        arquivo << cidade << endl;
        arquivo << estado << endl << endl;
        arquivo.close();
        cout << "Cadastro realizado com sucesso!" << endl;
    }

    // Caso ocorra algum probema com o arquivo, exibe uma mensagem de erro
    else{
        cout << "Erro ao realizar o cadastro!" << endl;
    }

    cout << "Pressione ENTER para retornar ao Menu" << endl;
    cin.ignore();
}

// Função para realizar um novo pedido
void Pedir() {
    string nome;
    string sobrenome;
    long cpf;
    int dia;
    int mes;
    int ano;
    int idade;
    string endereco;
    int numero;
    string bairro;
    string cidade;
    string estado;

    char nom[20];
    char sobrenom[40];
    char end[100];
    char bai[50];
    char cid[30];
    char est[3];
    char lixo[1];

    long numcpf;

    system("clear");
    cout << endl << "=============================================================" << endl << endl;
    cout << "                        Novo pedido                          " << endl;
    cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;
    cout << "Digite o CPF do cliente: ";
    cin >> numcpf;
    cin.ignore();
    cout << endl;

    // Abre o arquivo de texto no modo somente leitura
    FILE *arquivo = fopen("Clientes.txt", "r");
    vector <Cliente> cli;

    // Caso o arquivo não possa ser aberto, exibe uma mensagem de erro
    if (arquivo == nullptr) {
        cout << "Não foi possível acessar os dados dos clientes cadastrados!" << endl;
    }

    else{
        // O loop lê os dados contidos no arquivo de texto e tranfere para variáveis do tipo char. Caso a leitura de nome e sobrenome do cliente falhe (caso fscanf retornar um valor inválido), o loop é interrompido imediatamente, pois não há mais clientes no arquivo
        while (true) {
            if (fscanf(arquivo, "%s %[^\n]", nom, sobrenom) != 2) break;
            fscanf(arquivo, "%ld [^\n]", &cpf);
            fscanf(arquivo, "%d/%d/%d [^\n]", &dia, &mes, &ano);
            fscanf(arquivo, "%d [^\n]", &idade);
            fgets(end, sizeof(end), arquivo);
            fscanf(arquivo, "%d [^\n]", &numero);
            fgets(lixo, sizeof(lixo), arquivo);
            fgets(bai, sizeof(bai), arquivo);
            fgets(cid, sizeof(cid), arquivo);
            fgets(est, sizeof(est), arquivo);

            // Remove '\n' das strings lidas com fgets
            end[strcspn(end, "\n")] = '\0';
            bai[strcspn(bai, "\n")] = '\0';
            cid[strcspn(cid, "\n")] = '\0';
            est[strcspn(est, "\n")] = '\0';

            // Converte as strings lidas para strings do C++
            nome = nom;
            sobrenome = sobrenom;
            endereco = end;
            bairro = bai;
            cidade = cid;
            estado = est;

            // Cria o objeto endereço, data e cliente, e envia para o final do vetor de clientes
            Endereco e(estado, cidade, bairro, endereco, numero);
            Cliente c(nome, sobrenome, cpf, idade, dia, mes, ano, e);
            cli.push_back(c);
        }
        fclose(arquivo);

        // Busca o cliente pelo CPF no vetor de clientes cadastrados
        bool encontrado = false;
        Cliente *cliente;
        for (int i = 0; i < cli.size(); i++){
            // Se encontrar, a variável "encontrado" se torna verdadeira, e o cliente é copiado
            if (cli[i].getCPF() == numcpf) {
                cliente = &cli[i];
                encontrado = true;
                break;
            }
        }

        // Com o cliente encontrado, libera a criação do pedido
        if (encontrado){

            // Pega a data atual para inserir no pedido
            time_t agora = time(0);
            tm *ltm = localtime(&agora);
            int diaH = ltm -> tm_mday;
            int mesH = 1 + ltm -> tm_mon;
            int anoH = 1900 + ltm -> tm_year;
            Data hoje(diaH, mesH, anoH);

            // Variável para armazenar as opções escolhidas
            vector <int> opcoes;
            int num;

            // Variável para armazenar os produtos do pedido
            vector <Produto> produtos;

            system("clear");
            cout << endl << "=============================================================" << endl << endl;
            cout << "\t  Seja bem-vindo(a) " << cliente -> getNome() << " " << cliente -> getSobrenome() << "!" << endl;
            cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;
            cout << "Temos os seguintes sabores disponíveis:" << endl;
            cout << "1 - Bolo de abacaxi" << endl;
            cout << "2 - Bolo de banana" << endl;
            cout << "3 - Bolo de chocolate" << endl;
            cout << "4 - Bolo de fubá" << endl;
            cout << "5 - Bolo de laranja" << endl;
            cout << "6 - Bolo simples" << endl;
            cout << endl << "=============================================================" << endl << endl;
            cout << "Digite os números dos bolos que gostaria de pedir, separados" << endl << 
                    "apenas por espaço, e digite 0 para encerrar as escolhas. Caso" << endl << 
                    "queira mais de 1 bolo do mesmo sabor, basta repetir o número." << endl;

            // Armazena as opções escolhidas enquanto o usuário digitar um número inteiro diferente de 0
            while ((cin >> num) && (num != 0)) {
                opcoes.push_back(num);
            }
            cin.ignore();

            system("clear");
            cout << endl << "=============================================================" << endl << endl;
            cout << "\t  Seja bem-vindo(a) " << cliente -> getNome() << " " << cliente -> getSobrenome() << "!" << endl;
            cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;
            for (int i = 0; i < opcoes.size(); i++) {
                if (opcoes[i] == 1) {
                    produtos.push_back(boloAbacaxi);
                }
                else if (opcoes[i] == 2) {
                    produtos.push_back(boloBanana);
                }
                else if (opcoes[i] == 3) {
                    produtos.push_back(boloChocolate);
                }
                else if (opcoes[i] == 4) {
                    produtos.push_back(boloFuba);
                }
                else if (opcoes[i] == 5) {
                    produtos.push_back(boloLaranja);
                }
                else if (opcoes[i] == 6) {
                    produtos.push_back(boloSimples);
                }
                else {
                    cout << "Produto " << opcoes[i] << " inválido!" << endl << endl;
                }
            }

            // Cria o pedido e exibe as informações
            Pedido ped(*cliente, hoje, produtos);
            ped.print();

            // Salva o pedido em um vetor de pedidos
            pedidos.push_back(ped);
        }

        // Caso o cliente não tenha sido encontrado, exibe uma mensagem de erro
        else {
            cout << "Cliente com CPF " << numcpf << " não encontrado!" << endl << "Faça o cadastro antes de realizar o pedido" << endl << endl;
        }
    }

    cout << "=============================================================" << endl << endl;
    cout << "Pressione ENTER para retornar ao Menu" << endl;
    cin.ignore();
}

// Função para visualizar os produtos do cardápio
void Cardapio(){
    system("clear");
    cout << endl << "=============================================================" << endl << endl;
    cout << "                    Sabores disponíveis                      " << endl;
    cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;

    // Abre o arquio de texto "Cardapio.txt" que contém os sabores de bolo disponíveis para compra
    fstream arquivo;
    arquivo.open("Cardapio.txt", ios::in);
    string texto;

    // Com o arquivo aberto, imprime para o usuário os sabores disponíveis, os ingredientes utilizados, e o preço de cada bolo
    if (arquivo.is_open()) {
        while (getline(arquivo, texto)) {
            cout << texto << endl;
        }
        arquivo.close();
    }

    // Caso o cardápio não possa ser aberto, exibe uma mensagem de erro
    else{
        cout << "Cardápio não encontrado!" << endl;
    }

    cout << endl << "=============================================================" << endl << endl;
    cout << "Pressione ENTER para retornar ao Menu" << endl;
    cin.ignore();
}

// Função para confirmar o fechamento do programa
void Encerrar(char opcao) {
    opcao = 'o';
    
    // Enquanto 'S', 's', 'N', ou 'n' não for digitado, repete a pergunta
    while (opcao != 'S' || opcao != 's' || opcao != 'N' || opcao != 'n') {
        system("clear");
        cout << endl << "=============================================================" << endl << endl;
        cout << "                      Encerrar sessão                        " << endl;
        cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;
        cout << "Deseja mesmo encerrar o programa? Todas as alterações feitas" << endl << "serão salvas automaticamente. (S/N)" << endl;
        cin >> opcao;

        // Se 'S' ou 's' for digitado, o programa é encerrado
        if (opcao == 'S' || opcao == 's') {
            Log();
            system("clear");
            exit(0);
        }

        // Se 'N' ou 'n' for digitado, a variável "opcao" assume o valor 9 e o programa retorna para o Menu
        if (opcao == 'N' || opcao == 'n') {
            opcao = 9;
            break;
        }
    }
}

int main(){
    char opcao;
    opcao = '9';
    while (opcao == '9'){
        system("clear");
        cout << endl << "=============================================================" << endl << endl;
        cout << "|‾‾‾‾‾\\  |‾‾‾‾‾|  |        |‾‾‾‾‾‾  |‾‾‾‾‾|  ‾‾‾|‾‾‾  |‾‾‾‾‾|" << endl;
        cout << "|     |  |     |  |        |        |     |     |     |     |" << endl;
        cout << "|—————<  |     |  |        |—————   |—————|     |     |—————|" << endl;
        cout << "|     |  |     |  |        |        |    \\      |     |     |" << endl;
        cout << "|_____/  |_____|  |______  |______  |     \\  ___|___  |     |" << endl;
        cout << endl << "—————————————————————————————————————————————————————————————" << endl << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Novo pedido" << endl;
        cout << "3 - Sabores" << endl;     
        cout << "0 - Encerrar" << endl;
        cout << endl << "=============================================================" << endl << endl;
        cout << "Digite o que deseja fazer a seguir (1, 2, 3 ou 0):" << endl;
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
        // Caso a primeira opção seja escolhida, chama a função de cadastro de pacientes. Ao retornar da função, chama o Menu novamente
        case '1':
            Cadastrar();
            opcao = '9';
            break;

        // Caso a segunda opção seja escolhida, chama a função de atendimento de pacientes. Ao retornar da função, chama o Menu novamente
        case '2':
            Pedir();
            opcao = '9';
            break;

        // Caso a terceira opção seja escolhida, chama a função de pesquisa de pacientes. Ao retornar da função, chama o Menu novamente
        case '3':
            Cardapio();
            opcao = '9';
            break;

        // Caso a quarta opção seja escolhida, chama a função de encerramento do programa. Ao retornar da função, chama o Menu novamente
        case '0':
            Encerrar(opcao);
            opcao = '9';
            break;

        // Caso nenhuma das opções seja escolhida, o Menu é chamado novamente
        default:
            opcao = '9';
            break;
        }        
    }
}