import java.util.Scanner;

class TestaConta {

    public static void main(String[] args){

        Conta normal = new Conta();
        ContaCorrente corrente = new ContaCorrente();
        ContaPoupanca poupanca = new ContaPoupanca();
        Atualiza atualizador = new Atualiza();
        double intermediario;
        double[] taxa = new double[3];
        boolean igualDiferente;
        Scanner scan = new Scanner(System.in);

        System.out.print("Digite o valor que deseja depositar na conta comum: ");
        intermediario = scan.nextDouble();
        normal.depositaSaldo(intermediario);

        System.out.print("Digite o valor que deseja depositar na conta corrente: ");
        intermediario = scan.nextDouble();
        corrente.depositaSaldo(intermediario);

        System.out.print("Digite o valor que deseja depositar na conta poupança: ");
        intermediario = scan.nextDouble();
        poupanca.depositaSaldo(intermediario);

        System.out.print("As taxas das contas serão iguais (True/False): ");
        igualDiferente = scan.nextBoolean();

        if (igualDiferente == true){

            System.out.print("Digite a porcentagem de atualização (ex: 0.10): ");
            taxa[0] = scan.nextDouble();

            taxa[1] = taxa[0];
            taxa[2] = taxa[1];

        }
        else {

            System.out.print("Digite a porcentagem de atualização da conta comum (ex: 0.10): ");
            taxa[0] = scan.nextDouble();

            System.out.print("Digite a porcentagem de atualização da conta corrente (ex: 0.10): ");
            taxa[1] = scan.nextDouble();

            System.out.print("Digite a porcentagem de atualização da conta poupança (ex: 0.10): ");
            taxa[2] = scan.nextDouble();

        }

        System.out.println("--------------");

        atualizador.pegaTaxa(taxa[0]);
        atualizador.imprimeRelatorio(normal);

        atualizador.pegaTaxa(taxa[1]);
        atualizador.imprimeRelatorio(corrente);

        atualizador.pegaTaxa(taxa[2]);
        atualizador.imprimeRelatorio(poupanca);

    }

}