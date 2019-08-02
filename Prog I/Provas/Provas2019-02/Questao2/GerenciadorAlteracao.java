class GerenciadorAlteracao{

    public void Transforma(Formas [] forma){
        int i ;
        for(i = 1; i < forma.lenght; i ++){
            if(forma[i] instanceof Transformavel){
                Transformavel t = (Transformavel) forma[i];
                t.transforma(0.5);
            }
            else if( forma[i] instanceof Rotacionavel){
                Rotancionavel r = (Rotancionavel) forma[i];
                r.rotaciona(3.14);
            }
        }
    }

	public void MoveParaOrigem(formas [] forma){
		int i ;
		for(i = 1; i < forma.length; i++){
			formas[i].setPonto(newe Ponto());
		}
	}
}
