/* A) Implemente a classe Gerenciador, com o método analisa(). Se a string passada como parâmetro possuir
tamanho igual a zero, o método levanta a exceção TokenDesconhecido;se a string possuir tamanho igual a 5, o
método levanta a exceção ComandoMalFormado. Para todos os outros casos, o método não levanda exceção alguma */

class Gerenciador{

    public boolean analise(String s){
        if(s.length() == 0){
            TokenDesconhecido(s);
        }
        if (s.length >= 5){
            ComandoMalFormado(s);
        }

    }
}
