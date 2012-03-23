#include <stdio.h>
#include <string.h>

#define maxlen 100

typedef struct {
	int elem[maxlen];
	int length;
}sqlist;

sqlist a;

int delete(sqlist *a, int k) {
	if (k >= a->length) return 0;
	int i;
	for (i = k; i < a->length - 1; i++)
		a->elem[i] = a->elem[i + 1];
	a->length--;
	return 1;
}

int insert(sqlist *a, int k, int e) {
	if (k > a->length) return 0;
	int i;
	for (i = a->length - 1; i >= k; i--)
		a->elem[i + 1] = a->elem[i];
	a->elem[k] = e;
	a->length++;
	return 1;
}

void creat(sqlist *a, int n) {
	a->length = n;
	int i = 0;
	for (; i < n; i++)
		scanf("%d", &a->elem[i]);
}

int findelem(sqlist *a, int k) {
	int i = 0;
	for (; i < a->length; i++)
		if (a->elem[i] == k) {
			printf("POS = %d\n", i);
			return 1;
		}
	return 0;
}

void showlist(sqlist *a) {
	int i = 0;
	for (; i < a->length; i++)
		printf("%d ", a->elem[i]);
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
				creat(&a, n);
				puts("creat done");
				break;
			case 2: puts("input the position K and the element E:");
				scanf("%d%d", &k, &e);
				c = insert(&a, k, e);
				if (c) puts("insert done");
				else puts("insert error");
				break;
			case 3: puts("input the position K:");
				scanf("%d", &k);
				c = delete(&a, k);
				if (c) puts("delete done");
				else puts("delete error");
				break;
			case 4: puts("input the value K:");
				scanf("%d", &k);
				c = findelem(&a, k);
				if (!c) puts("findelem error");
				break;
			case 5: showlist(&a) ; break;
		}
	}

	return 0;
}
