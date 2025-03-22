public class ex01 {
    public static void main(String[] args) {
        Veiculo veiculo1 = new Veiculo("ABC1234", "Chevrolet", "Cruze");
        Veiculo veiculo2 = new Veiculo("DEF5678", "Fiat", "Palio");

        Falha falha1 = new Falha("Motor", "Motor fundido");
        Falha falha2 = new Falha("Freio", "Freio quebrado");
        Falha falha3 = new Falha("Pneu", "Pneu furado");

        veiculo1.adicionarFalha(falha1);
        veiculo1.adicionarFalha(falha2);
        veiculo2.adicionarFalha(falha3);


        Diagnostico diagnostico = new Diagnostico(1, veiculo1);
        System.out.println(diagnostico.fornecimentoDiagnostico(veiculo1));

        Diagnostico diagnostico2 = new Diagnostico(2, veiculo2);
        System.out.println(diagnostico2.fornecimentoDiagnostico(veiculo2));
    }
}
