import java.util.Objects;

public class Estagiario extends Empregado{
    private double valecoxinha;

    public Estagiario (int ID, String nome, int departamento, double salario, double valecoxinha){
        super(ID, nome, departamento, salario);
        this.valecoxinha = valecoxinha;
    }

    public void setValecoxinha( double valecoxinha ){
        this. valecoxinha = valecoxinha;
    }

    public double pagamento(){
        // Calcula o salário líquido
        return(this.getSalario()+this.valecoxinha);
    }

    public String toString(){
        return "Estagiario: " +super.toString() + ", vale coxinha=" + this.valecoxinha;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Estagiario that = (Estagiario) o;
        return Double.compare(that.valecoxinha, valecoxinha) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(valecoxinha);
    }
}
