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
    ComandaBebida bebida = new ComandaBebida();
    ComandaComida comida  = new ComandaComida();
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

                    System.out.print("\n");

                }                

            }

        }
        
    }

    public boolean cancelaReserva(){

        if (this.reserva == true){

            for(int comparador = 0; comparador < this.numCadastrados; comparador++){

                this.clientes[comparador] = null;

            }

            this.numCadastrados = 0;
            this.reserva = false;

            return true;
        }
        else {

            System.out.println("Essa mesa não está reservada");
            return false;
        }

    }

    public void add_Bebida(int num_pedido){
    if(num_pedido < this.bebida.quantd_bebidas()){
       this.bebida.setConsumo(this.bebida.getOpcao(num_pedido));
       this.bebida.setValor(this.bebida.getPreco(num_pedido));
    }else{
        System.out.print("Opcao nao existe");
    }
    }

    public void add_Comida(int num_pedido){
        if(num_pedido < this.comida.quantd_comidas()){
        this.comida.setConsumo(this.comida.getOpcao(num_pedido));
        this.comida.setValor(this.comida.getPreco(num_pedido));
        }else{
            System.out.print("Opcao nao existe");
        }
     }

     public void setComanda(){
        int qntd_comida, qntd_bebida, opc, num;
        System.out.print("Deseja adicionar a sua comanda:\n1 - Comida\n2- Bebida\n\n> ");
        opc = scan.nextInt();
        if(opc == 1){
        this.comida.listaCardapio();
        System.out.print("Quantas comidas deseja: ");
        qntd_comida = scan.nextInt();
        for(int i = 0; i < qntd_comida; i++){
            System.out.print("Num - Comida: ");
            num = scan.nextInt();
            add_Comida(num);
        }
        }
        if(opc == 2){
        this.bebida.listaCardapio();
        System.out.print("Quantas bebidas deseja: ");
        qntd_bebida = scan.nextInt();   
        for(int i = 0; i < qntd_bebida; i++){
            System.out.print("Num - Bebida: ");
            num = scan.nextInt();
            add_Bebida(num);
        }
        }
     }
     
     public double getComanda(){
        System.out.println("--- Comanda ---");
        System.out.println("-> Comidas");
        this.comida.listarConsumo();
        System.out.println("\n-> Bebidas");
        this.bebida.listarConsumo();

        double tot_valor = 0.00;
        tot_valor = bebida.getValor() + comida.getValor();
        return tot_valor;
     }

    public boolean getReserva(){

        return this.reserva;

    }

    public double dividirConta(){

        return (this.bebida.dividirConta(numCadastrados) + this.comida.dividirConta(numCadastrados));

    }

        public double desconto_bebida(){
        double desconto = 0.00;
         if(this.bebida.getValor() > 70){
        System.out.println("Em compras acima de R$70 voce ganha 10% de desconto *nas compras em bebidas");
        desconto = this.comida.calcular10porcento();
         }
        return desconto;
    }

    public double desconto_comida(){
        double desconto = 0.00;
        if(this.comida.getValor() > 70){
        System.out.println("Em compras acima de R$70 voce ganha 10% de desconto *nas compras em comidas");
        desconto = this.bebida.calcular10porcento();
        }
        return desconto;
    }
}