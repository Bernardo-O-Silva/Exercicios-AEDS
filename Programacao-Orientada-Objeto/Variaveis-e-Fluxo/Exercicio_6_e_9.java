//Exercício 6 e 9, acidentalmente usei duas variáveis pra fazer.

class Exercicio_6_e_9 {

    public static void main(String[] args){

        int numero;
        int fibonacci[] = new int[12];

        fibonacci[0] = 1;
        fibonacci[1] = fibonacci[0];
        numero = 1;

        while (numero == numero){

            if (numero == 1 || numero == 2){

                System.out.println(fibonacci[numero - 1]);

            }
            else if (numero >= 3){

                fibonacci[numero - 1] = fibonacci[numero - 2] + fibonacci[numero - 3];

                if (fibonacci[numero - 1] > 100){

                    break;

                } 

                System.out.println(fibonacci[numero - 1]);

            }

            numero++;

        }

    }

}