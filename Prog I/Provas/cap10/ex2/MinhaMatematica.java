class MinhaMatematica{
    private int a;
    private int b;

    public MinhaMatematica(){}
    public MinhaMatematica(int a,int b){
        this.a = a;
        this.b = b;
    }

    public int soma(int a, int b) throws Exception{
        if (b == 0 || a == 0){
            throw new Exception();
        }
        return this.getA() +this.getB();


    }
    public int subtrai(int a, int b)throws Exception{
        if (b == 0 || a == 0){
            throw new Exception();
        }
        return this.getA() - this.getB();


    }
    public int multiplica(int a, int b)throws Exception{
        if (b == 0 || a == 0){
            throw new Exception();
        }
        return this.getA() * this.getB();


    }
    public double divide(int a, int b)throws  Exception{
        if (b == 0 || a == 0){
            throw new Exception();
        }
        return this.getA() % this.getB();


    }
    public void setA(int a){
        this.a = a;
    }
    public void setB(int b){
        this.b = b;
    }
    public int getA(){
        return this.a;
    }

    public int getB(){
        return this.b;
    }
}
