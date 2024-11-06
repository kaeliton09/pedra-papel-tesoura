#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct usuario
typedef struct{
    char nome[25];
    char apelido[20];
    char senha[16];
    int nivel;
    int vitorias;
    int partidas;
} Usuario;

void menu_login();

void criar_cadastro();