public class DayOfWeek {
	/* This program uses an algorithm to show the day of the 
	 * week in the gregorian calendar of some date. The inputs are
	 * m y d, and the output is a number representing a day in the week
	 */
	public static void main(String args[]) {
		int month = Integer.parseInt(args[0]); // 1 for January, 2 for February , ...
		int day = Integer.parseInt(args[1]); // 0 for Sunday, 1 for Monday, 2 for Tuesday, ...
		int year = Integer.parseInt(args[2]);

		int yo = year - (14 - month)/12;
		int x = yo + yo/4 - yo/100 + yo/400;
		int mo = month + ((14 - month)) - 2;
		int d = (day + x + (31 * mo)/12) % 7;

		System.out.println(d); 
	}
}