//787 - Maximum Sub-sequence Product
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String []arg)
	{
		BigInteger a[] = new BigInteger[105];
		Scanner sc = new Scanner(System.in);
		String s;
		StringTokenizer tk;
		BigInteger max, sol;
		int TAM;
		while(sc.hasNext()){
			s = sc.nextLine();
			tk = new StringTokenizer(s, " ");
			
			for(TAM=0; tk.hasMoreTokens(); TAM++){
				a[TAM] =  new BigInteger(tk.nextToken());
			}
			
			max = (a[0]);
				
			for(int i=0; i<TAM-1; i++){
				sol = new BigInteger("1");
				for(int j=i; j<TAM-1; j++){
					sol = sol.multiply(a[j]);
					if( max.compareTo(sol) == -1)
						max = sol;
				}
			}
			System.out.println(max);
		}
	}
}
