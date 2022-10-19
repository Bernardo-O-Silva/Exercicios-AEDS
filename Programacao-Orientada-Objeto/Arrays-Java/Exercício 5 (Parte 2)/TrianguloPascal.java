class TrianguloPascal {

    private int[][] TrianguloPascal = new int[11][11];//10 linhas
    private int tamanhoTriangulo = 11;

    TrianguloPascal(){

        this.criaPascal();

    }

    private void criaPascal() {

        this.TrianguloPascal[0][0] = 1;
        this.TrianguloPascal[1][0] = 1;
        this.TrianguloPascal[1][1] = 1;

        for (int comparador = 2; comparador < this.tamanhoTriangulo; comparador++){

            for (int comparador2 = 0; comparador2 < comparador; comparador2++){

                if (comparador2 == 0 || comparador2 == comparador - 1){

                    this.TrianguloPascal[comparador][comparador2] = 1; 

                }
                else {

                    this.TrianguloPascal[comparador][comparador2] = this.TrianguloPascal[comparador - 1][comparador2 - 1] + this.TrianguloPascal[comparador - 1][comparador2];

                }

            }

        }

    }
    
    public void imprimePascal(){

        System.out.println("Triângulo de Pascal:");

        for (int comparador = 0; comparador < this.tamanhoTriangulo; comparador++){

            for (int comparador2 = 0; comparador2 < comparador; comparador2++){

                System.out.print(this.TrianguloPascal[comparador][comparador2] + " ");

            }

            System.out.print("\n");

        }

    }

}
