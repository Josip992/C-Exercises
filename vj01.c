//zd1
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int mystrlen(char* a) {
	int i;
	int br = 0;
	for (i = 0; a[i] != '\0'; i++) {
		br++;
	}
	return br;
}

int main(void) {

	char str[30];
	int duljina;

	printf("Upisite string:\n");
	scanf("%s", str);

	duljina = mystrlen(str);

	printf("Duljina stringa je: %d\n", duljina);

	return 0;
}

//////
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void  mystrcpy(char* a, char* b)
{
	int i;

	for (i = 0; a[i] != '\0'; i++) {
		b[i] = a[i];
	}
	b[i]='\0';
}

int main(void)
{
	char str1[30];
	char str2[30];

	printf("Unesite prvi string: \n");
	scanf("%s", str1);
	
	mystrcpy(str1, str2);

    printf("string 1 je: %s,a string 2 je %s\n", str1, str2);


	return 0;
}


//zd2
//////////
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int  mystrcmp(char* a, char* b)
{
    int i;
    
    for(i=0;a[i]!='\0'&&b[i]!='\0';i++){
        if(a[i]>b[i]){
            return 1;
        }else if(a[i]<b[i])
        {
            return -1;
        }
    }   
    if(a[i]!='\0'){
        return 1;
    }
    else if(b[i]!='\0'){
        return -1;
    }
    return 0;
    
	
}

int main(void){

    char str1[]="autonobil";
    char str2[]="automobil";
    
    
    printf("Rezultat: %d\n", mystrcmp(str1,str2));
    
	return 0;
}


//zd3
///////
//zd4

#include<stdio.h>
#include<string.h>

void mystrcat(char* a, char* b)
{

	int i=strlen(a);
	int j;
	for(j=0;b[j]!='\0';j++){
	    a[i+j]=b[j];
	    
	}
    a[i+j]='\0';
}

int main(void)
{
	char str1[100] = "automobila";
	char str2[] = "testghg";
	
	mystrcat(str1, str2);
    printf(" %s\n", str1);
	return 0;
}
//////////
//zd5
#include<stdio.h>
#include<string.h>

void reverse(char* a, char* b)
{
    int i=strlen(a)-1;
    int j=0;
    for(i;i>=0;i--){
        b[j]=a[i];
        j++;
    }
    b[j+1]='\0';
    
	
}

int main(void)
{
	char str1[100] = "automobil";
	char str2[100] = "";
	
	reverse(str1, str2);
    printf(" %s\n", str2);
	return 0;
}
/////
//zd6
#include<stdio.h>
#include<string.h>
/*•	mystrstr() – funkcija vraca pokazivac (unutar prvog stringa)
koji pokazuje na prvo pojavljivanje drugog stringa. Ako ga ne pronade, 
funkcija vraca NULL.*/
char* mystrstr(char* a, char* b) //funkcija koja vraca pointer
{
    int j=0;
  for(int i=0;i<strlen(a)-strlen(b);i++){
     if(a[i]==b[j]){
         for(j=0; b[j] != '\0'; j++){
             if(b[j]!=a[i+j]){
                 break;
             }
         }
         if(b[j]=='\0'){
             return &a[i];//vraca adresu prvog slova 
         }
     }
  }
  return NULL;
	
}

int main(void)
{
    char* slovo = NULL; //tu spremamo adresu koju funkcija vraca
	char str1[100] = "automobil";
	char str2[100] = "omo";
	slovo = mystrstr(str1, str2);
    printf("%c\n",*slovo);
	
    
	return 0;
}