class Fotos{

    private String url;
    private String descricao;

    public void setUrl(String link){

        this.url = link;

    }
    
    public void setDescricao(String desc){

        this.descricao = desc;

    }

    public String getUrl(){

        return this.url;

    }

    public String getDescricao(){

        return this.descricao;

    }

    public void imprimeInfo(){

        System.out.println(url + " - " + descricao);

    }


}