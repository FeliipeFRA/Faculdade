// INTEGRANTES:
// Felipe Ferreira Rangel de Almeida - 2208490
// Sérgio Luís Filippin Júnior       - 2259500
// Vinícius Eleutério Branquinho     - 2187258

// COMPILAR:
// g++ trabalho2.cpp -o trabalho2.exe
// EXECUTAR:
// .\trabalho2.exe imgX.foo imgX.foo2

// BIBLIOTECAS
#include <iostream> // entrada e saida de dados pelo dispostivo padrão
#include <fstream>  // escrita e leitura de arquivos
#include <string> // strings
using namespace std;



// FUNÇÕES
void conversorFoo(const string& arq_lei, const string& arq_esc);

// MAIN
int main(int argc, char* argv[]) {
    // argc = contador de argumentos passados
    // argv = vetor de argumentos passados (foo e foo2)

    if (argc != 3) { // verifica se passou todos os argumentos
        cerr << "Argumentos passados incorretamente!" << endl;
        return 1;
    }

    string arq_lei = argv[1];
    string arq_esc = argv[2];

    conversorFoo(arq_lei, arq_esc);

    return 0;
}

// FUNÇÕES
void conversorFoo(const string& arq_lei, const string& arq_esc) { // passando o foo como parametro

    // define tamanho da tabela de densidade
    const int tamanhotabela = 69;
    // aloca dinamicamente o vetor de caracteres
    char* vetortabela = new char[tamanhotabela + 1]; // +1 para o caractere nulo no final da string
    
    // inicializando variaveis para preencher o vetortabela corretamente (bug aspas duplas)
    string tabela = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,";
    char aspas = '"';
    string restotabela = "^`.";

    // preenche o vetor alocado dinamicamente com os caracteres
    for (int i = 0; i < tamanhotabela; ++i) {
        if (i < 64) {
            vetortabela[i] = tabela[i];
        } else if (i == 64) {
            vetortabela[i] = aspas;
        } else {
            vetortabela[i] = restotabela[i - 65];
        }
    }


    // abrindo o arquivo foo, no modo leitura binaria
    ifstream arquivo(arq_lei, ios::binary); 
    if (!arquivo.is_open()) {
        cerr << "Falha ao abrir o arquivo!" << endl;
        exit(-1);
    }

    // VARIÁVEIS
    int largura;
    int altura;

    // passando os dois primeiros campos do arquivo foo para largura e altura, respectivamente
    arquivo >> largura >> altura;

    // verificando se leu corretamente
    if (arquivo.fail()) {
        cerr << "Falha na leitura do arquivo! FLAMENGO" << endl;
        arquivo.close();
        exit(-1);
    }


    // teste
    cout << "\n\nLargura da imagem: " << largura << " pixels." << endl;
    cout << "Altura da imagem: " << altura << " pixels.\n\n" << endl;

    // criar variavel tamanho da imagem
    int tam = largura * altura;


    // alocar vetor dinamicamente para receber os bytes (char = 1 byte)
    // unsigned char recebe valores de 0 a 255, ao inves de valores negativos, melhor pra trabalhar
    unsigned char* bytes = new unsigned char[tam]; // cria um ponteiro do tipo q aponta para a primeira posição do vetor dos pixels

    arquivo.ignore(); // mesma coisa do cin.ignore, limpar buffer pra tirar o \n apos ler um numero

    // lendo os bytes/pixels com a função read
    // reinterpret_cast converte para o tipo passado entre <> no caso ponteiro char normal o que foi passado entre (), no caso bytes q é o pontei do tipo unsigned char
    arquivo.read(reinterpret_cast<char*>(bytes), tam); // tam = quantidade de pixels da imagem


    // verificação se leu corretamente os bytes sem chegar no fim
    if (arquivo.fail() && !arquivo.eof()) {
        cerr << "Falha na leitura dos pixels da imagem." << endl;
        delete[] bytes;
        arquivo.close();
        exit(-1);
    }

    arquivo.close(); // fechando arquivo de leitura
    
    // ESCRITA

    // abrir o arquivo .foo2 em modo de escrita SERGIO 
    ofstream arquivoesc(arq_esc, ios::out); // abre/cria o arquivoesc no modo saida que recebera os dados convertidos
    
    // verificação se abriu correamente o arquivo de saida
    if (!arquivoesc.is_open()) {
        cerr << "Falha ao abrir o arquivo de saída!" << endl;
        delete[] bytes; // desaloca memoria dinamica
        exit(-1); // fecha codigo e retorna -1
    }

    // escrevendo a largura e altura no .foo2 SERGIO
    arquivoesc << largura << " " << altura << "\n"; 

    // convertendo bytes do vetor bytes para seu repectivo caractere do vetortabela e escrevendo no arquivo foo2
    for (int i = 0; i < tam; i++) { // for para todos os bytes do arquivo
        unsigned char pixel = bytes[i]; // variavel pixel recebe o byte respectivo do for
        char caractereASCII = vetortabela[(pixel * tamanhotabela) / 255]; // cria o char formatado com a tabela de densidade multiplicando o valor do pixel (0 - 255) por 69 e dividindo por 255, dando um result dentro do intervalo
        arquivoesc << caractereASCII;
        if ((i + 1) % largura == 0) {
            arquivoesc << '\n';
        }
    }
    

    // fechando o arquivo de escrita 
    arquivoesc.close(); 
    // liberando memoria alocada
    delete[] bytes;
    delete[] vetortabela;
}

