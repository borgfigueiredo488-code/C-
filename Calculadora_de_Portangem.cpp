#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int menu();
int categorias();
void guardar_dados(std::string tipo_veiculo, int valor_veiculo);
void processar_escolha(int opcao);
void lerArquivo();
int somar_dividas();
void pesquisa();
void dividas(int valor);
void guardar_dividas(std::string matricula, int valor_divida);
void estatistica();
int contar_pagamentos();
int contar_dividas();

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
            cout<<"\n"<< endl;
            int op, valor;
            valor = 0;
            op = categorias();
            if (op == 1){
                valor+=20;
            }else if(op == 2){
                valor+=45;
            }else if(op == 3){
                valor+=60;
            }else if(op == 4){
                valor+=80;
            }
            dividas(valor);
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
            cout<<"\n"<< endl;
        estatistica();
        break;
            

            default:
            cout<<"Opção invalida"<<endl;
        }

    }while(opc != 5);

    return 0;
}
int menu(){
    int opcao;
    cout << "\n===== SISTEMA DE PORTAGEM =====\n";
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

void guardar_dividas(std::string matricula, int valor_divida){
    ofstream arquivo("dividas.txt", ios::app);
    if (!arquivo){
        cout<<"Erro ao abrir o arquivo"<<endl;
    }
    arquivo << "Matricula: " << matricula << " | Valor em divida: " << valor_divida << endl;
    arquivo.close(); 
    cout << "Divida registrada com sucesso!\n" << endl;
}

void dividas(int valor){
    string v1, v2, v3;
    bool valido;

    do {
        cout << "Digite as primeiras 3 letras da Matricula: ";
        cin >> v1;
        valido = (v1.length() == 3);

        for(char c : v1){
            if(!isalpha(c)){
                valido = false;
                break;
            }
        }
        if(!valido)
            cout << "Entrada invalida. Digite apenas 3 letras.\n";

    } while(!valido);

    do {
        cout << "Digite 3 numeros da Matricula: ";
        cin >> v2;
        valido = (v2.length() == 3);
        for(char c : v2){
            if(!isdigit(c)){
                valido = false;
                break;
            }
        }
        if(!valido)
            cout << "Entrada invalida. Digite apenas 3 numeros.\n";

    } while(!valido);

    do {
        cout << "Digite as ultimas 2 letras da Matricula: ";
        cin >> v3;
        valido = (v3.length() == 2);
        for(char c : v3){
            if(!isalpha(c)){
                valido = false;
                break;
            }
        }
        if(!valido)
            cout << "Entrada invalida. Digite apenas 2 letras.\n";

    } while(!valido);

    for(char &c : v1) c = toupper(c);
    for(char &c : v3) c = toupper(c);
    string resultado = v1 + "-" + v2 + "-" + v3;
    guardar_dividas(resultado, valor);
    
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

int somar_dividas(){

    ifstream arquivo("dividas.txt");
    string linha;
    int total = 0;

    if(!arquivo){
        cout << "Erro ao abrir dividas.txt" << endl;
        return 0;
    }

    while(getline(arquivo, linha)){

        size_t pos = linha.find("Valor em divida:");

        if(pos != string::npos){

            string valor_str = linha.substr(pos + 16);
            int valor = stoi(valor_str);

            total += valor;
        }
    }

    arquivo.close();
    return total;
}
int contar_dividas(){

    ifstream arquivo("dividas.txt");
    string linha;
    int contador = 0;

    if(!arquivo){
        cout << "Erro ao abrir dividas.txt" << endl;
        return 0;
    }

    while(getline(arquivo, linha)){
        contador++;
    }

    arquivo.close();
    return contador;
}

int contar_pagamentos(){

    ifstream arquivo("dados.txt");
    string linha;
    int contador = 0;

    if(!arquivo){
        cout << "Erro ao abrir dados.txt" << endl;
        return 0;
    }

    while(getline(arquivo, linha)){
        contador++;
    }

    arquivo.close();
    return contador;
}
void estatistica(){

    int pagamentos = contar_pagamentos();
    int dividas = contar_dividas();
    int total_dividas = somar_dividas();

    int total_carros = pagamentos + dividas;

    ifstream arquivo("dados.txt");

    string linha;

    int classe1 = 0;
    int classe2 = 0;
    int classe3 = 0;
    int classe4 = 0;

    int faturamento = 0;

    if(!arquivo){
        cout << "Erro ao abrir dados.txt" << endl;
        return;
    }

    while(getline(arquivo, linha)){

        if(linha.find("20") != string::npos){
            classe1++;
            faturamento += 20;
        }
        else if(linha.find("45") != string::npos){
            classe2++;
            faturamento += 45;
        }
        else if(linha.find("60") != string::npos){
            classe3++;
            faturamento += 60;
        }
        else if(linha.find("80") != string::npos){
            classe4++;
            faturamento += 80;
        }
    }

    arquivo.close();

    cout << "\n===== ESTATISTICAS =====" << endl;
    cout << "Carros ligeiros: " << classe1 << endl;
    cout << "Carros medios: " << classe2 << endl;
    cout << "Carros pesados: " << classe3 << endl;
    cout << "Carros muito pesados: " << classe4 << endl;

    cout << "\nCarros que pagaram: " << pagamentos << endl;
    cout << "Numero total de carros em divida: " << dividas << endl;
    cout << "Carros total que passaram: " << total_carros << endl;

    cout << "\nFaturamento do dia: " << faturamento << " mt" << endl;
    cout << "Total dividas: " << total_dividas << " mt" << endl;
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
