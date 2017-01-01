import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Score
{
	private static boolean primero=true;

	private static BufferedReader br;

	public static void main(String[] args) throws Exception
	{
		br = new BufferedReader(new InputStreamReader(System.in));
		solucionarProblema2();
	}

	private static void solucionarProblema2() throws IOException
	{
		String line=br.readLine();
		while(line!=null)
		{
			String[] args=line.split(" ");
			int newScore=Integer.parseInt(args[0]);
			int places=Integer.parseInt(args[1]);
			
			line=br.readLine();
			String[] scores=(line.length()==0?new String[]{}:line.split(" "));
			
			if(primero)
			{
				imprimirSolucion(""+solucionarCaso(newScore, places,scores));
				primero=false;
			}
			else imprimirSolucion("\n"+solucionarCaso(newScore, places,scores));
			line=br.readLine();
		}
	}

	private static int solucionarCaso(int newScore, int places,String[]scores)
	{
		int pos = 1;
		boolean llego = false;
		for (int i = 0 ; i < scores.length ; i++)
		{
			int actual = Integer.parseInt(scores[i]);
			if (actual < newScore) 
				return pos;
			if (actual == newScore) 
				llego = true;
			if (!llego) pos++;
		}
		if (scores.length == places) return -1;
		return scores.length+1;
	}

	private static void imprimirSolucion(String solucion)
	{
		System.out.print(solucion);
	}
}