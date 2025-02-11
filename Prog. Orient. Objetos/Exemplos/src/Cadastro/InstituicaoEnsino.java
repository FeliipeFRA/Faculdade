package Cadastro;

public class InstituicaoEnsino {
	
	public static void main(String[] args) {
		Aluno aluno1 = new Aluno();
		aluno1.setNome("Eliza Bomfim");
		aluno1.setBairro("Rua das Flores");
		aluno1.setNumero(1900);
		aluno1.setCep("14021-090");
		
		System.out.println(aluno1.getNome());
		System.out.println(aluno1.getEndereco());
	}
	
}
