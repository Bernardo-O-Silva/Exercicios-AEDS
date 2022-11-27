class ContaPoupanca extends Conta {

    @Override
    public void atualizaSaldo(double taxa) {

        this.saldo += this.saldo * (taxa * 3);

    }

}