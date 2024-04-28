// 202314409 김유미 
// 4주차 퀴즈 4.

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode { // 노드 타입을 구조체로 정의한다.
	element data;
	struct listnode* link;
} listnode;

// 맨 앞에 노드 삽입 
listnode* insert_first(listnode* head, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
listnode* insert(listnode* head, listnode* pre, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// 맨 앞의 노드를 삭제
listnode* remove_first(listnode* head) {
	listnode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
listnode* remove(listnode* head, listnode* pre) {
	listnode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// 역순의 리스트를 리턴하는 함수 작성
listnode* reverse(listnode* head) {
	// 순회 포인터로 p, q, r을 사용
	listnode* p, * q, * r;

	p = head;  // p는 역순으로 만들 리스트
	q = NULL;  // q는 역순으로 만들 노드

	while (p != NULL) {
		r = q;  // r은 역순으로 된 리스트
		// r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r;  // q의 링크 방향을 바꾼다
	}
	return q;
}

void print_list(listnode* head) {
	for (listnode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	listnode* head1 = NULL;
	listnode* head2 = NULL;

	for (int i = 4; i >= 1; i--) {
		head1 = insert_first(head1, i * 10);
	}
	print_list(head1);

	head2 = reverse(head1);
	print_list(head2);

	return 0;
}

