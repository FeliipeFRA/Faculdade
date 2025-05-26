public interface Certificavel {
    void emitirCertificado() throws CursoSemInstrutorException, CursoSemInscritosException;;
    String getDescricaoCertificado();
}
