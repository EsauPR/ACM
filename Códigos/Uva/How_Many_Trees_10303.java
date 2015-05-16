//10303 - How Many Trees?

import java.util.*;
import java.math.*;


class Main
{
	public static void main(String []agrs)
	{
		int num;
		Scanner sc =  new Scanner(System.in);
		BigInteger fact[] =  new BigInteger[2009];
		BigInteger sol[] =  new BigInteger[1005];
		fact[0] = new BigInteger("1");
		fact[1] = new BigInteger("1");
		sol[0] = new BigInteger("1");
		BigInteger tmp;
		
		for(Integer i=2; i<=2000; i++){
			tmp = new BigInteger(i.toString());
			fact[i] = fact[i-1].multiply(tmp);
		}
		for(Integer i=1; i<=1000; i++)
		{
			sol[i] = fact[2*i];
			sol[i] =  sol[i].divide(fact[i+1].multiply(fact[i]));
		}
		
		while(sc.hasNext())
		{
			num = sc.nextInt();
			System.out.println(sol[num]);
		}
	}
}
