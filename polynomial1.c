// 202314409 김유미 
// 3주차 퀴즈 1.

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a)>(b))?(a):(b))
#define max_degree 101

typedef struct { // 다항식 구조체 타입 선언
	int degree;// 다항식의 차수
	float coef[max_degree];// 다항식의 계수
} polynomial;

//polynomial poly_add1(polynomial a, polynomial b) { // c = a+b 여기서 a와 b는 다항식이다. 구조체가 반환된다. 
//	polynomial c;// 결과 다항식
//	int apos = 0, bpos = 0, cpos = 0;// 배열 인덱스 변수
//	int degree_a = a.degree;
//	int degree_b = b.degree;
//	c.degree = max(a.degree, b.degree); // 결과 다항식 차수
//	while (apos <= a.degree && bpos <= b.degree) {
//		if (degree_a > degree_b) {  // a항 > b항
//			c.coef[cpos++] = a.coef[apos++];
//			degree_a--;
//		}
//		else if(degree_a == degree_b) {  // a항 == b항
//			c.coef[cpos++] = a.coef[apos++] + b.coef[bpos++];
//			degree_a--;
//			degree_b--;
//		}
//		else {// b항 > a항
//			c.coef[cpos++] = b.coef[bpos++];
//			degree_b--;
//		}
//	}
//	return c;
//}

polynomial poly_sub1(polynomial a, polynomial b) { // c = a+b 여기서 a와 b는 다항식이다. 구조체가 반환된다. 
	polynomial c;// 결과 다항식
	int apos = 0, bpos = 0, cpos = 0;// 배열 인덱스 변수
	int degree_a = a.degree;
	int degree_b = b.degree;
	c.degree = max(a.degree, b.degree); // 결과 다항식 차수
	while (apos <= a.degree && bpos <= b.degree) {
		if (degree_a > degree_b) {  // a항 > b항
			c.coef[cpos++] = a.coef[apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // a항 == b항
			c.coef[cpos++] = a.coef[apos++] - b.coef[bpos++];
			degree_a--;
			degree_b--;
		}
		else {// b항 > a항
			c.coef[cpos++] = b.coef[bpos++];
			degree_b--;
		}
	}
	return c;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_sub1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}

