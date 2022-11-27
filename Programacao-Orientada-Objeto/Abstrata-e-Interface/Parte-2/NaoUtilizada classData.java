import java.util.Scanner;

class Data {

    private int dia;
    private int mes;
    private int ano;
    private boolean resultado;
    Scanner scan = new Scanner(System.in);

    public void setData(int dia, int mes, int ano) {

        this.dia = dia;

        this.mes = mes;

        this.ano = ano;

        this.resultado = this.verificaData();

        return this.resultado;

    }

    public void setDefault(){

        this.dia = 1;
        this.mes = 1;
        this.ano = 1970;

    }

    public void mostraData(){

        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);

    }

    public boolean verificaData(){

        if (this.dia < 1 || this.mes < 1 || this.ano < 1){

            System.out.println("\n*!ERRO: VALOR INSERIDO MUITO PEQUENO!*\n");
            return false;

        }
        else if (this.dia > 31 || this.mes > 12){

            System.out.println("\n*!ERRO: VALOR INSERIDO MUITO GRANDE!*\n");
            return false;

        }
        else if (this.mes == 4 || this.mes == 6 || this.mes == 9 || this.mes == 11){

            if (this.dia > 30){

                System.out.println("\n*!ERRO: O MÊS DIGITADO NÃO POSSUI MAIS DE 30 DIAS!*\n");
                return false;

            }
            
        }        
        else if (this.mes == 2){

            if (this.ano % 4 == 0 || this.ano % 400 == 0){

                if (this.dia > 29){

                    System.out.println("\n*!ERRO: O MÊS DIGITADO NÃO POSSUI MAIS DE 29 DIAS (ANO BISSEXTO)!*\n");
                    return false;

                }    

            }
            else {

                if (this.dia > 28){

                    System.out.println("\n*!ERRO: O MÊS DIGITADO NÃO POSSUI MAIS DE 28 DIAS (ANO NÃO BISSEXTO)!*\n");
                    return false;

                }
                
            }

        }

        return true;

    }

}