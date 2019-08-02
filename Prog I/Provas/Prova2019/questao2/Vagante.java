class Vagante extends Agente{

    public void setFerramenta(Item i){
        if(i.nome.charAt(0) == "F" &&
           i.volume == 0 &&
           i.id == 0){

            return true;
           }
        super.setFerramenta();

    }

    public void setVida( int v){
        super.setVida(v);
        peso = v * 2;
    }

    public int getVida(){
        if(this.feerramenta.nome.equals("Amuleto")){
            return super.getVida() * 2;

        }
        
        return super.getVida();
        
    }
}