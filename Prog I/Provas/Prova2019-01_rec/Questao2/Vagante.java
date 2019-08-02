class Vagante{

    public void setFerramenta(Item i){
        if(i.setFerramenta().nome.charAt(0) == "nenhum" ||
           i.setFerramenta().id == 0 ||
           i.setFerramenta().volume == 0){
               
            super.setFerramenta(i);
        }
    }

    public void setPeso(Item i){
        if(getPosicao().getX() == getFerramenta().getVolume() &&
           getPosicao().getY() == getFerramenta().getVolume() &&
           getPosicao().setX (getFerramenta().getVolume())
    }

    public void getVida(Item i ){
        if(i).getFerramenta.id == 20){
            return super.getVida * 2;
        }
    }
}