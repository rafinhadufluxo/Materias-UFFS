/*  b) Inimigo achaAlvoMaisProximo(Inimigo i[])- método pertencente à classe Inimigo. O método itera no
vetor de inimigos recebido como parâmetro, retornando o inimigo cujas componentes x,y da posição E as
componentes a,b da velocidade sejam iguais aos do objeto que invocou o método    */

class Inimigo{
    private int vida;

    public Inimigo(){

    }

    public int getVida(){
        return this.vida;
    }
    public void setVida(int v){
        this.vida = v;
    }

    public achaAlvoMaisProximo(Inimigo o[]){
        Inimigo inimigoProximo;
        for(i = 1; i < o.lentgh;i++){
            if(
                o[i].boid.getPosicao().getX() == this.boid.getPosicao().getX()
                && o[i].boid.getPosicao().getY() == this.boid.getPosicao().getY()
                && o[i].boid.forca().getA() == this.boid.forca().getA()
                && o[i].boid.forca().getB() == this.boid.forca().getB()
            ) {
                inimigoProximo = o[i];
            }
        }
        

    }
    
}
