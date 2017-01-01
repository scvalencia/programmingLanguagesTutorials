public class Canvas { 
    public static void main(String args[])
    {
        int N = Integer.parseInt(args[0]);
        int taylor = 1;
        int i;
        if(N != 0)
        {
            for(int j = 0; j <= N; j++)
            {
                for(i = 1; i <= N; i++)
                {
                    int factoria = 1;
                    factoria = factoria * i;
                    taylor += (Math.pow(N,i)) / factoria;
                    System.out.println(taylor);
                }


            }

        }
        
    }
}