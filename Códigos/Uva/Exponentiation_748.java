import java.util.*;
import java.math.*;

public class Exponentiation_748{
    public static void main(String args[])
    {
        String s;
        int p,i;
        BigDecimal num;
        Scanner sc =  new Scanner(System.in);
        
        while(sc.hasNext())
        {
            s = sc.next();
            p = sc.nextInt();
            num = new BigDecimal(s);
            num = num.pow(p);
            s = num.toPlainString();
            
            i = s.length()-1;
            while(s.charAt(i)=='0')
                i--;
            Boolean  b = false;
            for(int k=0; k<=i; k++)
            {
                if(s.charAt(k)!='0')
                    b = true;
                if(b)
                    System.out.print(s.charAt(k));
            }
            System.out.println();
        }
    }
}
