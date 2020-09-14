//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);
void menu();
void stats();

	//initialize array of 10 elements
	int values[10];

	//get length of array
	int length = (sizeof(values) / sizeof(values[0]));
	
	//global variables to be used in all sorting functions to keep track of cycles and swaps
	int cycles;
	int swaps;


int main(){


	menu();
	return(0);


} // end main



void printValues(){
	//print elements in array in proper order
	printf("[ ");

	int i;
	for(i=0; i < length; i++){
	
		printf("%d ", values[i]);	

	}
	printf("]\n");
}
void stats(){
	
	printValues();
	printf("Cycles: %d\n", cycles);
	printf("Swaps:  %d\n", swaps);

}

void swap(int* a, int* b){

	int temp;

	//store value of first element
	temp = *a;

	//change first index to be second index
	*a = *b;

	//give original a value to be stored at old b value
	*b = temp;
	
	swaps++;//add to number of times swap function is called
}	

void bubbleS(){

	//decare variables for for loops
	int i;
	int j;
 
	for (i = 1; i < length; i++){
		for (j = 0; j < length - 1; j++){
			if (values[j] > values[j+1]){
				swap(&(values[j]), &(values[j + 1]));
				printValues();//delete
				
			}
			cycles++;//add to num of comparisons
		}
	}
	printf("\n");
}
void selectionS(){

	//decare variables for for loops
	int i;
	int j;
	int min;//to store lowest index each pass
	for (i = 0; i < length - 1; i++){
		
		min = i;		

		for (j = i + 1; j < length; j++){
			if (values[min] > values[j]){
				min = j;
			}
				
			
			cycles++;//add to num of comparisons
		}
		swap(&(values[min]), &(values[i]));
		printValues();//delete
	}
	printf("\n");
}


void menu(){

	int i;
	int val;

	//reset values to be 0 so no left over values interfere with function or stats()
	swaps = 0;
	cycles = 0;
	val = 0;

	printf("Let me sort a 10 element array for you!");
	for(i = 0; i < length; i++){
		printf("Enter number %d: ", i+1);
		scanf("%d", &val);
		values[i] = val;	
	
	}
	
	printf("Before: ");
	printValues();

	do{
		//menu function looking for a response from the user on how they would like to sort the array
		printf("How would you like to sort the Array?\n\n1) Bubble Sort\n\n2) Selection Sort\n\n");
		scanf("%d", &val);//take in stray left over input	
		scanf("Enter the corresponding number: %d", &val);//take input from user
		

		if(val == 1){
	
			bubbleS();
			stats();

		}else if(val == 2){
	
			selectionS();
			stats();

		}else{
			printf("I'm sorry, I do not understand...");
			val = 0;
		}
	}while(val == 0);

}
