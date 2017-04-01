#include <stdio.h>

int cmpfunc(const void *a, const void *b);
int main(){
	int n;
	int i,j;
	printf("Enter no. of requests\t");
	scanf("%d",&n);
	int queue[n];
	printf("Enter the requests\n");	
	for(i=0; i<n; i++)
		scanf("%d",&queue[i]);
	
	int current, limit;
	int direction;
	printf("Enter the limit\t");
	scanf("%d",&limit);
	printf("Enter the current head and direction\t");
	scanf("%d%d",&current,&direction);
	
	qsort(queue,n,sizeof(int),cmpfunc);
	for(i=0; i<n; i++)
		printf("%d ",queue[i]);

	int pos = 0;
	int seek = 0;
	while(pos<n && queue[pos]<current)
		pos++;
	if(pos < n){
		pos--;
		printf("%d\n",pos);
		if(direction == 0){
			for(i=pos; i>=0; i--){
				printf("Seeked %d\n",queue[i]);
				seek += abs(current - queue[i]);
				current = queue[i];
			}
			printf("Seeked 0\n");
			seek = seek + (current-0) + limit;
			current = limit;
			for(i=n-1; i>pos; i--){
				printf("Seeked %d\n",current);
				seek += abs(current - queue[i]);
				current = queue[i];
			}
		}
		else{



		}

		printf("Seek time: %d\n",seek);	
	}
}

int cmpfunc(const void *a, const void *b){
	return *((int *)a) - *((int *)b);
}
