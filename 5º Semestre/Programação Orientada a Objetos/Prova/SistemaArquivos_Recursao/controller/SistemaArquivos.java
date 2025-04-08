package controller;

import java.util.Date;

import entities.Arquivo;
import entities.Pasta;

public class SistemaArquivos {
    public static void main(String[] args) {

	// Exemplo de uso
        Pasta raiz = new Pasta("1","Raiz",new Date(),new Date(),"Admin",null,null);
        Arquivo arquivo1 = new Arquivo("1", "Arquivo1.txt", "txt", 100, new Date(), new Date(), "Autor1", raiz, "Conteudo do arquivo 1");
        Arquivo arquivo2 = new Arquivo("2", "Arquivo2.txt", "txt", 200, new Date(), new Date(), "Autor2", raiz, "Conteudo do arquivo 2");
        Pasta subPasta = new Pasta("2", "SubPasta", new Date(), new Date(), "Admin", raiz, null);

        raiz.adicionarConteudo(arquivo1);
        raiz.adicionarConteudo(arquivo2);
        raiz.adicionarConteudo(subPasta);

        Arquivo arquivo3 = new Arquivo("3", "Arquivo3.txt", "txt", 300, new Date(), new Date(), "Autor3", subPasta, "Conteudo do arquivo 3");
        subPasta.adicionarConteudo(arquivo3);

        System.out.println("Tamanho da pasta raiz: " + raiz.getTamanho() + " bytes");
    }
}
