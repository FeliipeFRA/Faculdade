package entities;

import java.util.Date;

public class Item {
    private String id;
    private String nome;
    private Date dataCriacao;
    private Date dataAlteracao;
    private String criador;
    private Pasta pastaMae;
    private long tamanho;
    
    public Item(String id, String nome, Date dataCriacao, Date dataAlteracao, String autor, Pasta pastaMae, long tamanho) {
        this.id = id;
        this.nome = nome;
        this.dataCriacao = dataCriacao;
        this.dataAlteracao = dataAlteracao;
        this.criador = autor;
        this.pastaMae = pastaMae;
        this.tamanho = tamanho;
    }
    
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public Date getDataCriacao() {
        return dataCriacao;
    }
    public void setDataCriacao(Date dataCriacao) {
        this.dataCriacao = dataCriacao;
    }
    public Date getDataAlteracao() {
        return dataAlteracao;
    }
    public void setDataAlteracao(Date dataAlteracao) {
        this.dataAlteracao = dataAlteracao;
    }
    public String getCriador() {
        return criador;
    }
    public void setCriador(String criador) {
        this.criador = criador;
    }
    public Pasta getPastaMae() {
        return pastaMae;
    }
    public void setPastaMae(Pasta pastaMae) {
        this.pastaMae = pastaMae;
    }
    public long getTamanho() {
        return tamanho;
    }
    public void setTamanho(long tamanho) {
        this.tamanho = tamanho;
    }
}
