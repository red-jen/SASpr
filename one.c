#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RESERVATION 200
#define MAX_NOM 100
#define MAX_PRENOM 100
#define MAX_AGE 100
#define MAX_NUM 80
#define MAX_DATE 200
#define MAX_STATUS 60
typedef struct{
       int day;
       int month;
       int year;
   }Date;
typedef struct{
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    char age[MAX_AGE];
    char num[MAX_NUM];
    char status[MAX_STATUS];
    Date date;
    int id;
}resrvations;
resrvations stock[MAX_RESERVATION];
int count =0;
int recherche;
int choix;
  void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void ajouter(){
    printf("bonjour,entrer votre nom : ");
    scanf(" %[^\n]",stock[count].nom);
    printf("\nentrer votre prenom : ");
    scanf(" %[^\n]",stock[count].prenom);
    printf("\n entrer votre age : ");
    scanf("%s", stock[count].age);
    printf("\nentrer votre numero de telephone : ");
    scanf("%s", stock[count].num);
    printf("\n votre status ; (validé, reporté, annulé, traité) ? : ");
    scanf("%s", stock[count].status);
    printf("\n la date de votre reservation ?(dd/mm/yyyy)");
    printf("\n entrer la date par jour (dd)");
    scanf("%d",stock[count].date.day);
     printf("|\n entrer le mois (mm)");
    scanf("%d",&stock[count].date.month);
     printf("|\n entrer l'anne (yyyy)");
    scanf("%d",&stock[count].date.year);
    stock[count].id = rand()%1000 + 1 ;
    printf("\n votre id est : %d  , veullez vous le rmember",stock[count].id);
    printf("\n votre reservation est complete  :) ");

count ++;
}

int main(){
    srand(time(NULL));
do{
    printf("selectionnez un choix !!!(selectionez le nombre de votre choix )!!!\n ");
    printf("1 -  Ajouter une réservation \n");
    printf("2 - Modifier ou supprimer une réservation \n");
    printf("3 - Afficher les détails d'une réservation \n");
    printf("4 - Tri des réservations\n");
    printf("5 - Recherche des réservations\n");
    printf("6 - Statistiques\n");
    printf("0 - quitter\n");
    printf("entrer votre choix : ");
    scanf("%d",&choix);

    switch(choix){
        case 1 :
        ajouter(stock,count);
        break;

        case 0 :
        printf("Au Revoir ): !!");
        break;

        default :
        printf("choix invalid !!!!");
        break;
    }

}while(choix != 0);
return 0;
}
