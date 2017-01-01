public class DiceRand {
	public static void main(String[] args){
		double random = Math.random();
		int number = (int) (random * (6)) + 1;
		System.out.println(number);
	}
}