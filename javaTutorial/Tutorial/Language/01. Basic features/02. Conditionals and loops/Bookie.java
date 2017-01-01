public class Bookie  { 
    public static void main(String[] args) { 
        int N = Integer.parseInt(args[0]);

        // ruler of order 0
        String ruler = " ";

        // repeat N times
        for (int i = 1; i <= N; i++) {

            // concatenate a ruler of order 0, the number i, and a ruler of order 0
            ruler = ruler + i + ruler;

            // print out the final result
            System.out.println(ruler);
        }

    }
}