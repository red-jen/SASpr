#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RESERVATION 200
#define MAX_NOM 100
#define MAX_PRENOM 100
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
    int age;
    int num;
    char status[MAX_STATUS];
    Date date;
    int id;
}resrvations;
resrvations stock[MAX_RESERVATION];
int count =0;
int rechercheid;
int choix;
void ajouter(){
    getchar();
    printf("bonjour,entrer votre nom : ");
    scanf(" %[^\n]",stock[count].nom);
    printf("\nentrer votre prenom : ");
    scanf(" %[^\n]",stock[count].prenom);
    printf("\nentrer votre age : ");
    scanf("%d",&stock[count].age);
    while(stock[count].age < 0 || stock[count].age > 140) {
        printf("Age invalide, entrer votre age reel : ");
        scanf("%d", &stock[count].age);
    }
    printf("\nentrer votre numero de telephone : ");
    scanf("%d",&stock[count].num);
    printf("\nvotre status ; (valide, reporte, annule, traite) ? : ");
    scanf("%s", stock[count].status);
     while(strcmp(stock[count].status, "valide") != 0 &&
          strcmp(stock[count].status, "reporte") != 0 &&
          strcmp(stock[count].status, "annule") != 0 &&
          strcmp(stock[count].status, "traite") != 0) {
        printf("Entrer un statut correct (valide, reporte, annule, traite) : ");
         scanf("%s", stock[count].status);
    }
    printf("\nla date de votre reservation ?(dd/mm/yyyy)");
    printf("\nentrer la date par jour (dd) : ");
     scanf("%d",&stock[count].date.day);
   while(stock[count].date.day < 1 || stock[count].date.day > 31) {
        printf("\nEntrer un jour valide : ");
         scanf("%d", &stock[count].date.day);
    }
     printf("\nentrer le mois (mm) : ");
      scanf("%d",&stock[count].date.month);
    while(stock[count].date.month < 1 || stock[count].date.month > 12) {
        printf("\nEntrer un mois valide : ");
         scanf("%d", &stock[count].date.month);
    }

     printf("\nentrer l'anne (yyyy) : ");
      scanf("%d",&stock[count].date.year);
    while(stock[count].date.year < 2024 || stock[count].date.year > 2050) {
        printf("\nEntrer une annee valide : ");
         scanf("%d", &stock[count].date.year);
    }
    stock[count].id = rand()%1000 + 1 ;
    printf("\nvotre id est : %d  , veullez vous le rmember",stock[count].id);
    printf("\nvotre reservation est complete  :) \n");

count ++;
}

    void modifier(){
        printf("set ce que tu veux modifier ou supprimer un reservation ? \n");
        printf("pour modifier slectionner 1 , pour supprimer selection 2 , pour quiiter  entrer 0 \n");
        printf("votre choix  : ");
         scanf("%d",&choix);
         if(choix == 1){
            printf("entrer l'id que tu veux modifier : ");
            scanf("%d",&rechercheid);
 for(int i=0;i<count;i++){

         if(rechercheid == stock[i].id){
            printf("tu veux modifier le nom de ce id (oui = 1 , non = autre chose )?");
            scanf("%d",choix);
            if(choix == 1){
                char nn[100];
                printf("entrer le nom que tu veux");
                scanf(" %[^\n]",nn);
                strcpy(stock[i].nom, nn);
            }
            printf("tu veux modifier le prenom de ce id (oui = 1 , non = autre chose )?");
            scanf("%d",choix);
            if(choix == 1){
                char nn[100];
                printf("entrer le prenom que tu veux");
                scanf(" %[^\n]",nn[100]);
                strcpy(stock[i].prenom, nn);
            }
            printf("tu veux modifier l'age de ce id (oui = 1 , non = autre chose )?");
            scanf("%d",choix);
            if(choix == 1){
                int ann;
                printf("entrer l'age que tu veux");
                scanf("%d",&ann);
                while(ann < 0 || ann > 140) {
        printf("Age invalide, entrer votre age reel : ");
        scanf("%d", &ann);
    }
                stock[i].age = ann;
            }
             printf("tu veux modifier la numero de ce id (oui = 1 , non = autre chose )?");
            scanf("%d",choix);
            if(choix == 1){
                int ann;
                printf("entrer la numero que tu veux : ");
                scanf("%d",&ann);
                stock[i].num = ann;
            }
            printf("tu veux modifier le status de ce id (oui = 1 , non = autre chose )?");
            scanf("%d",choix);
            if(choix == 1){
                char nn[100];
                printf("entrer le nouveau status");
                scanf(" %s",nn[100]);
                 while(strcmp(nn[100], "valide") != 0 &&
          strcmp(nn[100], "reporte") != 0 &&
          strcmp(nn[100], "annule") != 0 &&
          strcmp(nn[100], "traite") != 0) {
        printf("Entrer un statut correct (valide, reporte, annule, traite) : ");
         scanf("%s",stock[i].status);
    }


            }
            printf("tu veux changer la date (oui = 1 , non = autre chose )");
             scanf("%d",choix);
            if(choix == 1){
             printf("\nla date de votre reservation ?(dd/mm/yyyy)");

    printf("\nentrer la date par jour (dd) : ");
     scanf("%d",&stock[i].date.day);
   while(stock[i].date.day < 1 || stock[i].date.day > 31) {
        printf("\nEntrer un jour valide : ");
         scanf("%d", &stock[i].date.day);
    }
     printf("\nentrer le mois (mm) : ");
      scanf("%d",&stock[i].date.month);
    while(stock[i].date.month < 1 || stock[i].date.month > 12) {
        printf("\nEntrer un mois valide : ");
         scanf("%d", &stock[i].date.month);
    }

     printf("\nentrer l'anne (yyyy) : ");
      scanf("%d",&stock[i].date.year);
    while(stock[i].date.year < 2024 || stock[i].date.year > 2050) {
        printf("\nEntrer une annee valide : ");
         scanf("%d", &stock[i].date.year);
    }
            }
         }
         if(choix ==2){
            printf("entrer  lid de reservartion que tu veux supprimer : \n ");
             scanf("%d",rechercheid);
             for(int i=0;i<count;i++){

   if(rechercheid==stock[i].id){
        for (int j = i; j<count ;j++){
        strcpy(stock[j].nom,stock[j+1].nom);
        strcpy(stock[j].prenom,stock[j+1].prenom);
        stock[j].num=stock[j+1].num;
        stock[j].age=stock[j+1].age;
         stock[j].id=stock[j+1].id;
          strcpy(stock[j].status,stock[j+1].status);


        }
    count--;
    printf("la reservation est supprimer ");
     break;
    }

    }
         }

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
        ajouter();
        break;
        case 2 :
            modifier();
         break;
        case 0 :
        printf("Au Revoir ): !!\n");
        break;

        default :
        printf("choix invalid !!!\n");
        break;
    }

}while(choix != 0);
return 0;
}
