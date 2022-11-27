class Atualiza {

    private double saldoTotal = 0.0;
    private double taxa;
    double saldo;

    public void pegaTaxa(double taxaRecebida) {
        
        this.taxa = taxaRecebida;

    }

    public void imprimeRelatorio(Conta contaRecebida) {

        System.out.println("--Dados da conta--");
        System.out.print("Saldo antes da atualização: ");
        contaRecebida.imprimeSaldoSimples();
        contaRecebida.atualizaSaldo(this.taxa);
        System.out.print("Saldo após atualização: ");
        contaRecebida.imprimeSaldoSimples();
        this.saldo = contaRecebida.getSaldo();
        this.saldoTotal += this.saldo;
        System.out.println("Saldo Total: " + this.saldoTotal);
        System.out.println("--------------");

    }

}