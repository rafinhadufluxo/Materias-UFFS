class Memoria{
	Variable[] array;
	private int last;

	public Memoria(){
		array=new Variable[1000];
		last = 0;	
	}

	public int atualizaVar(double x, String h){
		int i;
		for(i=0; i<last; i++){
			if((array[i].nome).equals(h)){
				array[i].set_valor(x);
				return 1;			
			}
		}
		array[i]=new Variable(x, h);
		last++;
		return 0;
	}

	public double variavelView(String h){
		int i;
		for(i=0; i<last;i++){
			if(array[i] != null && (array[i].nome).equals(h))
				return array[i].get_valor();
		}
		return 0;
	}

	public boolean variavelExiste(String h){
		int i;
		for(i=0; i<last; i++)
			if((array[i].nome).equals(h))
				return true;
		return false;
	}

}
