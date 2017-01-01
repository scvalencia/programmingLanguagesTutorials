import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Board {

	static BufferedReader r ;
	static PrintWriter w ;
	
	static boolean[][] pas;
	static int[][] mat;
	static int N;
	static int M;
	
	static boolean primero = true;

	public static void main(String[] args) throws IOException
	{
		r = new BufferedReader(new InputStreamReader(System.in));
		w = new PrintWriter(System.out , true);
		String linea;
		while ( (linea = r.readLine()) != null ) {
			N = Integer.parseInt(linea);
			mat = new int[N][];
			for( int i = 0 ; i < N ; i++) {
				linea = r.readLine();
				M = linea.length();
				mat[i] = new int[M];
				for (int j = 0 ; j < M ; j++) 
					mat[i][j] = linea.charAt(j)=='H'? 0:linea.charAt(j)-'0';
			}
			pas = new boolean[N][M];
			
			if (primero){
				w.print(sol(0,0));
				primero = false;
			}
			else 
				w.print("\n" + sol(0,0));
			
		}
	}

	private static int sol(int X, int Y) 
	{
		
		if (pas[X][Y] == true) return -1;
		if (mat[X][Y] == 0) return 0;
		
		pas[X][Y] = true;
		
		int up = 0;
		int down = 0;
		int left = 0;
		int right = 0;
		
		if (Y-mat[X][Y]>=0) {
			up = sol(X,Y-mat[X][Y]);
			if (up == -1) {
				pas[X][Y] = false;
				return -1;
			}
		}
		if (Y+mat[X][Y]<M) {
			down = sol(X,Y+mat[X][Y]);
			if (down == -1) {
				pas[X][Y] = false;
				return -1;
			}
		}
		
		if (X-mat[X][Y]>=0) {
			left = sol(X-mat[X][Y],Y);
			if (left == -1) {
				pas[X][Y] = false;
				return -1;
			}
		}
		if (X+mat[X][Y]<N) {
			right = sol(X+mat[X][Y],Y);
			if (right == -1) {
				pas[X][Y] = false;
				return -1;
			}
		}
		
		int max = up;
		if (down > max) max = down;
		if (left > max) max = left;
		if (right > max) max = right;
		
		pas[X][Y] = false;
		return max + 1;
	}
}