//bubble.c
//pefully it runs sixty four times
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){
	printf("Before:  \n");
	printValues();
	printf("\n");
	sort();
	printf("After: \n");
	printValues();





  return(0);
} // end main

void printValues(){
	//print elements in array in proper order
	printf("[ %d %d %d %d %d %d %d %d %d ]\n", values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8]);
}

void swap(int* a, int* b){

	int temp;

	//store value of first element
	temp = *a;

	//change first index to be second index
	*a = *b;

	//give original a value to be stored at old b value
	*b = temp;
	

}

void sort(){


	//define i, j, cycle variable
	int i;
	int j;
 	int cycles = 0;	

	//go throught the for loop while is is from 0 to 8 cycle this to be used as the first index
	for (i = 0; i < MAX - 1; i++){
		for (j = 0; j < MAX - 1; j++){
			if (values[j] > values[j + 1]){
				swap(&(values[j]), &(values[j + 1]));
				printValues();// shwo changes

			} 
			
			cycles ++;//add number of times the array has been examined(two values have been compared in the array
		
		}

	}
	
	printf("Comparisons made: %d\n\n", cycles);//print number of cycles at end of sorting function
}

