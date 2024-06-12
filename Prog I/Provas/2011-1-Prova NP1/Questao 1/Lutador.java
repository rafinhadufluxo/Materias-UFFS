class Lutador extends Atleta{
    private int numLutas;

    public Lutador(){

    }

    public void setNumlutas(int n){
        this.numLutas = n;
    }

    public int getNumlutas(){
        return this.numLutas;
    }

    public void DefinirCategoria(){
        super.setPeso();
    }
    
    public void  ImprimirExperiencia(){
        if (numLutas <= 10){
            System.out.println('Iniciante');
        }
        if (numLutas > 11 && numLutas < 20){
            System.out.println("Intermediario");
        }
        if (numLutas > 20){
            System.out.println('Experiente');
        }
    }
}