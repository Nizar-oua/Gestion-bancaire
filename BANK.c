#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BANK.h"



void creerCompte(CompteBancaire *compte) {
    printf("Entrez le num�ro de compte : ");
    scanf("%d", &compte->numeroCompte);
    printf("Entrez le nom du titulaire : ");
    scanf("%s", compte->nom);
    compte->solde = 0.0;
    printf("Compte cr�� avec succ�s.\n");
    sauvegarderDansFichier("Cr�ation de compte", compte, 0.0);
}

// Fonction pour effectuer un d�p�t
void deposer(CompteBancaire *compte, float montant) {
    if (montant > 0) {
        compte->solde += montant;
        printf("D�p�t r�ussi. Nouveau solde : %.2f\n", compte->solde);
        sauvegarderDansFichier("D�p�t", compte, montant);
    } else {
        printf("Montant invalide.\n");
    }
}

// Fonction pour effectuer un retrait
void retirer(CompteBancaire *compte, float montant) {
    if (montant > 0 && montant <= compte->solde) {
        compte->solde -= montant;
        printf("Retrait r�ussi. Nouveau solde : %.2f\n", compte->solde);
        sauvegarderDansFichier("Retrait", compte, montant);
    } else {
        printf("Retrait impossible. Solde insuffisant ou montant invalide.\n");
    }
}

// Fonction pour afficher le solde
void afficherSolde(CompteBancaire *compte) {
    printf("Compte N�%d - Titulaire : %s - Solde : %.2f\n",
           compte->numeroCompte, compte->nom, compte->solde);
    sauvegarderDansFichier("Affichage du solde", compte, 0.0);
}

// Fonction pour afficher les d�tails d'un compte
void afficherDetailsCompte(CompteBancaire *compte) {
    printf("\n--- D�tails du compte ---\n");
    printf("Num�ro de compte : %d\n", compte->numeroCompte);
    printf("Nom du titulaire : %s\n", compte->nom);
    printf("Solde actuel : %.2f\n", compte->solde);
    sauvegarderDansFichier("Affichage des d�tails", compte, 0.0);
}

// Fonction pour supprimer un compte
void supprimerCompte(CompteBancaire *compte) {
    compte->numeroCompte = 0;
    strcpy(compte->nom, "");
    compte->solde = 0.0;
    printf("Le compte a �t� supprim� avec succ�s.\n");
    sauvegarderDansFichier("Suppression de compte", compte, 0.0);
}

// Fonction pour effectuer un transfert d'argent
void transfererArgent(CompteBancaire *de, CompteBancaire *vers, float montant) {
    if (montant > 0 && montant <= de->solde) {
        de->solde -= montant;
        vers->solde += montant;
        printf("Transfert r�ussi. Nouveau solde (de) : %.2f\n", de->solde);
        printf("Nouveau solde (vers) : %.2f\n", vers->solde);
        sauvegarderDansFichier("Transfert (de)", de, montant);
        sauvegarderDansFichier("Transfert (vers)", vers, montant);
    } else {
        printf("Transfert impossible. Solde insuffisant ou montant invalide.\n");
    }
}

// Fonction pour sauvegarder les op�rations dans un fichier
void sauvegarderDansFichier(const char *operation, CompteBancaire *compte, float montant) {
    FILE *fichier = fopen("banque.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(fichier, "%s : Compte N�%d - Titulaire : %s - Montant : %.2f - Solde : %.2f\n",
            operation, compte->numeroCompte, compte->nom, montant, compte->solde);
    fclose(fichier);
}
