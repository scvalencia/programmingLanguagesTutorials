# include <stdio.h>
void selection_Sort(int length, int array[]) {
	int maxInArray = 0, last = 0, position = 0;
	for(position = maxInArray; position < length; position++) 
		if(array[position] > maxInArray) 
			maxInArray = position;
	last = array[length - 1];
	array[length - 1] = array[position];
	array[position] = last;
	if(length > 1)
		selection_Sort(--length, array);	
}
int main(void) {
		
	void selection_Sort(int length, int array[length]);
	
	int mayuds[] = {4, 3, 5, 8};
	selection_Sort(3, mayuds);
	for(int i = 0; i < 4; i++)
		printf("%d ", mayuds[i]);
	printf("\n");	
	return 0;
}