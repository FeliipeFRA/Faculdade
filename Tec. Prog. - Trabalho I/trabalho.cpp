// integrantes:
// Felipe Ferreira Rangel de Almeida - 2208490
// Felipe Lemes Ferreira             - 2250767
// Sergio Lu�s Filippin J�nior       - 2259500
// Vin�cius Eleut�rio Branquinho     - 2187258

//bibliotecas utilizadas
#include <iostream> // entrada e sa�da de dados
#include <cstdlib> // gerar o random
#include <ctime> // pegar o tempo do pc como seed
#include <algorithm> // usar a fun��o sort, para ordenar o array
#include <bitset> // converter para binario
#include <cmath> // fun��o pow

using namespace std;

// fun��es
int gerarIndividuo(int min, int max);
void gerarPopulacao(int populacao[], int tampop, int min, int max);
double avaliarIndividuo(int a, int b, int c, int d, int e, int f, int x);
void selecionarPais(const int melhoresIndividuos[], int tampop, int paisdageracao[]);
string converterBinario(int ind);
void paisBinario(string paisbin[], int paisdageracao[], int tampop);
void crossover(string filhosbin[], const string paisbin[], int tampop, int numFilhos, double taxadecross);
int converterInteiro(string ind);
void filhosInt(int filhosint[], string filhosbin[], int numFilhos);
void mutacao(string filhosbin[], int numFilhos, double taxademuta);
bool perfeito(double qualidade[], int populacao[], int tampop);


int main() {

    const int tampop = 10; // <------ DEFINIR O TAMANHO DA POPULA��O
    int maximo = 2000;
    int minimo = -2000;
    int a, b, c, d, e, f;
    int maximoGeracoes;
    double taxadecross;
    double taxademuta;
    int melhoresIndividuos[tampop];

    // definir o numero de gera��es
    cout << "========================================" << endl;
    cout << "           ALGORITMO GENETICO           " << endl;
    cout << "========================================" << endl;

    int populacao[tampop];
    gerarPopulacao(populacao, tampop, minimo, maximo);

    cout << "- Defina o numero de geracoes: ";
    cin >> maximoGeracoes;
    while (maximoGeracoes <= 0) {
        cout << "- O numero de geracoes deve ser positivo! Tente novamente." << endl;
        cout << "- Defina o numero de geracoes: ";
        cin >> maximoGeracoes;
    }

    // definir a taxa de crossover

    cout << "- Defina a taxa de CrossOver [em %]: ";
    cin >> taxadecross;
    taxadecross = taxadecross / 100;

    // definir a taxa de muta��o
    cout << "- Defina a taxa de Mutacao [em %]: ";
    cin >> taxademuta;
    taxademuta = taxademuta / 100;

    // definir os coeficientes da equa��o
    cout << "========================================" << endl;
    cout << "            EQUACAO PROBLEMA            " << endl;
    cout << "  ax^5 + bx4 + cx^3 + dx^2 + ex + f = 0 " << endl;
    cout << "========================================" << endl;
    cout << "- Informe os valores de:" << endl;
    cout << "'a': ";
    cin >> a;
    while (a == 0) {
        cout << "- 'a' precisa ser diferente de 0! Tente novamente." << endl;
        cout << "'a': ";
        cin >> a;
    }
    cout << "'b': ";
    cin >> b;
    cout << "'c': ";
    cin >> c;
    cout << "'d': ";
    cin >> d;
    cout << "'e': ";
    cin >> e;
    cout << "'f': ";
    cin >> f;

    for (int geracao = 0; geracao < maximoGeracoes; geracao++) {
        double qualidade[tampop];

        // avaliando todos os indiv�duos gerados
        for (int i = 0; i < tampop; i++) {
            qualidade[i] = avaliarIndividuo(a, b, c, d, e, f, populacao[i]);
        }


        // ordenando os �ndices da popula��o de acordo com a qualidade dos indiv�duos
        int indices[tampop];
        for (int i = 0; i < tampop; ++i) {
            indices[i] = i;
        }


        sort(indices, indices + tampop, [&](int i, int j) { return qualidade[i] < qualidade[j]; });


        // armazenando todos os indiv�duos da popula��o ordenados por qualidade
        for (int i = 0; i < tampop; i++) {
            melhoresIndividuos[i] = populacao[indices[i]];
        }
        // verificando se encontrou a solu��o perfeita

        if (perfeito(qualidade, populacao, tampop)) {
            break;
        }


        // selecionando pais da pr�xima gera��o
        int paisdageracao[tampop / 2 - 1];
        selecionarPais(melhoresIndividuos, tampop, paisdageracao);


        // convertendo pais para bin�rio
        string paisbin[tampop / 2 - 1];
        paisBinario(paisbin, paisdageracao, tampop);


        // fazendo o crossover
        const int numFilhos = tampop / 2;
        string filhosbin[tampop / 2];
        crossover(filhosbin, paisbin, tampop, numFilhos, taxadecross);


        // mutando os filhos
        mutacao(filhosbin, numFilhos, taxademuta);


        // convertendo filhos pra inteiros
        int filhosint[tampop / 2];
        filhosInt(filhosint, filhosbin, numFilhos);


        // avaliando filhos
        double qualidadefilhos[numFilhos];
        for (int i = 0; i < numFilhos; i++) {
            qualidade[i] = avaliarIndividuo(a, b, c, d, e, f, filhosint[i]);
        }


        // identificando os �ndices dos menos aptos (2� metade da populacao)
        int menosaptos[tampop / 2];
        for (int i = tampop / 2; i < tampop; ++i) {
            menosaptos[i - tampop / 2] = indices[i];
        }


        // substituindo os menos aptos pelos filhos gerados, se forem melhores
        for (int i = 0; i < numFilhos; i++) {
            if (qualidadefilhos[i] < qualidade[menosaptos[i]]) {
                populacao[menosaptos[i]] = filhosint[i];
                qualidade[menosaptos[i]] = qualidadefilhos[i];
            }
        }

    }

    cout << "========================================" << endl;
    cout << "Melhor Individuo: " << melhoresIndividuos[0];
    cout << "\n\n\n";

    return 0;
}

// gera um indiv�duo
int gerarIndividuo(int min, int max) {
    static bool jaGerou = false;
    if (!jaGerou) {
        srand(time(0));
        jaGerou = true;
    }

    int individuo = min + rand() % (max - min + 1);

    return individuo;
}

// gera uma popula��o inicial
void gerarPopulacao(int populacao[], int tampop, int min, int max) {
    for (int i = 0; i < tampop; i++) {
        populacao[i] = gerarIndividuo(min, max);
    }
}

// avalia o qu�o o indiv�duo satisfaz a equa��o
double avaliarIndividuo(int a, int b, int c, int d, int e, int f, int x) {
    double resultado = (a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) + d * pow(x, 2) + e * x + f);
    return abs(resultado);
}

// seleciona pais da popula��o atual
void selecionarPais(const int melhoresIndividuos[], int tampop, int paisdageracao[]) {
    int metade = tampop / 2;

    for (int i = 1; i < metade; i++) {
        paisdageracao[i - 1] = melhoresIndividuos[i];
    }
}

// converte um inteiro para binario (string)
string converterBinario(int ind) {
    return bitset<32>(ind).to_string();
}

// converte os pais da gera��o para binario
void paisBinario(string paisbin[], int paisdageracao[], int tampop) {
    for (int i = 0; i < tampop / 2 - 1; i++) {
        paisbin[i] = converterBinario(paisdageracao[i]);
    }
}

// faz o crossover
void crossover(string filhosbin[], const string paisbin[], int tampop, int numFilhos, double taxadecross) {
    // n�mero de filhos � a metade do tamanho da popula��o

    // for pra gerar os filhos
    for (int i = 0; i < numFilhos; i++) {

        double testetaxa = (double)rand() / RAND_MAX;
        // isso gera um int e divide por um valor aleat�rio gigante, retornando um double entre 0 e 1

        // usa a taxa de crossover para testar se vai acontecer ou n�o
        if (testetaxa < taxadecross) {
            // faz o crossover se o numero aleatorio entre 0 e 1 for maior q a taxa de crossover definida pelo usu�rio

            // ponto de corte
            const int pdc = 32 / 2;

            // seleciona o indice de dois pais aleat�rios
            int pai1 = rand() % (tampop / 2 - 1);
            int pai2 = rand() % (tampop / 2 - 1);
            // verifica se os pais n�o s�o iguais
            while (pai1 == pai2) {
                pai2 = rand() % (tampop / 2 - 1); // Corrigido aqui
            }

            // gera o filho combinando os bits dos pais
            string filho = paisbin[pai1].substr(0, pdc) + paisbin[pai2].substr(pdc, 31);
            filhosbin[i] = filho;
        }
        else {
            // se nao for, o filho vira um dos pais
            int pai = rand() % (tampop / 2 - 1);
            // escolhe um pai aleatorio
            filhosbin[i] = paisbin[pai];
            // o filho vira ele, pois n passou na taxa de crossover
        }
    }
}

// converte um binario (string) para inteiro
int converterInteiro(string ind) {
    bitset<32> bits(ind);
    return static_cast<int>(bits.to_ulong());
}

// converte os filhos da gera��o para inteiro
void filhosInt(int filhosint[], string filhosbin[], int numFilhos) {
    for (int i = 0; i < numFilhos; i++) {
        filhosint[i] = converterInteiro(filhosbin[i]);
    }
}

// faz a muta��o
void mutacao(string filhosbin[], int numFilhos, double taxademuta) {
    for (int i = 0; i < numFilhos; i++) {
        // mesmo esquema da taxa de cross, definir se o filho vai ser mutado ou n�o
        double testetaxa = (double)rand() / RAND_MAX;
        // isso gera um int e divide por um valor aleat�rio gigante, retornando um double entre 0 e 1
        string filho = filhosbin[i];
        // compara com a taxa de muta para testar se vai acontecer ou n�o
        if (testetaxa < taxademuta) {
            // vai mutar se o numero aleatorio entre 0 e 1 for maior q a taxa q foi definida

            int preservar = 16; // <--- quantidade de primeiros bits q v�o ser poupados da muta��o
            int bitmutado = preservar + (rand() % (32 - preservar)); // vai definir um bit aleatorio pra ser flipado
            if (filho[bitmutado] == '0') {
                filho[bitmutado] = '1';
            }
            else {
                filho[bitmutado] = '0';
            }
            filhosbin[i] = filho;
        }
    }
}

// verificar se achou o perfeito, pra n rodar o loop atoa
bool perfeito(double qualidade[], int populacao[], int tampop) {
    // avalia a qualidade dos indiv�duos
    for (int i = 0; i < tampop; i++) {
        // se achar a solu��o, retorna ture
        if (qualidade[i] == 0) {
            return true;
        }
    }
    // se n, false
    return false;
}

// casos de uso

// CASO 1:
// tamanho popula��o: 10
// gera��es: 25
// crossover: 55
// muta��o: 95
// a: 6
// b: 32
// c: 61
// d: 23
// e: 5
// f: 1
// MELHOR IND�VIDUO: -70

// CASO 2:
// tamanho popula��o: 100
// gera��es: 20
// crossover: 75
// muta��o: 65
// a: 3
// b: 12
// c: 42
// d: 36
// e: 12
// f: 8
// MELHOR IND�VIDUO: -1


// observa��es

// o tamanho da popula��o � definido no c�digo, pois estavamos tendo dificuldade ao desenvolver em uma 
// estrutura que o usu�rio definia o tamanho.

// existe tamb�m no c�digo, na fun��o de muta��o, uma v�riavel denominada preservar, o valor inserido nela
// ser� o n�mero dos primeiros bits do individuo que n�o ser�o submetidos a muta��o. Preservando apenas o 
// primeiro como recomendado em aula estavamos tendo problema com as muta��es, podendo ocorrer filhos muito 
// diferentes, o que deixava todo o processo menos eficiente.

// por fim, vale adicionar que estav�mos tendo problemas com o VS CODE, pois um dos integrantes teve problemas 
// para configur� - lo e por consequ�ncia, utiliz� - lo.Por isso, utilizamos o Visual Studio Community para 
// desenvolver a maior parte do c�digo, permitindo que todos pudessem estar envolvidos no processo.Ao terminar o 
// c�digo fizemos testes no VS CODE e resolvemos algumas incompatibilidades, por�m temos ci�ncia de que podemos 
// ter deixado alguma passar despercebida, o que pode ocasionar no mal funcionamento do c�digo quando compilado 
// e executado no VS CODE.
