#include<stdio.h> 

int n;
char pro[100][100];

void addtores(char res[],char c){
	int i;
	for(i=0;res[i]!='\0';i++){
		if(res[i]==c) return;
	}
	res[i] = c;
	res[i+1] = '\0';
}

void first(char *res,char c){
	
	char subresult[20];
	int Epsilon;
	subresult[0]='\0';
	res[0]='\0';
	
	if(!isupper(c)){
		addtores(res,c);
		return;
	}
	int i;
	for(i=0;i<n;i++){
		if(pro[i][0]==c){
			if(pro[i][3]=='#') addtores(res,'#');
			else{
				int j=3;
				while(pro[i][j]!='\0'){
					Epsilon = 0;
					first(subresult,pro[i][j]);
					int k;
					for(k=0;subresult[k]!='\0';k++) if(subresult[k]!='#') addtores(res,subresult[k]);
					for(k=0;subresult[k]!='\0';k++) if(subresult[k]=='#') Epsilon = 1;
					if(Epsilon!=1) break;
					j++;
				}
				if(pro[i][j]=='\0') addtores(res,'#');
			}
		}
	}
	
}


void follow(char *res,char c){
	char substring[20];
	int epsilon = 0;
	res[0] = '\0';
	substring[0] = '\0';
	
	if(c==pro[0][0]) addtores(res,'$');
	int i;
	
	for(i=0;i<n;i++){
		int j = 3;
		while(pro[i][j]!='\0'){
		
			if(pro[i][j] == c){
				int l = j+1;
				
				while(pro[i][l]!='\0'){
					first(substring,pro[i][l]);
					int k;
					
					for(k=0;substring[k]!='\0';k++) if(substring[k]!='#') addtores(res,substring[k]);
					for(k=0;substring[k]!='\0';k++) if(substring[k]=='#') epsilon = 1;
					if(epsilon != 1) break;
					epsilon = 0;
					l++;
				}
				if(pro[i][l]=='\0' && pro[i][j]!=pro[i][0]){
					follow(substring,pro[i][0]);
					int k;
					for(k=0;substring[k]!='\0';k++) addtores(res,substring[k]);
					break;
				}
			}
			j++;
		}
	}
	return;
}


void main(){
	printf("Enter no of productions :");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%s",pro[i]);
	
	int visit[100];
	for(i=0;i<100;i++) visit[i]=0;
	for(i=0;i<n;i++) visit[pro[i][0]] = 1;
	
	char res[100];
	
	printf("NT\tfirst\t");
	printf("follow\n");
	for(i=0;i<100;i++){
		if(visit[i]==1){
			printf("%c\t",i);
			first(res,i);
			
			int j;
			for(j=0;res[j]!='\0';j++)
				printf("%c ",res[j]);
			printf("\t");
				
			follow(res,i);
				
			for(j=0;res[j]!='\0';j++)
				printf("%c ",res[j]);
				
			printf("\n");		
		}
		
	}
}
 
//	Enter no of productions :8
//	S->ABCD
//	A->a
//	A->#
//	B->b
//	C->c
//	C->#
//	D->d
//	D->e
//	NT      first   follow
//	A       a #     b
//	B       b       c d e
//	C       c #     d e
//	D       d e     $
//	S       a b     $

/*
S-aBDh
B-cC
C-bC/#
D-EF
E-g/#
F-f/#
first
s-a
B-c
C-b,#
D-g,f,#
E-g,#
F-f,#
follow
S-$
B-g,f,h
C-g,f,h
D-h
E-f,h
F-h

*/


