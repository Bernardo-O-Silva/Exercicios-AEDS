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
            System.out.println("2 - Reservar uma mesa");
            System.out.println("3 - Cancelar reserva");
            System.out.println("4 - Fazer pedido");
            System.out.println("5 - Pagar");
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

                        if (numMesa < restaurante.getNumMesas() || numMesa > restaurante.getNumMesas()){

                            System.out.println("Número inválido digitado");

                        }

                        System.out.println("A mesa "+ numMesa +" já reservada!");
                        
                    }
                    break;
                
                case 3:

                    System.out.print("Digite o número da mesa cuja reserva deseja cancelar: ");
                    numMesa = scan.nextInt();

                    if (restaurante.cancelaReserva(numMesa) == true){

                        System.out.println("Reserva cancelada.");         

                    }

                    break;

                case 4:

                    System.out.print("Digite o número da mesa cujo pedido deseja fazer: ");
                    numMesa = scan.nextInt();                    
                    if (restaurante.setComanda(numMesa) == false){

                        System.out.println("Número inválido digitado.");

                    }

                    break;
                
                case 5:

                    System.out.print("Digite o número da mesa conta deseja fechar: ");
                    numMesa = scan.nextInt();  

                    if (restaurante.pagar(numMesa) == false){

                        System.out.println("Número inválido digitado.");

                    }                
                    else {

                        restaurante.cancelaReserva(numMesa);
                        System.out.println("Obrigado por escolher o Restaurante "+ restaurante.getNome() +", volte sempre!" );

                    }
                    break;                                                       

                default:
                    
                    System.out.println("Erro: Valor inválido digitado.");
                    break;
            }


        }


    }

}