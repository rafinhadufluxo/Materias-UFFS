class MovieBlock extends MovieClip {
    public MovieBlock(float h) {
        super(h);
        
    }
    public String resumo() {
        return "Block: resumo";
    }
    public void imprime() {
        super.imprime();
        System.out.println("Block " + getX());
    }
    public void inverte() {
        setX(900);
        System.out.println("b inverte");
    }
    public void fim() {
        System.out.println("block fim!");
    }
    public void setX(int i) {
        super.setX(i + 1);
        System.out.println("setX " + getX());
    }
}