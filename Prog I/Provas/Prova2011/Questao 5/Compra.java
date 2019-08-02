class Compra {
	private String nomeProduto;
	private double preco;
	private int quantidade;
	
	public Compra(){
  	}
	
	public Compra(String produto, float preco, int quantidade) {
		this.nomeProduto = produto;
		this.preco = preco;
		this.quantidade = quantidade;
	}

	public void setNomeProduto(String novo) {
		this.nomeProduto = novo;
	}

	public String getNomeProduto() {
		return this.nomeProduto;	
	}

	public void setPreco(double preco) {
    	this.preco = preco;
	}
 	public double getPreco() {
    	return this.preco;
	}
	
	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}

	public int getQuantidade() {
		return this.quantidade;
	}

	// Imprime todas as propriedades da classe
	public void imprimeResumo() {
		System.out.println(this.nomeProduto);
		System.out.println(this.preco);
		System.out.println(this.quantidade);
	}
}
