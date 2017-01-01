public class CountingPrimes {
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);

		int count = 0;

		for(int i = 1; i <= n; i++) {
			boolean flag = true;
			for(int j = 2; j < i && flag; j++) {
				if (i % j == 0)
					flag = false;
			}
		}

		System.out.println(count);
	} 
	
}