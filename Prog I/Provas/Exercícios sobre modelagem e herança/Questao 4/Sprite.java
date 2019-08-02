class Sprite {
    private int x;
    public int scaleY;
    
    public Sprite (int x, int s) {
        this.x = x;
        this.scaleY = s;
    }

    public int getX() {
        return this.x;
    }

    public void setX(int i) {
        this.x = i;
    }

    public void oi() {
        imprime();
        System.out.println("Soi");
    }

    public void inverte() {
        this.x = - this.scaleY;
        System.out.println("x = " + getX());
    }

    public String resumo() {
        return x + " " + scaleY;
    }

    public void imprime() {
        System.out.println(getX() + " " + scaleY);
    }
}