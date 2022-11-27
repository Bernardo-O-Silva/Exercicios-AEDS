import java.util.Scanner;

class Agenda {

    private static final int NUM_MAX = 100;
    private static final int INICIO = 0;

    private Pessoa[] contatos = new Pessoa[this.NUM_MAX];
    private int numAmigos = 0;
    private int numConhecidos = 0;
    private String aux;
    private int auxButInt;
    private int result;

    Scanner scan = new Scanner(System.in);

    public Agenda(int numGalerinha){

        for(int comparador = 0; comparador < numGalerinha; comparador++){

            this.result = 1 + (int)(Math.random() * 2);

            if (this.result == 1){

                this.contatos[comparador] = new Amigo();
                this.numAmigos++;

                this.contatos[comparador].setID(this.result);

            }
            else {

                this.contatos[comparador] = new Conhecido();
                this.numConhecidos++;

                this.contatos[comparador].setID(this.result);               

            }

        }

    }

    public int getNumAmigos(){

        return this.numAmigos;

    }

    public int getNumConhecidos(){

        return this.numConhecidos;

    }    

    public void addInformacoes(){

        System.out.println("Das "+ (this.numConhecidos + this.numAmigos) +" pessoas de sua agenda:\n"+ this.numAmigos +" são amigos;\n"+ this.numConhecidos +" são conhecidos;\n");

        System.out.println("-CADASTRO DE INFORMAÇÕES-\n");

        for(int comparador = 0; comparador < (this.numAmigos + this.numConhecidos); comparador++){

            if(this.contatos[comparador].getID() == 1){

                System.out.print("Digite o nome de seu(ua) amigo(a): ");
                this.aux = scan.nextLine();

                this.contatos[comparador].setNome(this.aux);

                System.out.print("Digite a idade de "+ this.contatos[comparador].getNome() +": ");
                this.auxButInt = scan.nextInt();

                this.contatos[comparador].setIdade(this.auxButInt);
                
                scan.nextLine();

                System.out.print("Digite a data do aniversário de "+ this.contatos[comparador].getNome() +": ");
                this.aux = scan.nextLine();
                
                this.contatos[comparador].setInfo(this.aux);


            }
            else {

                System.out.print("Digite o nome de seu(ua) conhecido(a): ");
                this.aux = scan.nextLine();

                this.contatos[comparador].setNome(this.aux);

                System.out.print("Digite a idade de "+ this.contatos[comparador].getNome() +": ");
                this.auxButInt = scan.nextInt();

                this.contatos[comparador].setIdade(this.auxButInt);

                scan.nextLine();

                System.out.print("Digite o endereço de email de "+ this.contatos[comparador].getNome() +": ");
                this.aux = scan.nextLine();

                this.contatos[comparador].setInfo(this.aux);

            }

        }

    }

    public void imprimeInformacoes(){ //Juntei o imprimeAniversario e o imprimeEmail

        System.out.println("-Lista de contatos-\n");

        for(int comparador = 0; comparador < (this.numAmigos + this.numConhecidos); comparador++){

            System.out.println("Contato "+ (comparador + 1) +":");
            System.out.println("Nome: "+ this.contatos[comparador].getNome());
            System.out.println("Idade: "+ this.contatos[comparador].getIdade());

            if (this.contatos[comparador].getID() == 1){

                System.out.print("Aniversário: ");
            
            }
            else {

                System.out.print("Email: ");

            }

            System.out.println(this.contatos[comparador].getInfo() +"\n");

        }

    }

}