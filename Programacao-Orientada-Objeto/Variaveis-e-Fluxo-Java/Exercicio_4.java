class Exercicio_4 {

    public static void main(String[] args){

        int fatorial, comparador, comparador2;

        for (comparador = 0; comparador < 10; comparador++){

            fatorial = 1;

            for (comparador2 = 0; comparador2 <= comparador; comparador2++){

                fatorial = fatorial * (comparador2 + 1);

            }

            System.out.println(fatorial);

        }

    }

}