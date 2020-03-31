//Assignment 1 - QuickSort in C language
//Sukriti Agarwal

#include <stdio.h>

void qsort(int* a, int n); // quick sort array a with n elements in place in C (from assignment)
void swap(int* a, int* b);// function to swap elements
void print(int* a);// printer function for the array

int arrayLength;

int main() {
	arrayLength = 10;
	int a[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1 };
	//fill a[] with the elements as described in the lab handout
	printf("unsorted: ");
	//printing original array to make sure everything is working
	print(a);
	//calling qsort on the array to perform the sorting algorithm
	qsort(a, arrayLength);
	//print sorted array
	printf("\nsorted: ");
	print(a);
	return 0;
}

void qsort(int* a, int n) {	//quicksort algorithm
	if (n < 2) //an array of one element in implicitly sorted - the base length of 0/1 elements is sorted
		return;

	int pivot = a[n / 2];//selecting a pivot element in the middle of the array
	int* l = a;//finds element of left side of array
	int* r = a + n - 1;//finds element of right side of array (-1 because of the pivot)
	while (l <= r) {
		if (*l < pivot)//iterate through array until a number greater than pivot is found
			l++; //Numbers smaller than pivot should be on the left of the pivot
		else if (*r > pivot) //reverse iterate from right side until item less than pivot is found
			r--; //Numbers larger than pivot should be on the right side
		else {
			swap(l, r);//now swap elements - so they are in its right place
			l++; //Then increment the left
			r--; //Decrement the right
		}
	}
	//now make recursive calls until the entire list is sorted
	qsort(a, r - a + 1); //Sort the left of the pivot
	qsort(l, a + n - l); //Sort the right of the pivot
}

void swap(int* a, int* b) {
	//simple swap algorithm - create a temp so the two values are swapped
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int* a) {
	//simple print function
	int i;
	printf("[");
	for (i = 0; i < arrayLength; i++) {
		printf("%d", *(a + i));
		if (i < arrayLength - 1) //Print commas after every element except the last one
			printf(", ");
	}
	printf("]");
}