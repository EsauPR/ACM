//Krakovia 10925

import java.util.*;
import java.math.*;

class Main
{
	public static void main(String []arg)
	{
		BigInteger n1,n2,na;
		int n,nc=1;;
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			n =  sc.nextInt();
			if(n==0) break;
			na = sc.nextBigInteger();
			n1 = new BigInteger("0");
			for(int i=0; i<n; i++)
			{
				n2 = sc.nextBigInteger();
				n1 = n1.add(n2);
			}
			System.out.println("Bill #" + nc + " costs " + n1 + ": each friend should pay " + n1.divide(na) + "\n");
			nc++;
		}
	}
}
