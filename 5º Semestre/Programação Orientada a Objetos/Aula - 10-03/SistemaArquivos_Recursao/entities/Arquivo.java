package entities;

import java.util.Date;

public class Arquivo extends Item{
    private String tipo;
    private Object conteudo;

    public Arquivo(String id, String nome, String pTipo, long tamanho, Date dataCriacao, Date dataAlteracao,
	    String autor, Pasta pastaMae, Object conteudo) {
	super(id, nome, dataCriacao, dataAlteracao, autor, pastaMae, tamanho);
	this.tipo = pTipo;
	this.conteudo = conteudo;
    }
    public Object getConteudo() {
        return conteudo;
    }

    public void setConteudo(Object conteudo) {
        this.conteudo = conteudo;
    }
    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
}
