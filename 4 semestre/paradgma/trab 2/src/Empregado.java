public class Empregado {
    private int ID;
    private String nome;
    private int departamento;
    private double salario;

    public Empregado (int ID, String nome, int departamento, double salario){
        this.ID = ID;
        this.nome=nome;
        this.departamento= departamento;
        this.salario= salario;
    }

    public double getSalario() {
        return salario;
    }

    public double pagamento() {
        return salario;
    }

    public int getDepartamento() {
        return departamento;
    }

    public int getID() {
        return ID;
    }

    public String getNome() {
        return nome;
    }

    public void setAdicional(double novo_percentual){

    }

    @Override
    public String toString() {
        return  "ID=" + ID +
                ", nome='" + nome + '\'' +
                ", departamento=" + departamento +
                ", salario=" + salario;
    }
}
