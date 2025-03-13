cmake_minimum_required(VERSION 3.30)
project(TP1_INF155_H2025 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP1_INF155_H2025 main.c
        couleur.h
        couleur.c
        util.h
        util.c
        terrain.h
        terrain.c
        jeu.h
        jeu.c
        interaction.c
        interaction.h)
