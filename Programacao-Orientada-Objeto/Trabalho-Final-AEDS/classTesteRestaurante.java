import java.util.Scanner;

class TesteRestaurante{

    public static void main(String[] args){

        //Variáveis
        Scanner scan = new Scanner(System.in);
        Restaurante restaurante = new Restaurante();
        boolean repetir = true;
        int escolha;
        int numMesa;
        String data;

        System.out.println("Bem-vindo ao restaurante " + restaurante.getNome() +"!\n");

        while(repetir != false){
            
            System.out.println("Digite o que deseja fazer:\n");

            System.out.println("1 - Mostrar informações");
            System.out.println("2 - Cadastrar uma mesa");
            System.out.println("0 - Sair");

            System.out.print("\n> ");
            escolha = scan.nextInt();

            switch(escolha){
                
                case 0:
                    
                    repetir = false;
                    System.out.println("Saindo...");
                    break;

                case 1:
                    
                    restaurante.mostraInfo();
                    break;
                
                case 2:

                    System.out.print("Digite o número da mesa que deseja reservar: ");
                    numMesa = scan.nextInt();

                    if (restaurante.reservaMesa(numMesa) == true){

                        System.out.println("Mesa reservada com sucesso!");                        

                    }
                    else {

                        System.out.println("A mesa"+ numMesa +" já está cadastrada!");
                        
                    }
                    break;

                default:
                    
                    System.out.println("Erro: Valor inválido digitado.");
                    break;
            }


        }


    }

}