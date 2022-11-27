import java.util.Scanner;

class TestaBanco {

    public static void main(String[] args){

        Banco bb_ou_seja_Banco_do_Bernardo = new Banco();
        ContaCorrente[] corrente = new ContaCorrente[5];
        ContaPoupanca[] poupanca = new ContaPoupanca[5];
        Atualiza atualizaContas = new Atualiza();
        double valor;
        boolean verificaTaxa;
        double[] taxa = new double[2];
        Scanner scan = new Scanner(System.in);

        for (int comparador = 0; comparador < 10; comparador++){

            if (comparador < 5){

                corrente[comparador] = new ContaCorrente();

                System.out.print("Digite o valor que deseja depositar na "+ (comparador + 1) +"ª conta corrente: ");
                valor = scan.nextDouble();
                corrente[comparador].depositaSaldo(valor);
                bb_ou_seja_Banco_do_Bernardo.adicionaConta(corrente[comparador]);                


            }
            else if (comparador >= 5 && comparador < 10){

                poupanca[comparador - 5] = new ContaPoupanca();

                System.out.print("Digite o valor que deseja depositar na "+ (comparador - 4) +"ª conta poupança: ");
                valor = scan.nextDouble();
                poupanca[comparador - 5].depositaSaldo(valor);
                bb_ou_seja_Banco_do_Bernardo.adicionaConta(poupanca[comparador - 5]);

            }

        }

        System.out.println("As contas terão a mesma taxa.");
        System.out.println("ATENÇÃO: se as taxas forem diferentes, serão 2 taxas, uma para cada tipo de conta.");
        System.out.print("(True/False): ");
        verificaTaxa = scan.nextBoolean();

        if (verificaTaxa == true){

            System.out.print("Digite a taxa das contas: ");
            taxa[0] = scan.nextDouble();

            taxa[1] = taxa[0];

        }
        else {

            System.out.print("Digite a taxa das contas corrente: ");
            taxa[1] = scan.nextDouble();

            System.out.print("Digite a taxa das contas poupança: ");
            taxa[2] = scan.nextDouble();

        }

        for (int comparador = 0; comparador < 2; comparador++){

            for (int comparador2 = 0; comparador2 < 5; comparador2++){

                atualizaContas.pegaTaxa(taxa[comparador]);
                atualizaContas.imprimeRelatorio(bb_ou_seja_Banco_do_Bernardo.pegaConta(comparador2));

            }

        }

    }

}
