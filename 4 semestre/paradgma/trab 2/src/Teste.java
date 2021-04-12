public class Teste {

    public void testeEmpregado(){
        for (int i = 1; i < 11; i++){
            Empregado empregado = new Empregado(i,"Pedro", i%3, 550*i );
            System.out.println(empregado);
        }
    }

    public void testeEstagiario(){
        for (int i = 1; i < 11; i++){
            Estagiario estagiario = new Estagiario(i,"Carla", i%3, 300*i, i*3 );
            System.out.println(estagiario);
            System.out.println(estagiario.pagamento());
        }
    }

    public void testeFuncionario(){
        for (int i = 1; i < 11; i++){
            Funcionario funcionario = new Funcionario(i,"Joana", i%3, 550*i, i*3 );
            System.out.println(funcionario);
            System.out.println(funcionario.pagamento());
        }
    }

    public void testePresidente(){
        for (int i = 1; i < 11; i++){
            Presidente presidente = new Presidente(i,"Victor", i%3, 550*i );
            System.out.println(presidente);
            System.out.println(presidente.pagamento());
        }
    }

    public void testeEmpresa(){
        Empresa empresa = new Empresa();
        Estagiario estagiario = new Estagiario(1,"Carla", 2, 900, 45 );
        Funcionario funcionario = new Funcionario(2,"Joana", 3, 5500, 1 );
        Presidente presidente = new Presidente(3,"Victor", 1, 9000 );
        Funcionario funcionario1 = new Funcionario(1,"Joana", 3, 5500, 200 );

        empresa.addEstagiario(estagiario);
        empresa.addFuncionario(funcionario);
        empresa.addPresidente(presidente);
        empresa.adiciona(funcionario1);

        empresa.imprimeFunc(1);

        System.out.println(empresa.pagamento(1));
        System.out.println(empresa.pagamento(2));
        System.out.println(empresa.pagamento(0));
    }



}
