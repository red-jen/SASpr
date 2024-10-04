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
    char num[10];
    char status[MAX_STATUS];
    Date date;
    int id;
}resrvations;

resrvations stock[MAX_RESERVATION];
int count =0;
int rechercheid;
int choix;

void ajouter_reservation_par_defaut(const char* nom, const char* prenom, int age, const char* num, const char* status, int day, int month, int year, int id) {
    if (count < MAX_RESERVATION) {
        strcpy(stock[count].nom, nom);
        strcpy(stock[count].prenom, prenom);
        stock[count].age = age;
        strcpy(stock[count].num, num);  
        strcpy(stock[count].status, status);
        stock[count].date.day = day;
        stock[count].date.month = month;
        stock[count].date.year = year;
        stock[count].id = id;
        count++;
    }
}

void initialiser_reservations_par_defaut() {
   
    ajouter_reservation_par_defaut("Reda", "Jenhaji", 18, "0664146942", "valide", 22, 10, 2025, 10);
    ajouter_reservation_par_defaut("Sophie", "Martin", 25, "0601234567", "valide", 15, 11, 2024, 11);
    ajouter_reservation_par_defaut("Albert", "Camus", 32, "0607654321", "reporte", 3, 12, 2024, 12);
    ajouter_reservation_par_defaut("Emma", "Dubois", 28, "0612345678", "valide", 7, 1, 2025, 13);
    ajouter_reservation_par_defaut("Thomas", "Robert", 45, "0623456789", "annule", 18, 2, 2025, 14);
    ajouter_reservation_par_defaut("Chloe", "Petit", 22, "0634567890", "valide", 29, 3, 2025, 15);
    ajouter_reservation_par_defaut("Antoine", "Richard", 37," 0645678901", "traite", 10, 4, 2025, 16);
    ajouter_reservation_par_defaut("Lea", "Moreau", 30, "0656789012", "valide", 5, 5, 2025, 17);
    ajouter_reservation_par_defaut("Hugo", "Simon", 41, "0667890123", "reporte", 20, 6, 2025, 18);
    ajouter_reservation_par_defaut("Manon", "Laurent", 26, "0678901234", "valide", 12, 7, 2025, 19);

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
    scanf("%s",&stock[count].num);
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

void modifier() {
    printf("Voulez-vous modifier ou supprimer une reservation?\n");
    printf("1. Modifier\n2. Supprimer\n0. Quitter\nVotre choix: ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Entrez l'ID de la reservation a modifier: ");
        scanf("%d", &rechercheid);

        for (int i = 0; i < count; i++) {
            if (stock[i].id == rechercheid) {
                int choix_mod;
                printf("Modifier le nom (1: Oui, autre: Non)? ");
                scanf("%d", &choix_mod);
                if (choix_mod == 1) {
                    printf("Entrez le nouveau nom: ");
                    scanf(" %[^\n]", stock[i].nom);
                }

                printf("Modifier le prenom (1: Oui, autre: Non)? ");
                scanf("%d", &choix_mod);
                if (choix_mod == 1) {
                    printf("Entrez le nouveau prenom: ");
                    scanf(" %[^\n]", stock[i].prenom);
                }

                printf("Modifier l'age (1: Oui, autre: Non)? ");
                scanf("%d", &choix_mod);
                if (choix_mod == 1) {
                    do {
                        printf("Entrez le nouvel age: ");
                        scanf("%d", &stock[i].age);
                    } while (stock[i].age < 0 || stock[i].age > 140);
                }

                printf("Modifier le numero (1: Oui, autre: Non)? ");
                scanf("%d", &choix_mod);
                if (choix_mod == 1) {
                    printf("Entrez le nouveau numero: ");
                    scanf("%s", stock[i].num);
                }

                printf("Modifier le statut (1: Oui, autre: Non)? ");
                scanf("%d", &choix_mod);
                if (choix_mod == 1) {
                    do {
                        printf("Entrez le nouveau statut (valide, reporte, annule, traite): ");
                        scanf("%s", stock[i].status);
                    } while (strcmp(stock[i].status, "valide") != 0 && strcmp(stock[i].status, "reporte") != 0 &&
                             strcmp(stock[i].status, "annule") != 0 && strcmp(stock[i].status, "traite") != 0);
                }

                printf("Modifier la date (1: Oui, autre: Non)? ");
                scanf("%d", &choix_mod);
                if (choix_mod == 1) {
                    do {
                        printf("Entrez le nouveau jour: ");
                        scanf("%d", &stock[i].date.day);
                    } while (stock[i].date.day < 1 || stock[i].date.day > 31);

                    do {
                        printf("Entrez le nouveau mois: ");
                        scanf("%d", &stock[i].date.month);
                    } while (stock[i].date.month < 1 || stock[i].date.month > 12);

                    do {
                        printf("Entrez la nouvelle annee: ");
                        scanf("%d", &stock[i].date.year);
                    } while (stock[i].date.year < 2024 || stock[i].date.year > 2050);
                }

                printf("Modification terminee.\n");
                return;
            }
        }

        printf("ID introuvable.\n");

    } else if (choix == 2) {
        printf("Entrez l'ID de la reservation a supprimer: ");
        scanf("%d", &rechercheid);

        for (int i = 0; i < count; i++) {
            if (stock[i].id == rechercheid) {
                for (int j = i; j < count - 1; j++) {
                    stock[j] = stock[j + 1];
                }
                count--;
                printf("Reservation supprimee.\n");
                return;
            }
        }

        printf("ID introuvable.\n");
    }
}
    
void triage() {
    int choix;
    printf("Choisissez le critere de tri:\n");
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
                // Echange sans utiliser de pointeurs
                resrvations temp = stock[j];
                stock[j] = stock[j+1];
                stock[j+1] = temp;
            }
        }
    }

    printf("Tri effectue.\n");

    // Afficher les reservations triees
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Nom: %s, Date: %02d/%02d/%04d\n", 
               stock[i].id, stock[i].nom, 
               stock[i].date.day, stock[i].date.month, stock[i].date.year);
    }
}

void recherche() {
    int choix_recherche;
    printf("Choisissez le critere de recherche:\n");
    printf("1. Recherche par ID\n");
    printf("2. Recherche par nom\n");
    printf("3. Recherche par date\n");
    printf("Votre choix: ");
    scanf("%d", &choix_recherche);

    switch(choix_recherche) {
        case 1: {
            int id_recherche;
            printf("Entrez l'ID a rechercher: ");
            scanf("%d", &id_recherche);
            
            for (int i = 0; i < count; i++) {
                if (stock[i].id == id_recherche) {
                    printf("Reservation trouvee:\n");
                    printf("ID: %d, Nom: %s %s, Date: %02d/%02d/%04d, Status: %s\n", 
                           stock[i].id, stock[i].nom, stock[i].prenom,
                           stock[i].date.day, stock[i].date.month, stock[i].date.year,
                           stock[i].status);
                    return;
                }
            }
            printf("Aucune reservation trouvee avec cet ID.\n");
            break;
        }
        case 2: {
            char nom_recherche[MAX_NOM];
            printf("Entrez le nom a rechercher: ");
            scanf(" %[^\n]", nom_recherche);
            
            int trouve = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(stock[i].nom, nom_recherche) == 0) {
                    printf("Reservation trouvee:\n");
                    printf("ID: %d, Nom: %s %s, Date: %02d/%02d/%04d, Status: %s\n", 
                           stock[i].id, stock[i].nom, stock[i].prenom,
                           stock[i].date.day, stock[i].date.month, stock[i].date.year,
                           stock[i].status);
                    trouve = 1;
                }
            }
            if (!trouve) {
                printf("Aucune reservation trouvee avec ce nom.\n");
            }
            break;
        }
        case 3: {
            int jour, mois, annee;
            printf("Entrez la date a rechercher (JJ ) : ");
            scanf("%d ", &jour);
            printf("(MM )  : ");
            scanf("%d", &mois);
            printf("(yyyy)  : ");
            scanf("%d", &annee);
            
            int trouve = 0;
            for (int i = 0; i < count; i++) {
                if (stock[i].date.day == jour && stock[i].date.month == mois && stock[i].date.year == annee) {
                    printf("Reservation trouvee:\n");
                    printf("ID: %d, Nom: %s %s, Date: %02d/%02d/%04d, Status: %s\n", 
                           stock[i].id, stock[i].nom, stock[i].prenom,
                           stock[i].date.day, stock[i].date.month, stock[i].date.year,
                           stock[i].status);
                    trouve = 1;
                }
            }
            if (!trouve) {
                printf("Aucune reservation trouvee a cette date.\n");
            }
            break;
        }
        default:
            printf("Choix invalide.\n");
            break;
    }
}

int main(){
    srand(time(NULL));
     initialiser_reservations_par_defaut();
do{
    printf("selectionnez un choix !!!(selectionez le nombre de votre choix )!!!\n ");
    printf("1 -  Ajouter une reservation \n");
    printf("2 - Modifier ou supprimer une reservation \n");
    printf("3 - Afficher les details d'une reservation \n");
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
        recherche();
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