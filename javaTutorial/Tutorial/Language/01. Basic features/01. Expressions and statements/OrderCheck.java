public class OrderCheck {
	public static void main(String[] args) {
		int x = Integer.parseInt(args[0]);
		int y = Integer.parseInt(args[1]);
		int z = Integer.parseInt(args[2]);
		boolean ans = false;
		if ((x < y && y < z) || (x > y && y > z))
			ans = true;
		System.out.println(ans);
	}	
}