#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int abs(int j);
int cmpfunc(const void *a,const void *b);
int main(){
	int n;
	int i,j;
	printf("Enter the size of queue\t");
	scanf("%d",&n);
	int queue[n];
	printf("Enter the requests\n");
	for(i=0; i<n; i++)
		scanf("%d",&queue[i]);
	int current;
	printf("Enter the current head position\t");
	scanf("%d",&current);

	int direction;
	printf("Enter direction: 0->left and 1->right\n");
	scanf("%d",&direction);
	
	qsort(queue,n,sizeof(int),cmpfunc);
	for(i=0; i<n; i++)
		printf("%d ",queue[i]);
	//printf("%d %d %d %d %d",queue[0],queue[1],queue[2],queue[3],queue[4]);
	int pos = 0;
	int seek = 0;
	int head;
	while(pos < n && queue[pos] <= current)
		pos++;
	if(pos < n){
		pos--;
		if(direction == 0){
			for(head = pos; head >=0; head--){
				printf("Seeked: %d\n",queue[head]);
				seek = seek + abs(current - queue[head]);
				current = queue[head];
			}
			seek = seek + abs(current - 0);
			current = 0;
			for(head=pos+1; head<n; head++){
				printf("Seeked: %d\n",current);
				seek = seek + abs(current - queue[head]);
				current = queue[head];	
			}
			
		}

		else{
			for(head=pos+1; head<n; head++){
				printf("Seeked: %d\n",current);
				seek = seek + abs(current - queue[head]);
				current = queue[head];	
			}
			for(head = pos; head >=0; head--){
				printf("Seeked: %d\n",current);
				seek = seek + abs(current - queue[head]);
				current = queue[head];
			}
		}
	}
	printf("Seek: %d\n",seek);
	return 0;
}

int cmpfunc(const void *a,const void *b){
	return (*(int *)a) - (*(int *)b);
}
