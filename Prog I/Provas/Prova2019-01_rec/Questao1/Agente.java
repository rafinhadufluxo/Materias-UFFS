class Agente{

    public boolean isUsavel(){
        
        if(getPosicao().getX () > && getPosicao().getY() > 0 && 
            getVida() > 0 && getPeso()> 10){
                return true;
            }
        return false;

    }
    public boolean contaItensIguais(Item []item){
        int count;
        for(i = 0; i < item.length; i ++){
            if(i.getFerramenta().getNome().equals(item[i].getNome()) &&
               i.getFerramenta().getId() == item[i].getId()){

                return count ++;
            }
        }
        
    }
}