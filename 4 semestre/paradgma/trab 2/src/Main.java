/*

Entrega de trabalho - Nome do trabalho

Eu,

Luan Rocha D'Amato - 31817051

todas as respostas são fruto de nosso próprio trabalho,
não copiamos respostas de colegas externos à equipe,
não disponibilizamos nossas respostas para colegas externos à equipe e
não realizamos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/


import org.w3c.dom.ls.LSOutput;
import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Teste teste = new Teste();
        Scanner s = new Scanner(System.in);
        Empresa empresa = new Empresa();


//        teste.testeEmpregado();
//        teste.testeEstagiario();
//        teste.testeFuncionario();
//        teste.testePresidente();
//        teste.testeEmpresa();

        int escolha;
        do{
           escolha = menu(s);

           switch (escolha){
               case 1:
                   addFunc(s, empresa);
                   break;
               case 2:
                   calcularPgamento(s, empresa);
                   break;
               case 3:
                   adicional(s, empresa);
                   break;
               case 4:
                   relatorio(empresa);
                   break;

           }
        }while (escolha !=5);

        System.out.println("Obrigado! \nEspero que tenha gostado :)");



    }

    private static String entradaString(Scanner s, String Mensagem){
       while (true) {
           System.out.print(Mensagem + ": ");
           String input = s.nextLine();

           try {
               return input;

           } catch (NumberFormatException e) {
               System.out.println("Por favor, digite algo.");
           }
       }
    }

    private static int entradaInt(Scanner s, String Mensagem){
        while (true) {
            System.out.print(Mensagem + ": ");
            String input = s.nextLine();

            try {
                return Integer.parseInt(input);

            } catch (NumberFormatException e) {
                System.out.println("Por favor, informe um número inteiro.");
            }
        }
    }

    private static Double entradaDouble(Scanner s, String Mensagem){
        while (true) {
            System.out.print(Mensagem + ": ");
            String input = s.nextLine();

            try {
                return Double.parseDouble(input);

            } catch (NumberFormatException e) {
                System.out.println("Por favor, informe um número.");
            }
        }
    }

    private static int menu(Scanner s){
        int escolha;
        do {
            System.out.println("\n \n \n");
            System.out.println("1. Adicionar um funcionário; ");
            System.out.println("2. Calcular pagamento do funcionário;");
            System.out.println("3. Aumentar o adicional de todos os funcionários;");
            System.out.println("4. Relatório dos funcionários da empresa;");
            System.out.println("5. Encerrar programa");
            escolha = entradaInt(s, "Sua opção");

            if (escolha<1 || escolha>5) {
                System.out.println("Escolha uma opcao entre 1 a 5: ");
            }
        } while(escolha<1 || escolha>5);
        return escolha;
    }

    private static void addFunc(Scanner s, Empresa empresa){
        int func;
        do{
            System.out.println("1 - Estagiario");
            System.out.println("2 - Funcionario");
            System.out.println("3 - Presidente");
            func = entradaInt(s, "Tipo de funcionario");
        }while (func<1 || func>3);

        int sucesso;
        if (func == 1){
            int id = entradaInt(s, "ID");
            String nome = entradaString(s, "Nome");
            int departamento = entradaInt(s, "Departamento");
            double salario = entradaDouble(s, "Salario");
            double valecoxinha = entradaDouble(s, "Vale Coxinha");
            Estagiario estagiario = new Estagiario(id, nome, departamento, salario, valecoxinha);
            sucesso = empresa.addEstagiario(estagiario);
        }else if (func == 2){
            int id = entradaInt(s, "ID");
            String nome = entradaString(s, "Nome");
            int departamento = entradaInt(s, "Departamento");
            double salario = entradaDouble(s, "Salario");
            double adicional = entradaDouble(s, "adicional");
            Funcionario funcionario = new Funcionario(id, nome, departamento, salario, adicional);
            sucesso = empresa.addFuncionario(funcionario);
        }else{
            int id = entradaInt(s, "ID");
            String nome = entradaString(s, "Nome");
            int departamento = entradaInt(s, "Departamento");
            double salario = entradaDouble(s, "Salario");
            Presidente presidente = new Presidente(id, nome, departamento, salario);
            sucesso = empresa.addPresidente(presidente);
        }

        if(sucesso == 1){
            System.out.println("Funcionario adicionado com sucesso");
        }else if(sucesso == -1){
            System.out.println("Já existe um funcionario com esse id");
        }else if (sucesso == -2){
            System.out.println("Não é possivel adicionar mais funcionarios");
        }
    }

    private static void calcularPgamento(Scanner s, Empresa empresa)
    {
        int tam = empresa.getTamanho();
        if (tam == 0){
            System.out.println("Empresa sem funcionarios");
            return;
        }
        int escolha;
        do{
            System.out.println("Deseja procurar pelo funcionario?(1-sim | 2-não)");
            escolha = entradaInt(s, "");
        }while (escolha != 1 && escolha != 2);

        if (escolha == 1){
            do{
                System.out.println("Por id ou por nome?(1-id | 2-nome)");
                escolha = entradaInt(s, "");
            }while (escolha != 1 && escolha != 2);

            if(escolha ==1){
                int indice = empresa.buscaPorId(entradaInt(s, "id do funcionario"));
                System.out.println("Indice:" + indice);
            }else{
                int indice = empresa.buscaPorNome(entradaString(s, "Nome do funcionario"));
                System.out.println("Indice:" + indice);
            }
        }

        double valor = empresa.pagamento(entradaInt(s, "Indice do funcionario"));

        if (valor == -1.0){
            do{
                System.out.println("Posicao maior que tamanho do vetor");
                valor = empresa.pagamento(entradaInt(s, "Indice do funcionario"));
            }while (valor == -1.0);
        }

        System.out.println("Valor:" + valor);

    }

    private static void relatorio(Empresa empresa){
        int tam = empresa.getTamanho();
        if (tam == 0){
            System.out.println("Empresa sem funcionarios");
            return;
        }
        for (int i = 0; i < tam; i++) {
            //percorre lista e imprime cada indice
            System.out.println(empresa.imprimeFunc(i));
        }
    }

    private static void adicional(Scanner s, Empresa empresa){
        int tam = empresa.getTamanho();
        if (tam == 0){
            System.out.println("Empresa sem funcionarios");
            return;
        }
        if(!empresa.setAdicional(entradaDouble(s, "Novo percentual do adicional"))){
            System.out.println("Algo deu errado");
        }else{
            System.out.println("Adicionais atualizados");
        }
    }
}
