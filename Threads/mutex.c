/*
Mutex (Mutual Exclusion), programlamada eşzamanlılık problemlerini çözmek için kullanılan bir senkronizasyon mekanizmasıdır. 
Mutex, kaynaklara veya belirli kod bloklarına eşzamanlı erişimi kontrol etmek için kullanılır.

Mutex, bir anahtar gibi düşünülebilir. Bir iş parçacığı (thread) belirli bir kaynağa erişmek istediğinde, mutex kilidini talep eder. 
Eğer mutex kilidi serbest ise (yani başka bir iş parçacığı tarafından kullanılmıyorsa), iş parçacığı kaynağa erişim sağlar ve mutex kilidini kendisi alır. Bu işlem sonucunda, başka iş parçacıkları aynı kaynağa eşzamanlı olarak erişmeye çalıştığında, mutex kilidi dolu olduğu için beklemek zorunda kalır.

Mutex'in temel amacı, aynı anda yalnızca bir iş parçacığının belirli bir kaynağa erişmesini sağlamaktır.
 Bu sayede, race condition gibi eşzamanlılık sorunlarının önüne geçilir ve kaynakların tutarlı bir şekilde kullanılması sağlanır.

Bir mutex genellikle iki temel işlemi destekler:

Kilitleme (Locking): İş parçacığı, belirli bir kaynağa erişmek istediğinde mutex kilidini talep eder.
Eğer mutex kilidi serbest ise, iş parçacığı kaynağa erişim sağlar ve mutex kilidini alır. Bu işlem, kaynakla ilgili işlemlerin güvenli bir şekilde gerçekleşmesini sağlar.

Kilidi Açma (Unlocking): İş parçacığı, kaynak kullanımını tamamladıktan sonra mutex kilidini bırakır veya serbest bırakır. Bu işlem, başka iş parçacıklarının aynı kaynağa erişim yapabilmesini sağlar.

Mutex'ler, özellikle paylaşılan bellek veya kaynak kullanımı gerektiren çoklu iş parçacıklı programlarda sıklıkla kullanılır. 
Mutex'ler sayesinde, kritik bölge adı verilen belirli kod blokları, yalnızca tek bir iş parçacığı tarafından aynı anda erişilebilir hale gelir ve eşzamanlılık problemleri önlenir.
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int globalvar = 0;
pthread_mutex_t mutex;
#define THREAD_NUM 64

void *mainthread(void *args)
{
    usleep(1000 + rand() % 9000);
    //pthread_mutex_lock(&mutex);
    if(((int)args % 2 == 0))
        globalvar += 1;
    else
        globalvar -= 1;
    //pthread_mutex_unlock(&mutex);
    return NULL;
}
int main()
{
    srand(time(NULL));
    pthread_mutex_init(&mutex,NULL);
    pthread_t tid[THREAD_NUM];
    int i = 0;
    while(i < THREAD_NUM)
    {
        if(pthread_create(&tid[i],NULL,&mainthread,(void *)i) < 0) // eğer dönen değer 0 ise thread oluşturma başarılı :)
        {
            printf("Thread oluşturmadik :( \n");
            break;
        }
        i++;
    }
    int j = 0;
    while(j < i)
    {
        pthread_join(tid[j],NULL);
        j++;
    }
    printf("Globalvar : %d\n",globalvar);
    pthread_mutex_destroy(&mutex);

}