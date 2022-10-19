import java.util.Scanner;

class Data {

    private int dia;
    private int mes;
    private int ano;
    private int resultado;
    Scanner scan = new Scanner(System.in);

    void setData() {

        System.out.print("Dia: ");
        this.dia = scan.nextInt();
        System.out.print("Mês: ");
        this.mes = scan.nextInt();
        System.out.print("Ano: ");
        this.ano = scan.nextInt();

        resultado = this.verificaData();

        if (resultado == 100) {

            this.setData();

        }

    }

    void mostraData(){

        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);

    }

    int verificaData(){

        if (this.dia < 1 || this.mes < 1 || this.ano < 1){

            System.out.println("\n*!ERRO: VALOR INSERIDO MUITO PEQUENO!*\n");
            return 100;

        }
        else if (this.dia > 31 || this.mes > 12){

            System.out.println("\n*!ERRO: VALOR INSERIDO MUITO GRANDE!*\n");
            return 100;

        }
        else if (this.mes == 4 || this.mes == 6 || this.mes == 9 || this.mes == 11){

            if (this.dia > 30){

                System.out.println("\n*!ERRO: O MÊS DIGITADO NÃO POSSUI MAIS DE 30 DIAS!*\n");
                return 100;

            }
            
        }        
        else if (this.mes == 2){

            if (this.ano % 4 == 0 || this.ano % 400 == 0){

                if (this.dia > 29){

                    System.out.println("\n*!ERRO: O MÊS DIGITADO NÃO POSSUI MAIS DE 29 DIAS (ANO BISSEXTO)!*\n");
                    return 100;

                }    

            }
            else {

                if (this.dia > 28){

                    System.out.println("\n*!ERRO: O MÊS DIGITADO NÃO POSSUI MAIS DE 28 DIAS (ANO NÃO BISSEXTO)!*\n");
                    return 100;

                }
                
            }

        }

        return 0;

    }

}