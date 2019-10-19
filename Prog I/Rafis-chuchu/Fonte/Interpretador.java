import java.util.Scanner;

class Interpretador{

	private Pilha loop;
	private String temp;
	private Memoria mem;
	private int cont;
	private Alu solve;
	private Scanner s;	
	
	public Interpretador(){
		loop=new Pilha();
		mem = new Memoria();
		solve = new Alu();
		s=new Scanner(System.in);
	}

	private void imprime(String expressao){
		expressao=expressao.trim();
		String[] vars=expressao.split(">");
		for(int i=0; i<vars.length; i++){
			vars[i]=vars[i].trim();
			if(vars[i].charAt(0)=='\''){
				String[] temp=vars[i].split("\'");
				System.out.print(temp[1]);
			}else System.out.print(solve.leExpressao(vars[i], mem));
		}
		System.out.print("\n");
	}

	private int desvio(String[] cmd, int i, char inicio){
		int cont=0;		
		char fim='$';	

		if(inicio=='!')
			fim='¬';	
		for(i=i+1;i<cmd.length && cmd[i] != null;i++)
			if(cmd[i].charAt(0)==inicio)
				cont++;
			else if(cmd[i].charAt(0)==fim)
					if(cont==0)
						break;
					else
						cont--;
		return i;
	} 

	public boolean interpreta(String[] cmd){
		int i;
		char instrucao;
		String temp;
		
		//Elimina os espaços de todas as linhas e substitui pelos tokens
		for(i=0; i<cmd.length && cmd[i] != null; i++){
			cmd[i]=cmd[i].trim();
			cmd[i]=cmd[i].replace("end if","$");
			cmd[i]=cmd[i].replace("end while","¬");
			cmd[i]=cmd[i].replace("var","#");
			cmd[i]=cmd[i].replace("if","@");
			cmd[i]=cmd[i].replace("while","!");
			cmd[i]=cmd[i].replace("show","§");
			cmd[i]=cmd[i].replace("break","€");
			cmd[i]=cmd[i].replace("get",".");
		}

		for(i=0; i<cmd.length && cmd[i] != null; i++){
							
			//Retira o token e salva na instrucao
			instrucao=cmd[i].charAt(0);
			temp=cmd[i].substring(1);
			temp=temp.trim();

			switch(instrucao){
				case'#':
					//atualiza variavel
					String[] newvar=temp.split("=");
					double n = (newvar.length > 1)? solve.leExpressao(newvar[1], mem): 0;
					mem.atualizaVar(n, newvar[0].trim());
					break;
				case '§': 
					//imprime 
					this.imprime(temp);
					break;

				case '@': 
					//if
					if(solve.leIf(temp, mem)==false)
						i=desvio(cmd, i, instrucao);
					break;

				case '!': 
					//loop;
					if(solve.leIf(temp, mem)==true)
						loop.push(i);
					else
						i = this.desvio(cmd, i, instrucao);
					break;
			
				case '¬':
					//end loop;
					if(loop.vazio())				
						i=loop.topo()-1;
					loop.pop();
					break;
	
				case '€': 
					//break;
					i=desvio(cmd, i, '!');
					loop.pop();
					break;
				case '.':
					//scan
					double x = s.nextDouble();
					mem.atualizaVar(x, temp);
					break;
				case '$':
					//end if
					break;
				default: 
					System.out.println(" syntax error "+ (i+1));
					return false;
			}
		}	
	return true;
	}
}
