package ex_oop1;

public class Vidro {
    private int posicao;
    public boolean aberto;
    
    public Vidro(){
        this.posicao = 10;
        this.aberto = false;
    }
    public Vidro(int posicao, boolean aberto){
        this.posicao = posicao;
        this.aberto = aberto;
    }
    
    public void baixarVidro(){
        if(posicao > 0){
            posicao -= 2;
        }
        else{
            System.out.println("Vidro ja esta aberto!\n");
        }
        aberto = true;
    }
    public void subirVidro(){
        if(posicao >= 10){
            aberto = false;
            System.out.println("Vidro ja esta fechado!\n");
        }
        else{
            posicao += 2;
        }
    }
    public int getPosicao(){
        return posicao;
    }
    public void setPosicao(int pos){
        if(pos >= 0 && pos <= 10){
            this.posicao = pos;
        }
        else{
            System.out.println("Posicao fora dos limites permitidos!\n");
        }
    }
}