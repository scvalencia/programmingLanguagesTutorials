import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Winner {

	static BufferedReader r ;
	static boolean primero = true;

	public static void main(String[] args) throws IOException
	{
		r = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		while ( (linea = r.readLine()) != null ) {
			int num = Integer.parseInt(linea);
			
			String[] jug = new String[num];
			for (int i = 0 ; i < num ; i++) {
				jug[i] = r.readLine();
			}
			
			double[] pun = new double[num];
			
			for (int i = 0 ; i < 5 ; i++) {
				int R = 0;
				int S = 0;
				int P = 0;
				
				for (int j = 0 ; j < num ; j++) {
					if (jug[j].charAt(i) == 'R') R++;
					if (jug[j].charAt(i) == 'P') P++;
					if (jug[j].charAt(i) == 'S') S++;
				}
				
				for (int j = 0 ; j < num ; j++) {
					if (jug[j].charAt(i) == 'R'){
						pun[j] += S;
						pun[j] += ((double)R-1)*1/2;
					}
					if (jug[j].charAt(i) == 'P'){
						pun[j] += R;
						pun[j] += ((double)P-1)*1/2;
					}
					if (jug[j].charAt(i) == 'S'){
						pun[j] += P;
						pun[j] += ((double)S-1)*1/2;
					}
				}
			}
			
			int max = 0;
			for (int i = 1 ; i < num ; i++) {
				if (pun[i] > pun[max]) max = i;
			}
			if (primero){
				System.out.print(max);
				primero = false;
			}
			else {
				System.out.print("\n" + max);
			}
				
		}
	}
}