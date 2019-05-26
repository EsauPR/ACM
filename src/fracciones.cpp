#include<stdio.h>

int gcd(int a, int b)
{
	return (b==0)	?  a   :   gcd(b,a%b);
}

struct fraction
{
	int p,q;
	fraction():p(0),q(1){}
	fraction(int a, int b)
	{
		int g=gcd(a,b);
		p=a/g;
		q=b/g;
		if(q<0)
		{
			p*=-1;
			q*=-1;
		}
	}

	fraction operator + (const fraction &a) const
	{
		int x=p*a.q+q*a.p;
		int y=q*a.q;
		return fraction(x,y);
	}
	fraction operator - (const fraction &a) const
	{
		int x=p*a.q-q*a.p;
		int y=q*a.q;
		return fraction(x,y);
	}
	void operator +=(const fraction &a)
	{
		int x=p*a.q+q*a.p;
		int y=q*a.q;
		int g=gcd(x,y);
		p=x/g;
		q=y/g;
		if(q<0)
		{
			p*=-1;
			q*=-1;
		}
	}
};

int main()
{
	fraction a=fraction(5,9);
	fraction b=fraction(2,3);
	fraction c;
	printf("a = %d/%d\n",a.p,a.q);
	printf("b = %d/%d\n",b.p,b.q);
	c=a+b;
	printf("c = %d/%d\n",c.p,c.q);
	c=a-b;
	printf("c = %d/%d\n",c.p,c.q);
	a+=b;
	printf("a = %d/%d\n",a.p,a.q);
	return 0;
}
