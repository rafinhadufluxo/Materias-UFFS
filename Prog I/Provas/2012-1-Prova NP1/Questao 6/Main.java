import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Autor a = new Autor();
		Post p = new Post();
		Scanner s = new Scanner(System.in);

		System.out.print("informe o ID: ");
		int id = s.nextInt();

		System.out.print("Informe o autor: ");
		String autor = s.nextLine();
		
		s.nextLine();

		//Pode escrever sem dar enter, qnd terminar de escrever. Tecle o enter parceiro !
		System.out.print("Informe a frase : ");
		String texto = s.nextLine();

		a.setNome(autor);
		a.setId(id);
		p.setNome(autor);
		p.setTexto(texto);
		
		p.imprimeResumo();
	}
}
