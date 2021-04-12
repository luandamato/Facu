public class Empresa {

    private Empregado[] funcionarios = new Empregado[100];
    private int tamanho = 0;

    public Empresa (){

    }

    public int getTamanho(){
        return this.tamanho;
    }

    public int adiciona(Empregado emp){
        //verifica se lista ja esta cheia
        if (tamanho != funcionarios.length){
            if (buscaPorId(emp.getID()) == -1){
                funcionarios[tamanho] = emp;
                tamanho++;
                return 1;
            }else{
                return -1;
            }

        }else{
            return -2;
        }

    }

    public int busca(Empregado emp){
        //percorre a lista
        for (int i = 0; i < tamanho-1; i++){
            if (funcionarios[i].equals(emp)){
                //se for igual retorna o indice
                return i--;
            }
        }

        return -1;
    }

    public int buscaPorId(int id){
        //percorre a lista
        for (int i = 0; i < tamanho; i++){
            if (funcionarios[i].getID() == id){
                //se for igual retorna o indice
                return i--;
            }
        }
        return -1;
    }

    public int buscaPorNome(String nome){
        //percorre a lista
        for (int i = 0; i < tamanho-1; i++){
            if (funcionarios[i].getNome().equals(nome)){
                //se for igual retorna o indice
                return i--;
            }
        }

        return -1;
    }

    public int remove(int posicao){
        if (posicao > funcionarios.length -1){
            System.out.println("Posicao maior que tamanho do vetor");
            return -1;
        }else{
            //exclui o ponto
            funcionarios[posicao] = null;

            //faz os pontos à direita passar um para a esquerda (tampa o buraco)
            for (int i = posicao; i<tamanho -1; i++){
                funcionarios[i] = funcionarios[i+1];
            }
            if (tamanho > 0){
                funcionarios[tamanho-1] = null;
                tamanho--;
            }
            return 1;
        }
    }

    public String imprimeFunc(int i) {
        return funcionarios[i].toString();
    }

    public int addEstagiario(int ID, String nome, int departamento, double salario, double valecoxinha){
        Estagiario est = new Estagiario(ID, nome, departamento, salario, valecoxinha);
        return this.adiciona(est);
    }
    public int addEstagiario(Estagiario est){
        return this.adiciona(est);
    }

    public int addFuncionario(int ID, String nome, int departamento, double salario, double adicional){
        Funcionario func = new Funcionario(ID, nome, departamento, salario, adicional);
        return this.adiciona(func);
    }
    public int addFuncionario(Funcionario func){
        return this.adiciona(func);
    }

    public int addPresidente( int ID, String nome, int departamento, double salario){
        Presidente pres = new Presidente(ID, nome, departamento, salario);
        return this.adiciona(pres);
    }
    public int addPresidente(Presidente pres){
        return this.adiciona(pres);
    }

    public Double pagamento(int i){
        if (i > tamanho -1) {

            return -1.0;
        }
        return funcionarios[i].pagamento();
    }

    public boolean setAdicional(double adicional){
        for(int i = 0; i < this.tamanho; i++){
            try{
                funcionarios[i].setAdicional(adicional);
            }catch (NumberFormatException e){
                return false;
            }
        }
        return true;
    }


}
