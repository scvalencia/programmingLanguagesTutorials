import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException  {
        
         InputStreamReader isr=new InputStreamReader(System.in);
         BufferedReader br=new BufferedReader(isr);
         BigInteger fib[] =new BigInteger[105];
         StringBuffer sb=new StringBuffer("");
         fib[0]=BigInteger.ONE;
         fib[1]=BigInteger.valueOf(2);
         for(int i=2;i<105;i++){
             fib[i]=fib[i-1].add(fib[i-2]);
         }
         
         String m="";
         BigInteger temp1=BigInteger.ONE,temp2=BigInteger.ONE;
         boolean first=true;
         while((m=br.readLine())!=null){
             if(!first)
                 sb.append("\n");
             temp1=BigInteger.ZERO;
             temp2=BigInteger.ZERO;
             StringBuilder s=new StringBuilder(m);
             m=s.reverse().toString();
             int string1=m.length(); 
             for(int j=0;j<m.length();j++){
                 if(m.charAt(j)=='1')
                     temp1=temp1.add(fib[j]);
             }
             m=br.readLine();
             s=new StringBuilder(m);
             m=s.reverse().toString();
             for(int j=0;j<m.length();j++){
                 if(m.charAt(j)=='1')
                     temp2=temp2.add(fib[j]);
             }
             int string2=m.length();
             BigInteger sum=temp1.add(temp2);
             String ans="";
             int i=Math.max(string1, string2)+1;
             boolean flag=false;
             if(sum.compareTo(BigInteger.ZERO)==0)
                ans="0";
             while(sum.compareTo(BigInteger.ZERO)>-1 && i>-1){
                 if(sum.compareTo(fib[i])>-1){
                        sum=sum.subtract(fib[i]);
                        ans+="1";
                        flag=true;
                    }
                    else{
                        if(flag)
                            ans+="0";
                    }
                 i--;
             }
             first=false;
             sb.append(ans).append("\n");
             if(br.ready())
                br.readLine();
         }
         System.out.print(sb);
    }
}