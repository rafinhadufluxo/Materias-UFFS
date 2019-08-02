class Atleta{
    private double peso;
    private int idade;
    private String categoria;

    public Atleta(){}
    public Atleta(Double peso, int idade, String categoria){
        this.peso = peso;
        this.idade = idade;
        this.categoria = categoria;
    }
    public void setPeso(double peso){
        this.peso = peso;
    }

    public double getPeso(){
        return this.peso;
    }

    public void setIdade(int idade){
        if( idade <= 10){
            System.out.println('Infantil');
            return this.idade = idade;
        }
        if (idade > 11 && idade >= 18){
            System.out.println('Juvenil');
            return this.idade = idade
        }
        if (idade > 18){
            System.out.println("adulto");
            return this.idade;
        
        }
    }

    public int getIdade(){
        return this.idade;
    }
    public void setCategoria(String categoria){
        this.categoria = categoria;
    }
    public void getCategoria(){
        return this.categoria;
    }

    public void DefinirCategoria(){
        Idade();
        
    }
}