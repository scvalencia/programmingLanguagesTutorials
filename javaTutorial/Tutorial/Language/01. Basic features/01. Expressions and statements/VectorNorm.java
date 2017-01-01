public class VectorNorm {
	public static void main(String[] args) {
		double x = Double.parseDouble(args[0]);
		double y = Double.parseDouble(args[1]);

		double size = Math.sqrt(Math.pow(x, 2.0) + Math.pow(y, 2.0));
		System.out.println(size);
	}
}