#include <stdio.h>
#include <stdlib.h>

int main() {
	
	 
	   int islem,bakiye=1000,tutar;
	   int sifre;
	   
	  printf("Sifrenizi Giriniz: ");
	  scanf("%d",&sifre);
	  if (sifre == 1234){
	  	printf("Islemler\n\n1:Para cekme\n2:Para yatirma\n3:Havale\n4:Bakiye Sorgula\n5:Kart iade\n\n\n");
	  printf("Islemi seciniz:");
	  scanf("%d",&islem);
	  }
	  	
	  else {
	  	printf("Sifreniz Yanlis Tekrar Deneyin");
	  	goto son;	
      }
	  switch(islem){
	
	  case 1:
	  	printf("Bakiyeniz:%d\n",bakiye);
	  	printf("Cekilecek Tutar:");
	  	scanf("%d",&tutar);
	  	if(tutar > bakiye){
	  		printf("Bakiye Yetersiz\n");
		  }
		  bakiye= bakiye-tutar;
		  printf("Bakiyeniz: %d",bakiye);
		  break;
	  	
	  
	  case 2:
	  	printf("Bakiyeniz:%d\n",bakiye);
	  	printf("Yatirilicak Tutar:");
	  	scanf("%d",&tutar);
	  	
		  bakiye= bakiye+tutar;
		  printf("Bakiyeniz: %d",bakiye);
		  break;
	  	
	  case 3:
	    printf("Bakiyeniz:%d\n",bakiye);
	  	printf("Havale Yapilacak Tutar:");
	  	scanf("%d",&tutar);
	  	if(tutar >  bakiye){
	  		printf("Bakiye Yetersiz\n");
		  }
		  bakiye= bakiye-tutar;
		  printf("Bakiyeniz: %d",bakiye);
		  break;
	 
	  case 4:
	    printf("Bakiyeniz:%d\n",bakiye);
		  break;
	  
	  case 5:
	   printf("**Kartinizi Alabilirsiniz**\n");
	   break;
	   
	   default:
	   	printf("Bilinmeyen islem");
	   	break;
	  
	  }
	  	
	son:		
	 return 0;	
		
	}
	
   
   
   


