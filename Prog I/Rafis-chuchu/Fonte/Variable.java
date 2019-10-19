/*	Esta classe representa a estrutura de uma variável.
 	Só existem variaveis do tipo Double		*/

class Variable{
	private double valor;
	public String nome;

	public Variable(double x, String h){
		this.valor=x;
		this.nome=h;
	}
	
	public void set_valor(double x){
		this.valor=x;
	}

	public double get_valor(){
		return this.valor;
	}
}
