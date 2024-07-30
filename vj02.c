//zd1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*•	int* podniz(int *niz, int start, int stop) – vraca novi niz koji je kopija dijela niza od indeksa start do indeksa stop.*/
int* podniz(int niz[], int start, int stop){

  int* niz3 = (int*)malloc(sizeof(int)*(stop-start+1));
  for(int i = 0; i < (stop-start+1); i++){
      *(niz3+i)=niz[start+i];
  }
  printf("\n");
  return niz3;
}


int main(void)
{
     int niz[10]={2,5,1,3,6,5,8,9,8,7}, start, stop;
     int* niz2=NULL;
     
     printf("unesite start: ");
     scanf(" %d", &start);
     printf("unesite stop: ");
     scanf(" %d", &stop);
     niz2=podniz(niz, start, stop);
     for(int i =0; i < (stop - start +1); i++)
        printf("%d ", *(niz2+i));
    free(niz2);
    
    return 0;
}
////////////////
//zd2
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*int* filtriraj(int *niz, int n, int th, int *nth) – vraca novi niz koji sadrži brojeve iz originalnog niza koji su manji od th. 
Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. */
int* filtriraj(int *niz, int n, int th, int *nth){
    int*niz3=NULL;
    int j =0;
    for(int i = 0; i < n; i++){
        if(niz[i]<th)
            *nth +=1;
    }
    niz3 = (int*)malloc(sizeof(int)*(*nth));
    for(int i = 0; i < n; i++){
        if(niz[i]<th)
            {
                *(niz3+j)=niz[i];
                j++;
            }
        
    }
    return niz3;
}


int main(void)
{
     int niz[10]={2,5,1,3,6,5,8,9,8,7}, n=10, th=7, nth=0;
     int* niz2=filtriraj(niz, n, th, &nth);
    for(int i = 0; i < nth; i++){
        printf(" %d ", *(niz2+i));
    }
    free(niz2);
    return 0;
    
}
///////////////
//zd3
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela.
Funkcija vraca dva pokazivaca koji pokazuju na prvi i na drugi dio.*/

int** podijeli(int *niz, int n){
    int** niz3=(int**)malloc(sizeof(int*)*2);
    
    for(int i = 0; i < 2; i++){
        niz3[i]=(int*)malloc(sizeof(int)* (int)n/2);
    }
    for(int i =0; i < 2; i++){
        for(int j =0; j < (int)n/2; j++){
            *(*(niz3+i)+j)=niz[i*((int)n/2)+j];
        }
    }
    return niz3;
}


int main(void)
{
    int niz[10]={1,2,3,4,5,6,7,8,9,10};
    int duljina= sizeof(niz)/sizeof(niz[0]);
    int**niz2=podijeli(niz,duljina);
    for(int i =0; i < 2; i++){
        for(int j =0; j < (int)duljina/2; j++){
           printf(" %d ",*(*(niz2+i)+j)) ;
        }
        printf("\n");
    }
    return 0;
    
}