public class Quadratic {
	public static void main(String[] args) {
		double a = Double.parseDouble(args[0]);
		double b = Double.parseDouble(args[1]);
		double c = Double.parseDouble(args[2]);

		double discriminant = b * b - (4 * a * c);
		if (discriminant > 0.0) {
			double firstX = (- b + Math.sqrt(discriminant)) / (2 * a);
			double secndX = (- b - Math.sqrt(discriminant)) / (2 * a);
			System.out.println(firstX);
			System.out.println(secndX);
		}
		else 
			System.out.println("No real roots");

	}
}
