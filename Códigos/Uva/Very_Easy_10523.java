// 10523 very Easy

import java.math.*;
import java.util.*;

public class Very_Easy_10523{
	public static void main(String []args){
		
		Scanner sc = new Scanner( System.in );
		int n1,n2;
		BigInteger [][]MAT = new BigInteger[16][151];
		BigInteger []a = new BigInteger[16];
		BigInteger []b = new BigInteger[151];
		for(Integer i=1; i<151; i++)
			b[i] = new BigInteger(i.toString());
		for(Integer i=1; i<16; i++){
			MAT[i][1] = new BigInteger(i.toString());
			a[i] = new BigInteger( i.toString() );
		}
		for(Integer i=2; i<151; i++){
			//*
			MAT[1][i] = a[1].pow(i); MAT[1][i] = MAT[1][i].multiply(b[i]); MAT[1][i] = MAT[1][i-1].add(MAT[1][i]);
			MAT[2][i] = a[2].pow(i); MAT[2][i] = MAT[2][i].multiply(b[i]); MAT[2][i] = MAT[2][i-1].add(MAT[2][i]);
			MAT[3][i] = a[3].pow(i); MAT[3][i] = MAT[3][i].multiply(b[i]); MAT[3][i] = MAT[3][i-1].add(MAT[3][i]);
			MAT[4][i] = a[4].pow(i); MAT[4][i] = MAT[4][i].multiply(b[i]); MAT[4][i] = MAT[4][i-1].add(MAT[4][i]);
			MAT[5][i] = a[5].pow(i); MAT[5][i] = MAT[5][i].multiply(b[i]); MAT[5][i] = MAT[5][i-1].add(MAT[5][i]);
			MAT[6][i] = a[6].pow(i); MAT[6][i] = MAT[6][i].multiply(b[i]); MAT[6][i] = MAT[6][i-1].add(MAT[6][i]);
			MAT[7][i] = a[7].pow(i); MAT[7][i] = MAT[7][i].multiply(b[i]); MAT[7][i] = MAT[7][i-1].add(MAT[7][i]);
			MAT[8][i] = a[8].pow(i); MAT[8][i] = MAT[8][i].multiply(b[i]); MAT[8][i] = MAT[8][i-1].add(MAT[8][i]);
			MAT[9][i] = a[9].pow(i); MAT[9][i] = MAT[9][i].multiply(b[i]); MAT[9][i] = MAT[9][i-1].add(MAT[9][i]);
			
			MAT[10][i] = a[10].pow(i); MAT[10][i] = MAT[10][i].multiply(b[i]); MAT[10][i] = MAT[10][i-1].add(MAT[10][i]);
			MAT[11][i] = a[11].pow(i); MAT[11][i] = MAT[11][i].multiply(b[i]); MAT[11][i] = MAT[11][i-1].add(MAT[11][i]);
			MAT[12][i] = a[12].pow(i); MAT[12][i] = MAT[12][i].multiply(b[i]); MAT[12][i] = MAT[12][i-1].add(MAT[12][i]);
			MAT[13][i] = a[13].pow(i); MAT[13][i] = MAT[13][i].multiply(b[i]); MAT[13][i] = MAT[13][i-1].add(MAT[13][i]);
			MAT[14][i] = a[14].pow(i); MAT[14][i] = MAT[14][i].multiply(b[i]); MAT[14][i] = MAT[14][i-1].add(MAT[14][i]);
			MAT[15][i] = a[15].pow(i); MAT[15][i] = MAT[15][i].multiply(b[i]); MAT[15][i] = MAT[15][i-1].add(MAT[15][i]);
			//*/
		}
		
		while(sc.hasNext()){
			n1 = sc.nextInt();
			n2 = sc.nextInt();
			//System.out.println(n1 + " " +n2);
			if(n2==0) System.out.println("0");
			else System.out.println(MAT[n2][n1]);
		}
		
	}
}
