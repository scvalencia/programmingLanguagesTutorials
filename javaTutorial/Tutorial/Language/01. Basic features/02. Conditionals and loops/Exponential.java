public class Exponential {
	public static void main(String[] args) {

		int limit = Integer.parseInt(args[0]);

		double sum = 0.0;
		double term = 1.0;

		for(int i = 0; sum != sum + term; i++) {

			sum += term;
			term = 1.0;
			for(int j = 1; j <= limit; j++) {
				term *= limit / j;
			}

		}

		System.out.println(sum);
	}
}