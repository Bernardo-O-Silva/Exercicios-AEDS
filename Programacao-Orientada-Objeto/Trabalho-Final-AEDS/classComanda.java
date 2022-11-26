import java.util.ArrayList;

abstract class Comanda{
    private ArrayList<String> consumo = new ArrayList<String>();
    private double valor;

    public String getConsumo(int i) {
        return consumo.get(i);
    }
    
    public double getValor() {
        return valor;
    }

    public void setConsumo(String c) {
        consumo.add (c);
    }

    public void setValor(double v) {
        this.valor = this.valor + v;
    }

    public double calcular10porcento() {
        double porcent;
        porcent = this.valor / 10; 
        return porcent;
    }

    public double dividirConta(int quantd){
        double v_unit;
        v_unit = this.valor / quantd;
        return v_unit;
    }

    public void listarConsumo(){
        for(int i = 0; i < consumo.size(); i++){
        System.out.println(consumo.get(i));
        }
    }

}