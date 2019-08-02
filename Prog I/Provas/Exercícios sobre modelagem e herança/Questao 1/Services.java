/* A)int contaPossiveisCandidatos(Inimigo i[])- método estático pertencente à classe Services(crie
essa classe também). Retorna o número de objetos do vetor que tenham: posição x ou y maiores que 100, 
energia menor ou igual a 50 e velocidade com tamanho igual a 200.  */

class Services{
    private int x;
    private int y;

    public int contaPossiveisCandidatos(Inimigo inimigos[]){
        int canditadosQualificados =0;
        lista_vetor = new Vetor();
        for(i = 0; i < inimigos.lenght ; i ++){
            Inimigo inimigoI = inimigos[i];
            if (
                inimigoI.posicao.getX() > 100
                && inimigoI.posicao.getY() > 100
                && inimigoI.boid.velocidade == 200
                && inimigoI.boid.energia <= 50
            ) {
                canditadosQualificados++;
            }
        }
        return canditadosQualificados;
    }
}
