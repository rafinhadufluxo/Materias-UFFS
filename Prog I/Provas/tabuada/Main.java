import java.util.Scanner;
class Main{
	public static void main(String[] args){
		Tabuada t = new Tabuada();
		Scanner s = new Scanner(System.in);

		System.out.println("Informe a tabuada que deseja:");
		int num = s.nextInt();
		
		t.mult(num);

	}
}
