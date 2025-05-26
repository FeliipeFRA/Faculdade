import java.util.ArrayList;
import java.util.List;

public class Impressora<T> {
    private List<T> lista;

    public Impressora() {
        this.lista = new ArrayList<>();
    }

    public void adicionarItem(T item) {
        lista.add(item);
    }

    public void removerItem(T item) {
        lista.remove(item);
    }


    public void imprimirDetalhes() {
        for (T item : lista) {
            System.out.println(item.toString());
        }
    }
}
