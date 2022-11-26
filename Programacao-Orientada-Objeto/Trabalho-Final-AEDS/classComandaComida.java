import java.util.ArrayList;

 class ComandaComida extends Comanda
{
    private ArrayList<String> opcao = new ArrayList<String>();
    private ArrayList<Double> preco = new ArrayList<Double>();


    public ComandaComida(){

        this.Cardapio();

    }

    public String getOpcao(int i) {
        return opcao.get(i);
    }
    
    public double getPreco(int i) {
        return preco.get(i);
    }

    public void novaComida(String nome, double valor){
        opcao.add(opcao.size(), nome);
        preco.add(opcao.size(), valor);
     }

    public void Cardapio() {
        opcao.add (0, "Batata Frita");         preco.add(0, 7.90);
        opcao.add (1, "Prato Feito");          preco.add(1, 13.70);
        opcao.add (2, "Coxinha");              preco.add(2, 3.50);
        opcao.add (3, "Hamburguer");           preco.add(3, 8.50);
    }

    public void listaCardapio(){
        System.out.println("Num  |   Valor  |   Bebida");
        for(int i = 0; i < opcao.size(); i++){
            System.out.println(+ i + "    |   " + preco.get(i) + "    |   " + opcao.get(i));
        }
    }

    public int quantd_comidas(){
        return opcao.size();
    }

}