//713 - Adding Reversed Numbers
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String []arg)
	{
		String a,b,res;
		BigInteger num1,num2;
		Scanner sc = new Scanner(System.in);
		int nc;
		nc = sc.nextInt();
		for(int i=0; i<nc; i++)
		{
			a = sc.next();
			b = sc.next();
			res = "";
			for(int j=a.length()-1; j>=0; j--)
				res += a.charAt(j);
			a = res;
			res = "";
			for(int j=b.length()-1; j>=0; j--)
				res += b.charAt(j);
			b = res;
			num1 = new BigInteger(a);
			num2 = new BigInteger(b);
			num1 = num1.add(num2);
			a = num1.toString();
			res = "";
			for(int j=a.length()-1; j>=0; j--)
				res += a.charAt(j);
			a = res;
			num1 = new BigInteger(a);
			System.out.println(num1);
		}
	}
}
