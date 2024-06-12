/* A)reposicionaInativos() - método estático pertencente à classe Utils . Recebe como parâmetro um vetor de objetos 
Personagem ; percorre esse vetor alterando a posição x e y para ­1 e ­1 de todos todos os objetos cuja vida seja 
menor que zero, ou a posição x seja maior que 640 ou a posição y seja maior que 480 . O método não retorna valor.	*/

class Utils{
	public void reposicionaInativos(personagem v[]){
		for(i = 1; i < v.lentgh;i++){
		    if(v[i].getVida() < 0 && 
		    	v[i]getPosicao().getX() < 640 && 
		    	v[i].getPosicao().getY() > 480
			)
		}

}
