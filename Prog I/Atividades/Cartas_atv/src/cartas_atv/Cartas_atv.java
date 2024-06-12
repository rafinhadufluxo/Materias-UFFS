package cartas_atv;
import java.util.Scanner;
public class Cartas_atv {

    public static void main(String[] args) {
        Baralho b = new Baralho();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Digite o numero de cartas a ser distribuidas: ");
        int num = sc.nextInt();
        b.embaralhar();
        
       Carta[] c = b.darCartas(num);
         System.out.printf("Cartas recebidas: \n");
       for(int i = 0; i< c.length; i++){
            System.out.println(c[i]);
        }
    }
   
}