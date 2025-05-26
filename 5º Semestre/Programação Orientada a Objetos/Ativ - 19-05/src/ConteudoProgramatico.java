public class ConteudoProgramatico {
    private String tema;
    private int duracaoHoras;

    public ConteudoProgramatico(String tema, int duracaoHoras) {
        this.tema = tema;
        this.duracaoHoras = duracaoHoras;
    }

    public String getTema() {
        return tema;
    }

    public void setTema(String tema) {
        this.tema = tema;
    }

    public int getDuracaoHoras() {
        return duracaoHoras;
    }

    public void setDuracaoHoras(int duracaoHoras) {
        this.duracaoHoras = duracaoHoras;
    }

    public String toString() {
        return "ConteudoProgramatico{" +
                "tema='" + tema + '\'' +
                ", duracaoHoras=" + duracaoHoras +
                '}';
    }
}
