/*3)(1.5) Implemente o código necessário para criar a classe OrganizadorPosicao . Essa classe possui 
um método chamado confina , que recebe como parâmetro uma forma. Esse método deve levantar uma exceção 
chamada EPosicaoInvalida se a posição x ou y da forma passada for negativa. O método levanta a exceção
EPosicaoForaQuadrantes e a soma da posição x e y da forma for maior que 300. Por fim, o método levanta 
a exceção EPosicaoAngular se a posição x for igual à posição yda forma. Faça um pequeno programa de 
teste  que instancie um OrganizadorPosicao e uma forma trapésio; o programa deve passar o objeto 
trapésio para  o método confina , pegando todas as exceções que podem ser levantadas (para cada 
exceção pega, imprima  na tela o nome dessa exceção).     */

class OrganizadorPosicao{

    public void confina(Forma f)throws EPosicaoInvalida, EPosicaoForaQuadrantes, EPosicaoAngular{
        if( getPosicao().getX() < 0 || getPosicao().getY() < 0){
            EPosicaoInvalida();

        }
        if(getPosicao().getX() > 300 || getPosicao().getY() > 300){
            EPosicaoForaQuadrantes();

        }
        if(getPosicao().getX() == getPosicao().getY() ){
            EPosicaoAngular();
        }

    }
}