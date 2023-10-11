#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// struct kullanarak stack işlemleri yaptık
// fakat push dolu ise artık hata mesajı dönmüyor
// artık stack dolu ise yeni bir dizi tanımlayıp stack boyutu 2 katına çıkıyor
// ilk dizimiz yenlsi açtığımız diziye kopyalanıyor ve ilk dizi ile işimiz bitince freele,


#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct stack
{
    int top;
    int size;
    int *dizi;
}typedef s;


int push(s stack,int *tab,int veri)
{
    if(stack.top+1 == stack.size)
    {
        printf("Stack Dolu \n");
        return -1;
    }
    else
    {
        stack.top++;
        tab[stack.top]= veri; 
        return stack.top;
    }
}
int pop(s stack)
{
    if(stack.top == -1)
    {
        printf("Stack boş \n");
        return -1;
    }
    else
    {
        stack.top--;
        return stack.top;
    }
}
void yazdir(s stack)
{
    int i = 0;
    while(i<stack.top+1)
    {
        printf("%d\n",stack.dizi[i]);
        i++;
    }
}
int main()
{
    s stack;
    stack.dizi = (int *)malloc(sizeof(stack));
    stack.top = -1;
    stack.size = 10;
    stack.top = push(stack,stack.dizi,232);
    stack.top = push(stack,stack.dizi,22);
    stack.top = push(stack,stack.dizi,23);
    stack.top = push(stack,stack.dizi,2342);
    yazdir(stack);
    printf("---pop---\n");
    stack.top=pop(stack);
    stack.top=pop(stack);
    stack.top=pop(stack);
    yazdir(stack);


}