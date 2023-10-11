#include <stdio.h>
#include <stdlib.h>

struct n
{
    int data;
    struct n *next;
};
typedef struct n node;

node *sona_ekleme(node *tmp, int veri)
{
    if (tmp == NULL)
    {
        tmp = (node *)malloc(sizeof(node));
        tmp->data = veri;
        tmp->next = NULL;
        return tmp;
    }

    node *iter = tmp;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    node *yeni = (node *)malloc(sizeof(node));
    yeni->next = NULL;
    yeni->data = veri;
    iter->next = yeni;
    return tmp;
}

void yazdir(node *tmp)
{
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

node *basaekle(node *tmp, int veri)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = veri;
    new->next = tmp;
    return new;
}

node *sondansil(node *tmp)
{
    if (tmp == NULL)
    {
        return NULL;
    }

    if (tmp->next == NULL)
    {
        free(tmp);
        return NULL;
    }

    node *iter = tmp;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }

    free(iter->next);
    iter->next = NULL;
    return tmp;
}

node *bastansil(node *tmp)
{
    if (tmp == NULL)
    {
        return NULL;
    }

    node *new_start = tmp->next;
    free(tmp);
    return new_start;
}

void arayaekle(node *tmp, int x, int y)
{
    while (tmp->data != x)
        tmp = tmp->next;

    node *new = (node *)malloc(sizeof(node));
    new->next = tmp->next;
    new->data = y;
    tmp->next = new;
}

int main()
{
    node *start = NULL;
    int i = 0;

    while (i < 6)
    {
        start = sona_ekleme(start, i * 10);
        i++;
    }

    yazdir(start);
    arayaekle(start, 30, 62);
    start = basaekle(start, 55);
    start = sondansil(start);
    start = bastansil(start);
    start = basaekle(start, 55);
    start = basaekle(start, 55);
    start = basaekle(start, 55);
    yazdir(start);

    // Belleği temizle
    while (start != NULL)
    {
        node *temp = start;
        start = start->next;
        free(temp);
    }

    return 0;
}