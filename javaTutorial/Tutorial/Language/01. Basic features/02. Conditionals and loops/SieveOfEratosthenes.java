public class SieveOfEratosthenes {
	public static void main(String[] args) {

		int N = Integer.parseInt(args[0]);
		boolean[] isPrime = new boolean[N + 1];

		for(int i = 2; i <= N; i++)
			isPrime[i] = true;

		for(int i = 2; i <= N; i++) 
			if(isPrime[i])
				for(int j = i + 1; j <= N; j++)
					if (j % i == 0)
						isPrime[j] = false;

		int count = 0;


		for(int i = 2; i <= N; i++)
			if(isPrime[i]) {
				//System.out.print(i + " ");
				count += 1;
			}


		//System.out.println();	
		System.out.println("Pi(" + N + ") = " + count);

		
	}
}