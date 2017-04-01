#include <stdio.h>

int main(){
	int n,m;
	int i,j;
	printf("String length\t");
	scanf("%d",&n);
	int p[n];	
	printf("Reference String\n");
	for(i=0; i<n; i++){
		scanf("%d",&p[i]);
	}
	printf("Frame length\t");
	scanf("%d",&m);
	int frame[m];
	for(i=0; i<m; i++)
		frame[i] = -1;

	int empty = 0;
	int faults = 0;
	int present;
	for(i=0; i<n && empty < m; i++){
		present = 0;
		for(j=0; j<m; j++){
			if(p[i] == frame[j]){
				present = 1;
				break;	
			}
			else if(frame[j] == -1)
				break;
		}
		if(!present){
			frame[empty++] = p[i];
			faults++;
		}
	}

	int s, k;
	int replace, pos;
	int maxpos;
	for(s = i; s<n; s++){
		present = 0;
		for(j=0; j<m; j++){
			if(p[s] == frame[j]){
				present = 1;
				break;	
			}

		}
		if(!present){
			maxpos = 0;
			for(j=0; j<m; j++){
				present = 0;
				for(k=s+1; k<n; k++){
					if(p[k] == frame[j]){
						present = 1;
						if(k > maxpos){
							maxpos = k;
							replace = frame[j];
							pos = j;
						}
						break;
					}
				}
				if(!present){
					replace = frame[j];
					pos = j;
					break;
				}
				
			}
			printf("Replaced frame %d with %d\n",replace,p[s]);
			frame[pos] = p[s];
			faults++;
		}
	}
	printf("Faults: %d\n",faults);
	
	return 0;
}
