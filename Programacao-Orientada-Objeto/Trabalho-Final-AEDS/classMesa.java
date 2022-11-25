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

    //Construtor
    public Mesa(){

        this.numeroMesa++;

    }

    //Métodos
    public void setData(String data){

        this.data = data;

    }

    public boolean reservar(){

        if (this.reserva == false) {

            this.reserva = true;
            this.resposta = true;

        }
        else {

            this.resposta = false;

        }

        return this.resposta;

    }

    public boolean adicionaCliente(String nome, String email){

        this.clientes[this.numCadastrados].setNome(nome);
        this.clientes[this.numCadastrados].setEmail(email);
        this.numCadastrados++;

    }

    public void imprimeInfo(){

        if (this.numeroMesa == 0){

            System.out.println("Não há mesas cadastradas no sistema.");

        }
        else {

            System.out.println("Mesa Número "+ this.numeroMesa + ":");

            if (numCadastrados == 0){

                System.out.println("A mesa número "+ this.numCadastrados +" não está reservada");

            }
            else {

                System.out.println("Cliente(s):");
                
                for (int comparador; comparador < this.numCadastrados; comparador++){

                   Sytem.out.println("- "+ this.clientes[comparador].getNome() +" - "+ this.clientes[comparador].getEmail() +";"); 

                }

            }

        }
        
    }


}