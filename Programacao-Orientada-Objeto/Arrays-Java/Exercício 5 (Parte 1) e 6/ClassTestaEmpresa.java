import java.util.Scanner;

class TestaEmpresa {

    public static void main(String[] args){

        Empresa companhia = new Empresa();
        Funcionario intermediario = new Funcionario();
        Scanner scan = new Scanner(System.in);
        int maxFuncionarios;
        boolean escolha;

        maxFuncionarios = companhia.getTotal();

        companhia.setEmpresa();

        for (int comparador = 0; comparador < maxFuncionarios; comparador++){

            System.out.println("------------------------------------");

            intermediario.setFuncionario();

            companhia.adicionaFuncionario(intermediario);

            intermediario = new Funcionario();

            if (comparador == maxFuncionarios - 1 && maxFuncionarios != 10){

                System.out.println("Deseja digitar mais funcionários? (True/False)");
                System.out.print("> ");
                escolha = scan.nextBoolean();

                if (escolha == true){

                    companhia.adicionaMAISFuncionarios();
                    maxFuncionarios = companhia.getTotal();

                }
                else {

                    break;

                }             

            }

        }

        System.out.println("------------------------------------");

        companhia.mostraEmpresa();

    }

}