import java.util.Scanner;

class Exercicio_7 {

    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        int numeroX;
        
        System.out.print("Digite o número X: ");
        numeroX = scan.nextInt();

        while (numeroX == numeroX){

            if (numeroX % 2 == 0){

                numeroX = numeroX / 2;

            }
            else if (numeroX % 2 != 0){

                numeroX = 3 * numeroX + 1;
                
            }

            if (numeroX != 1){

                System.out.print(numeroX);

            }

            if (numeroX == 1){

                System.out.println(numeroX);

                break;

            }

            System.out.print(" -> ");

        }

    }

}