#include <stdio.h>
#include <memory.h>

int main()
{
	int n;

	while(scanf("%d", &n)!=EOF)
	{
		n-=2;
		int A[2][2]={{1,0},{0,1}}; //identidad
		int R[2][2]={{1,1},{1,0}}; //matriz de fibo
		while( n>0 )
		{
			if( n&1 )
			{
				int tmp[ 2 ][ 2 ] = { { 0 , 0 } , { 0 , 0 } };
				for(int i = 0; i < 2; i++)
					for(int j = 0; j < 2; j++)
						for(int k = 0; k < 2; k++)
						{
							tmp[ i ][ j ] += A[ i ][ k ]*R[ k ][ j ];
							tmp[ i ][ j ] %= 10000; // numero de digitos del fibo
						}
				memcpy( A, tmp, sizeof tmp  );
				
			}
			int tmp[ 2 ][ 2 ] = { { 0 , 0 } , { 0 , 0 } };
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
					for(int k = 0; k < 2; k++)
					{
						tmp[ i ][ j ] += R[ i ][ k ]*R[ k ][ j ];
						tmp[ i ][ j ] %= 10000; // numero de digitos del fibo
					}
			memcpy( R, tmp, sizeof tmp  );
			n>>=1;
		}
		printf("%d\n", A[0][0]);
	}	
	
	return 0;
}
