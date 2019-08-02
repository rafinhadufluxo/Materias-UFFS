import java.util.Scanner;
class MinhaException{
  public static void main(String[] args){

      try {
          MinhaMatematica m = new MinhaMatematica();
          Scanner s = new Scanner(System.in);

          System.out.print("informe A: ");
          int a = s.nextInt();
          System.out.print("informe B: ");
          int b = s.nextInt();

          m.setA(a);
          m.setB(b);
          System.out.println("Soma: " + m.soma(a,b));
          System.out.println("Multi: " + m.multiplica(a,b));
          System.out.println("Divide: " + m.divide(a,b));
          System.out.println("Subtrai: " + m.subtrai(a,b));

      }catch(Exception e) {
          System.out.println("Valores invalidos");
      }
  }
}
