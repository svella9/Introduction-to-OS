#include <stdio.h>
#include <stdlib.h>

//void Safesequence(int **allocation, int **max, int **need, int *available, int pn, int rn);
int main(){
	int pn, rn;
	int i,j;
	printf("Enter the no. of processes\n");
	scanf("%d",&pn);
	printf("Enter the no. of resources\n");
	scanf("%d",&rn);
	
	int R[rn];
	
	for(i=0; i<rn; i++){
		printf("Enter the number of instances of R%d\t",i+1);
		scanf("%d",&R[i]);
		printf("\n");
	}

	int allocation[pn][rn];
	printf("Enter allocation matrix\n");
	for(i=0; i<pn; i++)
		for(j=0; j<rn; j++)
			scanf("%d",&allocation[i][j]);
	
	int max[pn][rn];
	printf("Enter maximum matrix\n");
	for(i=0; i<pn; i++)
		for(j=0; j<rn; j++)
			scanf("%d",&max[i][j]);

	int available[rn];
	int sum = 0;
	for(j=0; j<rn; j++){
		for(i=0; i<pn; i++)
			sum+=allocation[i][j];
		available[j] = R[j] - sum;
		sum = 0;
	}

	int need[pn][rn];
	for(i=0; i<pn; i++)
		for(j=0; j<rn; j++)
			need[i][j] = max[i][j] - allocation[i][j];
	
	for(i=0; i<pn; i++){
		printf("process P%d\n",i+1);
		for(j=0; j<rn; j++){
			printf("allocated %d maximum %d need %d\n",allocation[i][j],max[i][j],need[i][j]);				
		}
		printf("--------------------------------------------------------------\n");
	}

	printf("Availability R1 %d R2 %d R3 %d\n", available[0],available[1],available[2]);
	printf("--------------------------------------------------------------\n");
	
	//Safesequence(allocation,max,need,available,pn,rn);

	int work[rn];
	int finish[pn];
	int sequence[pn];
	int k = 0, c1 = 0, c2;
	int flag=0;
	for(i=0; i<pn; i++)
		finish[i] = 0;
	for(j=0; j<rn; j++)
		work[j] = available[j];
while(c1!=pn){
	c2 = c1;
	for(i=0; i<pn; i++){
		int count = 0;
		for(j=0; j<rn; j++){
			if(need[i][j]<=work[j])	
				count++;
		}
		if(count==rn && finish[i]==0){
			for(j=0; j<rn; j++)
				work[j] = work[j] + allocation[i][j];
			finish[i] = 1;
			c1++;
			sequence[k++] = i;
		}
	}
	if(c1 == c2){
		printf("Not a safe sequence...\n");
			exit(0);
	}
}
	printf("Safe Sequence\n");
	for(i=0; i<pn; i++){
		printf("P%d Availablity of ",sequence[i]+1);
		for(j=0; j<rn; j++){
			available[j] += allocation[sequence[i]][j];
			printf("R%d %d ",j+1,available[j]);		
		}
		printf("\n");
	}

	return 0;

}

/*void Safesequence(int **allocation, int **max, int **need, int *available, int pn, int rn){
	int work[rn];
	int finish[pn];
	int sequence[pn];
	int i,j;
	int k = 0, c1 = 0, c2;
	int flag=0;
	for(i=0; i<pn; i++)
		finish[i] = 0;
	for(j=0; j<rn; j++)
		work[j] = available[j];
while(c1!=pn){
	c2 = c1;
	for(i=0; i<pn; i++){
		int count = 0;
		for(j=0; j<rn; j++){
			if(need[i][j]<=work[j])	
				count++;
		}
		if(count==rn && finish[i]==0){
			for(j=0; j<rn; j++)
				work[j] = work[j] + allocation[i][j];
			finish[i] = 1;
			c1++;
			sequence[k++] = i;
		}
	}
	if(c1 == c2){
		printf("Not a safe sequence...\n");
			exit(0);
	}
}
	
	for(i=0; i<pn; i++){
		printf("Safe Sequence\n");
		printf("P%d Availablity of ",sequence[i]+1);
		for(j=0; j<rn; j++){
			available[j] += allocation[sequence[i]][j];
			printf("R%d %d ",j+1,available[j]);		
		}
		printf("\n");
	}
}*/	

