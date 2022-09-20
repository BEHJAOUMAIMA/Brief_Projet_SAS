#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/******************structures************************************/
struct Produit
{
    char code[20];
    char nom[15];
    int quantite;
    double prix;
};
/******************global variables*****************************/

struct Produit tab[100];
int produits = 0;
/*******************Fonctions***********************************/
void cleanCls()
{
    system("cls||clear");
}
int ajouterUnProduit()
{

    printf("\nVeuillez entrer le code du produit : ");
    scanf("%s", tab[produits].code);
    printf("Veuillez entrer le nom du produit : ");
    scanf("%s", tab[produits].nom);
    printf("Veuillez entrer la quantite du produit : ");
    scanf("%d", &tab[produits].quantite);
    printf("Veuillez entrer le prix convenable : ");
    scanf("%lf", &tab[produits].prix);
    printf("\nC est bon , vous avez ajouter le produit correctement!\n");
    return 1;
}
int ajouterPlusieursProduits()
{
    int i, nombre;
    printf("Quel est le nombre de produits que vous souhaitez ajouter ?");
    scanf("%d", &nombre);
    for (i = 0; i < nombre; i++)
    {
        printf("\nVeuillez entrer le code du produit : ");
        scanf("%s", tab[produits].code);
        printf("Veuillez entrer le nom du produit : ");
        scanf("%s", tab[produits].nom);
        printf("Veuillez entrer la quantite du produit : ");
        scanf("%d", &tab[produits].quantite);
        printf("Veuillez entrer le prix convenable : ");
        scanf("%lf", &tab[produits].prix);
        produits++;
    }
    printf("\nC est bon , vous avez ajouter les produits correctement!\n");

    return 1;
}

void ListerProduitsNom()
{
    int i, j;
    struct Produit temporaire;
    for (i = 0; i < produits - 1; i++)
    {
        for (j = i + 1; j < produits; j++)
        {
            if (tab[i].nom[0] > tab[j].nom[0])
            {
                strcpy(temporaire.nom, tab[i].nom);
                strcpy(temporaire.code, tab[i].code);
                temporaire.quantite = tab[i].quantite;
                temporaire.prix = tab[i].prix;

                strcpy(tab[i].nom, tab[j].nom);
                strcpy(tab[i].code, tab[j].code);
                tab[i].quantite = tab[j].quantite;
                tab[i].prix = tab[j].prix;

                strcpy(tab[j].nom, temporaire.nom);
                strcpy(tab[j].code, temporaire.code);
                tab[j].quantite = temporaire.quantite;
                tab[j].prix = temporaire.prix;
            }
        }
    }

    for (i = 0; i < produits; i++)
    {
        printf("Nom = %s \t\t Code = %s \t\t Quantite = %d\t\t Prix = %.2f \t\t Prix TTC= %.2f\n", tab[i].nom, tab[i].code, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
    }
}
void ListerProduitsPrix()
{
    int i, j;
    struct Produit temporaire;
    for (i = 0; i < produits - 1; i++)
    {
        for (j = i + 1; j < produits; j++)
        {
            if (tab[i].prix < tab[j].prix)
            {
                strcpy(temporaire.nom, tab[i].nom);
                strcpy(temporaire.code, tab[i].code);
                temporaire.quantite = tab[i].quantite;
                temporaire.prix = tab[i].prix;

                strcpy(tab[i].nom, tab[j].nom);
                strcpy(tab[i].code, tab[j].code);
                tab[i].quantite = tab[j].quantite;
                tab[i].prix = tab[j].prix;

                strcpy(tab[j].nom, temporaire.nom);
                strcpy(tab[j].code, temporaire.code);
                tab[j].quantite = temporaire.quantite;
                tab[j].prix = temporaire.prix;
            }
        }
    }

    for (i = 0; i < produits; i++)
    {
        printf("Nom = %s \t\t Code = %s \t\t Quantite = %d\t\t Prix = %.2f \t\t Prix TTC= %.2f\n", tab[i].nom, tab[i].code, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
    }
}

void AchatProduits()
{
    int i, quantiteAchetee;
    char codeProduit[20];
    ListerProduitsNom();
    printf("Veuillez taper le code du produit que vous souhaitez acheter :\n");
    scanf("%s", codeProduit);

    for (i = 0; i < produits; i++)
    {
        if (strcmp(tab[i].code, codeProduit) == 0)
        {
            printf("Code %s\t\t Nom %s\t\t Quantite = %d\t\t Prix = %.2fDHS\t\t Prix TTC = %.2fDHS \n\n", tab[i].code, tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
        }

        printf("\n\n\nVeuillez saisir la quantite du produit que vous voulez acheter :\n");
        scanf("%d", &quantiteAchetee);

        for (i = 0; i < produits; i++)
        {
            if (strcmp(tab[i].code, codeProduit) == 0)
            {
                if (tab[i].quantite > quantiteAchetee)
                {
                    tab[i].quantite -= quantiteAchetee;
                    printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[i].code, tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
                }
                else
                {
                    printf("\nStock epuise !!! Veuillez revenir prochainement. Merci pour votre Comprehension\n\n");
                }
            }
        }
    }
}
void RchercherParCode()
{
    char codeProduit[20];
    int i;
    printf("Veuillez taper le code du produit :\n");
    scanf("%s", codeProduit);
    for (i = 0; i < produits; i++)
    {
        if (strcmp(tab[i].code, codeProduit) == 0)
        {
            printf("Voici Les Informations Du Produit \n\n");
            printf("Nom %s\t\t Quantite = %d\t\t Prix = %.2fDHS\t\t Prix TTC = %.2fDHS \n\n", tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
        }
        else
        {
            printf("\nOuuups! Le code que vous avez taper ne coresspond a aucun Produit de notre Pharmacie!");
        }
    }
}
void RechercherParQuantite(){
     int i, quantiteRecherchee;
     int trouvee = 0;
     printf("\n\n Veuillez Saisir la quantité a rechercher :\n");
     scanf("%d",&quantiteRecherchee);
     for (i=0; i<produits; i++){
        if(tab[i].quantite==quantiteRecherchee){
          printf("\n\n La quantite que vous avez tapee est existee !\n\n");
          printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[i].code, tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
        trouvee=1;
        }
     }
     if(trouvee==0){
        printf("\n\nOuuups!!! La Quantite est Non Trouvable");

     }

}
void AfficherEtatStock(){
    int i;
    int etat = 0;
    printf("Affichage des Produits qui ont une quantite inferieure a 3 :\n\n");
    for(i=0; i<produits ; i++){
        if(tab[i].quantite<3){
            printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[i].code, tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
            etat =1;
        }

    }
    if (etat == 0){
       printf("Y a aucun produit a une quantite inferieure a 3 !!\n\n");
    }


}
void AlimenterStock(){
   int i,indice, quantiteAjoutee;
   char codeProduit[20];
   printf("\n\nVeuillez entrer le Code du produit :\n\n");
   scanf("%s",codeProduit);
   for (i=0; i<produits; i++){
     if (strcmp(tab[i].code,codeProduit)==0){
        printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[i].code, tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);
    indice=i;
     }
   }
   printf("\nVeuillez saisir la Quantite que vous souhaiter ajouter au stock de ce Produit :\n\n");
   scanf("%d", &quantiteAjoutee);

    tab[indice].quantite +=quantiteAjoutee;


   printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[indice].code, tab[indice].nom, tab[indice].quantite, tab[indice].prix, (tab[indice].prix) * 1.15);
}

void SupprimerProduit(){
   int i, j;
   char codeProduit[20];
   printf("Veuiller entrer le Code du Produit que Vous voulez Supprimer :");
   scanf("%s", codeProduit);
   for(i=0; i<produits ; i++){
     if(strcmp(tab[i].code,codeProduit)==0){
        for(j=i; j<produits; j++){
            tab[j]= tab[j+1];
         }
       produits--;
      }
    }
   printf("\n\n\n Voici la liste mis a jour apres la supression du Produit\n\n\n");
   for (i=0; i<produits; i++){
   printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[i].code, tab[i].nom, tab[i].quantite, tab[i].prix, (tab[i].prix) * 1.15);

   }
}

int main()
{
    int choix1, choix2, choix3;
    do
    {
        printf("\t\tBienvenue au Pharmacie YouCode !\t\t\n\n");
        printf("\t*********************************************************************************************\n\n");
        printf("\t\t1 : Ajouter un produit pharmaceutique :\n");
        printf("\t\t2 : Ajouter plusieurs produits pharmaceutiques :\n");
        printf("\t\t3 : lister les produits pharmaceutiques :\n");
        printf("\t\t4 : Achat d'un produit pharmaceutique :\n");
        printf("\t\t5 : Rechercher un produit pharmaceutique :\n");
        printf("\t\t6 : Afficher Etat du Stock des Produits pharmaceutiques:\n");
        printf("\t\t7 : Alimenter le stock des Produits pharmaceutiques :\n");
        printf("\t\t8 : Supprimer un produit pharmaceutique :\n");
        printf("\t\t9 : Statistiques de Ventes :\n\n");
        printf("\t*********************************************************************************************\n\n");
        printf("\t\tDonner Votre Choix : ");
        scanf("%d", &choix1);

        switch (choix1)
        {
        case 1:
        {
            cleanCls();
            ajouterUnProduit();
        }
        break;

        case 2:
        {
            cleanCls();
            ajouterPlusieursProduits();
        }
        break;
        case 3:
        {
            printf("liste des Produits : \n");
            printf("\t1--Selon le nom : \n");
            printf("\t2--Selon l'Ordre Decroissant du Prix : \n");
            printf("\t\t Entrer Votre Choix : \n");
            scanf("%d", &choix2);
            switch (choix2)
            {
            case 1:
            {
                cleanCls();
                printf("Liste des Produits selon le nom :\n");
                ListerProduitsNom();
                break;
            }
            case 2:
            {
                cleanCls();
                printf("Liste des Produits selon le prix :\n");
                ListerProduitsPrix();
                break;
            }
            }
        }

        case 4:
        {
            cleanCls();
            AchatProduits();
            break;
        }
        case 5:
        {
            cleanCls();
            printf("Rechercher Un Produit pharmaceutique : \n");
            printf("\t1-- Par Code : \n");
            printf("\t2-- Par Quantite : \n");
            printf("\t\t Quel est Votre Choix : \n");
            scanf("%d", &choix3);
            switch(choix3)
            {
                case 1 :{
                       cleanCls();
                       RchercherParCode();
                       break;
                }
                case 2 :{
                       cleanCls();
                       RechercherParQuantite();
                       break;
                }
            }
            break;
        }
        case 6:{
            cleanCls();
            AfficherEtatStock();
            break;
        }
        case 7:{
           cleanCls();
           AlimenterStock();
            break;
        }
        case 8:{
            cleanCls();
            SupprimerProduit();
            break;
        }
        case 9:
            break;
        default:
            break;
        }
    } while (1);
    return 0;
}
