#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DataPoint {
	float x, y;	
};

struct DataPoint getPoint() {
	float x, y;
	scanf("%f %f", &x, &y);

	struct DataPoint dp = {.x = x, .y = y};
	return dp;
}

void displayPoint(struct DataPoint dp) {
	printf("%f %f\n", dp.x, dp.y);
}

void displaySummary(struct DataPoint data[], int size) {
	float xavg, yavg;
	float sx, sy, sxy, sxx;
	float m, b;

	int i = 0;
	for(; i < size; i++) {
		struct DataPoint dp = *(data + i);
		sx += dp.x;
		sy += dp.y;
		sxy += dp.x * dp.y;
		sxx += dp.x * dp.x;
	}

	xavg = sx; yavg = sy;
	xavg = sx / size; yavg = sy / size;

	m = (sx * sy) - size * sxy;
	m /= (sx * sx) - size * sxx;

	b = (sy * sxx) - (sx * sxy);
	b /= (size * sxx) - (sx * sx);

	printf("\n");
	printf("data.x average: %f\n", xavg);
	printf("data.y average: %f\n", yavg);
	printf("regression.m: %f\n", m);
	printf("regression.b: %f\n", b);
}

int main(int argc, char const *argv[]) {

	int N;
	scanf("%d", &N);

	struct DataPoint* data = (struct DataPoint*) calloc(N, sizeof(struct DataPoint));

	int i = 0;
	for(; i < N; i++) {
		struct DataPoint dp = getPoint();
		*(data + i) = dp;
	}

	displaySummary(data, N);

	return 0;
}