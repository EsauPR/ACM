// 11448 Who said crisis?

import java.util.*;
import java.math.*;

public class Who_Said_Crisis_11448{
	public static void main(String []arg){
	
		BigInteger a,b;
		Scanner sc = new Scanner(System.in);
		String n1,n2;
		int nc = sc.nextInt();
		
		while(nc>0){
			n1 = sc.next();
			n2 = sc.next();
			a = new BigInteger(n1);
			b = new BigInteger(n2);
			
			System.out.println(a.subtract(b));
			nc--;
		}
		
	}
}
