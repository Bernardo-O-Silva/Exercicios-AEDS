import java.util.Scanner;

class Porta {

    private boolean estado;
    Scanner scan = new Scanner(System.in);

    Porta(){

        System.out.print("Deseja abrir a porta? (True/False): ");
        estado = scan.nextBoolean();

    }

    public boolean getEstado(){

        return estado;

    }


}