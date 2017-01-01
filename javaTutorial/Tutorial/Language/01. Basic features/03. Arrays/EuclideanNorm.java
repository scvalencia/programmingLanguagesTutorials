public class EuclideanNorm {
	public static void main(String[] args) {
		int N = 100;
		long[] a = new long[N];
		a[0] = 1;
		a[1] = 2;
		for(int i = 2; i < N; i++)
			a[i] = a[i-1] + a[i-2];

		for(int i = 0; i < N; i++)
			System.out.println(a[i]);

	}
	
}