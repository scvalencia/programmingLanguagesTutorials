import java.util.*;
import java.io.*;

class MatrixThreads extends Thread {

	private static int M[][];
	private static int total = 0;
	private static int max = 0;
	public int id;
	public int suma;
	public boolean termino;

	public static void main(String[] args) throws IOException {
		BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in));
  		String line = buf.readLine().trim();
  		int size = Integer.parseInt(line);
  		MatrixThreads threads[] = new MatrixThreads[size];  		
  		inicializarMatriz(size);
  		boolean flag = false;
  		int last = 0;
  		while(!flag) {
  			total = 0;
  			for(int i = 0; i < M[0].length; i++) {
  				Thread newThread = new MatrixThreads(i);
  				threads[i] = (MatrixThreads) newThread;
  				newThread.start();
  				System.out.println(i + " --> " + total); // Sensible!!!!
  				last = ((MatrixThreads)newThread).suma;
  			}
  			flag = true;
  			for(int i = 0; i < M[0].length; i++)
  				if(!((MatrixThreads)threads[i]).termino) {
  					flag = false;
  					break;
  				}
  		}
  		System.out.println("********************");
  		System.out.println("N: " + size);
  		System.out.println("Sum: " + (total - last));
  		System.out.println("Max: " + max);
	}

	public MatrixThreads(int id) { 
  		this.termino = false; 		
  		this.suma = 0;
  		this.id = id;
  	}

	private static void inicializarMatriz(int n) {
  		M = new int[n][n];
  		int m = 0;
  		for(int i = 0; i < n; i++)
  			for(int j = 0; j < n; j++) {
  				M[i][j] = m;
  				m++;
  			}
  	}

  	public void run() {
  		int rows = M[0].length;
  		for(int i = 0; i < rows; i++) {
  			int itm = M[id][i];
  			if(itm > max)
  				max = itm;
  			suma += itm;
  		}
  		total += suma;
  		termino = true;		
  	}
	
}