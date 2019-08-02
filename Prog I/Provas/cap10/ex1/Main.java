import java.util.Scanner;
class Main{
    public static void main(String[] args){
        
        try {
            Matematica m = new Matematica();
            Scanner s = new Scanner(System.in);

            System.out.print("informe A: ");
            int a = s.nextInt();
            System.out.print("informe B: ");
            int b = s.nextInt();

            m.setA(a);
            m.setB(b);
            System.out.println(m.soma(a,b));
            
        }catch(Exception e) {
            System.out.println("Valores invalidos");
        }   
    }
}   
       
        
        

   