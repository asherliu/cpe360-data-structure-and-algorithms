#include <assert.h>
#include <iostream>
#include <math.h> 
#include <stdio.h> 
#include <string.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubble_sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}



/* Function to sort an array using insertion sort*/
void insertion_sort(int *arr, int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

void selection_sort(int *arr, int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 


// Driver code
int main(int args, char **argv)
{
    std::cout<<"/path/to/exe count\n";
    assert(args>1);
    int count = atoi(argv[1]);

    int *array_bubble = new int[count];
    int *array_select = new int[count];
    int *array_insert = new int[count];

    for(int i = 0; i < count; i ++)
    {
        int tmp = rand()%23425345;
        array_bubble[i] = tmp;
        array_select[i] = tmp;
        array_insert[i] = tmp;

    }

    bubble_sort(array_bubble, count);
    insertion_sort(array_insert, count);
    selection_sort(array_select, count);

    
    assert(memcmp(array_bubble,array_insert,sizeof(int)*count) == 0);
    assert(memcmp(array_bubble,array_select,sizeof(int)*count) == 0);

    
    std::cout<<"The sorting results match!\n";
}

