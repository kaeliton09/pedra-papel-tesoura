#include "jogo.h"
#include "arquivo.h"
#include "login.h"
#include <string.h>
#include <time.h>

void telaInicial(Usuario * usuario){
    system("cls");
    printf("\nbem-vindo(a) ao jogo %s\n", usuario->apelido);
    printf("+ - - - - - - - - M E N U  - - - - - - - - +\n");
    printf("|(1) - jogar nova partida                  |\n");
    printf("|(2) - ver rank                            |\n");
    printf("+ - - - - - - - - - - - - - - - - - - - - -+\n");
    printf("digite o numero da opcao que deseja: ");
    int opcaoMenuJogo = 0;
    scanf("%d", &opcaoMenuJogo);

    //validando numero de opcao
    while(opcaoMenuJogo != 1 && opcaoMenuJogo != 2){
        printf("opcao invalida, digite um numero valido.\n");
        printf("digite o numero da opcao que deseja: ");
        scanf("%d", &opcaoMenuJogo);
    }

    //direcionando para opcao desejada
    if(opcaoMenuJogo == 1) NovaPartida(usuario);
    else printf("top 1\n");
}

void NovaPartida(Usuario * usuario){
    system("cls");
    printf("\n- - - - - - - - P A R T I D A - - - - - - - -\n");
    printf("(1) - pedra | (2) papel | (3) - tesoura\n");
    printf("escolha sua jogada:\n");
    int JogadaUsuario = 0;
    scanf("%d", &JogadaUsuario);

    //validando jogada 
    while(JogadaUsuario != 1 && JogadaUsuario != 2 && JogadaUsuario != 3){
        printf("jogada invalida, digite um numero valido.\n");
        printf("escolha sua jogada:\n");
        scanf("%d", &JogadaUsuario);
    }

    //jogada aleatoria do bot
    int JogadaBot = 0;
    srand(time(NULL));
    JogadaBot = (rand()%3)+1;

    if(VerificaoVitoria(JogadaUsuario, JogadaBot) == 1){
        Jogada(JogadaUsuario, JogadaBot);
        printf(" V I T O R I A \n");

        //atualizando dados
        usuario->vitorias++;
        usuario->partidas++;
        if(usuario->vitorias % 5 == 0) usuario->nivel++;

        printf("boa jogada, o que desja fazer agora? \n");
        printf("(1) - jogar novamente \n");
        printf("(2) - voltar ao menu principal\n");
        printf("digite o numero da opcao que deseja: ");
        int opcaoVerificacao = 0;
        scanf("%d", &opcaoVerificacao);
        
        //validando opcao
        while(opcaoVerificacao != 1 && opcaoVerificacao != 2){
            printf("opcao invalida, digite um numero valido.\n");
            printf("digite o numero da opcao que deseja: ");
            scanf("%d", &opcaoVerificacao);
        }

        if(opcaoVerificacao == 1) NovaPartida(usuario);
        else telaInicial(usuario);
    }
    else if(VerificaoVitoria(JogadaUsuario, JogadaBot) == 2){
        Jogada(JogadaUsuario, JogadaBot);
        printf(" E M P A T E \n");

        //atualizando dados
        usuario->partidas++;

        printf("que pena... o que desja fazer agora? \n");
        printf("(1) - jogar novamente \n");
        printf("(2) - voltar ao menu principal\n");
        printf("digite o numero da opcao que deseja: ");
        int opcaoVerificacao = 0;
        scanf("%d", &opcaoVerificacao);
        
        //validando opcao
        while(opcaoVerificacao != 1 && opcaoVerificacao != 2){
            printf("opcao invalida, digite um numero valido.\n");
            printf("digite o numero da opcao que deseja: ");
            scanf("%d", &opcaoVerificacao);
        }

        if(opcaoVerificacao == 1) NovaPartida(usuario);
        else telaInicial(usuario);
    }
    else{
        Jogada(JogadaUsuario, JogadaBot);
        printf(" D E R R O T A \n");

        //atualizando dados
        usuario->partidas++;

        printf("que pena... o que desja fazer agora? \n");
        printf("(1) - jogar novamente \n");
        printf("(2) - voltar ao menu principal\n");
        printf("digite o numero da opcao que deseja: ");
        int opcaoVerificacao = 0;
        scanf("%d", &opcaoVerificacao);
        
        //validando opcao
        while(opcaoVerificacao != 1 && opcaoVerificacao != 2){
            printf("opcao invalida, digite um numero valido.\n");
            printf("digite o numero da opcao que deseja: ");
            scanf("%d", &opcaoVerificacao);
        }

        if(opcaoVerificacao == 1) NovaPartida(usuario);
        else telaInicial(usuario);
    }
}

void Jogada(int JogadaUsuario, int JogadaBot){
    char Jogador[8];
    char Bot[8];

    if(JogadaUsuario == 1) strcpy(Jogador, "pedra");
    else if(JogadaUsuario == 2) strcpy(Jogador, "papel");
    else strcpy(Jogador, "tesoura");

    if(JogadaBot == 1) strcpy(Bot, "pedra");
    else if(JogadaBot == 2) strcpy(Bot, "papel");
    else strcpy(Bot, "tesoura");
    
    //imprimindo jogada
    printf("jogador: %s\n", Jogador);
    printf("Bot: %s\n", Bot);
}

int VerificaoVitoria(int JogadaUsuario, int JogadaBot){
    if(JogadaUsuario == 1){//pedra
        if(JogadaBot == 1) return 2;//empate
        else if(JogadaBot == 2) return 0;//perdeu
        else return 1;//ganhou
    }
    else if(JogadaUsuario == 2){//papel
        if(JogadaBot == 1) return 1;//ganhou
        else if(JogadaBot == 2) return 2;//empatou
        else return 0;//perdeu
    }
    else{//tesoura
        if(JogadaBot == 1) return 0;//perdeu
        else if(JogadaBot == 2) return 1;//ganhou
        else return 2;//empatou
    }
}