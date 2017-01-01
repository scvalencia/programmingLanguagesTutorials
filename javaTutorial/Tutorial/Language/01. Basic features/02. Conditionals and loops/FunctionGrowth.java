public class FunctionGrowth {
	public static void main(String args[]) {
		System.out.println("log(N)\tN\tNlog(N)\tN2\tN3\t2N");
		for(long i = 2; i <= 2048; i *= 2) {
			System.out.print(Math.log(i));
			System.out.print("\t");
			System.out.print(i);
			System.out.print("\t");
			System.out.print(i * Math.log(i));
			System.out.print("\t");
			System.out.print(i*i);
			System.out.print("\t");
			System.out.print(i*i*i);
			System.out.print("\t");
			System.out.println(2*i);
		}
	}
}