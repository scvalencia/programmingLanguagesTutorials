public class Tautology { 
    public static void main(String[] args) { 
    	boolean a = true;
    	boolean b = true ;
    	boolean expression;
    	expression = (!(a&&b)&&(a||b))||((a&&b)||!(a||b));
    	System.out.println(expression);
    }
}