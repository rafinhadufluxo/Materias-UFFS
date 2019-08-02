class Main{
    public static void main(String[] args) {
        OrganizadorPosicao go = New OrganizadorPosicao();
        Quadrado q = new Quadrado();

        try{
            go.confina(q);
            //System.out.println("SHOWW");

        }catch (EPosicaoInvalida a ){
            System.out.println("Posicao invalida");
            
        }catch (EPosicaoForaQuadrantes b){
            System.out.println("Posicao fora do quadrante");

        }catch (EPosicaoAngular c){
            System.out.println("Posicao angular");

        }
        
    }
}