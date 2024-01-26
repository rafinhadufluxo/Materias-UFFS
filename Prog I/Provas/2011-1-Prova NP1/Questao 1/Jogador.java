class Jogador extends Atleta{
    private double altura;

    public void Jogador(){
    
    }

    public void setAltura(double altura){
        if( altura <  1.90){ 
            System.out.println("Levantador");
            this.altura = altura;
        }else{
            System.out.println('Atacante');
            this.altura = altura;
        }
        
    }

    public double getAltura(){
        return this.altura;
    }
    
    public void DefinirCategoria(){
        setAltura();
    }

}