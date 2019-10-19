//Operadores Matematicos de logica simples. 
class Alu{

		public double leExpressao(String expressao, Memoria mem){
		expressao=expressao.trim();
		String[] vars=expressao.split("\\*|\\+|\\-|%|/");
		double[] vec=new double[vars.length]; 
		int i, j;

		for(i=0; i<vars.length && vars[i]!=null; i++){
			vars[i]=vars[i].trim();
			if(mem.variavelExiste(vars[i]))
				vec[i]=mem.variavelView(vars[i]);
			else 
				try{
					vec[i]=Double.parseDouble(vars[i]);
				}catch(Exception e){
					vec[i]=0;
				}
		}

		double resultado=vec[0];
		for(i=0, j=1; i<expressao.length(); i++){
			if(expressao.charAt(i)=='+' || expressao.charAt(i)=='-' || expressao.charAt(i) == '%' || expressao.charAt(i)== '*' || expressao.charAt(i)=='/'){
				switch(expressao.charAt(i)){
					case '*': resultado*=vec[j];break;
					case '-': resultado-=vec[j];break;
					case '+': resultado+=vec[j];break;
					case '/': resultado/=vec[j];break;
					case '%': resultado%=vec[j];break;
				}
				j++;			
			}
		}	
		return resultado;
	}

	public boolean leIf(String expressao, Memoria mem){
		expressao=expressao.trim();
		String[] vars=expressao.split(">|<|&|!");
		double[] vec=new double[vars.length]; 
		int i;
		for(i=0; i<vars.length && vars[i]!=null; i++){
			vars[i]=vars[i].trim();
			if(mem.variavelExiste(vars[i]))
				vec[i]=mem.variavelView(vars[i]);
			else 
				vec[i]=this.leExpressao(vars[i], mem);
		}
		for(i=0; i<expressao.length(); i++){
			if(expressao.charAt(i)=='>' || expressao.charAt(i)=='<' || expressao.charAt(i) == '&' || expressao.charAt(i) == '!'){
				switch(expressao.charAt(i)){
					case '>': return (vec[0]>vec[1]);
					case '<': return (vec[0]<vec[1]);
					case '&': return (vec[0]==vec[1]);
					case '!': return (vec[0]!=vec[1]);
				}		
			}
		}	
		return false;
	}

}
