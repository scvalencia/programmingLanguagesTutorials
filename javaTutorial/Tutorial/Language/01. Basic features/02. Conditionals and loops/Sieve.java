public class Sieve
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		int prime = 0;
		boolean[] A = new boolean[N+1];
		for(int i = 0; i < N; i++) A[i] = true;

		for(int i = 2; i <= N/i; i++)
		{
			if(A[i])
			{
				for(int j = i; j <= N/i; j++) A[i * j] = false;
			}
		}
		for(int i = 2; i < N; i++)
		{
			if(A[i]) prime++;
		}
		System.out.println(prime);
	}
}