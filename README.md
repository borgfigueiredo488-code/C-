## Nome dos membro

- Edil Borge Figueiredo
- Faria Fernando Gua
- Daniel Armando Antônio
- Kevin Muerembe

  


# Sistema de Calculadora de portagens(Via verde)

## Descrição do Projeto
Este projeto em **C++** é um sistema simples para gestão de passagens de veículos e controle de dívidas. 
O programa permite registrar veículos que passam por um ponto de cobrança, registrar dívidas de veículos que não pagaram, consultar dívidas existentes e exibir estatísticas gerais sobre os pagamentos e dívidas.

O sistema utiliza **arquivos de texto (`dados.txt` e `dividas.txt`)** para armazenar informações permanentemente.

## Funcionalidades Principais
- **Registrar passagem**: Registra o pagamento de um veículo, salvando o tipo e valor no arquivo `dados.txt`.
- **Registrar dívida**: Registra veículos que não pagaram, pedindo a matrícula (3 letras + 3 números + 2 letras) e o valor da dívida, salvando em `dividas.txt`.
- **Consultar dívidas**: Mostra todas as dívidas registradas no arquivo `dividas.txt`.
- **Estatísticas**: Exibe:
  - Total de carros que passaram (pagaram ou estão em dívida)
  - Total de carros em dívida
  - Total de valor de todas as dívidas
- **Sair**: Encerra o programa.

# Diferenças entre C e C++ usando o código de Calculadora de portagens(Via verde)

Este documento explica **todas as diferenças entre C++ e C** que existem no código de gestão de passagens e dívidas de veículos, considerando **entrada/saída, strings, arquivos, loops, conversões, funções e validação de dados**.

No código, utilizamos **C++**, que permite entrada e saída de dados de forma direta com `cin` e `cout`:

int opcao;
cout << "Escolha uma opcao: ";
cin >> opcao;

##Em C, a mesma operação seria feita com scanf e printf:

int opcao;
printf("Escolha uma opcao: ");
scanf("%d", &opcao);

Diferença: C++ é mais seguro e legível, enquanto C exige formatos e endereços explícitos.

Para strings, o código C++ usa std::string, que possui métodos como .length(), .substr() e permite concatenação com +:

string v1 = "ABC";
cout << v1.length();   // retorna 3
v1 = v1 + "-123-XY";

##Em C, strings são arrays de char, e operações exigem funções da biblioteca string.h:
char v1[10] = "ABC";
printf("%lu", strlen(v1));
strcat(v1, "-123-XY");

Para manipulação de arquivos, C++ usa ofstream e ifstream:
ofstream arquivo("dados.txt", ios::app);
arquivo << "Veiculo ligueiro 20" << endl;
arquivo.close();

##Em C, seria necessário usar FILE*:

FILE *arquivo = fopen("dados.txt", "a");
fprintf(arquivo, "Veiculo ligueiro 20\n");
fclose(arquivo);

Diferença: C++ é orientado a objetos e mais seguro. Em C, você precisa gerenciar ponteiros e funções manualmente.

Para loops, o código C++ utiliza for each moderno:
for(char c : v1) {
    c = toupper(c);
}

##Em C, o mesmo loop precisa usar índice:

for(int i = 0; i < strlen(v1); i++) {
    v1[i] = toupper(v1[i]);
}
Para validação de caracteres (isalpha, isdigit) em matrículas:

##C++ permite loops modernos com funções prontas:

for(char c : v1){
    if(!isalpha(c)){
        valido = false;
    }
}

##Em C, precisaríamos fazer o mesmo usando índices:

for(int i = 0; i < strlen(v1); i++){
    if(!isalpha(v1[i])){
        valido = 0;
    }
}
Para conversão de string para número:

##C++: stoi(valor_str) retorna um int e lança exceção em caso de erro.

C: atoi(valor_str) retorna um int, mas não avisa se a conversão falhar.
Na passagem de strings para funções, C++ permite:
void guardar_dividas(string matricula, int valor_divida)

##Em C seria:

void guardar_dividas(char* matricula, int valor_divida)

#Outras diferenças importantes do código:

Concatenação de strings: C++ com +; C com strcat.
Leitura de linhas completas de arquivos: C++ usa getline(arquivo, linha); C usaria fgets(linha, tamanho, arquivo).
Soma de valores de dívidas: C++ converte substring direto com stoi; em C seria necessário copiar substring e usar atoi.
Contagem de registros: C++ lê linha por linha com getline e incrementa contador; em C, seria fgets em loop e contador manual.
Estrutura geral: funções em C++ retornam string e recebem string; em C, seria necessário usar buffers e ponteiros para strings.

# C++
