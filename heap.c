//202314409 ������ 
// 3���� ���� 3.

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	double* p1;
	p1 = (double*)malloc(sizeof(double));  // ���� �޸� �Ҵ�

	if (p1 == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}

	*p1 = 23.92;

	printf("%.2f\n", *p1);

	free(p1);  // ���� �޸� �ݳ�

	return 0;
}