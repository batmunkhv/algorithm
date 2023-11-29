#include <stdio.h>

int fibo(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==1) return 2;
	return fibo(n-1)+fibo(n-2)-fibo(n-3);
}
int main()
{
	printf("%d",fibo(35));
	return 0;
}

