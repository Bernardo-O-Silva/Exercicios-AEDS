class Conhecido extends Pessoa {

    private String email;

    public Conhecido(){

        this.email = "UNDEFINED";

    }

    @Override
    public void setInfo(String info){

        this.email = info;

    }

    @Override
    public String getInfo(){

        return this.email;

    }

}