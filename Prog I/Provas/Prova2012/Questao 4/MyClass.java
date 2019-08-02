class MyClass{
	public static void main(String[] args){
		double d = 2.7;
		Box b = new Box();
		b.doMinus(d);
		System.out.println(d);
		System.out.println(b.explain());
	}
}
