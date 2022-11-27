import java.util.Scanner;

class Amigo extends Pessoa{

    private String aniversario;
    private boolean repetir = true;

    Scanner scan = new Scanner(System.in);

    public Amigo(){

        this.aniversario = "01/01/1970";

    }

    @Override
    public void setInfo(String info){

        this.aniversario = info;

    }

    @Override
    public String getInfo(){

        return this.aniversario;

    }

}