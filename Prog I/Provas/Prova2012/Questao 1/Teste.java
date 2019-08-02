class Teste{
	private int var;
	
	public Teste(double var){
		this.var = (int) var;
	}

	public Teste(int var){
		this("hello");
	}

	public Teste(){
		System.out.println("good-bye");
	}

	public Teste(String s){
		this();
		System.out.println(s);
	}
}
