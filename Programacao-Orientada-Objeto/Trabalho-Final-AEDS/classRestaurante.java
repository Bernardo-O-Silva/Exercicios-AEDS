class Restaurante {

    //Constantes
    private static final int NUM_MESAS = 10;
    
    //Variáveis
    private String nome;
    private String endereco;
    private Mesa[] mesas = new Mesa[this.NUM_MESAS];
    private boolean reservada = false;

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


}