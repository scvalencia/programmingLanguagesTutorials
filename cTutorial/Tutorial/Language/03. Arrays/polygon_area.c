#include <stdio.h>

void output_corners(double array_x[], double array_y[], int size);
double polygon_area(double array_x[], double array_y[], int size);
double absolute_value(double b);

int main(void)
{
	double array_x[20];
	double array_y[20];
	int length;
	int sum = 0;


	printf("Introduce the length of the arrays: ");
	scanf("%d",&length);
	if(length > 20) printf("Length out of allowed bounds.\n");
	else
	{
		printf("Introduce the X vector of the coordinates of the polygon.\n");
		for(int i = 0; i < length; i++) scanf("%lf",&array_x[i]);
		printf("Introduce the Y vector of the coordinates of the polygon.\n");
		for(int i = 0; i < length; i++) scanf("%lf",&array_y[i]);
		if((array_x[0] != array_x[length-1]) || (array_y[0] != array_y[length-1]))
			printf("\nIs not a closed region.\n");
		else
		{
			printf("The area of the polygon with\nthe following coordinates is:\n");
			output_corners(array_x, array_y, length);
			printf("Area: %lf\n", polygon_area(array_x, array_y, length) );
		}
	}
	return 0;
	
}
void output_corners(double array_x[], double array_y[], int length)
{
	printf("\nx\t\ty\n");
	for(int j = 0; j < length; j++) printf("%f\t%f\n",array_x[j], array_y[j]);
	printf("\n\n");

}
double polygon_area(double array_x[], double array_y[], int size)
{
	double summation = 0;
	double area_net;
	double area;
	for(int i = 0; i <= (size-1); i++)
	{
		summation += (array_x[i+1] + array_x[i])*(array_y[i+1]-array_y[i]);
	}
	area_net = absolute_value(summation);
	area = area_net * 0.5;
	return(area);
}
double absolute_value(double b)
{
	double a;
	a = (b >= 0)?b:0-b;
	return a;
}
