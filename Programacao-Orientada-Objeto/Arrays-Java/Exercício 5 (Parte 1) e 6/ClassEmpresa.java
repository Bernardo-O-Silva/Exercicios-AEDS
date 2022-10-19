import java.util.Scanner;

class Empresa {

    private String nome;
    private Funcionario[] empregados = new Funcionario[5];
    private Funcionario[] empregadosNovo = new Funcionario[10];
    private String cnpj;
    private Data fundacao = new Data();
    private String nomeFundador;
    private int qtdFuncionarios = 0;
    Scanner scan = new Scanner(System.in);

    public void adicionaFuncionario(Funcionario funcionario){

        this.empregados[qtdFuncionarios] = funcionario;

        this.qtdFuncionarios++;

    }

    public void setEmpresa(){

        System.out.print("Digite o nome da empresa: ");
        this.nome = scan.nextLine();

        System.out.print("Digite o CNPJ da empresa: ");
        this.cnpj = scan.nextLine();

        System.out.println("Digite a data da fundação da empresa: ");
        this.fundacao.setData();

        System.out.print("Digite o nome do fundador da empresa: ");
        this.nomeFundador = scan.nextLine();

    }

    public void mostraEmpresa(){

        System.out.println("Nome: " + this.nome);
        System.out.println("CNPJ: " + this.cnpj);
        System.out.print("Fundada em: ");
        this.fundacao.mostraData();
        System.out.println("Fundador: " + this.nomeFundador);
        System.out.println("------------------------------------");
        System.out.println("Funcionários: ");
        System.out.println("------------------------------------");

        for (int comparador = 0; comparador < this.empregados.length; comparador++){

            this.empregados[comparador].mostra();

            System.out.println("------------------------------------");

        }

    }

    public int getTotal(){

        return this.empregados.length;

    }

    public void adicionaMAISFuncionarios(){

        for (int comparador = 0; comparador < this.empregados.length; comparador++){

            empregadosNovo[comparador] = empregados[comparador];

        }        

        empregados = empregadosNovo;

    }


}