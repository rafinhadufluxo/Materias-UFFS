class Ferramenta {
	private String marca;

	public Ferramenta() {
		this.marca="Nenhuma";
	}
	public String getMarca() {
		return this.marca;
	} 
	
	public void setMarca(String s) {
	this.marca = s;
	} 

	public void ativar() {
		System.out.println("Ativada!");
	}
	public String getInfos() {
		return "Tool " + this.marca;
	}
	public void imprimeDesc() {
		System.out.print("M: "+ this.marca);
	}
}
