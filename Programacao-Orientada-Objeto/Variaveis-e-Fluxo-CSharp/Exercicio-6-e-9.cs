using System;

class Exercicio_6_e_9 {

    static void Main(String[] args){

        int numero;
        int [] fibonacci = new int[12];

        fibonacci[0] = 1;
        fibonacci[1] = fibonacci[0];

        numero = 0;

        while (numero >= 0){

            if (numero >= 2){

                fibonacci[numero] = fibonacci[numero - 1] + fibonacci[numero - 2];
            }

            if (fibonacci[numero] > 100) {

                break;

            }

            Console.WriteLine(fibonacci[numero]);

            numero++;
        }

    }

}