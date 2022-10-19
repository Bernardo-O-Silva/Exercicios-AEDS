import java.util.Scanner;

class Casa {

    private String cor;
    private int totalDePortas = 3;
    private int qtdPortas = 0;
    private int qtdAbertas = 0;
    private Porta[] portas = new Porta[3];
    private boolean estadoPorta;
    Scanner scan = new Scanner(System.in);

    public void pinta(){

        System.out.print("Digite a cor que deseja pintar a casa: ");
        this.cor = scan.nextLine();

    }

    public void adicionaPorta(Porta p){

        portas[qtdPortas] = p;

        qtdPortas++;

    }

    public int totalDePortas(){
        
        return totalDePortas;

    }

    public void qtdPortasAbertas(){

        for (int comparador = 0; comparador < this.portas.length; comparador++){

            estadoPorta = portas[comparador].getEstado();

            if (estadoPorta == true){

                qtdAbertas++;

            }

        }

        System.out.println("Quantidade de portas abertas: " + this.qtdAbertas);

    }

    public void mostraCasa(){

        System.out.println("Casa:");
        System.out.println("-Atributos-");
        System.out.println("Cor: " + this.cor);
        this.totalDePortas = this.totalDePortas();
        System.out.println("Total de portas: " + this.totalDePortas);
        this.qtdPortasAbertas();
        
        for (int comparador = 0; comparador < this.portas.length; comparador++){

            estadoPorta = portas[comparador].getEstado();

            if (estadoPorta == true){

                comparador++;

                System.out.println("Porta " + comparador + ": Aberta");

                comparador--;

            }
            else {

                comparador++;

                System.out.println("Porta " + comparador + ": Fechada");

                comparador--;

            }

        }

    }

}