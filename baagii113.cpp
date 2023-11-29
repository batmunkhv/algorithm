#include<stdio.h>

void path_greedy(int map[][4],int path[][4],int x, int y){
	    
    	path[0][0] = map[0][0];

	int current_x=0, current_y=0;
	int below_cost, right_cost;
	while(!(current_x==x-1 && current_y==y-1)){
		if(current_x+1<x) below_cost=path[current_x][current_y] + map[current_x+1][current_y];
		else below_cost=1000;
		if(current_y+1<y) right_cost=path[current_x][current_y] + map[current_x][current_y+1];
		else right_cost=1000;
		if(below_cost<right_cost){
			path[current_x+1][current_y]=below_cost;
			current_x=current_x+1;
		}else{
			path[current_x][current_y+1]=right_cost;
			current_y=current_y+1;
		}
		printf("<%d,%d,%d>\n", current_x,current_y,path[current_x][current_y]);
	}
}
int main(){
 int map[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
 int path[3][4];
int x=3, y=4;
for(int i=0;i<x;i++) {
 for(int j=0;j<y;j++){
path[i][j]=-1;
 }
}
 path_greedy(map, path, x, y);

 printf("\n");
 for(int i=0;i<x;i++) {
 for(int j=0;j<y;j++){
printf("%d ",path[i][j]);
 }
printf("\n");
 }
 return 0;
}
