import java.util.Scanner;

class Exercicio_8 {

    public static void main(String [] args){

        Scanner scan = new Scanner(System.in);
        int numero, comparador, comparador2, numerosImprime;

        System.out.print("Digite o número final: ");
        numero = scan.nextInt();

        for (comparador = 0; comparador < numero; comparador++){

            for (comparador2 = 0; comparador2 <= comparador; comparador2++){

                numerosImprime = (comparador + 1) * (comparador2 + 1);

                System.out.print(numerosImprime);
                System.out.print(" ");

            }

            System.out.print("\n");

        }

    }

}