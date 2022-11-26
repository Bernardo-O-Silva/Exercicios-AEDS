import java.util.Scanner;

class Cliente{
    Scanner scanf = new Scanner(System.in);

    private String nome;
    private String email;


    public String getEmail() {
        return email;
    }

    public String getNome() {
        return nome;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    
}