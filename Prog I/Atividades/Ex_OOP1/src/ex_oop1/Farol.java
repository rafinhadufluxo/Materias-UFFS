package ex_oop1;
import java.util.Scanner;
public class Farol {
    Scanner sc = new Scanner(System.in); 
    public boolean ligado;
    public boolean alerta;
    public int luz;
    public Farol(){
        this.ligado = false;
        this.alerta = false; 
    }
    public void LigarFarol(){
        if(ligado == true){
            System.out.printf("O farol esta ligado!\n");
        }
        else{
            System.out.printf("\nForca da luz: "); 
            luz = sc.nextInt();
            setLuz(luz);
            ligado = true;
        }
    }
    public void DesligarFarol(){
        if(ligado == false){
            System.out.printf("O farol esta  desligado!\n");
        }
        else{
            luz = 0;
            ligado = false;
            System.out.printf("Farol desligado\n");
        }
        
    }
    public void LigarAlerta(){
         if(alerta == true)   {
              System.out.printf("O Pisca Alerta esta ligado!\n");
         }
         else{
             alerta = true;
             System.out.printf("\n\nPisca Alerta foi ligado!\nSe estiver com problemas, busque ajuda e use a pista de emergencia.\n\n");
         }
    }
     public void DesligarAlerta(){
         if(alerta == false)   {
              System.out.printf("O Pisca Alerta esta desligado!\n");
         }
         else{
             alerta = false;
             System.out.printf("Pisca Alerta foi desligado!\n");
         }
    }
    public void getLuz(){
        System.out.printf("\n%d\n", this.luz);
        
    }
    public void setLuz(int luz){
        if(luz >= 0 && luz <= 10){
            this.luz = luz;
        }
        else{
            System.out.println("Forca de luz fora do padrao!\n");
            LigarFarol();
        }        
    }
}

