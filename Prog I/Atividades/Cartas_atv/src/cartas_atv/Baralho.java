package cartas_atv;
import java.util.Random;

public class Baralho {
    private Carta cartas[]; 
    private int pCarta; //proxima carta
    public static final int  NUM_CARTA = 52; //total do baralho
    public static final int LIMITE_CARTA = 12; //carta po naipe
    
    public Baralho(){ //construtor
        this.cartas = new Carta[NUM_CARTA]; //cria o array
        this.pCarta = 0;
        criarBaralho();
        embaralhar();
    }
    
    private void criarBaralho(){
        String[] naipe = Carta.N;
        //cria o baralho inicial. 
        for(int i  = 0; i < 4;i++){ //<4
            for(int j = 0; j < Carta.LIMITE_CARTA; j++){ //<14
                if (!(j == 7 || j == 8)) {
                    if (j >= 9) {
                        cartas[((i * (Carta.LIMITE_CARTA - 2)) + (j - 2))] = new Carta(j + 1, naipe[i]); //+1 já que comeca em 0
                    } else {
                        //1 - 7
                        cartas[((i * (Carta.LIMITE_CARTA - 2)) + j)] = new Carta(j + 1, naipe[i]);
                    }
                }
            }
        }
    }
    public void embaralhar() {
        int a;
        Carta c;
        //gerador de números aleatórios
        Random random = new Random();
        for (int i = 0; i < cartas.length; i++){
            a = random.nextInt(NUM_CARTA);
            c = cartas[a];
            cartas[i] = cartas[a];
            cartas[a] = c;
        }
    }
    public Carta proxCarta(){
    Carta c = null;
    
    if(pCarta == NUM_CARTA){
        System.out.println("Valor fora do limite!\n");
    } 
    else{
        c = cartas[(pCarta++)]; 
    }
    return c;
}
    
    public Carta[] darCartas (int numCartas){
        
        try{
            Carta[] dist = new Carta[numCartas];
            for(int i = 0; i < numCartas; i++){
                dist[i] = proxCarta();
                if(dist == null || dist[i] == null){
                    dist[i] = proxCarta();
                }
           }
            return dist;
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Valor fora do limite!\n");
        }
         System.gc();
        return null;
    }
} 
        