import java.util.Scanner;

class Teste {

    public static void main(String[] args){

        Agenda contatinhos;
        int numContatos = 1;
        boolean repetir = true;

        Scanner scan = new Scanner(System.in);

        while(repetir == true){

            System.out.print("Digite o número de contatos da sua agenda (Máximo -> 100): ");
            numContatos = scan.nextInt();

            if (numContatos > 0 && numContatos <= 100){

                repetir = false;

            }
            else {
                
                System.out.println("O número digitado é muito pequeno ou muito grande.\n");

            }

        }

        contatinhos = new Agenda(numContatos);

        contatinhos.addInformacoes();

        contatinhos.imprimeInformacoes();

    }

}