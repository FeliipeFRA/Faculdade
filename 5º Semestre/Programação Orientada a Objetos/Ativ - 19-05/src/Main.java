public class Main {
    public static void main(String[] args) {
        System.out.println("SISTEMA SIGCERT");

        Professor professor = new Professor("Gabriel Bazo", "gabigol@bazotify.com");
        Professor professor2 = new Professor("Eliza Bonfim", "eliza@barao.edu.br");


        Aluno aluno = new Aluno("Felipe Lemes", "redpen@gmail.com");
        Aluno aluno2 = new Aluno("Pedro Murilo", "popmove@gmail.com");

        Curso curso = new Curso("Curso de Python");
        curso.setProfessorInstrutor(professor);

        curso.adicionarConteudo(new ConteudoProgramatico("Introducao ao Python", 10));
        curso.adicionarConteudo(new ConteudoProgramatico("Estruturas de Controle", 5));
        curso.adicionarConteudo(new ConteudoProgramatico("Estrutura de Dados", 15));

        curso.inscreverAluno(aluno);
        curso.inscreverAluno(aluno2);

        Curso curso2 = new Curso("Curso de Java");
        
        curso2.adicionarConteudo(new ConteudoProgramatico("Introdução ao Java", 10));
        curso2.inscreverAluno(aluno2);

        Curso curso3 = new Curso("Curso de JavaScript");
        curso3.setProfessorInstrutor(professor2);
        
        try {
            curso2.emitirCertificado();  // Este curso não tem professor atribuído
        } catch (CursoSemInstrutorException | CursoSemInscritosException e) {
            System.out.println("Erro ao emitir certificado para 'Curso de Java': " + e.getMessage());
        }

        try {
            curso3.emitirCertificado();  // Este curso tem professor atribuído
        } catch (CursoSemInstrutorException | CursoSemInscritosException e) {
            System.out.println("Erro ao emitir certificado para 'Curso de JavaScript': " + e.getMessage());
        }

        Impressora<Curso> impressora = new Impressora<>();
        impressora.adicionarItem(curso);

        impressora.imprimirDetalhes();
    
    }
}