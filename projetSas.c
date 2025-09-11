/////////////////version3/////////////////
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

int totplayers = 0;
int globalid = 1;

typedef struct
{
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[50];
    int age;
    int buts;
    int id;

} joueur;

int theprintfunction(int i, joueur info[])
{
   
    printf("%-17s :", "Nom ");
scanf(" %[^\n]", info[i].nom);

printf("%-17s :",  "Prenom ");
scanf(" %[^\n]", info[i].prenom);

printf("%-17s :", "Numero de maillot ");
scanf("%d", &info[i].numeroMaillot);

printf("%-15s :", "Poste (gardien, defenseur, milieu, attaquant) ");
scanf(" %[^\n]", info[i].poste);

printf("%-17s :", "Age ");
scanf("%d", &info[i].age);

printf("%-17s :", "Buts ");
scanf("%d", &info[i].buts);

info[i].id = globalid;
globalid++;

}
int theprintfunction2(int i, joueur info[])
{
  printf("%-20s %s\n", "Nom :", info[i].nom);
printf("%-20s %s\n", "Prenom :", info[i].prenom);
printf("%-20s %d\n", "Numero Maillot :", info[i].numeroMaillot);
printf("%-20s %s\n", "Poste :", info[i].poste);
printf("%-20s %d\n", "Age :", info[i].age);
printf("%-20s %d\n", "Buts :", info[i].buts);
printf("%-20s %d\n", "ID :", info[i].id);

}

/// /////// ajout///
void Ajouter(joueur info[])
{
    int count = 0;

    printf(CYAN"\n1."RESET"Ajouter un nouveau joueur");
    printf(CYAN"\n2."RESET"Ajouter plusieurs joueurs\n");
    printf(YELLOW"\nvotre choix :"RESET);
    scanf("%d", &count);

    if (count == 1)
    {
        for (int i = totplayers; i < 1 + totplayers; i++)
        {

            theprintfunction(i, info);
        }
        totplayers++;
    }
    else if (count == 2)
    {
        int nomber = 0;
        printf("combien de jour ");
        scanf(" %d", &nomber);
printf(YELLOW"\nVotre choix : "RESET);
        for (int i = totplayers; i < totplayers + nomber; i++)
        {
            theprintfunction(i, info);
        }

        totplayers = totplayers + nomber;
    }
    else
    {
        printf(RED"Choix invalide !\n"RESET);
    }
}
////////buble sort///
void bublesort(joueur info[], int size, int choix)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (choix == 1)
            { // name
                if (strcmp(info[j].nom, info[j + 1].nom) > 0)
                {

                    joueur temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
            else if (choix == 2)
            { /////age
                if (info[j].age > info[j + 1].age)
                {
                    joueur temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
            else if (choix == 3)
            { //  poste
                if (strcmp(info[j].poste, info[j + 1].poste) > 0)
                {
                    joueur temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
        }
    }
}

// Affichage////////////////////////////////
void Afficher(joueur info[])
{
    int choix;
    if (totplayers == 0)
    {
        printf(RED"Aucun joueur!\n"RESET);
        return;
    }
    printf(BLUE"1."RESET" Trier les joueurs par ordre alphabétique (Nom).\n");
    printf(BLUE"2. "RESET"Trier les joueurs par âge.\n");
    printf(BLUE"3."RESET" Afficher les joueurs par poste.\n");
    printf(YELLOW"\nVotre choix : "RESET);
    scanf("%d", &choix);
    if (choix == 1)
    {
        bublesort(info, totplayers, choix);
    }
    else if (choix == 2)
    {
        bublesort(info, totplayers, choix);
    }
    else if (choix == 3)
    {
        bublesort(info, totplayers, choix);
    }
    else
    {
        printf(RED"choix invalid!"RESET);
    }
    if (choix == 1 || choix == 2)
    {
        for (int i = 0; i < totplayers; i++)
        {

            theprintfunction2(i, info);
        }
    }
    else if (choix == 3)
    {
        printf("Poste: "CYAN"gardien\n"RESET);
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "gardien";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
        printf("Poste: "GREEN"défenseur\n"RESET);
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "défenseur";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
        printf("Poste: "BLUE"milieu\n"RESET);
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "milieu";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
        printf("Poste: "MAGENTA"attaquant\n"RESET);
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "attaquant";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
    }
}
////rechercher/////
int Rechercher(joueur info[])
{
    if (totplayers == 0)
    {
        printf(RED"Aucun joueur!\n"RESET);
        return 0;
    }
    char nomRechercher[50];
    int count = 0;
    int idRechercher;

    int trouve = 0;
    printf(BLUE"\n1."RESET"Rechercher un joueur par Identifiant.");
    printf(BLUE"\n2."RESET"Rechercher un joueur par Nom.");

    scanf("%d", &count);
    if (count == 1)
    {
        printf("Entrer id a rechercher :");
        scanf("%d", &idRechercher);

        for (int i = 0; i < totplayers; i++)
        {
            if (idRechercher == info[i].id)
            {

                theprintfunction2(i, info);

                trouve = 1;
                return i;
                break;
            }
        }

        if (!trouve)
        {
            printf(RED"joueur introuvable.\n"RESET);
            return -1;
        }
    }
    else if (count == 2)
    {
        printf("Entrer le nom à rechercher");
        scanf(" %[^\n]", nomRechercher);

        for (int i = 0; i < totplayers; i++)
        {
            if (strcmp(nomRechercher, info[i].nom) == 0)
            {
                theprintfunction2(i, info);
                trouve = 1;
                return i;
                break;
            }
        }

        if (!trouve)
        {
            printf(RED"joueur introuvable.\n"RESET);
            return -1;
        }
    }
    else
    {
        printf(RED"invalid choix.\n"RESET);
    }
}

/// ///////modifier////////////////
void modifies(joueur info[])
{
    if (totplayers == 0)
    {
        printf(RED"Aucun joueur!\n"RESET);
        return;
    }
    int index = Rechercher(info);
    if (index == -1)
    {
        printf(RED"Joueur introuvable, modification annulée.\n"RESET);
        return;
    }

    printf("Modifier les informations du joueur  %s :\n", info[index].nom);

    printf("le Nouveau poste : ");
    scanf(" %[^\n]", info[index].poste);

    printf("Nouveau age : ");
    scanf(" %d", &info[index].age);

    printf("Nouveau nombre de buts: ");
    scanf("%d", &info[index].buts);

    printf(GREEN"Joueur modifié !\n"RESET);
}

////////supprime
void supprimer(joueur info[])
{
    if (totplayers == 0)
    {
        printf(RED"Aucun joueur!\n"RESET);
        return;
    }
    int trouve = 0;
    int searchedid;
    printf("Entrez le id que vous recherchez: ");
    scanf(" %d", &searchedid);

    for (int i = 0; i < totplayers; i++)
    {
        if (searchedid == info[i].id)
        {
            for (int j = i; j < totplayers - 1; j++)
            {
                info[j] = info[j + 1];
            }
            totplayers--;
            printf(GREEN"joueur supprime avec succes\n"RESET);
            trouve = 1;
            break;
        }
    }
    if (trouve != 1)
    {
        printf(RED"joueur non trouve\n"RESET);
    }
}
void nombretotal(joueur info[])
{
    printf("le nombre total de joueurs : %d \n", totplayers);
}
void agemoyen(joueur info[])
{
    float moyenne;
    int x = 0;
    for (int i = 0; i < totplayers; i++)
    {
        x = info[i].age + x;
    }
    moyenne = (float)x / totplayers;
    printf("l’âge moyen : %.2f\n", moyenne);
}
void butmarque(joueur info[])
{
    int choix;
    printf("Entrer le nombre de buts :");
    printf(YELLOW"\nVotre choix : "RESET);
    scanf("%d", &choix);
    int x = 0;

    for (int i = 0; i < totplayers; i++)
    {
        if (info[i].buts > choix)
        {
            theprintfunction2(i, info);
            x++;
        }
        else
        {
            continue;
        }
    }
    if (x = 0)
    {
        printf(RED"Personne n’a plus de ce nombre de buts"RESET);
    }
}
void meilleurbuteur(joueur info[])
{
    int topbut = 0;
    if (totplayers == 0)
    {
        printf(RED"Aucun joueur enregistré.\n"RESET);
        return;
    }
    for (int i = 1; i < totplayers; i++)
    {
        if (info[i].buts > info[topbut].buts)
        {
            topbut = i;
        }
    }
    printf("Nom :%s\n", info[topbut].nom);
    printf("prenom %s\n", info[topbut].prenom);
    printf("numeroMaillot %d\n", info[topbut].numeroMaillot);
    printf("poste%s\n", info[topbut].poste);
    printf("age%d\n", info[topbut].age);
    printf("buts%d\n", info[topbut].buts);
    printf("id%d\n", info[topbut].id);
}
void plusjeuneEtage(joueur info[])
{
    int maxage = 0;
    int minage = 0;
    if (totplayers == 0)
    {
        printf("Aucun joueur enregistré.\n");
        return;
    }
    for (int i = 0; i < totplayers; i++)
    {
        if (info[i].age >= info[maxage].age)
        {
            maxage = i;
        }
        else if (info[minage].age >= info[i].age)
        {
            minage = i;
        }
    }
    theprintfunction2(maxage, info);
    theprintfunction2(minage, info);
}
void Statistiques(joueur info[])
{   
    int choix;
    printf(YELLOW"1. "RESET"Afficher le nombre total de joueurs dans l’équipe");
    printf(YELLOW"\n2. "RESET"Afficher l’âge moyen des joueurs.");
    printf(YELLOW"\n3. "RESET"Afficher les joueurs ayant marqué plus de X buts (X introduit par l’utilisateur).");
    printf(YELLOW"\n4. "RESET"Afficher le meilleur buteur (joueur avec le maximum de buts).");
    printf(YELLOW"\n5. "RESET"Afficher le joueur le plus jeune et le plus âgé.");

    printf(YELLOW"\n6. "RESET"Quitter\n");
    printf("====================================");

    printf(YELLOW"\nVotre choix : "RESET);
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        nombretotal(info);
        break;
    case 2:
        agemoyen(info);
        break;
    case 3:
        butmarque(info);
        break;
    case 4:
        meilleurbuteur(info);
        break;
    case 5:
        plusjeuneEtage(info);
        break;
    case 6:
        printf("Quitter\n");
            break;
    default:
        
        printf(RED"Choix Invalide\n"RESET);
            exit(0);
            
        
    }
    
}
int main()
{

    joueur info[100];
    int choix;
    char buffer[100];

    do
    { 
        printf("==================================================\n");

        printf(RED"\tGestion d’une Équipe de Football\t\n"RESET);
        printf(RED"==================================================\n"RESET);

        printf(BLUE"1."RESET
               " Ajouter un joueur");
        printf(BLUE"\n2."RESET
               " Afficher la liste de tous les joueurs ");
        printf(BLUE"\n3."RESET
               " Modifier un joueur ");
        printf(BLUE"\n4."RESET
               " Supprimer un joueur ");
        printf(BLUE"\n5."RESET
               " Rechercher un joueur ");
        printf(BLUE"\n6."RESET
               " Statistiques ");
        printf(RED"\n7. Quitter\n"RESET);
        printf(RED"=================================================="RESET);

            printf(YELLOW"\nVotre choix : "RESET);
         scanf("%d", &choix);
    
               
            
            // break;
            switch (choix)
            {
                case 1:
                    Ajouter(info);

                    break;
                case 2:
                    Afficher(info);
                    break;
                case 3:
                    modifies(info);
                    break;
                case 4:
                    supprimer(info);
                    break;
                case 5:
                    Rechercher(info);
                    break;
                case 6:
                
                    Statistiques(info);
                    break;
                case 7:
                    printf("exit\n");
                    break;
                default:
                    printf("Choix Invalide\n");
                    exit(0);
            }

    }while (choix != 7);
    return 0;
}
