class Quadrado extends Forma implements Segmentavel {
    // resto do codigo da classe aqui...
    public Segmento[] getSegmentos() {
        Pontos[] ps = getPontos();
        Segmento[] n = new Segmento[4];
        n[0] = new Segmento(ps[0], ps[1]);
        n[1] = new Segmento(ps[1], ps[2]);
        n[2] = new Segmento(ps[2], ps[3]);
        n[3] = new Segmento(ps[3], ps[0]);
        
        return n;
    }
}