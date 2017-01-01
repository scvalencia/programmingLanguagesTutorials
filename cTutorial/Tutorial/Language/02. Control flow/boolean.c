#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

bool NOT(bool X) {
	bool ans;
	if(X)
		ans = false;
	else
		ans = true;
	return ans;
}

bool AND(bool X, bool Y) {
	bool ans;
	if(X)
		if(Y)
			ans = true;
		else
			ans = false;
	else
		ans = false;
	return ans;
}

bool OR(bool X, bool Y) {
	bool ans;
	if(X)
		ans = true;
	else
		if(Y)
			ans = true;
		else
			ans = false;
	return ans;
}

bool IMP(bool X, bool Y) {
	bool ans;
	if(X)
		if(Y)
			ans = true;
		else
			ans = false;
	else
		ans = true;
	return ans;
}

bool EQV(bool X, bool Y) {
	bool ans;
	if(X)
		if(Y)
			ans = true;
		else
			ans = false;
	else
		if(Y)
			ans = false;
		else
			ans = true;
	return ans;
}

bool IF(bool X) {
	return X;
}

int main(int argc, char **argv) {
	printf("NOT: %d %d\n", NOT(0), NOT(1));
	printf("AND: %d %d %d %d\n", AND(0, 0), AND(0, 1), AND(1, 0), AND(1, 1));
	printf("OR:  %d %d %d %d\n", OR(0, 0), OR(0, 1), OR(1, 0), OR(1, 1));
	printf("IMP: %d %d %d %d\n", IMP(0, 0), IMP(0, 1), IMP(1, 0), IMP(1, 1));
	printf("EQV: %d %d %d %d\n", EQV(0, 0), EQV(0, 1), EQV(1, 0), EQV(1, 1));
	return 0;
}