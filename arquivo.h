#pragma once
#include "login.h"
#include <stdio.h>

void salvarNovoUsuario(Usuario const * novoUsuario);

int verificacaoLogin(char * apelido, char * senha);

Usuario* UsuarioAtual(char * apelido);

int salvarDados(Usuario * usuario);