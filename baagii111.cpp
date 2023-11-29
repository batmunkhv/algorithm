#include <stdio.h>

int main()
{
	int arr[][3]={{1,5,3},{2,4,7},{5,3,5}};
	int n=3;
   int sum=0;

	for(int i=0;i<n;i++){
		int best=1000;
		for(int j=0;j<n;j++){
			if(arr[i][j] < best) {
				best = arr[i][j];				
			}
		}
		sum=best+sum;
	}
	printf("%d ",sum);
	return 0;
}





