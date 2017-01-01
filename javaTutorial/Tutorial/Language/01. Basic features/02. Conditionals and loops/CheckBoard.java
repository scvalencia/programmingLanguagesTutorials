public class CheckBoard {
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);

		for(int i = 0; i < n; i++) {
			if(i % 2 == 0)
				System.out.print("* ");
			else
				System.out.print("+ ");

		
			for(int j = 0; j < n; j++) {
				if(j % 2 == 0)
					System.out.print("* ");
				else
					System.out.print("+ ");
			}
			System.out.println();
		
	}
}
}