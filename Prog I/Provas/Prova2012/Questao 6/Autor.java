class Autor{
	private String autor;
	private int id;
	
	public Autor(){
	}
	public Autor(String autor, int id){
		this.autor = autor;
		this.id = id;
	}
	
	public void setNome(String nome){
		this.autor = nome;
	}
	
	public String getNome(){
		return this.autor;

	}
	public void setId(int id){
		this.id = id;
	}

	public int getId(){
		return this.id;
	}
}
