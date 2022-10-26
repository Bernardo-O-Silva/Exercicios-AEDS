class ContaCorrente extends Conta {

    @Override
    public void depositaSaldo(double valorDesejado){

        this.saldo += valorDesejado - 0.10;

    }

    @Override
    public void atualizaSaldo(double taxa) {

        this.saldo += this.saldo * (taxa * 2);

    }

}