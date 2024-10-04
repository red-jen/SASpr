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

void ajouter_reservation_par_defaut(const char* nom, const char* prenom, int age, int num, const char* status, int day, int month, int year, int id) {
    if (count < MAX_RESERVATION) {
        strcpy(stock[count].nom, nom);
        strcpy(stock[count].prenom, prenom);
        stock[count].age = age;
        stock[count].num = num;
        strcpy(stock[count].status, status);
        stock[count].date.day = day;
        stock[count].date.month = month;
        stock[count].date.year = year;
        stock[count].id = id;
        count++;
    }
}

void initialiser_reservations_par_defaut() {
   
    ajouter_reservation_par_defaut("Reda", "Jenhaji", 18, 0664146942, "valide", 22, 10, 2025, 10);
    ajouter_reservation_par_defaut("Sophie", "Martin", 25, 0601234567, "valide", 15, 11, 2024, 11);
    ajouter_reservation_par_defaut("Albert", "Camus", 32, 0607654321, "reporte", 3, 12, 2024, 12);
    ajouter_reservation_par_defaut("Emma", "Dubois", 28, 0612345678, "valide", 7, 1, 2025, 13);
    ajouter_reservation_par_defaut("Thomas", "Robert", 45, 0623456789, "annule", 18, 2, 2025, 14);
    ajouter_reservation_par_defaut("Chloe", "Petit", 22, 0634567890, "valide", 29, 3, 2025, 15);
    ajouter_reservation_par_defaut("Antoine", "Richard", 37, 0645678901, "traite", 10, 4, 2025, 16);
    ajouter_reservation_par_defaut("Lea", "Moreau", 30, 0656789012, "valide", 5, 5, 2025, 17);
    ajouter_reservation_par_defaut("Hugo", "Simon", 41, 0667890123, "reporte", 20, 6, 2025, 18);
    ajouter_reservation_par_defaut("Manon", "Laurent", 26, 0678901234, "valide", 12, 7, 2025, 19);
}

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
                 while(strcmp(nn, "valide") != 0 && 
          strcmp(nn, "reporte") != 0 && 
          strcmp(nn, "annule") != 0 && 
          strcmp(nn, "traite") != 0) {
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
         }//suuuuuuuuuuuuuuuuuuuuuuuuuuprimer
         if(choix ==2){                                                                      //suuuuuuuuuuuuuuuuuuuuuuuuuuprimer
            printf("entrer  lid de reservartion que tu veux supprimer : \n ");
             scanf("%d",rechercheid);
             for(int i=0;i<count;i++){
   
   if(rechercheid==stock[i].id){
        for (int j = i; j<count-1 ;j++){
        // strcpy(stock[j].nom,stock[j+1].nom);
        // strcpy(stock[j].prenom,stock[j+1].prenom);
        stock[j]=stock[j+1];
        //   strcpy(stock[j].status,stock[j+1].status);
         
        }
    stock--;
    count--;
    printf("la reservation est supprimer ");
     break;
    }

    }
         }
 }
      
    }
    }
    
void triage() {
    int choix;
    printf("Choisissez le critère de tri:\n");
    printf("1. Trier par nom\n");
    printf("2. Trier par date\n");
    printf("3. Trier par ID\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int echange = 0;

            switch(choix) {
                case 1: // Tri par nom
                    if (strcmp(stock[j].nom, stock[j+1].nom) > 0) {
                        echange = 1;
                    }
                    break;
                case 2: // Tri par date
                    if (stock[j].date.year > stock[j+1].date.year ||
                        (stock[j].date.year == stock[j+1].date.year && stock[j].date.month > stock[j+1].date.month) ||
                        (stock[j].date.year == stock[j+1].date.year && stock[j].date.month == stock[j+1].date.month && stock[j].date.day > stock[j+1].date.day)) {
                        echange = 1;
                    }
                    break;
                case 3: // Tri par ID
                    if (stock[j].id > stock[j+1].id) {
                        echange = 1;
                    }
                    break;
                default:
                    printf("Choix invalide.\n");
                    return;
            }

            if (echange) {
                // Échange sans utiliser de pointeurs
                resrvations temp = stock[j];
                stock[j] = stock[j+1];
                stock[j+1] = temp;
            }
        }
    }

    printf("Tri effectué.\n");

    // Afficher les réservations triées
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Nom: %s, Date: %02d/%02d/%04d\n", 
               stock[i].id, stock[i].nom, 
               stock[i].date.day, stock[i].date.month, stock[i].date.year);
    }
}

    void recherche() {
    int choix_recherche;
    printf("Choisissez le critère de recherche:\n");
    printf("1. Recherche par ID\n");
    printf("2. Recherche par nom\n");
    printf("3. Recherche par date\n");
    printf("Votre choix: ");
    scanf("%d", &choix_recherche);

    switch(choix_recherche) {
        case 1: {
            int id_recherche;
            printf("Entrez l'ID à rechercher: ");
            scanf("%d", &id_recherche);
            
            for (int i = 0; i < count; i++) {
                if (stock[i].id == id_recherche) {
                    printf("Réservation trouvée:\n");
                    printf("ID: %d, Nom: %s %s, Date: %02d/%02d/%04d, Status: %s\n", 
                           stock[i].id, stock[i].nom, stock[i].prenom,
                           stock[i].date.day, stock[i].date.month, stock[i].date.year,
                           stock[i].status);
                    return;
                }
            }
            printf("Aucune réservation trouvée avec cet ID.\n");
            break;
        }
        case 2: {
            char nom_recherche[MAX_NOM];
            printf("Entrez le nom à rechercher: ");
            scanf(" %[^\n]", nom_recherche);
            
            int trouve = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(stock[i].nom, nom_recherche) == 0) {
                    printf("Réservation trouvée:\n");
                    printf("ID: %d, Nom: %s %s, Date: %02d/%02d/%04d, Status: %s\n", 
                           stock[i].id, stock[i].nom, stock[i].prenom,
                           stock[i].date.day, stock[i].date.month, stock[i].date.year,
                           stock[i].status);
                    trouve = 1;
                }
            }
            if (!trouve) {
                printf("Aucune réservation trouvée avec ce nom.\n");
            }
            break;
        }
        case 3: {
            int jour, mois, annee;
            printf("Entrez la date à rechercher (JJ ) : ");
            scanf("%d ", &jour);
            printf("(MM )  : ");
            scanf("%d", &mois);
            printf("(yyyy)  : ");
            scanf("%d", &annee);
            
            int trouve = 0;
            for (int i = 0; i < count; i++) {
                if (stock[i].date.day == jour && stock[i].date.month == mois && stock[i].date.year == annee) {
                    printf("Réservation trouvée:\n");
                    printf("ID: %d, Nom: %s %s, Date: %02d/%02d/%04d, Status: %s\n", 
                           stock[i].id, stock[i].nom, stock[i].prenom,
                           stock[i].date.day, stock[i].date.month, stock[i].date.year,
                           stock[i].status);
                    trouve = 1;
                }
            }
            if (!trouve) {
                printf("Aucune réservation trouvée à cette date.\n");
            }
            break;
        }
        default:
            printf("Choix invalide.\n");
            break;
    }
}

void Statistiques(){
    int stchoix;
    double sum1=0;
    int counti = 0;
    printf("selecter un choix :");
    printf("1 - la moyenne d'age des patients ayant reserve.");
    printf("2 - le nombre de patients par tranche d'age (ex. : 0-18 ans, 19-35 ans, 36+ ans)");
    printf("3 -  connaître le nombre total de reservations par statut (valide, annule, etc.).");
    printf("entrer votre choix : ");
    scanf("%d",&stchoix);
    switch(stchoix){
        case 1 :
        for(int i =0;i<=count;i++){
            
            sum += stock[i].age;
            
        }
        printf("la moyenne d'age est : %0.2f ",sum/count);
        break;
        
        case 2 :
        for(int=0;i<count;i++){
           if(stock[i].age < 19 && stock[i].age > 0){
           counti++; 
           }
        }
        printf("")
    }
}

int main(){
    srand(time(NULL));
     initialiser_reservations_par_defaut();
do{
    printf("selectionnez un choix !!!(selectionez le nombre de votre choix )!!!\n ");
    printf("1 -  Ajouter une reservation \n");
    printf("2 - Modifier ou supprimer une reservation \n");
    printf("3 - Afficher les détails d'une reservation \n");
    printf("4 - Tri des reservations\n");
    printf("5 - Recherche des reservations\n");
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
        case 3 :
        triage();
        break;
        case 4 :


        
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