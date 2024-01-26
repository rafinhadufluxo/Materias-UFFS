
class Martelo extends Ferramenta {
	public Martelo() {
		super();
	}
	public void ativar() {
		super.ativar();
		System.out.println("Martelando!");
	
	} 
	public void imprimeDesc() {
		System.out.print(getMarca() + " mar.");
	}
}
