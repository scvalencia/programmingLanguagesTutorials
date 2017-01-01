import java.util.*;

public class Sample {
	public static void main(String[] args) {
		List<Integer> values = new ArrayList<Integer>();
		int result = 0;
		for(int i = 0; i <= 100; i++)
			values.add(i);

		System.out.println(values.stream().filter(e -> e % 2 == 0).count());
	}

	public static void printList(List<Integer> arg) {
		for(int e : arg)
			System.out.print(e);
		System.out.println();
	}
}