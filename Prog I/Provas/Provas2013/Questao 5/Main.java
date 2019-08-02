class Main {
  public static void main(String args[]) {
    Sprite s = new Sprite(1, 2);
    MovieClip m = new MovieClip(5.5f);
    MovieBlock b = new MovieBlock(7.3f);
    s.resumo();
    s.inverte();
    s.imprime();
    m.imprime();
    m.negativo();
    m.resumo();
    m.inverte();
    System.out.println("b.x = " + b.getX());
    b.imprime();
    b.negativo();
    b.imprime();
  }
}
