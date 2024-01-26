class Main{
	public static void main(String[]args){
		Ferramenta f = new Ferramenta();
		Martelo m = new Martelo();
		f.setMarca("Tramontina");
		m.setMarca("Black&Decker");
		
		System.out.println(f.getMarca());
		System.out.println(m.getMarca());
		f.ativar();
		System.out.println(m.getInfos());
		m.ativar();
		f.imprimeDesc();
		m.imprimeDesc();
	}
}
