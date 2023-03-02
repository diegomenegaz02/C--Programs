#include <stdio.h>
#include <math.h>


float calcPrice(float amount){
	float discount;
	if(amount>=200.00){
		discount = amount/5;
		amount = amount-discount;
			
		printf("Military discount(20%%) \t %f \n ",discount);
	}else{
        	discount = amount *(0.15);
		amount = amount	- discount;
		printf("Military discount(15%%) \t %f \n",discount);
	}
	return(amount);
}

int  main(void){
	float total;
	char answer;
	float discountnum;	
	char y;
	printf("Cost of Purchase: ");
	scanf("\t%f", &total);
	 printf("In Military (y or n)?");
	 scanf("\t %c", &answer);
	 if(answer =='y'){
		printf("Cost of Purchase:\t %f \n ",total);
	        printf("In military(y or no)? \t %c \n", answer);	
		total = calcPrice(total);
		printf("Discounted total:\t %f \n ", total);
		discountnum = (total*.06);
		total = total + discountnum;
		printf("Sales tax (6%%) \t %f \n", discountnum);
		printf("Total \t %f \n ", total);
	 } else {

		 printf("Cost of Purchase:\t %f \n ",total);
	         printf("In military(y or no)? \t %c \n", answer);	
		 printf("Sales tax (6%%) \t %f \n", discountnum);
		 
		total = total + discountnum;
		 printf("Your total is\t %f \n", total);
		 
	 }return 0;
}

