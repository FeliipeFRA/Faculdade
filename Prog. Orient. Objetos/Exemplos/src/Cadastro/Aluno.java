package Cadastro;

import java.util.Date;

public class Aluno {
	
	// atributos
	private String codigo = "00000";
	private String nome = "default";
	private String rua;
	private int numero = 0;
	private String bairro;
	private String cep;
	private Date dataNasc;
	
	
	/* comentarios de mais
	 * de uma linha
	 */
	
	//metodos getters and setters
	
	public String getNome() {
		return nome;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public String getRua() {
		return rua;
	}


	public void setRua(String rua) {
		this.rua = rua;
	}


	public int getNumero() {
		return numero;
	}


	public void setNumero(int numero) {
		this.numero = numero;
	}


	public String getBairro() {
		return bairro;
	}


	public void setBairro(String bairro) {
		this.bairro = bairro;
	}


	public String getCep() {
		return cep;
	}


	public void setCep(String cep) {
		this.cep = cep;
	}


	public Date getDataNasc() {
		return dataNasc;
	}


	public void setDataNasc(Date dataNasc) {
		this.dataNasc = dataNasc;
	}
	
	
	public String getEndereco() {
		return rua + ", " + ", "+ numero + "Bairro: "+bairro+" - CEP: "+cep;
	}
	
	public long getIdade() {
		return System.currentTimeMillis() - dataNasc.getTime();
	}
}
