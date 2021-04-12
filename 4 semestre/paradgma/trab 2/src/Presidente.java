import java.util.Objects;

public class Presidente extends Empregado {
    private double previdencia, adicional_whisky, adicional_helicoptero,
            adicional_adicional;

    public Presidente( int ID, String nome, int departamento, double salario){
        super(ID, nome, departamento, salario);
        this.previdencia=0.05;
        this.adicional_whisky=0.9;
        this.adicional_helicoptero=0.7;
        this.adicional_adicional=3.8;
    }

    public void setAdicional(double novo_percentual){
        adicional_whisky=0.9*(1+novo_percentual);
        adicional_helicoptero=0.7*(1+novo_percentual);
        adicional_adicional=3.8*(1+novo_percentual);
    }
    public double pagamento(){
        // Calcula o salário líquido
        return(super.getSalario()*((1-this.previdencia)+this.adicional_whisky+this.adicional_helicoptero + this.adicional_adicional));
    }

    public String toString(){
        return  "Presidente: " + super.toString() +
                ", adicional=" + this.adicional_adicional +
                ", helicoptero=" + this.adicional_helicoptero +
                ", whisky=" + this.adicional_whisky +
                ", previdencia=" + this.previdencia;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Presidente that = (Presidente) o;
        return Double.compare(that.previdencia, previdencia) == 0 &&
                Double.compare(that.adicional_whisky, adicional_whisky) == 0 &&
                Double.compare(that.adicional_helicoptero, adicional_helicoptero) == 0 &&
                Double.compare(that.adicional_adicional, adicional_adicional) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(previdencia, adicional_whisky, adicional_helicoptero, adicional_adicional);
    }
}
