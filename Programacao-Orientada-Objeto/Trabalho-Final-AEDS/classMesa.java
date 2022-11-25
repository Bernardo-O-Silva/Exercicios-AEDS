import java.util.Scanner;

class Mesa {

    //Constantes
    private static final int PESSOAS_POR_MESA = 4;

    //Variáveis
    private static int numeroMesa = 0;
    private String data;
    private boolean reserva = false;
    private boolean resposta;
    private Cliente[] clientes = new Cliente[this.PESSOAS_POR_MESA];
    private int numCadastrados = 0;
    private int numAtual;
    private int numDesejados;
    private String nomeAux;
    private String emailAux;
    Scanner scan = new Scanner(System.in);

    //Construtor
    public Mesa(){

        this.numeroMesa++;
        this.numAtual = this.numeroMesa;

    }

    //Métodos
    public void setData(){

        this.data = this.scan.nextLine();

    }

    public String getData(){

        return this.data;

    }

    public boolean reservar(){

        if (this.reserva == false) {

            this.reserva = true;
            this.resposta = true;
            
            System.out.print("Digite a data da sua reserva: ");
            this.setData();

            for (boolean comparador = false; comparador != true; comparador = comparador){

                System.out.print("Digite o número de pessoas da mesa "+ this.numAtual +": ");
                this.numDesejados = this.scan.nextInt();                

                if (this.numDesejados < 1 || this.numDesejados > this.PESSOAS_POR_MESA){

                    System.out.println("Erro: o número deve estar entre 1 e "+ this.PESSOAS_POR_MESA +"!\n");

                }
                else {

                    comparador = true;

                }

            }

            scan.nextLine();

            for (int comparador = 0; comparador < this.numDesejados; comparador++){

                System.out.print("Digite o nome do "+ (comparador + 1) +"º cliente: ");
                this.nomeAux = scan.nextLine();
                
                System.out.print("Digite o email do "+ (comparador + 1) +"º cliente: ");
                this.emailAux = scan.nextLine();

                this.adicionaCliente(this.nomeAux, this.emailAux);

            }

        }
        else {

            this.resposta = false;

        }

        return this.resposta;

    }

    public void adicionaCliente(String nome, String email){

        this.clientes[this.numCadastrados] = new Cliente();

        this.clientes[this.numCadastrados].setNome(nome);
        this.clientes[this.numCadastrados].setEmail(email);
        this.numCadastrados++;

    }

    public void imprimeInfo(){

        if (this.numeroMesa == 0){

            System.out.println("Não há mesas cadastradas no sistema.");

        }
        else {

            System.out.println("Mesa Número "+ this.numAtual + ":\n");

            if (this.reserva == false){

                System.out.println("A mesa número "+ this.numAtual +" não está reservada!\n");

            }
            else {

                System.out.println("Reservada para: "+ this.data + "\n");

                if (this.numCadastrados == 0) {

                    System.out.println("Não há clientes cadastrados!\n");


                }
                else {

                    System.out.println("Cliente(s):");

                    for (int comparador = 0; comparador < this.numCadastrados; comparador++){

                        System.out.println("- "+ this.clientes[comparador].getNome() +" - "+ this.clientes[comparador].getEmail() +";"); 

                    }

                    System.out.println("\n");

                }                

            }

        }
        
    }


}