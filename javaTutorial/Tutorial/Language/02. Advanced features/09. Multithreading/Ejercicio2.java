import java.io.*;
import java.util.*;

public class Ejercicio2 extends Thread {
	// Matrix variables
	private static int [][] M;
	private static int total = 0;
	private static int max = -99999;
  private static boolean ok;
	// Thread variables
	private int id;
  	private int suma;
  	public boolean termino;

  	public static void main(String[] args) throws IOException {
  		BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in));
  		String line = buf.readLine().trim();
  		int size = Integer.parseInt(line);
  		inicializarMatriz(size);
  		for(int i = 0; i < size; i++) {
  			Thread newThread = new Ejercicio2(i);
  			newThread.start();
  			while(!ok);
  			
  		}
		System.out.println(total);
		System.out.println(max);
  	}

  	public Ejercicio2(int id) { 
  		termino = false; 		
  		suma = 0;
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
      ok = false;
  		int rows = M[0].length;
  		for(int i = 0; i < rows; i++) {
  			int itm = M[id][i];
  			if(itm > max)
  				max = itm;
  		}
  		termino = true;
      ok = termino;
  		total += suma;  		
  	}
}