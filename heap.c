//202314409 김유미 
// 3주차 퀴즈 3.

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	double* p1;
	p1 = (double*)malloc(sizeof(double));  // 동적 메모리 할당

	if (p1 == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	*p1 = 23.92;

	printf("%.2f\n", *p1);

	free(p1);  // 동적 메모리 반납

	return 0;
}