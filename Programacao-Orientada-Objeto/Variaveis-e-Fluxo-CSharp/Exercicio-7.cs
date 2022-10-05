using System;

class Exercicio_7 {

    static void Main(string[] args){

        int numeroX;
        
        Console.Write("Digite o número inicial: ");

        numeroX = Convert.ToInt32(Console.ReadLine());

        while (numeroX > -1){

            if (numeroX % 2 == 0) {

                numeroX = numeroX / 2;

            }

            else if (numeroX % 2 != 0) {

                numeroX = 3 * numeroX + 1;

            }

            if (numeroX != 1) {

                Console.Write(numeroX + " -> ");

            }

            else if (numeroX == 1){

                Console.WriteLine(numeroX);

                break;

            }

        }

    }

}