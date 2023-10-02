// partition.c
#include <stdio.h>

void displaysLine();
void sortsArrayByPivot(int [], int, int);
void swapsElements(int [], int, int);
void printArray(int [], int);

int main(void) {
	int i, pivot, size;

	printf("Enter the number of elements: ");
	scanf("%d", &size);
	int arr[size];

	printf("Enter %d integers: ", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter pivot: ");
	scanf("%d", &pivot);

	sortsArrayByPivot(arr, size, pivot);
	printArray(arr, size);

	return 0;
}

// Swaps elements
void swapsElements(int arr[], int firstIndex, int secondIndex) 
{
	int temp;
	temp = arr[firstIndex];
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
}

// Displays line
void displaysLine() 
{
	printf("------------------------------------------------------------------\ns");
}

// Sorts array based on pivot
// such that all elements <= pivot are before
// all numbers > pivot
void sortsArrayByPivot(int arr[], int size, int pivot) 
{
	int is_test = 0, left_pointer = 0, right_pointer = size - 1;

	if (is_test) {
		displaysLine();
		printf("* Before sort: ");
		printArray(arr, size);
		displaysLine();
	}

	while (left_pointer <= right_pointer) {
		while (arr[left_pointer] < pivot) 
		{	
			// If element that left pointer points to < pivot, go to next element
			left_pointer++;
		}

		while (arr[right_pointer] >= pivot) 
		{	
			// If element that right pointer points to >= pivot, go to next element
			right_pointer--;
		}

		// At this point, left pointer points to element >= pivot,
		// and right pointer points to element < pivot
		// swap only if the left and right pointers have not crossed one another
		// this 2nd condition is crucial because it is possible the left and right pointers have crossed each other
		// if yes, this means the left pointer points to an element < pivot,
		// and right pointer points to element >= pivot
		// hence the swapping of elements based on left pointer < pivot and right pointer >= pivot is wrong
		// because the elements these pointers point to are already at correct
		if (arr[left_pointer] >= pivot && arr[right_pointer] < pivot && left_pointer <= right_pointer)
		{	
			if (is_test) {
				printf("* so far, array before swap: ");
				printArray(arr, size);
				printf("* swap: index %d with index %d\n", left_pointer, right_pointer);
				printf("* so far, array after swap: ");
				printArray(arr, size);
				displaysLine();
			}
			swapsElements(arr, left_pointer++, right_pointer--);
		}
	}
}

// Prints array
void printArray(int arr[], int size) 
{
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
