class Funcionario {

    String nomeFn;
    String deptFn;
    double salarioFn;
    Data dataDeEntrada = new Data();

    void mostra() {

        System.out.println("Nome: " +this.nomeFn);
        System.out.println("Departamento: " +this.deptFn);
        System.out.println("Salário: R$ " +this.salarioFn);
        System.out.println("Data da Entrada: " +this.dataDeEntrada.dia+ "/" +this.dataDeEntrada.mes+ "/" +this.dataDeEntrada.ano);

    }

}