#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct anotacao {
    string nome;
    string date;
    string desc;
};


void fazerAnot (vector <anotacao> &a, int &option) {


    while (option > 0) {

    cin.ignore();

    anotacao nova;

    cout << endl << "Insira o nome da anotação: " << endl;
    getline(cin, nova.nome);

    cout << endl << "Insira a data da anotação: " << endl;
    getline(cin, nova.date);

    cout << endl << "Insira a descrição da anotação: " << endl;
    getline(cin, nova.desc);

    a.push_back(nova);

    cout << endl << "Parabéns! Você criou uma anotação. Deseja criar mais alguma? Se sim, digite 1, se não, digite 0" << endl;

    cin >> option;

    }

}

void editarAnot(vector <anotacao> &a, int &option) {


    cout << "Qual o número da anotação você deseja editar?" << endl;

    int opcao1;
    cin >> opcao1;

    cout << endl << "Escolha qual informação deseja editar (Digite 1 para nome, 2 para data e 3 para descrição)" << endl;

    int opcao2;
    cin >> opcao2;

    while (opcao2 > 3) {
        cout << endl << "Você digitou um número inválido! Por favor, digite somente uma das opções." << endl;
        cin >> opcao2;
    }
    
    while (opcao2 > 0) {

    cin.ignore();

    if (opcao2 == 1) {
        cout << "Insira novo nome: " << endl;
        getline(cin, a[(opcao1 - 1)].nome);
    }

    else if (opcao2 == 2) {
        cout << "Insira nova data: " << endl;
        getline(cin, a[(opcao1 - 1)].date);
    }

    else if (opcao2 == 3) {
        cout << "Insira nova descrição: " << endl;
        getline(cin, a[(opcao1 - 1)].desc);
    }

    cout << endl << "Alterado com sucesso! Deseja alterar mais algumas informação? Apenas digite o número correspondente. Se quiser voltar para o menu, digite 0." << endl;

    cin >> opcao2;

    while (opcao2 > 3) {
        cout << endl << "Você digitou um número inválido! Por favor, digite somente uma das opções." << endl;
        cin >> opcao2;
    }

    if (opcao2 == 0) break;
    

    }

    option = 0;

}

void excluirAnot(vector <anotacao> &a, int &option){

    cout << "Qual o número da anotação que você deseja apagar?" << endl;

    int opcao1;
    cin >> opcao1;

    while (opcao1 > 0) {

    a.erase(a.begin() + (opcao1 - 1));

    cout << "Você apagou sua anotação com sucesso! Deseja apagar mais alguma? Se sim, digite 1. Se não, digite 0" << endl;

    cin >> opcao1;

    if (opcao1 == 0) break;

    }

    option = 0;

}

void mostrarAnot(vector <anotacao> &a, int &option) {

    if (a.empty()) cout << endl << "Sua lista está vazia! Aperte 0 para voltar para o menu e faça suas anotações!" << endl;

    else {
    for (int i = 0; i < a.size(); i++) {
        cout << (i + 1) << ". " << a[i].nome << endl;
        cout << a[i].date << endl;
        cout << a[i].desc << endl << endl;
    }

    cout << endl << "Digite 0 para voltar para o menu." << endl;
    }
    
    cin >> option;

    

}

void menu (vector <anotacao> &a, int &option) {


    cout << "=========================" << endl;
    cout << "      AGENDA EM C++" << endl; 
    cout << "=========================" << endl << endl;

    cout << "Nesse terminal, você tem a opção de cadastrar uma anotação, " << endl;
    cout << "editala, apaga-la e visualizar todas as suas anotações. Cada" << endl;
    cout << "anotação é acompanhada de um nome, data e descrição." << endl << endl;

    cout << "Qual é sua ação?" << endl;
    cout << "---------------------------------------------" << endl;

    cout << "1 - Fazer anotação" << endl;
    cout << "2 - Excluir anotação" << endl;
    cout << "3 - Editar anotação" << endl;
    cout << "4 - Visualizar anotações" << endl << endl;

    cin >> option;

    cout << "---------------------------------------------" << endl;

    if (option == 1) fazerAnot(a, option);
    else if (option == 2) excluirAnot(a, option);
    else if (option == 3) editarAnot(a, option);
    else if (option == 4) mostrarAnot(a, option);

}



int main() {

    vector <anotacao> anot;

    int option = 0;

    while (option == 0) {
    menu(anot, option);
    }

}
