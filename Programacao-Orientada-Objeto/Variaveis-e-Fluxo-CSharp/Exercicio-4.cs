using System;

class Exercicio_4 {

    static void Main(string[] args){

        int fatorial, comparador, comparador2;

        for (comparador = 1; comparador <= 10; comparador++){

            fatorial = 1;

            for (comparador2 = 1; comparador2 <= comparador; comparador2++){

                fatorial = fatorial * comparador2;

            }

            Console.WriteLine(fatorial);

        }

    }

}