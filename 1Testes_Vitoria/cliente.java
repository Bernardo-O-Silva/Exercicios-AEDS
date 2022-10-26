/*
Crie uma classe Cliente, considerando que esta deva possuir :
    Construtor : O Construtor da classe deve possuir como parâmetro somente o código do Cliente.
        Atributos:
        • Código do Cliente
        • Nome Completo
        Métodos:
        • Inserção do nome do cliente
        • Retorna do nome do cliente
        • Retorna Código do Cliente
Crie um programa que instancie dois objetos Cliente, atribua o valor ao atributo Nome
do Cliente. Antes e após a atribuição, imprima o Nome do Cliente utilizando a função de
retorno.
*/

class Cliente{

    String nome;
    int codCliente;

    public void inserirNome(){
        this.nome = nome;
    }

    public String retornaNome(){
        return nome;
    }

    public int retornaCod(){
        return codCliente;
    }

    public Cliente(int codCliente){
        
        this.codCliente = codCliente;

    }  
}