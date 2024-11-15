#pragma once

#include "arquivo.h"
#include "login.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void telaInicial(Usuario * usuario);

void NovaPartida(Usuario * usuario);

void Jogada(int JogadaUsuario, int JogadaBot);

int VerificaoVitoria(int JogadaUsuario, int JogadaBot);

void Perfil(Usuario * usuario);

void sair(Usuario * usuario);