#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_KELIME_UZUNLUK 50

typedef struct 
{
    FILE *dosya;
    char kelime[MAX_KELIME_UZUNLUK];
    int bulundu;
} DosyaBilgisi;

void *dosyaKontrol(void *arg) {
    DosyaBilgisi *dosyaBilgisi = (DosyaBilgisi *)arg;
    char satir[256];

    while (!dosyaBilgisi->bulundu && fgets(satir, sizeof(satir), dosyaBilgisi->dosya) != NULL) {
        if (strstr(satir, dosyaBilgisi->kelime) != NULL) {
            dosyaBilgisi->bulundu = 1;
            break;
        }
    }

    pthread_exit(NULL);
}

int main() {
    char kelime[MAX_KELIME_UZUNLUK];
    printf("Kelimeyi girin: ");
    scanf("%s", kelime);

    FILE *dosya1 = fopen("deneme1.txt", "r");
    FILE *dosya2 = fopen("deneme2.txt", "r");
    FILE *dosya3 = fopen("deneme3.txt", "r");

    if (dosya1 == NULL || dosya2 == NULL || dosya3 == NULL) {
        printf("Dosyalar açılamadı.\n");
        return 1;
    }

    DosyaBilgisi dosyaBilgileri[3];
    dosyaBilgileri[0].dosya = dosya1;
    dosyaBilgileri[1].dosya = dosya2;
    dosyaBilgileri[2].dosya = dosya3;

    strcpy(dosyaBilgileri[0].kelime, kelime);
    strcpy(dosyaBilgileri[1].kelime, kelime);
    strcpy(dosyaBilgileri[2].kelime, kelime);

    pthread_t threadler[3];

    int i = 0;
    while (i < 3) {
        dosyaBilgileri[i].bulundu = 0;
        pthread_create(&threadler[i], NULL, dosyaKontrol, (void *)&dosyaBilgileri[i]);
        i++;
    }

    i = 0;
    while (i < 3) {
        pthread_join(threadler[i], NULL);
        i++;
    }

    fclose(dosya1);
    fclose(dosya2);
    fclose(dosya3);

    printf("Dosya1: %d\n", dosyaBilgileri[0].bulundu);
    printf("Dosya2: %d\n", dosyaBilgileri[1].bulundu);
    printf("Dosya3: %d\n", dosyaBilgileri[2].bulundu);

    return 0;
}