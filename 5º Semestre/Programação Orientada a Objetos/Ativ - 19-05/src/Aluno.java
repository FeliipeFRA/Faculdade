public class Aluno extends Pessoa {

    public Aluno(String nome, String email) {
        super(nome, email);
    }

    @Override
    public String getTipoPessoa() {
        return "Aluno";
    }
    public String toString() {
        return "Nome: " + getNome() + ", Email: " + getEmail();
    }
}
