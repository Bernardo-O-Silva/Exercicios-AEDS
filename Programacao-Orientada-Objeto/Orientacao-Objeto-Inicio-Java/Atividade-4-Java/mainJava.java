import java.util.Scanner;

class Exercicio1 {

    public static void main(String[] args){

        Funcionario funcionario = new Funcionario();
        Scanner scan = new Scanner(System.in);

        System.out.print("Digite o nome do funcionário: ");
        funcionario.nomeFn = scan.nextLine();
        
        System.out.print("Digite o departamento do funcionário: ");
        funcionario.deptFn = scan.nextLine();
        
        System.out.print("Digite o salário do funcionário: ");
        funcionario.salarioFn = scan.nextDouble();
        
        System.out.print("Digite o dia de entrada do funcionário: ");
        funcionario.dataDeEntrada.dia = scan.nextInt();

        System.out.print("Digite o mês de entrada do funcionário: ");
        funcionario.dataDeEntrada.mes = scan.nextInt();

        System.out.print("Digite o ano de entrada do funcionário: ");
        funcionario.dataDeEntrada.ano = scan.nextInt();

        funcionario.mostra();

    }

}