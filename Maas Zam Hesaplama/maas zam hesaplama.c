#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//FLOAT DEÐÝÞKENÝ
	
	float maas,yenimaas,zam;
	printf("Maas giriniz: ");
	scanf("%f",&maas);
	printf("Yapilacak zammý giriniz: ");
	scanf("%f",&zam);
	yenimaas=maas+(maas*zam/100);
	printf("%f",yenimaas);
	
	
	
	
	return 0;
	
}
