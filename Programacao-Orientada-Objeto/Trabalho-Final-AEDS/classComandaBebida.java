import java.util.ArrayList;

 class ComandaBebida extends Comanda
{
    private ArrayList<String> opcao = new ArrayList<String>();
    private ArrayList<Double> preco = new ArrayList<Double>();

    public ComandaBebida(){

        this.Cardapio();

    }

    public String getOpcao(int i) {
        return opcao.get(i);
    }
    
    public double getPreco(int i) {
        return preco.get(i);
    }

    public void Cardapio() {
        opcao.add (0, "Refrigerante");   preco.add(0, 5.90);
        opcao.add (1, "Agua");           preco.add(1, 1.90);
        opcao.add (2, "Suco Natural");   preco.add(2, 3.50);
        opcao.add (3, "Suco");           preco.add(3, 2.50);
    }

    public void novaBebida(String nome, double valor){
       opcao.add(opcao.size(), nome);
       preco.add(opcao.size(), valor);
    }

    public void listaCardapio(){
        System.out.println("Num  |   preco  |   Bebida");
        for(int i = 0; i < opcao.size(); i++){
            System.out.println(+ i + "    |   " + preco.get(i) + "    |   " + opcao.get(i));
        }
    }

    public int quantd_bebidas(){
        return opcao.size();
    }
}