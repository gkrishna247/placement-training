/*Write a C program to read an amount (integer value) and break the amount 
into smallest possible number of bank notes.
Note: The possible banknotes are 100, 50, 20, 10, 5, 2 and 1*/
#include <stdio.h>
int main()
{
    int am,h,fif,twe,tn,fiv,two,on,bl;
    printf("Enter the amount:\n");
    scanf("%d",&am);
    h=(am-(am%100))/100;
    bl=am-(h*100);
    fif=(bl-(bl%50))/50;
    bl=bl-(fif*50);
    twe=(bl-(bl%20))/20;
    bl=bl-(twe*20);
    tn=(bl-(bl%10))/10;
    bl=bl-(tn*10);
    fiv=(bl-(bl%5))/5;
    bl=bl-(fiv*5);
    two=(bl-(bl%2))/2;
    bl=bl-(two*2);
    on=bl%2;
    printf("number of 100 rupee banknotes are: %d\n",h);
    printf("number of 50 rupee banknotes are: %d\n",fif);
    printf("number of 20 rupee banknotes are: %d\n",twe);
    printf("number of 10 rupee banknotes are: %d\n",tn);
    printf("number of 5 rupee banknotes are: %d\n",fiv);
    printf("number of 2 rupee banknotes are: %d\n",two);
    printf("number of 1 rupee banknotes are: %d\n",on);
    return 0;
}

