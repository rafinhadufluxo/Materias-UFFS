class Main {
    public static void main(String args[]) {
    Sprite s = new Sprite(3,4);
    MovieClip m = new MovieClip(4.5f);
    MovieBlock b = new MovieBlock(3.14f);
    
    System.out.println("s.re = " + s.resumo());
    s.imprime();
    m.inverte();
    b.oi();
    b.outro();
    


    /*m.inverte();
    m.imprime();
    m.oi();
    b.imprime();
    b.negativo();
    b.outro();*/
    }
}
