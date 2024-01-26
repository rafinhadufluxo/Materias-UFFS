class Box{
	public double d;
	public int i;

	public void doMinus(double d){
		d = d - 10;
		i = 9;
	}

	public String explain(){
		return "Box: " + this.i + " " + this.d;
	}
}
