#include<stdio.h>
#include<conio.h>

int main(){
	int i,n,v;
	char ch, s[150], name[50];
	FILE *f1;
	FILE *fnum, *fodd, *feven;
	clrscr();
	/*
	// ----------- Write in Loop ------------
	f1 = fopen("MCA.txt", "a");

	printf("\n\tHow many student ? : ");
	scanf("%d",&n);
	for(i=1	;i<=n;i++){
		printf("\n\tEnter %d student name: ", i);
		scanf(" %s", s);
		fprintf(f1, "\n\t%s", s);
	}
	*/

	//printf("\n\tEnter file name: ");
	//scanf("%s", name);
	//gets(s);

	/*
	// ------------ Write String --------------
	f1 = fopen(name, "a");

	flushall();

	printf("\n\tEnter paragraph: ");
	scanf("%[^\n]s", s);
	//gets(s);

	fprintf(f1, "%s", s); // write string
	*/

	// --------------- Reand Full File String ---------
	/*
	f1 = fopen(name, "r");
	printf("\n\t%s file data:- \n", name);
	while((ch=getc(f1)) != EOF){
		printf("%c", ch);
	}
	*/

	fnum = fopen("fnum.txt", "r");
	fodd = fopen("fodd.txt", "w");
	feven = fopen("feven.txt", "w");
	while(!feof(fnum)){
		fscanf(fnum, "%d", &v); // read integer from file and value store in v vareable
		if(v/2 != 0){
			fprintf(fodd, "%d ", v);
		}
		else{
			fprintf(feven, "%d ", v);
		}
	}
	fclose(fnum);
	fclose(fodd);
	fclose(feven);

	//fclose(f1);
	getch();
	return 0;
}
