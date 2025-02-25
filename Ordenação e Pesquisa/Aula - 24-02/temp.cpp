#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib> // lib para uso da func atof (convert string - double)


using namespace std;

// estrutura que representa uma música, inclui titulo, artista, duração, album e genero
struct Musica {
    string titulo;
    string artista;
    double duracao;
    string album;
    string genero;
};

// função para carregar musicas de um arquivo csv
// o arquivo terá o formato:
// titulo,Artista,Duracao,Album,Genero
// "Song 1","Artista 1",3.45,"Album 1","Genero 1"
vector<Musica> carregarMusicas(const string& nomeArquivo){
    // vetor para armazenar as músicas lidas
    vector<Musica> musicas;
    /*
    ifstream é uma classe da lib padrão do C++ usada para ler arquivos. Ela cria um fluxo de entrada que permite que você leia o conteúdo de um arquivo, assim como na entrada de um teclado.
    Ela permite abertura, leitura e fechamento de arquivos dentro do programa
    */
   ifstream arquivo(nomeArquivo);
   // verifica se o arquivo foi aberto com sucesso.
   // caso contrario retorna erro
   if (!arquivo) {
    cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
    return musicas;
   }

    // declara um string para armazenar cada linha do arquivo
    string linha;
    // lê a primeira linha do arquivo, que é o cabeçalho, e a descarta
    // isso evita que os nomes dos campos façam parte dos dados
    getline(arquivo, linha);
    // inicia um loop que le o arquivo linha por linha
    // getline(arquivo, linha) retorna true enquanto houver linhas para serem lidas
    while(getline(arquivo, linha)) {
        // se a lista estiver vazia, ignore-a e passa para a proxima
        if(linha.empty()){
            continue;
        }
        // teria um stringstream (ss) a paritr da linha lida
        // o stringstream permite separar a linha em campos usando delimitadores
        std::stringstream ss(linha);
        string campo;
        // cria um objeto musica para armazenar  os dados desta linha
        Musica m;
        // lê o primeiro campo - titulo da linha, usando a virgula como delimitador
        if (getline(ss, campo, ',')){
            m.titulo = campo;
        }
        // le o segundo campo - artista
        if (getline(ss, campo, ',')) {
            m.artista = campo;
        }
        // converte a string lida para double utilizando atof
        if (getline(ss, campo, ',')){
            m.duracao = atof(campo.c_str());
        }
        // lê o quarto campo - album
        if (getline(ss, campo, ',')){
            m.album = campo;
        }
        // lê o quinto campo - genero
        if (getline(ss, campo, ',')){
            m.genero = campo;
        }
        // adiciona o objeto 'm' com os dados lidos ao final do vetor musicas usando o método push_back do vector (estrutura de lista)
        musicas.push_back(m);
    }
    // fecha o arquivo lido para liberar recursos
    arquivo.close();
    // retorna o vetor preenchido e pronto com os registros das musicas lido no arquivo csv
    return musicas;
}


int main (){
    // nome do arquivo csv contendo os registros
    string nomeArquivo = "local csv";
    // carrega as musicas a partir do arquivo
    vector<Musica> musicas = carregarMusicas(nomeArquivo);
    // exibe o numero de musicas carregadas
    cout << "Foram carregadas " << musicas.size() << " músicas." << endl;
    // exibe as 5 primeiras como exemplo
    for (size_t i = 0; i< musicas.size() && i < 5; i++){
        cout << i + 1 << ": "
            << "Titulo: " << musicas[i].titulo
            << ", Artista: " << musicas[i].artista
            << ", Duração: " << musicas[i].duracao
            << ", Álbum: " << musicas[i].album
            << ", Genero: " << musicas[i].genero
            << endl;
    }

    // agora sim a partir daqui implementar as rotinas de ordenação e pesquisa, medindo o desempenho conforme o numero de musicas aumenta

    return 0;
}