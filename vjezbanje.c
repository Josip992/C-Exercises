//vj00

//zd 3

int main()
{
   int a,b,c;

   printf("unesite a: \n");
   scanf("%d", &a);
   printf("unesite b: \n");
   scanf("%d", &b);

   c = a;
   a = b;
   b = c;

   printf(" a je :%d, b je: %d\n", a,b);
    return 0;
}

//zd4

int main()
{
   return 0;
}
   int a,b;

   printf("unesite a: \n");
   scanf("%d", &a);
   printf("unesite b: \n");
   scanf("%d", &b);

   if (a < b)
   {
       printf("a je manji od b!! \n");
   }
   else if (b < a)
   {
        printf("b je manji od a!! \n");
   }
   else{
    printf("brojevi su jednaki ! \n");
   }

//zd5

int main()
{
    int a, b, c;
    printf("unesite a, b i c: \n");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b && b < c) {
        printf("%d %d %d 1\n", a, b, c); // ABC
    }
    else if (a > b && b > c) {
        printf("%d %d %d 2\n", c, b, a); // CBA
    }
    else if (b < a && a < c) {
        printf("%d %d %d 3\n", b, a, c); // BAC
    }
    else if (a < b && a > c) {
        printf("%d %d %d 4\n", c, a, b); // CAB
    }
    else if (a < c && c < b) {
        printf("%d %d %d 5\n", a, c, b); // ACB
    }
    else if (b < c && c < a) {
        printf("%d %d %d 6\n", b, c, a); // BCA
    }

    return 0;
}

//vj01

//zd1

int main()
{
    int a,b;
    char znak;
    int rez;
    int ostatak;

    printf("unesite dva cijela broja: \n");
    scanf("%d %d", &a,&b);
    printf("unesite znak operacije izmedu brojeva: \n");
    scanf(" %c", &znak);
    if( znak == '+'){
        rez = a + b;
        printf("zbroj je %d", rez);
    }if( znak == '-'){
        rez = ( a - b );
        printf("razlika je %d", rez);
    }if( znak == '*'){
        rez = a*b;
        printf("umnozak je %d", rez);
    }if (b == 0 && znak == '/'){
			printf("Zabranjeno je dijeliti s nula!!");
			}
    else if ( znak == '/' && b != 0 ){
         rez = a/b;
        ostatak = a%b;
        printf("rezultat djeljenja je: %d, a ostatak iznosi %d", rez,ostatak);
    }



   return 0;
}

//zd2 (sto ako je film poceo prije ponoci, a zavrsio nakon???)

/*2. Napisati program u kojem se unosi vrijeme početka i kraja nekog filma (u satima,
minutama i sekundama) i ispisuje trajanje filma u satima, minutama i sekundama..
*/

int main()
{
    int psat,pmin,psek;
    int pssek;
    int zsat,zmin,zsek;
    int zssek;
    int razsek;
    int tsat,tmin,tsek;


    printf("unesite pocetak trajanja filma (sati/min/sek):\n");
    scanf("%f%f%f", &psat,&pmin,&psek);
    printf("Unesite vrijeme kraja filma (sati/min/sek): \n");
    scanf("%f%f%f", &zsat,&zmin,&zsek);

    pssek = (psat * ( 60 * 60 )) + (pmin * 60) + psek;
    zssek = (zsat * ( 60 * 60 )) + (zmin * 60) + zsek;
    razsek = zssek - pssek;

    printf("film je trajao %f sati %f minuta %f sekundi\n", razsek / 3600, razsek / 60, razsek);

   return 0;
}

//zd3


/*3. Napisati program koji provjerava je li unesen troznamenkasti broj Armstrongov.
Armstrongovi brojevi su brojevi koji su jednaki zbroju kubova svojih znamenki.
*/

int main()
{
    int trbroj; //troz broj
    int pznam,sznam,zznam; //prva srednja zadnja znamenka
    int zbrkub; //zbroj kubova

    printf("Unesite neki troznamenkasti broj: \n");
    scanf("%d", &trbroj);

    zznam = trbroj % 10;
    sznam = ( trbroj / 10 ) % 10;
    pznam = (trbroj / 10) / 10;
    zbrkub = (zznam*zznam*zznam) + (pznam*pznam*pznam) + (sznam*sznam*sznam);

    printf("Zbroj kubova znamenki je: %d\n", zbrkub);
    if (zbrkub == trbroj)
    {
        printf("Uneseni troznamenkasti broj je Armstrongov !!");
    }else{
        printf("Broj koji ste unjeli nije Armstrongov broj !!");
    }



   return 0;
}



