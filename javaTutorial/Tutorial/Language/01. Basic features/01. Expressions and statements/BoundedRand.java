public class BoundedRand {
	public static void main(String args[]) {
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);

		double p = Math.random();

		int n = (int) (p * (b - a)) + a;
		System.out.println(n); 
	}
}