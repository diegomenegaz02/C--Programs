#include <stdio.h>
#include <stdlib.h>
/*
 * Diego Menegaz, 9/25/2022 CSCO112 Lab 3
 * (I ALMOST FORGOT TO DO IT AGAIN)*/

void Grades(int size,int howManywrong[size]){
	printf("\nQuestion\t");//Realized should use size since coule be more answers
	for(int i=0;i<size;i++){
		printf("%d ",i+1);
	}
	printf("\nMissed By: \t");
	for(int k=0; k<size;k++){
	if(k!=size-1){

	printf("%d ",howManywrong[k]);
	}else{printf("%d\n ",howManywrong[k]);}
	}
}

//Had all var without using perm to call in main so first we fix
//
void readAnswers(int size,FILE* filePointer,char correctA[size]){
	//Citing Several Videos on how to use fscanf, im talkin hours of footage here.
	int ID;
	double score=0;
        float score2=0;	
	int howManywrong[size];
	char studentA[size];
	printf("\n");
	printf("ID\tGrade(%%)\n");
	for(int p=0; p<size;p++){
		howManywrong[p]=0;}


	while(fscanf(filePointer,"%d",&ID) ==1){
		 score =0;
		 char space;
		 fscanf(filePointer,"%c",&space); //Needs to get out of way cant be put into arr will break hate the space
		 for(int i=0; i<size;i++){
			 fscanf(filePointer,"%c", &studentA[i]);
			 if(studentA[i] == correctA[i]){
				 score++;//answer right score should reflect duh
			 }else{
				 howManywrong[i+1]++;//will match to question on who got what wrong
						     //plus 1 to make sure it lines up with space
			 }
			 
	 score2 =(score/size)*100;}
	printf("%d\t%0.2f%%\n",ID,score2);}//Fancy Formatting :D
	Grades(size,howManywrong);//Called once per line while loop
}

int main(void){
	FILE* filePointer;	
	filePointer=fopen("/public/lab3/exam.txt","r"); //Glad this worked
	if(filePointer == NULL){
		printf("File not Found\n");//Check if file name is all good
		return 1;
	}else{
		//Need to call the first line outside of the loop
		int size;
		fscanf(filePointer,"%d",&size);
		char correctA[size];
		printf("\nQuestion\t");
		char space;//again getting rid of pesky space 
		fscanf(filePointer,"%c",&space);//It took like 12 videos for me to get I should do fscanf for each unique element :D
		for(int i=0;i<size;i++){
			fscanf(filePointer,"%c", &correctA[i]);
			printf("%d", i);}
		printf("\nAnswer\t");
		for(int n=0;n<size;n++){
			printf("%c ",correctA[n]);}
	readAnswers(size,filePointer,correctA);
	}
	return 0;
}
