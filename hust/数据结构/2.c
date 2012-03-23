#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int elem;
	struct node * next;
};

struct node *head;

void creat(struct node *head, int n) {
	int i = 0;
	struct node *p, *q = head;
	for (; i < n; i++, q = q->next) {
		p = (struct node *) malloc(sizeof(struct node));
		scanf("%d", &(p->elem));
		p->next = 0;
		q->next = p;
	}
}

int insert(struct node *head, int k, int e) {
	int i = 0;
	struct node *p, *q = head;
	for (; i < k && q; i++, q = q->next) ;
	if (q == 0) return 0; 
	p = (struct node *) malloc(sizeof(struct node));
	p->next = q->next;
	p->elem = e;
	q->next = p;
	return 1;
}

int delete(struct node *head, int k) {
	int i = 0;
	struct node *p, *q = head;
	for (; i < k && q; i++, q = q->next) ;
	if (q == 0 || q->next == 0) return 0;
	p = q->next,
	q->next = q->next->next;
	free(p);
	return 1;
}

int findelem(struct node *head, int k) {
	int i = 0;
	struct node *p, *q = head;
	for (; i < k && q->next; i++, q = q->next)
		if (q->next->elem == k) {
			printf("POS %d", i);
			return 1;
		}
	return 0;
}

void showlist(struct node *head) {
	struct node *q = head;
	for (; q->next; q = q->next) 
		printf("%d ", q->next->elem);
	puts("");
}

int main() {
	int n, k, e, c;
		
	while(1){
		puts("             ");
		puts("             choose number 0~5:");
		puts("             1:creat list");
		puts("             2:insert element");
		puts("             3:delete elemetnt");
		puts("             4:find element");
		puts("             5:show list");
		puts("             0:exit");

		scanf("%d", &c);
		switch(c) {
			case 0: return 0;
			case 1: puts("input a number N:");
				scanf("%d", &n);
				printf("input %d numbers:\n", n);
				head = (struct node *) malloc(sizeof(struct node));
				head->next = 0;
				creat(head, n);
				puts("creat done");
				break;
			case 2: puts("input the position K and the element E:");
				scanf("%d%d", &k, &e);
				c = insert(head, k, e);
				if (c) puts("insert done");
				else puts("insert error");
				break;
			case 3: puts("input the position K:");
				scanf("%d", &k);
				c = delete(head, k);
				if (c) puts("delete done");
				else puts("delete error");
				break;
			case 4: puts("input the value K:");
				scanf("%d", &k);
				c = findelem(head, k);
				if (!c) puts("findelem error");
				break;
			case 5: showlist(head) ; break;
		}
	}

	return 0;
}
