class Gerenciador{

	public void analise(int n) throw ErroDivisaoZero, ErroNumeroMalInformado {
		if(n == 0){
			ErroDivisaoZero();
		}
		if( n == 5){
			ErroNumeroMalInformado();
		}
	}
}