/*2)(2.5) Implemente a classe GerenciadorAlteracao . Essa classe é responsável por realizar 
operações de rotação e transformação em um conjunto de formas que estejam selecionadas na tela 
em um determinado instante. A classe possui dois métodos. O método transforma recebe um vetor de 
formas como parâmetro (esse vetor por ter qualquer forma da aplicação). Esse método percorre o 
vetor informado, rotacionando as formas que podem ser rotacionadas e encolhendo as formas que 
podem ser encolhidas. O método moveParaOrigemtambém recebe um vetor de formas e o percorre movendo 
todas essas formas para a posição (0,0) do plano (origem).              */

class GerenciadorAlteracao{

    public void transforma(Formas []formas){
        int i;
        for(i = 1; i < formas.length; i ++){
            if(formas[i] instanceof Rotacionavel){
                Rotacionavel r = (Rotacionavel) formas[i];
                r.rotaciona(3.14);
            }else if(formas[i] instanceof Transformavel){
                Transformavel t = (Transformavel) formas[i];
                t.transforma(0.5);
            }
        }
    }

    public void moveParaOrigemtambém(Formas [] formas){
        int i;
        for(i = 1; i < formas.length; i++){
            formas[i].setPosicao(new Ponto())
        }
    }
}