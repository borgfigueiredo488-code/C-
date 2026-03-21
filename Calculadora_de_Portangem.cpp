#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int menu();
int categorias();

int main(){
    int opc;
    do{
        opc = menu();

        switch(opc){
            case 1:
            int saida = categorias();
        }

    }while(opc != 5);

    return 0;
}
int menu(){
    int opcao;
    cout << "\n1- registar passagem" << endl;
    cout << "2- dever passagem" << endl;
    cout << "3- consultar dividas" << endl;
    cout << "4- estatisticas" << endl;
    cout << "5- sair" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

int categorias(){
    int opcao;
    while (true)
    {
        cout << "\nClasse 1 - Veiculos ligeiros ------------- 20mt" << endl;
        cout << "Classe 2 - Veiculos medios --------------- 45mt" << endl;
        cout << "Classe 3 - Veiculos pesados -------------- 60mt" << endl;
        cout << "Classe 4 - Veiculos muitos pesados ------- 80mt" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        if(opcao > 4 || opcao < 1){
            cout << "opcao invalida\nDigite novamente" <<endl;
            continue;   
        }
        return opcao;
    }       
}
