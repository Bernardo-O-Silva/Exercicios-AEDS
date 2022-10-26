class Banco {

    private Conta[] contas = new Conta[15];
    private int qtdContasAdicionadas = 0;

    public void adicionaConta(Conta adicionar){

        this.contas[qtdContasAdicionadas] = adicionar;
        this.qtdContasAdicionadas++;

    }

    public Conta pegaConta(int contaDesejada){

        if (contaDesejada >= 0 && contaDesejada <= 15 - 1){

            return this.contas[contaDesejada];

        }
        else {

            System.out.println("A posição digitada não existe.\nA conta devolvida é a primeira.");
            return this.contas[0];

        }

    }

    public int totalDeContas(){

        return this.qtdContasAdicionadas;

    }

}