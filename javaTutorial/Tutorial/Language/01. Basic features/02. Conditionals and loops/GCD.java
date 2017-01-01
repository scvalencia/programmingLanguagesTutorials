public class GCD {
	public static void main(String[] args) {
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);

		while(b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}

		System.out.println(a);
	}
}