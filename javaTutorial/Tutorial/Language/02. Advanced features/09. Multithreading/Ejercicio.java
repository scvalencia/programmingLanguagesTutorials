import java.io.*;
import java.util.*;

public class Ejercicio extends Thread {
	// Matrix variables
	private static int [][] M;
	private static int total = 0;
	private static int max = -99999;
	// Thread variables
	private int id;
  	private int suma;
  	public boolean termino;

  	public static void main(String[] args) throws IOException {
  		BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in));
  		String line = buf.readLine().trim();
  		int size = Integer.parseInt(line);
  		Ejercicio[] threads = new Ejercicio[size];
  		inicializarMatriz(size);
  		for(int i = 0; i < size; i++) {
  			Thread newThread = new Ejercicio(i);
  			threads[i] = (Ejercicio) newThread;
  			for(int j = 0; j < size; j++)
  				threads[j].start();
  			for(int j = 0; j < size; j++)
  				if(((Ejercicio)threads[j]).termino)
  					total += ((Ejercicio)threads[i]).suma;
  		}
		System.out.println(total);
		System.out.println(max);
  	}

  	public Ejercicio(int id) { 
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
  		termino = true; 
  		total += suma;		
  	}
}