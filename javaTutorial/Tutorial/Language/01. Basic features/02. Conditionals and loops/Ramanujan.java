public class Ramanujan {
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);

		for(int a = 0; a <= n; a++) { 
			int a3 = (int) Math.pow(a,3);
			if (a3 > n)
				break;
			for(int b = 0; b <= n; b++) {
				int b3 = (int) Math.pow(b,3);
				if(a3 + b3 > n)
					break;
				for(int c = 0; c <= n; c++) {
					int c3 = (int) Math.pow(c,3);
					if(c3 > a3 + b3)
						break;
					for(int d = 0; d <= n; d++) {
						int d3 = (int) Math.pow(d,3);
						if(c3 + d3 > a3 + b3)
							break;

						if ((a3 + b3 == c3 + d3) && (a3 != b3) && (a3 != c3) 
							&& (a3 != d3) && (b3 != c3) && (b3 != d3) && (c3 != d3)) {
							int sum = a3 + b3;
							System.out.print((sum) + " = (");
							System.out.print(a + "^3 + " + b + "^3 = ");
							System.out.print(c + "^3 + " + d + "^3)");
							System.out.println();
						}
					}
				}
			}
		}


		
	}
}