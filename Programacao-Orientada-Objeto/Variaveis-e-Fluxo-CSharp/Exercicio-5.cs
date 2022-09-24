//Há uma diferença notável em se aumentar de int para long, entretanto, depois do número 20, mesmo com long, o cálculo para de funcionar.
//É necessário que essa mudança seja feita pois, quando o número fica muito grande, há um overflow com o int.

using System;

class Exercicio_5 {

    static void Main(String[] args){

        long fatorial, comparador, comparador2;

        for (comparador = 1; comparador <= 20; comparador++){

            fatorial = 1;

            for (comparador2 = 1; comparador2 <= comparador; comparador2++){

                fatorial = fatorial * comparador2;

            }

            Console.WriteLine(fatorial);

        }

    }

}