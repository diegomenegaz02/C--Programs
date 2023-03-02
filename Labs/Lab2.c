#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*Diego Menegaz Lab 2
 * CSCI 112*/

int  splitNum(int  a){
	int origin = a;
	int counter =0;
	while(a != 0){
	counter = counter + (a% 10);//Remainder removes last num from line
	a = a/10; //gets rid of remainder to goes to second num
	}
       	if(counter % 9==0){ //If Divisable by 9 return true
		printf("%d Is divisable by 9, because %d is divisable by 9\n",origin,counter);}	
	else if(counter %9 !=0){//if not returns false
		printf("%d Is not divisable by 9 since %d is not divisable by 9 \n",origin,counter);}
	return 0;
	

}
int main(void){
	int input;
	int num;
	int size = 10;
	int printnum;
	int array[size];
	int total=0;		
	printf("Please Enter Your Number Here: ");
	scanf(" %d",&input);
	num = input;
	
	for(int i=0; i< size; i++){
		printnum = num % 10;//Splits number up to be printed
		array[i]=printnum; // You know where this is going
		num = num/10;
		printnum =0;
	}
	for(int j=size;j>=0;j--){
		total = total + array[j];
		printnum = array[j];
		if(printnum !=0&& j!=0){
		printf("%d + " , printnum);}
		else if(printnum !=0 && j==0){

		printf("%d = %d \n " , printnum,total);}
		
	}	
	splitNum(input);
	return 0;}

