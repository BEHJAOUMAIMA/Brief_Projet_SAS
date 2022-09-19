#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/******************structures************************************/
struct Produit {
       char code[20];
       char nom [15];
       int quantite;
       double prix;
};
/******************global variables*****************************/

struct Produit tab[100];
       int produits = 0;
/*******************Fonctions***********************************/
void cleanCls(){
	system("cls||clear");
}
int ajouterUnProduit(){

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
int ajouterPlusieursProduits(){
    int i, nombre;
    printf("Quel est le nombre de produits que vous souhaitez ajouter ?");
    scanf("%d",&nombre);
    for (i = 0; i<nombre ; i++){
       printf("\nVeuillez entrer le code du produit : ");
       scanf("%s", tab[produits].code);
       printf("Veuillez entrer le nom du produit : ");
       scanf("%s", tab[produits].nom);
       printf("Veuillez entrer la quantite du produit : ");
       scanf("%d", &tab[produits].quantite);
       printf("Veuillez entrer le prix convenable : ");
       scanf("%lf", &tab[produits].prix);
       produits ++;
    }
    printf("\nC est bon , vous avez ajouter les produits correctement!\n");


    return 1;
}

void ListerProduitsNom() {
    int i, j;
    struct Produit temporaire;
    for (i=0; i<produits-1; i++){
        for (j=i+1; j<produits; j++){
            if (tab[i].nom[0]> tab[j].nom[0]){
             strcpy(temporaire.nom,tab[i].nom);
             strcpy(temporaire.code,tab[i].code);
             temporaire.quantite=tab[i].quantite;
             temporaire.prix=tab[i].prix;

             strcpy(tab[i].nom, tab[j].nom);
             strcpy(tab[i].code, tab[j].code);
             tab[i].quantite = tab[j].quantite;
             tab[i].prix=tab[j].prix;

             strcpy(tab[j].nom, temporaire.nom);
             strcpy(tab[j].code, temporaire.code);
             tab[j].quantite = temporaire.quantite;
             tab[j].prix = temporaire.prix;

            }
        }
    }

    for (i=0; i<produits; i++){
    printf("Nom = %s \t\t Code = %s \t\t Quantite = %d\t\t Prix = %.2f \t\t Prix TTC= %.2f\n",tab[i].nom, tab[i].code, tab[i].quantite, tab[i].prix,(tab[i].prix)*1.05);

    }
}
void ListerProduitsPrix() {
    int i, j;
    struct Produit temporaire;
    for (i=0; i<produits-1; i++){
        for (j=i+1; j<produits; j++){
            if (tab[i].prix< tab[j].prix){
             strcpy(temporaire.nom,tab[i].nom);
             strcpy(temporaire.code,tab[i].code);
             temporaire.quantite=tab[i].quantite;
             temporaire.prix=tab[i].prix;

             strcpy(tab[i].nom, tab[j].nom);
             strcpy(tab[i].code, tab[j].code);
             tab[i].quantite = tab[j].quantite;
             tab[i].prix=tab[j].prix;

             strcpy(tab[j].nom, temporaire.nom);
             strcpy(tab[j].code, temporaire.code);
             tab[j].quantite = temporaire.quantite;
             tab[j].prix = temporaire.prix;

            }
        }
    }

    for (i=0; i<produits; i++){
    printf("Nom = %s \t\t Code = %s \t\t Quantite = %d\t\t Prix = %.2f \t\t Prix TTC= %.2f\n",tab[i].nom, tab[i].code, tab[i].quantite, tab[i].prix,(tab[i].prix)*1.05);

    }
}

int main (){
    int choix1, choix2;
    do {
       printf("\t\tBienvenue au Pharmacie YouCode !\t\t\n\n");
       printf("\t\t***************************************************\n\n");
       printf("\t\t1 : Ajouter un produit pharmaceutique :\n");
       printf("\t\t2 : Ajouter plusieurs produits pharmaceutiques :\n");
       printf("\t\t3 : lister les produits pharmaceutiques :\n");
       printf("\t\t4 : Achat d'un produit pharmaceutique :\n");
       printf("\t\t5 : Rechercher un produit pharmaceutique :\n");
       printf("\t\t6 : Supprimer un produit pharmaceutique :\n");
       printf("\t\t7 : Statistiques de Ventes :\n\n");
       printf("\t\t***************************************************\n\n");
       printf("\t\tDonner Votre Choix : ");
       scanf("%d", &choix1);

       switch (choix1){
           case 1:{
               cleanCls();
               ajouterUnProduit();
                  }break;

           case 2:{
               cleanCls();
               ajouterPlusieursProduits();
                 } break;
           case 3:{
               printf("liste des Produits : \n");
               printf("\t1--Selon le nom : \n");
               printf("\t2--Selon l'Ordre Decroissant du Prix : \n");
               printf("\t\t Entrer Votre Choix : \n");
               scanf("%d",&choix2);
               switch(choix2){
                    case 1:{
                         cleanCls();
                         printf("Liste des Produits selon le nom :\n");
                         ListerProduitsNom();
                         break;
                    }
                    case 2 :{
                         cleanCls();
                         printf("Liste des Produits selon le prix :\n");
                         ListerProduitsPrix();
                    }
               }

           }

           case 4:
           break;
           case 5:
           break;
           case 6:
           break;
           case 7:
           break;
           default:
           break;
       }
    }while(1);
   return 0;
}
