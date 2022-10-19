import java.util.Scanner;

class Funcionario {

    private String nomeFn;
    private String deptFn;
    private double salarioFn;
    private Data dataDeEntrada = new Data();
    private boolean nomeCriacao;
    private int identificacao;
    private static int posicaoIdentificacao = 0;
    Scanner scan = new Scanner(System.in);

    Funcionario(String nomeDesejado) {

        nomeFn = nomeDesejado;
        nomeCriacao = true;

    }

    Funcionario() {

        nomeCriacao = false;

    }

    void mostra() {

        System.out.println("Nome: " +this.nomeFn);
        System.out.println("Nº Identificação: " +this.identificacao);
        System.out.println("Departamento: " +this.deptFn);
        System.out.println("Salário: R$ " +this.salarioFn);
        System.out.print("Data da Entrada: ");
        this.dataDeEntrada.mostraData();

    }

    void setFuncionario() {

        if (nomeCriacao == false){

            System.out.print("Digite o nome do funcionário: ");
            this.nomeFn = scan.nextLine();            

        }
        
        identificacao = Funcionario.posicaoIdentificacao + 1;
        Funcionario.posicaoIdentificacao++;

        System.out.print("Digite o departamento do funcionário: ");
        this.deptFn = scan.nextLine();
        
        System.out.print("Digite o salário do funcionário: ");
        this.salarioFn = scan.nextDouble();
        
        System.out.println("Digite a data de entrada do funcionário: ");
        this.dataDeEntrada.setData();

        scan.nextLine();

    }

}