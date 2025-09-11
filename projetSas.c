/////////////////version2/////////////////
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    printf("Nom : ");
    scanf(" %[^\n]", info[i].nom);
    printf("prenom :");
    scanf(" %[^\n]", info[i].prenom);
    printf("numeroMaillot :");
    scanf("%d", &info[i].numeroMaillot);
    printf("poste (gardien, défenseur, milieu, attaquant) :");
    scanf(" %[^\n]", info[i].poste);
    printf("age :");
    scanf("%d", &info[i].age);
    printf("buts :");
    scanf("%d", &info[i].buts);
    info[i].id = globalid;
    globalid++;
}
int theprintfunction2(int i, joueur info[])
{
    printf("Nom :%s\n", info[i].nom);
    printf("prenom %s\n", info[i].prenom);
    printf("numeroMaillot %d\n", info[i].numeroMaillot);
    printf("poste%s\n", info[i].poste);
    printf("age%d\n", info[i].age);
    printf("buts%d\n", info[i].buts);
    printf("id%d\n", info[i].id);
}

/// /////// ajout///
void Ajouter(joueur info[])
{
    int count = 0;

    printf("\n1.Ajouter un nouveau joueur");
    printf("\n2.Ajouter plusieurs joueurs\n");

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
        printf("combien de jour");
        scanf(" %d", &nomber);

        for (int i = totplayers; i < totplayers + nomber; i++)
        {
            theprintfunction(i, info);
        }

        totplayers = totplayers + nomber;
    }
    else
    {
        printf("Choix invalide !\n");
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
            { // sort by name
                if (strcmp(info[j].nom, info[j + 1].nom) > 0)
                {

                    joueur temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
            else if (choix == 2)
            { // sort by age
                if (info[j].age > info[j + 1].age)
                {
                    joueur temp = info[j];
                    info[j] = info[j + 1];
                    info[j + 1] = temp;
                }
            }
            else if (choix == 3)
            { // sort by poste
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
        printf("Aucun joueur!\n");
        return;
    }
    printf(" 1 Trier les joueurs par ordre alphabétique (Nom).\n");
    printf("2 Trier les joueurs par âge.\n");
    printf("3 Afficher les joueurs par poste.\n");

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
        printf("choix invalid!");
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
        printf("Poste: gardien\n");
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "gardien";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
        printf("Poste: défenseur\n");
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "défenseur";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
        printf("Poste: milieu\n");
        for (int i = 0; i < totplayers; i++)
        {
            char x[] = "milieu";

            if (strcmp(info[i].poste, x) == 0)
            {
                printf("%s \n", info[i].nom);
            }
        }
        printf("Poste: attaquant\n");
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
        printf("Aucun joueur!\n");
        return;
    }
    char nomRechercher[50];
    int count = 0;
    int idRechercher;

    int trouve = 0;
    printf("\n1.Rechercher un joueur par Identifiant.");
    printf("\n2.Rechercher un joueur par Nom.");

    scanf("%d", &count);
    if (count == 1)
    {
        printf("Entrer id a rechercher");
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
            printf("joueur introuvable.\n");
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
            printf("joueur introuvable.\n");
            return -1;
        }
    }
    else
    {
        printf("invalid choix.\n");
    }
}

/// ///////modifier////////////////
void modifies(joueur info[])
{
    if (totplayers == 0)
    {
        printf("Aucun joueur!\n");
        return;
    }
    int index = Rechercher(info);
    if (index == -1)
    {
        printf("Joueur introuvable, modification annulée.\n");
        return;
    }

    printf("Modifier les informations du joueur  %s :\n", info[index].nom);

    printf("le Nouveau poste : ");
    scanf(" %[^\n]", info[index].poste);

    printf("Nouveau age : ");
    scanf(" %d", &info[index].age);

    printf("Nouveau nombre de buts: ");
    scanf("%d", &info[index].buts);

    printf("✅ Joueur modifié avec succès !\n");
}

////////supprime
void supprimer(joueur info[])
{
    if (totplayers == 0)
    {
        printf("Aucun joueur!\n");
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
            printf("joueur supprime avec succes\n");
            trouve = 1;
            break;
        }
    }
    if (trouve != 1)
    {
        printf("joueur non trouve\n");
    }
}
void nombretotal(joueur info[])
{
    printf("le nombre total de joueurs %d", totplayers);
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
    printf("l’âge moyen %.2f", moyenne);
}
void butmarque(joueur info[])
{
    int choix;
    printf("entrer le nombre de buts");
    scanf("%d", choix);
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
        printf("no one has more then this number of buts");
    }
}
void meilleurbuteur(joueur info[])
{
    int topbut = 0;
    if (totplayers == 0)
    {
        printf("Aucun joueur enregistré.\n");
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
    printf("1.Afficher le nombre total de joueurs dans l’équipe");
    printf("\n2.Afficher l’âge moyen des joueurs.");
    printf("\n3.Afficher les joueurs ayant marqué plus de X buts (X introduit par l’utilisateur).");
    printf("\n4.Afficher le meilleur buteur (joueur avec le maximum de buts).");
    printf("\n5.Afficher le joueur le plus jeune et le plus âgé.");

    printf("\n7. Quitter\n");
    printf("====================================");

    printf("\nVotre choix : ");
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

    default:
        break;
    }
}
int main()
{

    joueur info[100];
    int choix;
    char buffer[100];

    do
    {
        printf("===========================================\n");

        printf("\tGestion d’une Équipe de Football\t\n");
        printf("===========================================\n");

        printf("1."
               " Ajouter un joueur");
        printf("\n2."
               " Afficher la liste de tous les joueurs ");
        printf("\n3."
               " Modifier un joueur ");
        printf("\n4."
               " Supprimer un joueur ");
        printf("\n5."
               " Rechercher un joueur ");
        printf("\n6."
               " Statistiques ");
        printf("\n7. Quitter\n");
        printf("===========================================");

        printf("\nVotre choix : ");
        scanf("%d", &choix);
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
            goto here;
        }

    } while (choix != 7);
here:
    return 0;
}
