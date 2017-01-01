import java.io.*;

public class JuanCamilo {
	public static void main(String[] args) {
		System.out.println(matchingParenthesis());
	}

	static boolean matchingParenthesis() {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String text = br.readLine();
			int answer = 0;
			int changes = 0;
			for(int i = 0; i < text.length(); i++) {
				char actual = text.charAt(i);
				if(answer == -1)
					return false;
				if(actual == '(') {
					answer++;
					changes++;
				}
				if(actual == ')') {
					answer--;
					changes++;
				}
			}
			if(changes > 0 && answer == 0)
				return true;
			return false;
		} catch(Exception e) {
			//FUCKU
		}
		return false;
	}
	
}