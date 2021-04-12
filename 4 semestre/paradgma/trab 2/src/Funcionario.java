import java.util.Objects;

public class Funcionario extends Empregado{
    private double previdencia, adicional;

    public Funcionario(int ID, String nome, int departamento, double salario, double adicional){
        super(ID, nome, departamento, salario);
        this.previdencia = 0.05;
        this.adicional = adicional;
    }
    public void setAdicional( double novo_percentual ){
        this.adicional = adicional*(1+adicional);
    }

    public double pagamento(){
        // Calcula o salário líquido
        return(super.getSalario()*((1- this.previdencia)+ this.adicional));
    }

    public String toString(){
        return  "Funcionario: " + super.toString() +
                ", adicional=" + this.adicional +
                ", previdencia=" + this.previdencia;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Funcionario that = (Funcionario) o;
        return Double.compare(that.previdencia, previdencia) == 0 &&
                Double.compare(that.adicional, adicional) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(previdencia, adicional);
    }
}
