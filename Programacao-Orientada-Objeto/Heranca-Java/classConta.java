class Conta {

    protected double saldo = 0.0;

    public void depositaSaldo(double valorDesejado) {
        
        this.saldo += valorDesejado;

    }

    public void retiraSaldo(double valorDesejado) {

        if (valorDesejado <= this.saldo){

            this.saldo -= valorDesejado;

        }
        else {

            System.out.println("O valor digitado é maior do que o saldo existente.");

        }

    }

    public void atualizaSaldo(double taxa){

        this.saldo += this.saldo * taxa;

    }

    public double getSaldo(){

        return this.saldo;

    }

    public void imprimeSaldoSimples() {

        System.out.print(this.saldo + "\n");

    }

}