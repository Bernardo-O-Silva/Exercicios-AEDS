import java.util.Scanner;

class Restaurante {

    //Constantes
    private static final int NUM_MESAS = 10;
    
    //Variáveis
    private String nome;
    private String endereco;
    private Mesa[] mesas = new Mesa[this.NUM_MESAS];
    private boolean reservada = false;
    Scanner scan = new Scanner(System.in);

    //Construtor
    public Restaurante(){

        for(int comparador = 0; comparador < this.NUM_MESAS; comparador++){

            this.mesas[comparador] = new Mesa();                       

        }

        this.setNome("Buchinho Cheio");
        this.setEndereco("Rua Ananás - Nº 41 - Bairro das Frutas");

    }

    //Métodos
    public String getNome(){

        return this.nome;

    }

    public void setNome(String nome){

        this.nome = nome;

    }

    public String getEndereco(){

        return this.endereco;

    }

    public void setEndereco(String endereco){

        this.endereco = endereco;

    }

    public void mostraInfo(){

        System.out.println("Nome: Restaurante "+ this.nome);
        System.out.println("Endereço: "+ this.endereco);

        System.out.print("\n");

        for (int comparador = 0; comparador < this.NUM_MESAS; comparador++){

            this.mesas[comparador].imprimeInfo();

        }

    }

    public boolean reservaMesa(int numMesa){

        numMesa--;

        if (numMesa < 0 || numMesa >= this.NUM_MESAS){

            return false;

        }
        else {

            return this.mesas[numMesa].reservar();

        }

    }

    public boolean cancelaReserva(int numMesa){

        numMesa--;

        if (numMesa < 0 || numMesa >= this.NUM_MESAS){

            return false;

        }
        else {

            return this.mesas[numMesa].cancelaReserva();

        }       

    }

    public int getNumMesas(){

        return this.NUM_MESAS;

    }

    public boolean setComanda(int numMesa){

        numMesa--;

        if (numMesa < 0 || numMesa >= this.NUM_MESAS){

            return false;

        }
        else if (this.mesas[numMesa].getReserva() == false) {

            return false;

        }
        else {

            this.mesas[numMesa].setComanda();
            return true;

        }             

    }

    public boolean pagar(int numMesa){

        double valor;
        double valorUser;
        boolean escolha;
        double desc_b, desc_c;

        numMesa--;

        if (numMesa < 0 || numMesa >= this.NUM_MESAS){

            return false;

        }
        else if (this.mesas[numMesa].getReserva() == false) {

            return false;
            
        }
        else {

            valor = this.mesas[numMesa].getComanda();
            System.out.print("\n");

            desc_b = this.mesas[numMesa].desconto_bebida();
            desc_c = this.mesas[numMesa].desconto_comida();

            valor = valor - desc_b;
            valor = valor - desc_c;

            System.out.println("\n Valor Total = R$" + valor);

            System.out.print("Deseja dividir a conta? (true/false): ");
            escolha = this.scan.nextBoolean();

            if (escolha == true){

                System.out.println("Cada um dos clientes pagará R$ "+ this.mesas[numMesa].dividirConta());

            }

            for (boolean comparador = false; comparador != true; comparador = comparador){

                System.out.print("Digite o valor TOTAL para efetuar o pagamento: ");
                valorUser = this.scan.nextDouble();

                if (valorUser >= valor){

                    System.out.println("Pagamento efetuado com sucesso!");
                    System.out.println("Troco: R$ "+ (valorUser - valor));
                    comparador = true;
                }
                else {

                    System.out.println("Valor insuficiente, digite novamente.");

                }

            }

            return true;

        } 

    }

}