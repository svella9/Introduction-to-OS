/*7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1*/
#include <stdio.h>

typedef struct Frame{
	int val;
	int count;
}Frame;

int main(){
	int n,m;
	int i,j;
	printf("Enter the length\t");
	scanf("%d",&n);
	int p[n];
	printf("Enter the reference string\n");
	for(i=0; i<n; i++)
		scanf("%d",&p[i]);
	printf("Enter the frame length\t");
	scanf("%d",&m);
	Frame frame[m];
	for(i=0; i<m; i++){
		frame[i].val = -1;
		frame[i].count = 0;
	}

	int empty = 0, faults = 0;
	int present, c = 0;
	for(i=0; empty<m && i<n; i++){
		present = 0;
		for(j=0; j<m; j++){
			if(frame[j].val == p[i]){
				present = 1;
				frame[j].count = ++c;
				break;
			}
			else if(frame[j].val == -1)
				break;
		}
		if(!present){
			frame[empty].val = p[i];
			frame[empty].count = ++c;
			empty++;
			faults++;
			
		}
	}
	
	int minpos, mincount;
	int s;
	for(s = i; s<n; s++){
		present = 0;
		mincount = 9999;
		for(j=0; j<m; j++){
			if(frame[j].val == p[s]){
				present = 1;
				frame[j].count = ++c;
				break;
			}
		}
		if(!present){
			for(j=0; j<m; j++){
				if(frame[j].count < mincount){
					mincount = frame[j].count;
					minpos = j;
				}
			}
			printf("Replaced frame %d with %d\n",frame[minpos].val,p[s]);
			frame[minpos].val = p[s];
			frame[minpos].count = ++c;
			faults++;
		}
	}
	printf("Faults: %d\n",faults);
}
