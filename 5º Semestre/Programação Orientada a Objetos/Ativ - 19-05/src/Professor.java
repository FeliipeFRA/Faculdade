public class Professor extends Pessoa{

    public Professor(String nome, String email) {
        super(nome, email);
    }

    @Override
    public String getTipoPessoa() {
        return "Professor";
    }
}
