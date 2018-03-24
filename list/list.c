#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int num;
	struct node_t *next;
} node_t;

node_t *node_init(void)
{
	node_t *s;

	s = (node_t *) malloc(sizeof(node_t));
	if (NULL == s) {
		printf("error\n");
		return NULL;
	}
	s->num = 0;
	s->next = NULL;

	return s;

}

node_t *node_add(node_t * src, int num)
{
	node_t *add;

	add = (node_t *) malloc(sizeof(node_t));
	if (NULL == add) {
		printf("error\n");
		return NULL;
	}
	add->num = num;
	add->next = src->next;
	src->next = add;
	return src;
}

node_t *node_insert(node_t * src, int index, int num)
{
	node_t *p, *add;
	int i;

	p = src->next;
	i = 0;
	while (NULL != p && i < index - 1) {
		i++;
		p = p->next;
	}

	add = (node_t *) malloc(sizeof(node_t));
	if (NULL == add) {
		printf("error\n");
		return NULL;
	}
	add->num = num;
	add->next = p->next;
	p->next = add;

	return src;
}

void node_delete(node_t * src)
{
	node_t *p, *tmp;

	p = src->next;
	src->next = NULL;
	while (p != NULL) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}

void node_print(node_t * src)
{
	while (NULL != src->next) {
		printf("%d\n", src->next->num);
		src->next = src->next->next;
	}
}

int main()
{
	int i;
	node_t *src;

	src = node_init();
	for (i = 0; i < 20; i++) {
		src = node_add(src, i * 10);
	}
	src = node_insert(src, 3, 45);
	node_print(src);
	node_delete(src);

	return 1;

}
