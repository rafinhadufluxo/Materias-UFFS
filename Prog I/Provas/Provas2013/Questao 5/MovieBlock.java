class MovieBlock extends MovieClip {
  public MovieBlock(float h) {
    super(h);
    setX(40);
  }
  public String resumo() {
    return "Block: " + super.resumo();
  }
  public void imprime() {
    super.imprime();
    System.out.println("Block "+getX());
  }
  public void inverte() {
    setX(900);
    System.out.println("b inverte");
  }
}
