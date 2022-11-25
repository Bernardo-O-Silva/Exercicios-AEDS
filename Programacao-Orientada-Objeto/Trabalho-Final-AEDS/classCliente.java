class Cliente{
    private String nome;
    private String email;
    ComandaBebida bebida = new ComandaBebida(){};
    ComandaComida comida  = new ComandaComida(){};

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
    
    public void add_Bebida(String opcao,double preco){
       this.bebida.setConsumo(opcao);
       this.bebida.setValor(preco);
    }

    public void add_Comida(String opcao,double preco){
        this.comida.setConsumo(opcao);
        this.comida.setValor(preco);
     }

     public void setComanda(){
        this.comida.listarConsumo();
        this.bebida.listarConsumo();
     }
}