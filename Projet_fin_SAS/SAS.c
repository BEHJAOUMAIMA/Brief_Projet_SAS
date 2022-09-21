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
struct Achat
{
    char code[20];
    char nom[15];
    int quantite;
    double prix, prixTTC;
    int jour, mois, annee;
};

/******************global variables*****************************/
struct Achat Achat[100];
struct Produit tab[100];
int produits = 0;
int produitsachetes = 0;
int Qnt=0;


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
    produits++;
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
                temporaire= tab[i];
                tab[i] = tab[j];
                tab[j] = temporaire;

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
                temporaire= tab[i];
                tab[i] = tab[j];
                tab[j] = temporaire;
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
    int heure, minute, seconde , jour, mois, annee;
    time_t maintenant;

    // renvoie de l'heure actuelle :
    time(&maintenant);
    // Convertir au Format de l'heure actuelle :


    struct tm *local = localtime(&maintenant);
    heure = local->tm_hour;
    minute = local->tm_min;
    seconde = local->tm_sec;
    jour = local->tm_mday;
    mois = local->tm_mon + 1;
    annee = local->tm_year + 1900;




    int i, quantiteAchetee, indice;
    char codeProduit[20];


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
                if (tab[i].quantite >= quantiteAchetee)
                {
                    tab[i].quantite -= quantiteAchetee;
                    indice = i;
        strcpy(Achat[produitsachetes].code, tab[i].code);
        strcpy(Achat[produitsachetes].nom, tab[i].nom);
        Achat[produitsachetes].prix = tab[i].prix;
        Achat[produitsachetes].prixTTC = (tab[i].prix)*1.15;
        Achat[produitsachetes].quantite = quantiteAchetee;
        Achat[produitsachetes].annee = local->tm_year + 1900;
        Achat[produitsachetes].mois = local -> tm_mon + 1;
        Achat[produitsachetes].jour = local -> tm_mday;
        produitsachetes++;
        Qnt += quantiteAchetee;
               printf("Code %s\t\t Nom %s\t Quantite = %d\t Prix = %.2fDHS\t Prix TTC = %.2fDHS \n\n", tab[indice].code, tab[indice].nom, tab[indice].quantite, tab[indice].prix, (tab[indice].prix) * 1.15);
               printf("Aujourd\'hui est : %s", ctime(&maintenant));
               printf("La date : %02d/%02d/%d\n", jour, mois, annee);
               printf("L\'heure : %02d:%02d:%02d\n", heure, minute, seconde);
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

void Statistiques(){

    time_t maintenant;
    // renvoie de l'heure actuelle :
    time(&maintenant);
    // Convertir au Format de l'heure actuelle :
    struct tm *local = localtime(&maintenant);

    double prixTotal = 0 , moyenne = 0,  max =0 , min = 1000;

			for(int i=0;i<produitsachetes;i++)
			{
				if(Achat[i].jour == local->tm_mday)
				{
					prixTotal += Achat[i].prix ;

				}
			}

			moyenne = prixTotal/Qnt ;

			for(int i=0;i<produitsachetes;i++)
			{
				if(Achat[i].prix > max)
				max = Achat[i].prix;
			}

			for(int i=0;i<produitsachetes;i++)
			{
				if(Achat[i].prix < min )
				min = Achat[i].prix;
			}


			printf(" le total des prix des produits vendus en journee courante est = %.2f\n",prixTotal);
			printf("la moyenne des prix des produits vendus en journee courante est = %.2f\n",moyenne);
			printf("le Max des prix des produits vendus en journee courante = %.2f\n",max);
			printf("le Min des prix des produits vendus en journee courante est = %.2f\n",min);
}

int main()
{

    int choix1, choix2, choix3, nombreAchats;
    do
    {
        printf("\n\n\t\tBienvenue au Pharmacie YouCode !\t\t\n\n");
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
            break;
        }

        case 4:
        {
            cleanCls();
            ListerProduitsNom();
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
        case 9:{
            cleanCls();
            Statistiques();
            break;
        }

        }
    } while (choix1!=0);
    return 0;
}

