
#include "jeu.h"
#include "terrain.h"
#include <stdio.h>

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int* joueur_carburant, t_terrain terrain){
    *joueur_carburant += terrain[joueur_ligne][joueur_colonne] - COUT_DEPLACEMENT_VOISIN;;
    terrain[joueur_ligne][joueur_colonne] = 00;
}

bool jeu_deplacer_joueur(int* joueur_ligne, int* joueur_colonne, t_direction direction){
    switch(direction) {
        case DIRECTION_HAUT:
            (*joueur_ligne)--; break;
        case DIRECTION_BAS:
            (*joueur_ligne)++; break;
        case DIRECTION_GAUCHE:
            (*joueur_colonne)--; break;
        case DIRECTION_DROITE:
            (*joueur_colonne)++; break;
        default:
            return false;
        }

    if(*joueur_ligne < 0 || *joueur_ligne > 10 || *joueur_colonne < 0 || *joueur_colonne > 10) {
        return false;
    }

    return true;
}

void jeu_init(t_terrain terrain, int* joueur_ligne, int* joueur_colonne, int* joueur_carburant,
                                                    int* destination_ligne, int* destination_colonne){
    *joueur_carburant = JOUEUR_CARBURANT_INITIAL;

    terrain_init(terrain);
    terrain_creer_stations_carburant(terrain, TOTAL_CARBURANT_NIVEAU_1);
    terrain_generer_position_sortie(destination_ligne, destination_colonne);
    terrain_generer_position_depart(*destination_ligne, *destination_colonne,
                                                        joueur_ligne, joueur_colonne);
}

void jeu_afficher_direction(t_direction direction) {
    switch (direction) {
        case DIRECTION_HAUT: printf("HAUT\n"); break;
        case DIRECTION_BAS: printf("BAS\n"); break;
        case DIRECTION_GAUCHE: printf("GAUCHE\n"); break;
        case DIRECTION_DROITE: printf("DROITE\n"); break;
        case DIRECTION_ERRONEE: printf("ERRONEE\n"); break;
        default:
            break;
    }
}

t_direction jeu_verifier_choix_deplacement(char* choix){
    t_direction direction;
    *choix = 0;

    scanf("%c", &choix);

    switch (choix) {
        case 'W || w':
            direction = DIRECTION_HAUT;
            break;
        case 'S || s':
            direction = DIRECTION_BAS;
            break;
        case 'A || a':
            direction = DIRECTION_GAUCHE;
            break;
        case 'D || d':
            direction = DIRECTION_DROITE;
            break;
        default: direction = DIRECTION_ERRONEE;
    }
    return direction;
}

void jeu_calculer_voisin(int case_ligne, int case_colonne, t_direction direction,
                                                    int* voisin_ligne, int* voisin_colonne){
    switch(direction) {
        case DIRECTION_HAUT:
            *voisin_ligne = case_ligne--;
            *voisin_colonne = case_colonne;
            break;
        case DIRECTION_BAS:
            *voisin_ligne = case_ligne++;
            *voisin_colonne = case_colonne;
            break;
        case DIRECTION_GAUCHE:
            *voisin_ligne = case_ligne;
            *voisin_colonne = case_colonne--;
            break;
        case DIRECTION_DROITE:
            *voisin_ligne = case_ligne;
            *voisin_colonne = case_colonne++;
            break;
        default: break;
    }
}

int jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant,
                                                    int destination_ligne, int destination_colonne){
    int cas = JEU_ETAT_EN_COURS;

    if(joueur_ligne == destination_ligne && joueur_colonne == destination_colonne) {
        cas = JEU_ETAT_VICTOIRE;
    } else if(joueur_carburant <= 0) {
        cas = JEU_ETAT_ECHEC;
    }

    return cas;
}