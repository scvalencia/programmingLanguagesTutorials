public class InversePermutation {
	public static void main(String[] args) {

		int data = args.length;
		int permutation[] = new int[data];
		for(int i = 0; i < data; i++)
			permutation[i] = Integer.parseInt(args[i]);
		boolean[] check = new boolean[data];
		for(int i = 0; i < data; i++)
			check[i] = false;

		for(int i = 0; i < data; i++) {
			if(permutation[i] <= 0 && permutation[i] < data)
				if(check[i])
					throw new RuntimeException("Input is not a permutation.");
				else
					check[i] = true;
		}

		int[] inverse = new int[data];
		for(int i = 0; i < data; i++)
			inverse[permutation[i]] = i;

		for(int i = 0; i < data; i++)
			System.out.print(inverse[i] + "  ");

		System.out.println();
	}
}