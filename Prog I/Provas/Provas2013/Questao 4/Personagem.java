class Personagem extends Entidade{
  private int ouro;
  private Item [] item;
  
  public Personagem(int ouro, Item[]){
    this.ouro = ouro;
    this.Item = Item;
    this.super();// pega o que tem na entidade
    imprime();
  
  public Personagem imprime(){
    System.out.println(this.ouro);
    System.out.println(this.Item);
    //System.out.println(this.getVida);
    
  }
}
