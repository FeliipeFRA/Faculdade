
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Pasta extends Item{
    private List<Item> conteudo = new ArrayList<Item>(); // Pode conter Arquivos e Pastas

    public Pasta(String id, String nome, Date dataCriacao, Date dataAlteracao, String autor,
	    Pasta pastaMae, List<Item> pConteudo) {
	super(id, nome, dataCriacao, dataAlteracao, autor, pastaMae, 0);

	this.setConteudo(pConteudo);
    }

    // M�todo recursivo para calcular o tamanho da pasta
    @Override
    public long getTamanho() {
        long tamanhoTotal = 0;
        if (this.getConteudo() == null || this.getConteudo().isEmpty()) {
            return 0;
        }
        for (Item item : this.getConteudo()) {
            tamanhoTotal += item.getTamanho();
        }
        return tamanhoTotal;
    }
    
    // M�todo para adicionar conte�do � pasta
    public void adicionarConteudo(Item conteudo) {
	if (conteudo != null) {
	    this.conteudo.add((Item)conteudo);
	}
    }
    
    public List<Item> getConteudo() {
        return conteudo;
    }

    public void setConteudo(List<Item> pConteudo) {
	if (pConteudo != null) {
	    this.conteudo.addAll(pConteudo);
	}
    }
 }
