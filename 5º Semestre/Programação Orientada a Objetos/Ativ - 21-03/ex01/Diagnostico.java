public class Diagnostico {
    int id;
    Veiculo veiculo;

    Diagnostico(int id, Veiculo veiculo) {
        this.id = id;
        this.veiculo = veiculo;
    }

    public String fornecimentoDiagnostico(Veiculo veiculo) {
        String diagnostico = "Diagnostico do veículo " + veiculo.getMarca() + " " + veiculo.getModelo() + " de placa " + veiculo.getPlaca() + ":\n";
        for (Falha falha : veiculo.getFalhas()) {
            diagnostico += falha.getNome() + ": " + falha.getDescricao() + "\n";
        }
        return diagnostico;
    }
}
