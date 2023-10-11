#include <stdio.h>
#include <stdlib.h>

struct n
{
    int data;
    struct n *next;
} typedef node;

node *pop(node *tmp)
{
    if(tmp == NULL)
    {
        printf("Stack boş\n");
        return tmp;
    }

    node *silinen = tmp;
    tmp = tmp->next;
    printf("Çıkarılan eleman: %d\n", silinen->data);
    free(silinen);
    return tmp;
}

node *push(node *tmp, int veri)
{
    node *yeni = (node *)malloc(sizeof(node));
    if(yeni == NULL)
    {
        printf("Bellek hatası\n");
        exit(1);
    }

    yeni->data = veri;
    yeni->next = tmp;
    tmp = yeni;

    return tmp;
}

void yazdir(node *tmp)
{
    while(tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    node *start;
    start = NULL;

    start = push(start, 32);
    start = push(start, 12);
    start = push(start, 22);

    printf("Stack yapısı:\n");
    yazdir(start);

    start = pop(start);

    printf("Stack yapısı:\n");
    yazdir(start);

    start = pop(start);
    start = pop(start);
    start = pop(start);
    if(start == NULL)
        return 0;
    printf("Stack yapısı:\n");
    yazdir(start);

    return 0;
}