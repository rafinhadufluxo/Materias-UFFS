package cartas_atv;

public class Carta {
    private int valor;  //1 a 9
    private String naipe; //espada, paus, ouros ou copas
    
    //constantes
    public static final String[] N = {"Espada", "Copas", "Ouros", "Paus"}; //4 naipes
    public static final int LIMITE_CARTA = 12;
    
    public Carta(int valor, String naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }   
    //sobrescrevendo o método toString
    @Override
    public String toString(){
        //se o valor da carta for >= a 10, ele receberá rainha, rei ou coringa. se não, receberá o valor aleatorio
        if(valor >= 10){
             String[] a = { "Rainha", "Coringa", "Rei"};
             int index = (int) (Math.random() * a.length);
             if(a[index] == "Coringa"){
                 return "Carta Coringa";
             }
             else{
             return "Carta " + a[index] + " de " + naipe;
             }
        } else{
               return "Carta " + valor + " de " + naipe;
        }
    }
}
