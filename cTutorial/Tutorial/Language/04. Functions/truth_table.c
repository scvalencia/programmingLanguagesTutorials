#include <stdio.h>
#include <stdbool.h>

bool expressionAB(bool A, bool B);
bool expressionAC(bool A, bool C);
bool expressionABC(bool A, bool B, bool C);
bool expression(bool A, bool B, bool C);


int main(void)
{
	printf("%s\n", (expression(0,0,0))? "True" : "False");
	printf("%s\n", (expression(0,0,1))? "True" : "False");
	printf("%s\n", (expression(0,1,0))? "True" : "False");
	printf("%s\n", (expression(0,1,1))? "True" : "False");
	printf("%s\n", (expression(1,0,0))? "True" : "False");
	printf("%s\n", (expression(1,0,1))? "True" : "False");
	printf("%s\n", (expression(1,1,0))? "True" : "False");
	printf("%s\n", (expression(1,1,1))? "True" : "False");
	return(0);
}

bool expressionAB(bool A, bool B)
{
	bool AB_value;
	AB_value = A && B;
	return(AB_value);
}
bool expressionAC(bool A, bool C)
{
	bool AC_value;
	AC_value = A && C;
	return(AC_value);
}
bool expressionABC(bool A, bool B, bool C)
{
	bool ABC_value;
	ABC_value = A && B && C;
	return(ABC_value);
}
bool expression(bool A, bool B, bool C)
{
	bool expression;
	expression = expressionAB(A, B) || expressionAC(A, C) || expressionABC(A, B, C);
	return expression;
}