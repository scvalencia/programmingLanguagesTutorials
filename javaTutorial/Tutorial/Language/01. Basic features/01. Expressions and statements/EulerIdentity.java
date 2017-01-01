public class EulerIdentity {
	public static void main(String[] args) {
		double angle = Double.parseDouble(args[0]);
		double cos = Math.pow(Math.cos(angle), 2.0);
		double sin = Math.pow(Math.sin(angle), 2.0);
		System.out.println(cos + sin);
	}
}