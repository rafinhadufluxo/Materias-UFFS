class Basico{
  private int id;
  private String rotulos[];
  
  public Basico(int id, String rotulos[]){
    setId(id);
    setRotulos(rotulos); 
  }
  
///////////////////////////////////////////////
class Entidade extends Basico {
   public Entidade(int energia,x,y,id,h){
     setEnergia = energia;
     posicao.setX(x);
     posicao.setY(y);
     super(id,h);
   }
     
//////////////////////////////////////////////////
class Jogador extends Entidade{
  
    public Jogador(int vida,energia,x,y,id,h){
      setVida (vida);
      super(energia,x,y,id,h);
      //this.x = x;
      //this.y = y;
      //this.id = id;
      //this.h = h;
    }
 }
  
