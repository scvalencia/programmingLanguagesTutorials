public class StdGaussian {
	// Generates random numbers using the Box-Muller formula 
	public static void main(String[] args) {
		double v = Math.random();
		double u = Math.random();
		double f = Math.sin(2 * Math.PI * v);
		double s = Math.pow((-2 * Math.log(u)), 0.5);
		System.out.println(f * s);
	}
}