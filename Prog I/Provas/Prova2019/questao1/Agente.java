class Agente{

    public boolean isUsavel(){
        if(getPosicao().getX() > 0 &&
           getPosicao().getY() > 0 &&
           getVida() > 10 && peso >10){
               return true;
        }
        return false;
    }

    public boolean possuiItem(Item i){
        if(this.ferramenta.id == i.id &&
           this.ferramenta.volume == i.volume &&
           this.ferramenta.nome.equals(i.nome)){

            return true;
        }
        return false;
    }
}