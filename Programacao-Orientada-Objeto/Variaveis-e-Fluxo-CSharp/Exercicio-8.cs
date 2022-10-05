using System;

class Exercicio_8 {

    static void Main(string[] args){

        int numero, comparador, comparador2, numImprime;

        Console.Write("Digite o número final: ");
        numero = Convert.ToInt32(Console.ReadLine());

        for (comparador = 0; comparador < numero; comparador++){

            for (comparador2 = 0; comparador2 <= comparador; comparador2++){

                numImprime = (comparador + 1) * (comparador2 + 1);

                Console.Write(numImprime + " ");

            }

            Console.WriteLine();

        }

    }

}