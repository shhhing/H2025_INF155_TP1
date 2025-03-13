//
// Created by willi on 2025-03-08.
//

#include "interaction.h"
#include "jeu.h"

#include <stdio.h>

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

void interaction_presenter_jeu() {
    printf("\n");
    printf("\t\tTP1 INF155 - JEU CONDUCTEUR\n");
    printf("\tMISSION3:    PILOTER LE VEHICULE\n");
    printf("\t\t    RECUPERER CARBURANT\n");
    printf("\t\t    ATTEINDRE LA SORTIE\n");
}

void interaction_afficher_options(int carburant) {
    printf("  	           M E N U");
    printf("\t1 - DEPLACER");
    printf("\t2 - BOOST BONUS");
    printf("\t3 - QUITTER");
}

int interaction_demander_action(int carburant) {

    return 0;
}

int interaction_demander_direction_deplacement(int interaction_demander_direction_deplacement) {
    jeu_afficher_direction();
    return 0;
}

void interaction_afficher_echec() {
    printf("VOUS AVEZ PERU\n");
}

void interaction_afficher_victoire(int carburant) {
    printf("VOUS AVEZ GAGNÉ\nIL VOUS RESTE %d de carburant", carburant);
}

int interaction_verifier_choix_action(int action, int carburant) {

    return 0;
}
