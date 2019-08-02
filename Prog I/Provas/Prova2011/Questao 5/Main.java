import java.util.Scanner;
class Main{
	public static void main(String[]args){
		Compra c = new Compra();
		Scanner s = new Scanner(System.in);

		System.out.print("Informe o produto: ");
		String produto = s.nextLine();

		System.out.print("Informe o valor: ");
		double preco = s.nextDouble();

		System.out.print("Informe a qntd: ");
		int quantidade = s.nextInt();

		c.setNomeProduto(produto);
		c.setPreco(preco);
		c.setQuantidade(quantidade);

		c.imprimeResumo();
	}
}
