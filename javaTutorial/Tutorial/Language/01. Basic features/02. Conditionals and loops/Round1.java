public class Round1 {
	public static void main(String[] args) {
		int pintura = Integer.parseInt(args[1]);
		int radio = Integer.parseInt(args[0]);
		int respuesta = 0;

		while(pintura - (Math.pow(radio + 1, 2) - Math.pow(radio, 2)) > 0) {
			pintura -= Math.pow(radio + 1, 2) - Math.pow(radio, 2);
			radio++;
			respuesta++;
		}

		System.out.println(respuesta);
	}
}