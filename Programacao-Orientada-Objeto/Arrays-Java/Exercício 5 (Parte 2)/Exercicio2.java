import java.util.Scanner;

class Exercicio2 {

    private int[] numeros = new int[10];
    private int[][] tabelaAparicao = new int[10][2];
    private int qtdMaisAparecida = 0;
    private int numMaisAparecido;
    private boolean ultimoNumJaAntigo = true;
    private int qtdNovos = 0;
    private int soma = 0;
    private double media = 0.0;
    private double mediana;
    private int moda;
    private int divisaoDoTotal;
    Scanner scan = new Scanner(System.in);

    Exercicio2(){

        this.setNumeros();
        this.calculaModa();
        this.calculaMedia();
        this.calculaMediana();

    }

    public void setNumeros() {
        
        for (int comparador = 0; comparador < this.numeros.length; comparador++){

            comparador++;
            System.out.print("Digite o " + comparador + "º número: ");
            comparador--;
            this.numeros[comparador] = scan.nextInt();

            if (comparador == 0){

                this.tabelaAparicao[comparador][0] = this.numeros[comparador];
                this.tabelaAparicao[comparador][1] = 1;
                this.qtdNovos++;

            }
            else if (comparador > 0){


                for (int comparador2 = 0; comparador2 < this.qtdNovos; comparador2++){

                    if (this.numeros[comparador] == this.tabelaAparicao[comparador2][0]){

                        this.tabelaAparicao[comparador2][1]++;
                        this.ultimoNumJaAntigo = true;
                        break;

                    }
                    else {
                
                        this.ultimoNumJaAntigo = false;

                    }

                }

                if (this.ultimoNumJaAntigo == false){

                    this.tabelaAparicao[this.qtdNovos][0] = this.numeros[comparador];
                    this.tabelaAparicao[this.qtdNovos][1] = 1;

                    this.qtdNovos++;

                }

            }

        }

    }

    public void calculaModa(){

        for (int comparador = 0; comparador < this.qtdNovos; comparador++){

            if (this.qtdMaisAparecida < this.tabelaAparicao[comparador][1]){

                this.numMaisAparecido = this.tabelaAparicao[comparador][0];
                this.qtdMaisAparecida = this.tabelaAparicao[comparador][1];

            }

        }

        this.moda = this.numMaisAparecido;        

    }

    public void calculaMedia(){

        for (int comparador = 0; comparador < this.numeros.length; comparador++){

            this.soma = this.soma + this.numeros[comparador];

        }

        this.media = (this.soma * 1.0) / this.numeros.length;

    }

    public void calculaMediana(){

        if (this.numeros.length % 2 != 0){

            this.divisaoDoTotal = this.numeros.length / 2;

            this.mediana = this.numeros[this.divisaoDoTotal];

        }
        else {

            this.divisaoDoTotal = this.numeros.length / 2;

            this.mediana = ((this.numeros[this.divisaoDoTotal - 1] + this.numeros[this.divisaoDoTotal]) / 2) * 1.0;

        }
        
    }

    public void imprimeResultados(){

        System.out.println("Média: " + this.media);
        System.out.println("Moda: " + this.moda);
        System.out.println("Mediana: " + this.mediana);

    }

}