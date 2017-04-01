#include <stdio.h>
#include <stdlib.h>


typedef struct Process{
	int burst;
	int wait;
	int turn;
	int remain;
}Process;

int main(){
	int n;
	int i,j;
	printf("Enter the no. of processes\t");
	scanf("%d",&n);
	Process P[n];
	for(i=0; i<n; i++){
		printf("Enter burst_time of P%d\t",i);
		scanf("%d",&P[i].burst);
		P[i].remain = P[i].burst;
		P[i].wait = 0;
	}
	int tq;
	printf("Enter time quantum\t");
	scanf("%d",&tq);
	int complete = 0;
	j = 0;
	while(complete < n){
		if(P[j].remain <= tq && P[j].remain > 0){
			for(i=0; i<n; i++)
				if(i!=j && P[i].remain > 0)
					P[i].wait += P[j].remain;
			P[j].turn = P[j].wait + P[j].remain;
			P[j].remain = 0;
			complete++;
		}
		else if(P[j].remain > 0){
			for(i=0; i<n; i++)
				if(i!=j && P[i].remain > 0)
					P[i].wait += tq;
			P[j].remain -= tq;
		}
		j = (j+1)%n;
		
	}
	printf("Process\tburst\twait\tturn\n");
	float total_wait = 0,total_turn = 0; 
	for(i=0; i<n; i++){
		printf("P%d\t%d\t%d\t%d\n",i,P[i].burst,P[i].wait,P[i].turn);
		total_wait += P[i].wait;
		total_turn += P[i].turn;
	}
	printf("Average wait: %f\n",total_wait/n);
	printf("Average turn: %f\n",total_turn/n);
	return 0;
}
