#include <stdio.h>

int main()
{
	int arr[][3]={{1,5,3},{2,4,7},{5,3,5}};
	int selected[4];
	int n=3;
	
	selected[0]=0;
	for(int i=0;i<n;i++){
		int best=1000;
		for(int j=0;j<n;j++){
			if(arr[i][j] < best) best = arr[i][j];
		}
		selected[i+1] = best + selected[i];
	}
	
	for(int i=0;i<=n;i++) printf("%d",selected[i]);
	return 0;
}
