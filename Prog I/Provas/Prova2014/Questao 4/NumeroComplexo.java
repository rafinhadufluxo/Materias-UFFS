class NumeroComplexo{
  private int a;
  private int b;
  
  public NumeroComplexo(int a,int b){
    //this.a = a;
   // this.b = b;
    setA(a);
    setB(b);
  }
  
  public NumeroComplexo soma(NumeroComplexo z){
    return new NumerComplexo(this.getA() + z.getA(), this.getB + z.getB());
  }
  public NumeroComplexo subtrai(NumeroCompelxo z){
    return new NumerComplexo(this.getA() - z.getA(), this.getB - z.getB());
  }
  
  public int getB(){
    return this.b; 
  }
  
  public int getA(){
    return this.a; 
  }
  
  public void setA(int a){
    this.a = a;
  }
  
  public void setB(int b){
    this.b = b;
  }
}
