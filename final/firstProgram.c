#include<stdio.h>
#include<stdlib.h>
int nP=0, n=0;
char prod[10][10], res[10];
void first(char);
int main()
{
	int i,c;
	char s,ch;
	printf("Enter no.of Productions: ");
	scanf("%d",&nP);
	for(i=0;i<nP;i++)
		scanf("%s%c",prod[i],&s);
	do {
		n=0;
		printf("Find First of :");
		scanf("%c",&ch);
		first(ch);
		printf("first(%c): {",ch);
		for(i=0;i<n;i++)
			printf("%c ,",res[i]);
		printf("}\n");
		printf("Enter 1 to continue ");
		scanf("%d%c",&c,&s);
	}while(c==1);
}
void first(char ch)
{
	int i;
	if(!(isupper(ch)))
		res[n++]=ch;
	for(i=0;i<nP;i++)
	{
		if(prod[i][0]==ch)
		{
			if(prod[i][2]=='#')
				res[n++]=prod[i][2];
			else if(islower(prod[i][2]))
				res[n++]=prod[i][2];
			else
				first(prod[i][2]);
		}
	}
}

/*
8
E=TR
R=+TR
R=#
T=FY
Y=*FY
Y=#
F=(E)
F=i
*/
/*
9
S=aBDh     {a ,}
B=cC       {c ,}
C=bC       {b ,# ,}
C=#
D=EF       {g ,# ,}
E=g        {g ,# ,}
E=#
F=f        {f ,# ,}
F=#
*/
