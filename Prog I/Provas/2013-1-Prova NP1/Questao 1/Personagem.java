/* b) podeUsarItem() - método pertencente à classe Personagem . Recebe como parâmetro uma String  que representa o nome de 
um Item . O método retorna true se o personagem possui, em seu vetor de itens, um  item cujo nome foi informado E se o 
personagem possui ouro suficiente para pagar pelo custo desse item a ser usado.  Ex.: se o personagem possui 10 de ouro e o 
custo do item é 5 , então o item pode ser usado. Se o personagem não possui  o item em questão ou não possui ouro suficiente, 
o método retorna false .			*/

class Personagem{
	public boolean podeUsarItem(Item[] itens){
		int cont = 0
		for(i = 1; i < item.lentgh;i++){
			if(i.getNome() == item && i.getValor() <= ouro){
				return true;
		    }
		}
		return false;

}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
/*class personagem{
    item[] itens;
    int ouro;
    public bool podeUsarItem(string str){
        for(int i = 0; i < itens.lenght(); i++){
            if(itens[i].nome == str && itens[i].custo < ouro){
                return true;
            }
        }
        return false;
    }
}		*/
