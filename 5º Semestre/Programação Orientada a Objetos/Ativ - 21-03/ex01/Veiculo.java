import java.util.ArrayList;

public class Veiculo {
    private String placa;
    private String marca;
    private String modelo;
    private ArrayList<Falha> falhas = new ArrayList<Falha>();

    Veiculo(String placa, String marca, String modelo) {
        this.placa = placa;
        this.marca = marca;
        this.modelo = modelo;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public void adicionarFalha(Falha falha) {
        falhas.add(falha);
    }

    public ArrayList<Falha> getFalhas() {
        return falhas;
    }
}
