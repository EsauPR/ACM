//465 Overflow 

import java.util.*;
import java.math.*;

class Main
{
	public static void main(String []arg)
	{
		Scanner sc =  new Scanner(System.in);
		BigInteger a,b,c;
		c = new BigInteger("2147483647");
		String num,op,s;
		StringTokenizer tk;
		while(sc.hasNext())
		{
	
			num = sc.nextLine();
			
			System.out.println(num);
			
			tk = new StringTokenizer(num," ");
			
			s = tk.nextToken();
			a = new BigInteger(s);
			op = tk.nextToken();
			s = tk.nextToken();
			b = new BigInteger(s);
			
			if(a.compareTo(c)==1)
				System.out.println("first number too big");
			
			if(b.compareTo(c)==1)
				System.out.println("second number too big");
			
			if(op.charAt(0) == '+')
				a = a.add(b);
			else a = a.multiply(b);

			if(a.compareTo(c)==1)
				System.out.println("result too big");
		}
		
	}
}
