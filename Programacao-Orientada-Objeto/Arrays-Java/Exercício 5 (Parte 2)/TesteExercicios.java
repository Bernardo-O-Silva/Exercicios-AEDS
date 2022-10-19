import java.util.Scanner;

class TesteExercicios {

    public static void Exercicio1(){

        Casa casinha = new Casa();
        Porta porta;
        int totalPortas;

        totalPortas = casinha.totalDePortas();

        casinha.pinta();

        for (int comparador = 0; comparador < totalPortas; comparador++){

            porta = new Porta();

            casinha.adicionaPorta(porta);

        }

        casinha.mostraCasa();

    }

    public static void Exercicio2(){

        Exercicio2 exercicioDois = new Exercicio2();

        exercicioDois.imprimeResultados();

    }

    public static void Exercicio3(){

        TrianguloPascal triangulo = new TrianguloPascal();

        triangulo.imprimePascal();

    }


    public static void main(String[] args){

        int selecionar;
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Selecione o exercício: ");
        selecionar = scan.nextInt();

        switch(selecionar){
        case 1:
            TesteExercicios.Exercicio1();
            break;
        case 2:
            TesteExercicios.Exercicio2();
            break;
        case 3:
            TesteExercicios.Exercicio3();
            break;
        default:
            System.out.println("ERRO!");
            break;
        }

    }

}