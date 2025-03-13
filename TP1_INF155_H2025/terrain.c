
#include "terrain.h"
#include "util.h"
#include <stdio.h>

int calcule_distance_Manhattan(int ligne_depart, int colonne_depart, int ligne_sortie, int colonne_sortie);

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

void terrain_generer_position_sortie(int* sortie_ligne, int* sortie_colonne) {

    int num_ligne = util_generer_nombre_aleatoire(0, NB_LIGNES);
    int num_colonne = util_generer_nombre_aleatoire(0, NB_COLONNES);

    *sortie_ligne = num_ligne;
    *sortie_colonne = num_colonne;
}

void terrain_generer_position_depart(int destination_ligne, int destination_colonne,
                                                    int* depart_ligne, int* depart_colonne) {
    int num_ligne = 0;
    int num_colonne = 0;
    int distance_manhattan = 0;

    do {
        num_ligne = util_generer_nombre_aleatoire(0, 10);
        num_colonne = util_generer_nombre_aleatoire(0, 10);

        distance_manhattan = calcule_distance_Manhattan(num_ligne, num_colonne,
                                    destination_ligne, destination_colonne);
    }while(distance_manhattan <= 10);

    *depart_ligne = num_ligne;
    *depart_colonne = num_colonne;
}

bool terrain_contient(int position_ligne, int position_colonne) {
    if ((position_ligne < 0 || position_ligne > NB_LIGNES) &&
                    (position_colonne < 0 || position_colonne > NB_COLONNES)) {

        return false;
    }
    return true;
}

int terrain_get_carburant(t_terrain terrain, int position_ligne, int position_colonne) {
    int q_carburant = 0;

    q_carburant = terrain[position_ligne][position_colonne];
    return q_carburant;
}

void terrain_set_carburant(t_terrain terrain, int position_ligne, int position_colonne, int carburant) {
    terrain[position_ligne][position_colonne] = carburant;
}

void terrain_init(t_terrain terrain) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            terrain[i][j] = 0;
        }
    }
}

void terrain_creer_stations_carburant(t_terrain terrain, int quantite_globale) {
    int g_carburant = quantite_globale; /////////////////////////
    int q_carburant = 0;

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            q_carburant = util_generer_nombre_aleatoire(0, STATION_MAX_CARBURANT);

            terrain[i][j] = q_carburant;
            g_carburant  -= q_carburant;

            if (g_carburant == 0) {
                break;
            }
        }

        if (g_carburant == 0) {
            break;
        }
    }
}

void terrain_afficher(t_terrain terrain, int courante, int destination_ligne, int destination_colonne) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            printf("%0d ", terrain[i][j]);
        }
    }
}

//  ***********************************
//  Definitions des fonctions privées
//  ***********************************

int calcule_distance_Manhattan(int ligne_depart, int colonne_depart, int ligne_sortie, int colonne_sortie) {
    int distance = 0;

    int diff_abs_ligne = ABS(ligne_depart - ligne_sortie);
    int diff_abs_colonne = ABS(colonne_depart - colonne_sortie);

    distance = diff_abs_ligne + diff_abs_colonne;

    return distance;
}