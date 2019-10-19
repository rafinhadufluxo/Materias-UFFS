/* 	Acadêmica: Rafaelle Arruda
	
	Trabalho da NP2, a pedido do Profº Fernando. Entretanto ela está sujeita a alterações pelo professor.
	
*/


import java.util.Scanner;
import java.io.File;

class Chuchu{
    public static void main(String args[]) {
        File f;
        Scanner s;
        Interpretador b;
        String linhas[] = new String[2000]; // arquivo pode ter, no máximo, 2000 linhas.

         try {
            // Referencia o arquivo. args[0] conterá os dados passados pela linha de comando.
            f = new File(args[0]);
            // Mandamos o Scanner ler a partir do arquivo.
            s = new Scanner(f);
            // Instanciamos o interpretador.
            b = new Interpretador();

            /* Lemos todas as linhas do arquivo para dentro do
             vetor "linhas".*/
            int i = 0;
            while(s.hasNext()) {
                linhas[i] = s.nextLine();
                i++;
            }

            /*	Inicializamos o interpretador com o vetor de linhas. A partir
            	desse ponto, o objeto "b" irá interpretar o código lido do arquivo.		*/
		 
            b.interpreta(linhas);
            
        }catch (Exception e) {
            System.out.println("Nao consegui ler o arquivo: " + (args.length > 0 ? args[0] : "(desconhecido)"));
            System.out.println("Uso: ");
            System.out.println("    java Rafis /caminho/para/arquivo.chuchu");
        }
	}
}
