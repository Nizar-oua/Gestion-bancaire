#ifndef BANK_H
#define BANK_H

typedef struct {
    int numeroCompte;
    char nom[50];
    float solde;
} CompteBancaire;

// Prototypes des fonctions
void creerCompte(CompteBancaire *compte);
void deposer(CompteBancaire *compte, float montant);
void retirer(CompteBancaire *compte, float montant);
void afficherSolde(CompteBancaire *compte);
void afficherDetailsCompte(CompteBancaire *compte);
void supprimerCompte(CompteBancaire *compte);
void transfererArgent(CompteBancaire *de, CompteBancaire *vers, float montant);
void sauvegarderDansFichier(const char *operation, CompteBancaire *compte, float montant);
#endif // BANK_H
