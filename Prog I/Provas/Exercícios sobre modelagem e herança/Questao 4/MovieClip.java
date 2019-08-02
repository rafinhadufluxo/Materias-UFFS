class MovieClip extends Sprite {
    private float alpha;
    
    public MovieClip(float h) {
        super(10, 22);
        alpha = h;
        setX(12);
    }

    public void negativo() {
        inverte();
        alpha = 0;
        System.out.println("Negativo!");
    }
    public String resumo() {
        return "Movie: " + super.resumo();
    }

    public void imprime() {
        System.out.println(resumo() + " " + alpha);
    }
}