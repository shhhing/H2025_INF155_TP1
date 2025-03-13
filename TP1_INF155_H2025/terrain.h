//
// Created by willi on 2025-03-04.
//

#ifndef TERRAIN_H
#define TERRAIN_H

//  taille du terrain
#define NB_LIGNES 10
#define NB_COLONNES 10

#include <stdbool.h>

//  *****************************
//  Definitions des types publics
//  *****************************

//  - Le type pour les cases du terrain
//  Chaque case du terrain contient une certaine quantité de carburant (éventuellement 0)
//  Seul ce module peut accéder aux valeurs des cases en passant par les indices des cases.
//  Les autres modules DOIVENT utiliser les fonctions d'accès qui se trouvent dans ce module-ci.
typedef int t_terrain[NB_LIGNES][NB_COLONNES];

//  Quantité maximale de carburant par case de terrain
#define STATION_MAX_CARBURANT 9

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Propose une position de sortie aleatoire pour un terrain de dimensions NB_LIGNES x NB_COLONNES
 * @name terrain_generer_position_sortie
 * @param sortie_ligne l'adresse ou déposer une ligne de sortie aleatoire
 * @param sortie_colonne l'adresse ou déposer une colonne de sortie aleatoire
 */
void terrain_generer_position_sortie(int* sortie_ligne, int* sortie_colonne);

/**
 * @brief Propose une position de depart aleatoire pour un terrain de dimensions NB_LIGNES x NB_COLONNES
 * @name terrain_generer_position_depart
 * @param destination_ligne la ligne de la sortie actuelle
 * @param destination_colonne la colonne de la sortie actuelle
 * @param depart_ligne l'adresse ou déposer la ligne choisie aléatoirement
 * @param depart_colonne l'adresse ou déposer la colonne choisie aléatoirement
 * @note la distance Manhattan entre la position de depart et la position de sortie doit être plus grande que 10.
 */
void terrain_generer_position_depart(int destination_ligne, int destination_colonne, int* depart_ligne, int* depart_colonne);

/**
 * @brief Vérifie qu'une position se trouve bien dans les limites du terrain de NB_LIGNES x NB_COLONNES
 * @name terrain_contient
 * @param position_ligne la ligne de la case a tester
 * @param position_colonne la colonne de la case a tester
 * @return True si la position se trouve à l'intérieur du terrain, false sinon
 */
bool terrain_contient(int position_ligne, int position_colonne);

/**
 * @brief Retourne la quantité de carburant qui se trouve sur une case donnee du terrain
 * @name terrain_get_carburant
 * @param terrain Le terrain
 * @param position_ligne la ligne de la case dont on veut connaitre la quantité de carburant
 * @param position_colonne la colonne de la case dont on veut connaitre la quantité de carburant
 * @return la quantité de carburant presente a cette position
 */
int terrain_get_carburant(t_terrain terrain, int position_ligne, int position_colonne);

/**
 * @brief Initialise la quantité de carburant sur une case du terrain
 * @name terrain_set_carburant
 * @param terrain le terrain dont on va modifier une case
 * @param position_ligne la ligne de la case a modifier
 * @param position_colonne la colonne de la case a modifier
 * @param carburant Le carburant qui se trouvera dans la case
 */
void terrain_set_carburant(t_terrain terrain, int position_ligne, int position_colonne, int carburant);

/**
 * @brief Initialise toutes les cases d'un terrain à 0 (zero)
 * @name terrain_init
 * @param terrain Le terrain dont on veut initialiser les cases
 */
void terrain_init(t_terrain terrain);

/**
 * @brief Cree aléatoirement les stations de gas sur le terrain.
 *        La quantité_globale des quantités de gas des stations est passée en paramètre.
 * @name terrain_creer_stations_carburant
 * @param terrain Le terrain sur lequel on veut creer les stations de gas
 * @param quantite_globale la quantité globale de carburant à allouer sur l'ensemble des stations
 */
void terrain_creer_stations_carburant(t_terrain terrain, int quantite_globale);

/**
 * @brief Affiche la quantité de gas pour toutes les cases d'un terrain.
 * De plus, presente la case courante et la case de destination avec des couleurs différentes.
 * @name terrain_afficher
 * @param terrain le terrain a afficher
 * @param courante la position de la case courante
 * @param destination_ligne la ligne de la position de la case de destination
 * @param destination_colonne la ligne de la position de la case de destination
 */
void terrain_afficher(t_terrain terrain, int courante, int destination_ligne, int destination_colonne);


#endif //TERRAIN_H