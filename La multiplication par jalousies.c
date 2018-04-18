#include <stdio.h>
#include <stdlib.h>

int main()
{

int nb1;
int nb2;
int nb3;
int i;
int j;
int k;
int tab1[100];
int tab2[100];
int tabE[100][100];
int tabM[100][100];
int tab3[100];


printf("Saisir le nombre de chiffres de la premiere multiplicateur: ");
scanf("%d" , & nb1);
for (i=1; i<=nb1; i=i+1)
{
    printf("Saisir le chiffre numero %d:",i);
    scanf("%d",&tab1[i-1]);
}

printf("Saisir le nombre de chiffres de la deuxieme multiplicateur: ");
scanf("%d" , & nb2);
for (i=1; i<=nb2; i=i+1)
{
    printf("Saisir le chiffre numero %d:",i);
    scanf("%d",&tab2[i-1]);
}

for (i=0; i<=99; i=i+1)
{
  for (j=0; j<=99; j=j+1)
  {
      tabE[i][j]=0;
      tabM[i][j]=0;
  }
}


for (i=0; i<=nb1-1; i=i+1)
{
    for (j=0; j<=nb2-1; j=j+1)
    {
        tabE[i][j]=(tab1[i]*tab2[j])/10;
    }
}


for (i=0; i<=nb1-1; i=i+1)
{
    for (j=0; j<=nb2-1; j=j+1)
    {
        tabM[i][j]=(tab1[i]*tab2[j])%10;
    }
}

nb3=nb1+nb2;

for (i=0; i<=nb3-2; i=i+1)
{
    tab3[i]=0;
    for (j=0; j<=i; j=j+1)
    {
        tab3[i]=tab3[i]+tabE[j][i-j];
    }
}


tab3[nb3-1]=0;

for (i=0; i<=nb3-2; i=i+1)
{
    for (j=0; j<=i; j=j+1)
    {
        tab3[i+1]=tab3[i+1]+tabM[j][i-j];
    }
}

for (i=nb3-1;i>=1;i=i-1)
{
   tab3[i-1]=tab3[i-1]+tab3[i]/10;
   tab3[i]=tab3[i]%10;
}


printf("\n");
printf("Le tableau obtenu est:");
printf("\n");

for (i=0; i<=nb2-1; i=i+1)
{
    for (j=0; j<=nb1-1; j=j+1)
    {
        printf("%d",tabE[j][i]);
        printf("%c",'/');
        printf("%d  ",tabM[j][i]);
    }
    printf("\n");
}


k=0;
while(tab3[k]==0)
{
    k=k+1;
}

printf("\n");
printf("Le resultat est:");

for(i=k;i<=nb3-1;i=i+1)
{
  printf("%d",tab3[i]);
}
printf("\n");
printf("\n");
printf("Vous pouvez quitter l'algorithme en tapant F");
printf("\n");



    return 0;
}
