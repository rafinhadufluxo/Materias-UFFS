class Posicao{
  private int x;
  private int y;
  
  public Posicao(int x, int y){
    this.x = x;
    this.y = y; 
  }
  public Posicao(){
  }
  
///////////////////////////////////////////////
class Entidade extends Posicao {
   private int vida;
   private Posicao posicao;
   
   public Entidade(int vida,x,y){
     this.vida = vida;
          super(x,y);
   }
   public Entidade(){
   }
     
//////////////////////////////////////////////////
class Personagem extends Entidade{
    private int ouro;
    private Item [] itens;
    
    public Personagem(int ouro, int vida){
      this.ouro = ouro;
      this.vida = vida;
    }
  
    public Personagem(int vida,ouro,x,y){
      this.ouro = ouro;
      super(x,y,vida);
      //this.x = x;
      //this.y = y;
      //this.id = id;
      //this.h = h;
    }
 }
