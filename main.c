#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    CompteBancaire compte1, compte2;
    int choix;
    float montant;

    while (1) {
        printf("\n--- Gestion Bancaire ---\n");
        printf("1. Créer un compte\n");
        printf("2. Dépôt\n");
        printf("3. Retrait\n");
        printf("4. Afficher le solde\n");
        printf("5. Transférer de l'argent\n");
        printf("6. Afficher les détails du compte\n");
        printf("7. Supprimer le compte\n");
        printf("8. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerCompte(&compte1);
                break;
            case 2:
                printf("Montant à déposer : ");
                scanf("%f", &montant);
                deposer(&compte1, montant);
                break;
            case 3:
                printf("Montant à retirer : ");
                scanf("%f", &montant);
                retirer(&compte1, montant);
                break;
            case 4:
                afficherSolde(&compte1);
                break;
            case 5:
                printf("Création d'un deuxième compte pour le transfert...\n");
                creerCompte(&compte2);
                printf("Montant à transférer : ");
                scanf("%f", &montant);
                transfererArgent(&compte1, &compte2, montant);
                break;
            case 6:
                afficherDetailsCompte(&compte1);
                break;
            case 7:
                supprimerCompte(&compte1);
                break;
            case 8:
                printf("Au revoir !\n");
                exit(0);
            default:
                printf("Option invalide.\n");
        }
    }

    return 0;
}


