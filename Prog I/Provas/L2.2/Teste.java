import java.util.Scanner;

class Teste{
    public static void main(String args[]) {
        Date d = new Date();
        Scanner s = new Scanner(System.in);

        System.out.print("Informe a hora: ");
        int hora = s.nextInt();

        System.out.print("Informe o minutos: ");
        int minutos = s.nextInt();

        System.out.print("Informe o segundos: ");
        int segundos = s.nextInt();

        d.setHora(hora);
        d.setMinutos(minutos);
        d.setSegundos(segundos);
    }
}


        