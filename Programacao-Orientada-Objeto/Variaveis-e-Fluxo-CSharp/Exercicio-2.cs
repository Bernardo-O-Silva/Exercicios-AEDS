using System;

class Exercicio_2 {

    static void Main(string[] args){

        int soma, comparador;

        soma = 0;

        for (comparador = 0; comparador <= 1000; comparador++){

            soma = soma + comparador;

        }

        Console.WriteLine(soma);

    }

}