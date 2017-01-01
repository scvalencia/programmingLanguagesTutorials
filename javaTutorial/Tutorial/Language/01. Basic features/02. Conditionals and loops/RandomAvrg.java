public class RandomAvrg {
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		double sum = 0.0;
		for(int i = 0; i < n; i++){
			double p = Math.random();
			System.out.print(p + " ");
			sum += p;
		}
		System.out.println();
		System.out.println(sum / (n + 0.0));
	}
}