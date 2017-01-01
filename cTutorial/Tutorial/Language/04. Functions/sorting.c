#include <stdio.h>
#define LENGTH 10

void bubbleSort(int array[], int n);
void selectionSort(int numbers[], int n);
void quickSort(int a[], int low, int high);
int split(int a[], int low, int high);
void printQuickSort(int a[]);

int main(void) {

	printf("Introduce the list: ");
	int vector[LENGTH];

	for(int j = 0; j < LENGTH; j++)
		scanf("%d", &vector[j]);

	printf("------------------------\n");
	
	printf("List: ");
	for(int i = 0; i < LENGTH; i++)
		printf("%d ", vector[i]);
	printf("\n");

	bubbleSort(vector, LENGTH);

	selectionSort(vector, LENGTH);

	printQuickSort(vector);

	printf("------------------------\n");
	return 0;

}

void bubbleSort(int numbers[], int n) {
	int i, j, temp;
	int b[LENGTH];
	for(int i = 0; i < LENGTH; i++)
		b[i] = numbers[i];
	for (i = (n - 1); i > 0; i--) {
    	for (j = 1; j <= i; j++) {
      		if (b[j-1] > b[j]) {
        		temp = b[j-1];
        		b[j-1] = b[j];
        		b[j] = temp;
      		}
    	}
  	}
	printf("Bubble sort: ");
	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
}

void selectionSort(int numbers[], int n) {
	int i, j, temp, least;
	int a[LENGTH];
	for(int o = 0; o < LENGTH; o++)
		a[o] = numbers[o];
	for(i = 0; i < LENGTH; i++){
      for(j = i + 1; j < LENGTH; j++){
           if(a[i] > a[j]) {
           	temp = a[i];
            a[i] = a[j];
            a[j] = temp;
           }
      }
  }
	printf("Selection sort: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void quickSort(int a[], int low, int high) {
	int middle, counter;
	if(low >= high) return;
	middle = split(a, low, high);
	quickSort(a, low, middle - 1);
	quickSort(a, middle + 1, high);
}

int split(int a[], int low, int high) {
	int part_element = a[low];
	for(;;) {
		while(low < high && part_element <= a[high])
			high--;
		if(low >= high) break;
		a[low++] = a[high];
		while(low < high && a[low] <= part_element)
			low++;
		if(low >= high) break;
		a[high--] = a[low];
	}
	a[high] = part_element;
	return (high);
}

void printQuickSort(int a[]) {
	int b[LENGTH];
	for(int i = 0; i < LENGTH; i++)
		b[i] = a[i];
	quickSort(b, 0, LENGTH - 1);
	printf("Quick sort: ");
	for(int i = 0; i < LENGTH; i++)
		printf("%d ", b[i]);
	printf("\n");
}
