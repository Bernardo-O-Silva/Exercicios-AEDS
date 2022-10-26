class Usuario{

    private String nome;
    private String email;
    private int qtdFotos = 0;
    private Fotos[] fotoUser = new Fotos[10];

    public void setNome(String name){

        this.nome = name;

    }

    public void setEmail(String addr){

        this.email = addr;

    }

    public String getNome(){

        return this.nome;

    }

    public String getEmail(){

        return this.email;

    }

    public void cadastra_foto(String link, String desc){

        this.fotoUser[qtdFotos] = new Fotos();

        this.fotoUser[qtdFotos].setUrl(link);
        this.fotoUser[qtdFotos].setDescricao(desc);

        this.qtdFotos++;

    }

    public void altera_descricao(int n, String desc){

        this.fotoUser[n].setDescricao(desc);

    }

    public int getQtdFotos(){

        return this.qtdFotos;

    }

    public Fotos[] getFoto(){

        return this.fotoUser;

    }

    public void imprimeInfo(){

        System.out.println(nome + " - " + email);

    }

}