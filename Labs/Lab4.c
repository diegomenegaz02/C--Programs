#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readFile(){

/*Diego Menegaz, Lab 4 10/6/202 */

FILE* filePointer;
filePointer =fopen("/public/lab4/hurricanes.csv","r");
if (filePointer == NULL){
	printf("Error with file");
	return;
}
char *line;
line = (char *)malloc(100); //Alocating space for line
char *copy[40];
char *data[40];
char *dataN[40];
char *trash[40];
char *trash2[40];
char *monthDay[40];
char *year[40];
char *space= (" ");
char *indent = {" \t"};
int count =0;



void SelectionSort(char *strs[],int size);


for(int i=0;i<40;i++){
	data[i] = malloc(sizeof(char)*200);//Allocating space on each spot in arr
	monthDay[i] = malloc(sizeof(char)*200);
	year[i] = malloc(sizeof(char)*200);	
	trash[i] = malloc(sizeof(char)*200);//Allocating space on each spot in arr
	trash2[i] = malloc(sizeof(char)*200);
	dataN[i] = malloc(sizeof(char)*200);//Allocating space on each spot in arr
	copy[i] = malloc(sizeof(char)*200);//Allocating space on each spot in arr
	}
while(fgets(line,45,filePointer)!=NULL){
	strcpy(copy[count],line);//using compy it will avoid some errors it did in the example
	//SelectionSort(copy[count],40);(Was supposed to compare and swap but would not work
	data[count] = strtok(copy[count],","); //Will combine name and cat but for now just name 
	trash[count] = strtok(NULL,"y");//Taking out the Category trash 
	dataN[count] = strtok(NULL," ");//Grabs Num
	trash2[count] = strtok(NULL,",");
	monthDay[count] = strtok(NULL,",");
	year[count] = strtok(NULL,"\n");	

	if(strlen(data[count]) < 7){

	strcat(data[count],indent); 
				    }
	strcat(data[count],indent); //Will add the space needed between the two
	strcat(data[count],dataN[count]); //Combines into one string so I have to do less to get it into file
	strcat(data[count],space);
	strcat(data[count],monthDay[count]);
	
	count++;
}
FILE* writePointer;
writePointer = fopen("Lab4.2.txt","w");
if(writePointer == NULL){
	printf("Error with Write File");
	printf("Have to get rid of warning %s and %s\n",trash[0],trash2[0]);
	return;
}
fprintf(writePointer,"Name and Category of Hurricanes\n");
for(int i=0; i<40;i++){
	
	fprintf(writePointer,"%s %s\n",data[i],year[i]);} //Adds single string to each line effectively filling it
fclose(filePointer);
fclose(writePointer);
}
void SelectionSort(char *strs[],int size){
	int i,j;
	char *temp[size];
	for(int p =0;p<size;p++){
	temp[p] = malloc(sizeof(char)*200);
	}
		
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(strcmp(strs[i],strs[j]) > 0){
					strcpy(temp[i],strs[i]);
					strcpy(strs[i],strs[j]);
					strcpy(strs[j],temp[i]);
					}
				}
			}
			}
int main(void){
	readFile();
	return 0;

}
