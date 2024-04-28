// 202314409 ������ 
// 4���� ���� 4.

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct listnode* link;
} listnode;

// �� �տ� ��� ���� 
listnode* insert_first(listnode* head, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
listnode* insert(listnode* head, listnode* pre, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// �� ���� ��带 ����
listnode* remove_first(listnode* head) {
	listnode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
listnode* remove(listnode* head, listnode* pre) {
	listnode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// ������ ����Ʈ�� �����ϴ� �Լ� �ۼ�
listnode* reverse(listnode* head) {
	// ��ȸ �����ͷ� p, q, r�� ���
	listnode* p, * q, * r;

	p = head;  // p�� �������� ���� ����Ʈ
	q = NULL;  // q�� �������� ���� ���

	while (p != NULL) {
		r = q;  // r�� �������� �� ����Ʈ
		// r�� q, q�� p�� ���ʷ� ���󰣴�.
		q = p;
		p = p->link;
		q->link = r;  // q�� ��ũ ������ �ٲ۴�
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

