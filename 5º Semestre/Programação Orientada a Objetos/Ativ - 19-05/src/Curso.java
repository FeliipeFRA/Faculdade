import java.util.ArrayList;
import java.util.List;

public class Curso implements Certificavel {
    private String titulo;
    private Professor professor_instrutor;
    private List<ConteudoProgramatico> conteudos;
    private List<Aluno> inscritos;
    private String descricaoCertificado;

    public Curso(String titulo) {
        this.titulo = titulo;
        this.conteudos = new ArrayList<>();
        this.inscritos = new ArrayList<>();
    }

    public String getTitulo() {
        return titulo;
    }

    public Professor getProfessorInstrutor() {
        return professor_instrutor;
    }

    public void setProfessorInstrutor(Professor professor_instrutor) {
        this.professor_instrutor = professor_instrutor;
    }

    public List<ConteudoProgramatico> getConteudos() {
        return conteudos;
    }

    public void adicionarConteudo(ConteudoProgramatico conteudo) {
        this.conteudos.add(conteudo);
    }
    
    public void removerConteudo(ConteudoProgramatico conteudo) {
        this.conteudos.remove(conteudo);
    }

    public List<Aluno> getInscritos() {
        return inscritos;
    }

    public void inscreverAluno(Aluno aluno) {
        this.inscritos.add(aluno);
    }

    public void removerAluno(Aluno aluno) {
        this.inscritos.remove(aluno);
    }

    @Override
    public void emitirCertificado() throws CursoSemInstrutorException, CursoSemInscritosException {
        if (professor_instrutor == null) {
            throw new CursoSemInstrutorException("Curso sem  professor instrutor definido.");
        }
        if (inscritos.isEmpty()) {
            throw new CursoSemInscritosException("Curso sem alunos inscritos.");
        }
        System.out.println("Emitindo certificado para o curso: " + titulo);
        System.out.println("Professor instrutor: " + professor_instrutor.getNome());
        System.out.println("Descrição do certificado: " + descricaoCertificado);
        for (Aluno aluno : inscritos) {
            System.out.println("Certificado emitido para: " + aluno.getNome());
        }
    }
    public String getDescricaoCertificado() {
        return descricaoCertificado;
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Curso: ").append(titulo).append("\n");
        sb.append("Professor: ").append(professor_instrutor.getNome()).append("\n");
        sb.append("Conteudos do curso:\n");
        for (ConteudoProgramatico conteudo : conteudos) {
            sb.append(" - ").append(conteudo.toString()).append("\n");
        }
        sb.append("Inscritos:\n");
        for (Aluno aluno : inscritos) {
            sb.append(" - ").append(aluno.toString()).append("\n");
        }
        return sb.toString();
    }
    
}
