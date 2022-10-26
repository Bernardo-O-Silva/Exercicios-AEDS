import java.util.Scanner;

class TestaPet{

    public static void main(String[] args){

        InstaPet instapet = new InstaPet();
        boolean end = false;
        int seleciona;
        int usuariosForam = 0;
        int fotosForam = 0;
        Scanner scan = new Scanner(System.in);

        while (end != true){

            System.out.println(" ");

            System.out.println("Escolha o que fazer");
            System.out.println(" ");
            System.out.println("1 - Cadastrar Usuários");
            System.out.println("2 - Cadastrar Fotos");
            System.out.println("3 - Alterar Descrição de Foto");
            System.out.println("4 - Listar Quantidade de Pets");
            System.out.println("5 - Listar Quantidade de Usuários");
            System.out.println("6 - Listar Pets");
            System.out.println("7 - Listar Usuários");
            System.out.println("8 - Sair");
            System.out.println(" ");
            System.out.print("> ");
            seleciona = scan.nextInt();
            
            switch(seleciona) {
            case 1:

                int usuariosDesejados;
                String nome;
                String email;

                System.out.print("Digite a quantidade de usuários que deseja inserir agora (" + (10 - usuariosForam) + " espaços restantes): ");                
                usuariosDesejados = scan.nextInt();

                if (usuariosDesejados > 10 || (usuariosDesejados + usuariosForam) > 10){

                    System.out.println("Não há espaço suficiente!");
                    break;

                }
                else {

                    scan.nextLine();

                    for (int comparador = usuariosForam; comparador < usuariosDesejados + usuariosForam; comparador++){

                        System.out.print("Digite o nome do usuário: ");
                        nome = scan.nextLine();

                        System.out.print("Digite o email de " + nome + ": ");
                        email = scan.nextLine();

                        instapet.cadastra_usuario(nome, email);

                    }

                    usuariosForam += usuariosDesejados;

                }

                break;

            case 2:

                String link;
                String desc;
                int fotosDesejadas;

                scan.nextLine();

                System.out.print("Digite o email do usuário onde queira adicionar a foto: ");
                email = scan.nextLine();

                System.out.print("Digite a quantidade de fotos do usuário " + email +": ");
                fotosDesejadas = scan.nextInt();

                if (fotosDesejadas > 10 || (fotosDesejadas + fotosForam) > 10){

                    System.out.println("Não há espaço suficiente!");
                    break;

                }

                scan.nextLine();

                for (int comparador = fotosForam; comparador < fotosDesejadas + fotosForam; comparador++){

                    System.out.print("Coloque aqui o link da imagem " + (comparador + 1) + ": ");
                    link = scan.nextLine();                

                    System.out.print("Digite a descrição da foto: ");
                    desc = scan.nextLine();

                    instapet.cadastra_foto(email, link, desc);

                }

                fotosForam += fotosDesejadas;

                break;

            case 3:

                int numFt;

                scan.nextLine();

                System.out.print("Digite o email do usuário onde queira mudar a descrição da foto: ");
                email = scan.nextLine();

                System.out.print("Digite o número da foto cuja descrição você quer mudar: ");
                numFt = scan.nextInt();

                numFt = numFt - 1;

                scan.nextLine();

                System.out.print("Digite a nova descrição da foto: ");
                desc = scan.nextLine();

                instapet.altera_descricao(email, numFt, desc);

                break;

            case 4:
              
                int qtdPets;

                scan.nextLine();

                System.out.print("Digite o email do usuário onde queira saber a quantidade de seus pets: ");
                email = scan.nextLine();
              
                qtdPets = instapet.qnt_pets(email);

                System.out.println("Quantidade de pets: " + qtdPets);

                break;

            case 5:

                int qtdUsers;

                qtdUsers = instapet.qnt_usuarios();

                System.out.println("Há " + qtdUsers + " usuários cadastrados.");

                break;

            case 6:

                Fotos[] listaPets = new Fotos[10];

                scan.nextLine();

                System.out.print("Digite o email do usuário cujos pets você queira listar: ");
                email = scan.nextLine();

                listaPets = instapet.listar_pets(email);

                for (int comparador = 0; comparador < (instapet.qnt_pets(email)); comparador++){

                    listaPets[comparador].imprimeInfo();

                }

                break;

            case 7:

                Usuario[] users = new Usuario[10];

                scan.nextLine();

                users = instapet.listar_usuarios();

                for (int comparador = 0; comparador < (instapet.qnt_usuarios()); comparador++){

                    users[comparador].imprimeInfo();

                }

                break;

            case 8:
                
                end = true;
                break;

            default:

                System.out.println("Erro.");
                break;
            
            }

        }

    }

}