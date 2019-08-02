class Main {
    public static void main(String args[]) {
        Sprite s = new Sprite(1, 2);
        MovieClip m = new MovieClip(5.5f);
        MovieBlock b = new MovieBlock(7.3f);
        System.out.println(s.resumo());
        s.imprime();
        m.negativo();
        m.inverte();
        m.imprime();
        m.oi();
        System.out.println("b.x = " + b.getX());
        b.imprime();
        b.negativo();
    }
}