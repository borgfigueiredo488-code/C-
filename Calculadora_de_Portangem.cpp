#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int menu();
int categorias();
void guardar_dados(std::string tipo_veiculo, int valor_veiculo);
void processar_escolha(int opcao);

int main(){
    int opc;
    do{
        opc = menu();

        switch(opc){
            case 1:
            int saida;
            saida = categorias();
            processar_escolha(saida);
            break;

            case 2:
            cout<<"Indisponivel"<<endl;
            break;

           case 3:
           int escolha;
           cout<<"\n1-Pesquisar Matricula"<< endl;
           cout<<"2-Mostar todas Matricula"<< endl;
           cout<<"escolha uma opcao: ";
           cin>>escolha;
           if(escolha == 1){
               cout<<"\n"<<endl;
               pesquisa();
           }else if(escolha == 2){
               cout<<"\n"<<endl;
               lerArquivo();
           }else{
               cout<<"Escolha invalida\n" <<endl;
               break;
           }
           break;
            case 4:
            cout<<"Indisponivel"<<endl;
            break;

            default:
            cout<<"Opção invalida"<<endl;
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

void guardar_dados(std::string tipo_veiculo, int valor_veiculo){
    ofstream arquivo("dados.txt", ios::app);
    if (!arquivo){
        cout<<"Erro ao abrir o arquivo"<<endl;
    }
}

void processar_escolha(int opcao){
    if (opcao == 1){
        guardar_dados("Veiculo ligueiro", 20);
    }else if(opcao == 2){
        guardar_dados("veiculo medio", 45);
    }else if(opcao == 3){
        guardar_dados("Veiculos pesados", 60);
    }else if(opcao == 4){
        guardar_dados("veiculo muito pesado", 80);
    }else{
        cout<< "Opcao invalida!\n"<<endl;
    }
}

void lerArquivo() {
    ifstream arquivo("dividas.txt");
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    string linha;

    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
}

void pesquisa(){
    string procura, linha;
    int encontrou = 0;
    ifstream arquivo("dividas.txt");
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    cout << "Digite a Matricula: ";
    cin >> procura;
    for(char &c : procura){
    c = toupper(c);}

    cout<<"\n"<<endl;
    while (getline(arquivo, linha)) {
        if (linha.find(procura) != string::npos) {
            encontrou = 1;
            cout << linha << endl;
        }
    }
    if(encontrou == 0){
        cout<<"\nNenhuma divida encontrada com essa matricula: "<<procura<<endl;
    }
}