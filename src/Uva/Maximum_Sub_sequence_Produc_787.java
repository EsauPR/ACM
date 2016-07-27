//787 - Maximum Sub-sequence Product
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String []arg)
	{
		BigInteger a[] = new BigInteger[105];
		String s = "";
		Scanner sc = new Scanner(System.in);
		BigInteger sum;
		BigInteger max;
		BigInteger Uno = new BigInteger("1");
		BigInteger Zero = new BigInteger("0");
		
		int tam=0;
		while(sc.hasNext())
		{
			tam = 0;
			s = sc.nextLine();
			StringTokenizer tk = new StringTokenizer(s," ");
			
			while(tk.hasMoreTokens())
				a[tam++] = new BigInteger(tk.nextToken());
			
			sum = new BigInteger("1");
			max = a[0];

			for(int i=1; i<tam-1; i++)
			{
				a[i] = a[i].multiply( a[i-1] );
				if( a[i].compareTo(Zero) == 0)
					i++;
			}
			
			for(int i=0; i<tam-1; i++)
				System.out.print(a[i] + " ");
			

			System.out.println("\n");
		}
		
		
	}
}

