using System;

public class Data {

    int dia;
    int mes;
    int ano;

}

public class Funcionario {

    string nomeFn;
    string deptFn;
    double salarioFn;
    Data dataDeEntrada = new Data();

    void mostra(){

        Console.WriteLine("Nome: " +this.nomeFn);
        Console.WriteLine("Departamento: " +this.deptFn);
        Console.WriteLine("Salário: R$ " +this.salarioFn);
        Console.WriteLine("Data de Entrada: " +this.dataDeEntrada.dia +this.dataDeEntrada.mes +this.dataDeEntrada.ano);

    }

}

public class Exercicio1 {

    static void Main(string[] args){

        Funcionario funcionario = new Funcionario();

        Console.Write("Digite o nome do funcionário: ");
        funcionario.nomeFn = Console.ReadLine();

        Console.Write("Digite o departamento do funcionário: ");
        funcionario.deptFn = console.ReadLine();

        Console.Write("Digite o salário do funcionário: ");
        funcionario.salarioFn = Convert.ToDouble(Console.ReadLine());

        Console.Write("Digite o dia de entrada do funcionário: ");
        funcionario.dataDeEntrada.dia = Convert.ToInt32(Console.ReadLine());

        Console.Write("Digite o mês de entrada do funcionário: ");
        funcionario.dataDeEntrada.mes = Convert.ToInt32(Console.ReadLine());

        Console.Write("Digite o ano de entrada do funcionário: ");
        funcionario.dataDeEntrada.ano = Convert.ToInt32(Console.ReadLine());

        funcionario.mostra();

    }

}