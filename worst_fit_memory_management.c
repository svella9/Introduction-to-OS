#include <stdio.h>
#include <strings.h>

typedef struct Partition{
	int size;
	int frag;
	char status[25];
}Partition;

typedef struct Process{
	int size;
	int seg;
}Process;

int main(){
	int n, m;
	int i, j;
	printf("Enter no. Partitions\t");
	scanf("%d",&n);
	printf("Enter no. process\t");
	scanf("%d",&m);
	
	Partition part[n];
	Process process[m];
	
	for(i=0; i<n; i++){
		printf("Enter size of partition%d\t",i);
		scanf("%d",&part[i].size);
		part[i].frag = part[i].size;
		strcpy(part[i].status, "free");
	}
	for(i=0; i<m; i++){
		printf("Enter size of process%d\t",i);
		scanf("%d",&process[i].size);
	}
	int worst, pos;
	for(i=0; i<m; i++){
		worst = 0;
		for(j=0; j<n; j++){
			if(part[j].frag >= process[i].size && part[j].frag > worst){
				worst = part[j].frag;
				pos = j;
			}
		}
		part[pos].frag -= process[i].size;
		strcpy(part[pos].status, "allocated");
		process[i].seg = pos;
	}
	printf("Partition no.\tPartition size\tfragment\tPartition status\n");
	for(i=0; i<n; i++){
		if(strcmp(part[i].status,"allocated") == 0){
			printf("%d\t\t%d\t\t%d\t\t%s to ",i,part[i].size,part[i].frag,part[i].status);
			for(j=0; j<m; j++){
				if(process[j].seg == i)
					printf("P%d ",j);
			}
			printf("\n");
		}
		else{
			printf("%d\t\t%d\t\t%d\t\t%s\n",i,part[i].size,part[i].frag,part[i].status);
		}
	}
	return 0;
}
