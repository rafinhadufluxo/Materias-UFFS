class MovieClip extends Sprite {
    private float alpha;
    
    public MovieClip(float h) {
        super(10, 22);
        alpha = h;
        setX(12);
    }
    public void negativo() {
        inverte();
        alpha = 2;
        System.out.println("Negativo!");
    }
    public String resumo() {
        return "Movie: " + super.resumo();
    }
    public void imprime() {
        //System.out.println(resumo() + " " + alpha);
        System.out.println("mimp: " + resumo() + " " + alpha);
    }
    public void fim() {
        System.out.println("movie fim");
    }
    public void outro() {
        fim();
        System.out.println("movie: " + alpha);
    }
}