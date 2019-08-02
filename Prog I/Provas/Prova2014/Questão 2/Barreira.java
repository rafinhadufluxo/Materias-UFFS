class Barreira extends Inimigo{
    public int getVida() {
        return super.getVida() + getVelocidade().tamanho() + super.getEnergia();
    }
    public int getEnergia() {
        return super.getEnergia() / getPosicao().getX();
    }
        
}
