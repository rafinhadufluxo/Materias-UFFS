class Post extends Autor{
	private String autor;
	private String texto;

	public Post(){
		super();
	}
	public void setTexto(String texto){
		this.texto = texto;
	}
	public String getTexto(){
		return this.texto;
	}
	public void setNome(String autor){
		this.autor = autor;
	}
	public String getNome(){
		return this.autor;
	}
	
	public void imprimeResumo(){
		
		//System.out.println(autor);
		System.out.println("\n" + " " + this.texto + " " + "\n");
	}
}



