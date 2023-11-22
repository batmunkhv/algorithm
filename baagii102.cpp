#include <stdio.h>

void path_dp(int map[][4],int path[][4],int x,int y){
	path[0][0]=map[0][0];
	
	int least_cost, least_x,least_y;
	while(!(least_x==x-1 && least_y==y-1)){
		least_cost=9999;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(path[i][j]!=-1){
					if(path[i+1][j] == -1){
						int cost = path[i][j] + map[i+1][j];
						if(cost < least_cost){
							least_cost = cost;
							least_x = i+1;
							least_y = j;
						}
					}
					if(path[i][j+1] == -1){
						int cost = path[i][j] + map[i][j+1];
						if(cost < least_cost){
							least_cost = cost;
							least_x = i;
							least_y = j + 1;
						}
						}
					}
					
				}
			}
			printf("<%d,%d,%d>\n",least_x,least_y,least_cost);
			path[least_x][least_y]=least_cost;
		}
	}
int main(){
	int map[3][4]={{0,5,2,8},{4,1,10,7},{3,9,6,11}};
	int path[3][4];
	int x=3, y=4;
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			path[i][j]=-1;
		}
	}
	
	path_dp(map,path,x,y);
	
	printf("\n");
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}
	return 0;
}
