Class Inimigo{
    private int vida;

    public Inimigo(){
    }

    public void setVida(int v){
        this.vida = v;
    }

    public int getVida(){
        return this.vida;
    }

    public devoCombater(Inimigo v[]){
        int c = 0;
        for(i = 1; i < v.lentgh;i++){
            if(v[i].getEnergia()> this.getEnergia && 
            v[i]getPosicao().getX() == getPosicao().getX && 
            v[i].getPosicao().getY() == getPosicao(). getY())
        }
        if (c>=5)
            return true;

    }
}
