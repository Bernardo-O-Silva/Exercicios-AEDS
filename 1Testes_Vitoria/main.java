/*
Programa que instancia dois objetos Cliente, atribui o valor ao atributo Nome
do Cliente. Antes e após a atribuição, imprime o Nome do Cliente utilizando a função de
retorno.
*/

class Main{

        public static void main(String[] args){ 
    
        Cliente meuCliente1 = new Cliente(1234);
        Cliente meuCliente2 = new Cliente(4321);

        meuCliente1.nome = "Vitória Ellen Honorio";
        meuCliente2.nome = "Virgina Motta";
    
        meuCliente1.retornaNome();
        meuCliente1.retornaCod();

        meuCliente2.retornaNome();
        meuCliente2.retornaCod();
    }
}