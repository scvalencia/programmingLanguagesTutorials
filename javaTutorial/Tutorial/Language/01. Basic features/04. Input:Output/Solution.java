import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Solution {
	
	static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter w = new PrintWriter(System.out , true);

	public static void main(String[] args) throws IOException {
		String linea;
		//System.out.println(gcd(81,27));
		while ( (linea = r.readLine()) != null ) {
			String[] fE = linea.split(" ");
			
			int a = Integer.parseInt(fE[0].split("*")[0].replaceAll("(", "").replaceAll(")", ""));
			int b = Integer.parseInt(fE[2].split("*")[0].replaceAll("(", "").replaceAll(")", ""));
			int c = Integer.parseInt(fE[4].replaceAll("(", "").replaceAll(")", ""));
			
			linea = r.readLine();
			fE = linea.split(" ");
			
			int d = Integer.parseInt(fE[0].split("*")[0].replaceAll("(", "").replaceAll(")", ""));
			int e = Integer.parseInt(fE[2].split("*")[0].replaceAll("(", "").replaceAll(")", ""));
			int f = Integer.parseInt(fE[4].replaceAll("(", "").replaceAll(")", ""));
			
			if (a*c-b*d == 0) {
				
				
				
			}
			else {
				int cr = a*c-b*d;
				int y = a*f-c*d;
				int x = c*e - b*f;
				
				int nx = x;
				int dx = cr;
				if (x != 0) {
					int gcd = gcd(Math.abs(nx),Math.abs(cr));
					nx = nx/gcd;
					dx = dx/gcd;
				}
				
				int ny = y;
				int dy = cr;
				if (y != 0) {
					int gcd = gcd(Math.abs(ny),Math.abs(cr));
					ny = ny/gcd;
					ny = dy/gcd;
				}
				
				String X = "";
				if ( ((double)nx)/((double)dx) > 0) {
					X = Math.abs(nx) + "/" + Math.abs(dx);
				}
				else {
					X = "(-" + Math.abs(nx) + ")/" + Math.abs(dx);
				}
				
				String Y = "";
				if ( ((double)ny)/((double)dy) > 0) {
					Y = Math.abs(ny) + "/" + Math.abs(dy);
				}
				else {
					Y = "(-" + Math.abs(ny) + ")/" + Math.abs(dy);
				}
				
				w.println("X=" + X + " Y=" + Y);
			}
		}
	}	
	public static int gcd (int x , int y) {
		return (y == 0)? x: gcd(x, x%y);
	}
}
