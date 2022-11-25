class TesteRestaurante{

    public static void main(String[] args){

        Restaurante restaurante = new Restaurante();
        boolean repetir = true;
        int escolha;

        System.out.println("Bem-vindo ao restaurante " + restaurante.getNome() +"!\n");

        while(repetir != false){
            
            System.out.println("Digite o que deseja fazer:");

            System.out.println("1 - Mostrar informações");

            switch(escolha){
                case 1:
                    
                    restaurante.mostraInfo();
                    break;

                default:
                    System.out.println("Erro: Valor inválido digitado.");
                    break;


            }


        }


    }





}