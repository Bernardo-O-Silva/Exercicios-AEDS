abstract class Pessoa {

    protected String nome;
    protected int idade;
    protected int identificacao;

    public Pessoa(String nome, int idade){

        this.nome = nome;
        this.idade = idade;

    }
    
    public Pessoa(){

        this.nome = "UNDEFINED";
        this.idade = 0;

    }

    public void setNome(String nome){

        this.nome = nome;

    }

    public String getNome(){

        return this.nome;

    }

    public void setIdade(int idade){

        this.idade = idade;

    }

    public int getIdade(){

        return this.idade;

    }

    public void setID(int ID){

        this.identificacao = ID;

    }

    public int getID(){

        return this.identificacao;

    }

    public abstract void setInfo(String info);

    public abstract String getInfo();

}