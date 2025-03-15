public abstract class ChatBot {
    private String nome;
    private String empresa;
    
    public abstract String saudacao(String nome_cliente);
    public abstract String menu_opcoes();
    public abstract String compreender_problema(String problema);
    public abstract String gerar_solucao();
    public abstract String despedida();

    public ChatBot(String nome, String empresa) {
        this.nome = nome;
        this.empresa = empresa;
    }
}
