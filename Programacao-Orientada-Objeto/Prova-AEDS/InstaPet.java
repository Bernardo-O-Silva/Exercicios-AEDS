class InstaPet{

    private Usuario[] users = new Usuario[10];
    private int qtdUsuarios = 0;
    private boolean encontrou = false;
    private String aux;

    public void cadastra_usuario(String nome, String email){

        this.users[this.qtdUsuarios] = new Usuario();

        this.users[this.qtdUsuarios].setNome(nome);
        this.users[this.qtdUsuarios].setEmail(email);

        this.qtdUsuarios++;

    }

    public void cadastra_foto(String email, String link, String desc){

        for (int comparador = 0; comparador < this.qtdUsuarios; comparador++){

            this.aux = this.users[comparador].getEmail();

            if (this.aux.equals(email) == true){

                this.encontrou = true;
                this.users[comparador].cadastra_foto(link, desc);
                
            }

        }

        if (this.encontrou == false){

            System.out.println("Email não cadastrado");

        }

    }

    public int qnt_pets(String email){

        for (int comparador = 0; comparador < this.qtdUsuarios; comparador++){

            this.aux = this.users[comparador].getEmail();

            if (this.aux.equals(email) == true){

                return this.users[comparador].getQtdFotos();

            }

        }   
         
        System.out.println("Email não cadastrado");
        return -1;
    
    }

    public int qnt_usuarios(){

        return this.qtdUsuarios;

    }

    public Fotos[] listar_pets(String email){

        this.encontrou = false;

        Fotos[] fotosRetornar = new Fotos[10];

        for (int comparador = 0; comparador < this.qtdUsuarios; comparador++){

            this.aux = this.users[comparador].getEmail();

            if (this.aux.equals(email) == true){

                this.encontrou = true;
                fotosRetornar = this.users[comparador].getFoto();

            }

        } 

        if (this.encontrou == false){

            System.out.println("Email não cadastrado");
            fotosRetornar[0].setUrl("Erro");
            fotosRetornar[0].setDescricao("Erro");

        }
        
        return fotosRetornar;

    }

    public Usuario[] listar_usuarios(){

        return this.users;

    }

    public void altera_descricao(String email, int n, String desc){

        this.encontrou = false;

        for (int comparador = 0; comparador < this.qtdUsuarios; comparador++){

            this.aux = this.users[comparador].getEmail();

            if (this.aux.equals(email) == true){

                this.encontrou = true;
                this.users[comparador].altera_descricao(n, desc);

            }

        } 

        if (this.encontrou == false){

            System.out.println("Email não cadastrado");

        }

    }

}