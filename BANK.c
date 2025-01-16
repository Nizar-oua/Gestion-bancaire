#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BANK.h"



void creerCompte(CompteBancaire *compte) {
    printf("Entrez le numéro de compte : ");
    scanf("%d", &compte->numeroCompte);
    printf("Entrez le nom du titulaire : ");
    scanf("%s", compte->nom);
    compte->solde = 0.0;
    printf("Compte créé avec succès.\n");
    sauvegarderDansFichier("Création de compte", compte, 0.0);
}

// Fonction pour effectuer un dépôt
void deposer(CompteBancaire *compte, float montant) {
    if (montant > 0) {
        compte->solde += montant;
        printf("Dépôt réussi. Nouveau solde : %.2f\n", compte->solde);
        sauvegarderDansFichier("Dépôt", compte, montant);
    } else {
        printf("Montant invalide.\n");
    }
}

// Fonction pour effectuer un retrait
void retirer(CompteBancaire *compte, float montant) {
    if (montant > 0 && montant <= compte->solde) {
        compte->solde -= montant;
        printf("Retrait réussi. Nouveau solde : %.2f\n", compte->solde);
        sauvegarderDansFichier("Retrait", compte, montant);
    } else {
        printf("Retrait impossible. Solde insuffisant ou montant invalide.\n");
    }
}

// Fonction pour afficher le solde
void afficherSolde(CompteBancaire *compte) {
    printf("Compte N°%d - Titulaire : %s - Solde : %.2f\n",
           compte->numeroCompte, compte->nom, compte->solde);
    sauvegarderDansFichier("Affichage du solde", compte, 0.0);
}

// Fonction pour afficher les détails d'un compte
void afficherDetailsCompte(CompteBancaire *compte) {
    printf("\n--- Détails du compte ---\n");
    printf("Numéro de compte : %d\n", compte->numeroCompte);
    printf("Nom du titulaire : %s\n", compte->nom);
    printf("Solde actuel : %.2f\n", compte->solde);
    sauvegarderDansFichier("Affichage des détails", compte, 0.0);
}

// Fonction pour supprimer un compte
void supprimerCompte(CompteBancaire *compte) {
    compte->numeroCompte = 0;
    strcpy(compte->nom, "");
    compte->solde = 0.0;
    printf("Le compte a été supprimé avec succès.\n");
    sauvegarderDansFichier("Suppression de compte", compte, 0.0);
}

// Fonction pour effectuer un transfert d'argent
void transfererArgent(CompteBancaire *de, CompteBancaire *vers, float montant) {
    if (montant > 0 && montant <= de->solde) {
        de->solde -= montant;
        vers->solde += montant;
        printf("Transfert réussi. Nouveau solde (de) : %.2f\n", de->solde);
        printf("Nouveau solde (vers) : %.2f\n", vers->solde);
        sauvegarderDansFichier("Transfert (de)", de, montant);
        sauvegarderDansFichier("Transfert (vers)", vers, montant);
    } else {
        printf("Transfert impossible. Solde insuffisant ou montant invalide.\n");
    }
}

// Fonction pour sauvegarder les opérations dans un fichier
void sauvegarderDansFichier(const char *operation, CompteBancaire *compte, float montant) {
    FILE *fichier = fopen("banque.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(fichier, "%s : Compte N°%d - Titulaire : %s - Montant : %.2f - Solde : %.2f\n",
            operation, compte->numeroCompte, compte->nom, montant, compte->solde);
    fclose(fichier);
}
