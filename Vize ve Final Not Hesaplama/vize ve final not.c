#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//vize ve finali girilen ��rencinin ge�ip ge�medi�ini yazd�ran program(vizenin y�zde 40'� finalin %60'�)
	
	int vize,final;
	float sonuc;
	
	
	printf("Vize notunuzu girin: ");
	scanf("%d",&vize);
	
	printf("Final notunuzu notunuzu girin: ");
	scanf("%d",&final);
	
	sonuc = vize*0.4+final*0.6;
	
	if (sonuc > 60){
		printf("Gectiniz\n");
	    printf("Notunuz:%.2f\n",sonuc);
	
	}
	else{
	
	printf("Kaldiniz\n");
	printf("Notunuz:%.2f\n",sonuc);
}
	return 0;
}
