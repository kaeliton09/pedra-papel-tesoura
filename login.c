#include "login.h"
#include "arquivo.h"
#include "jogo.h"


//menu login
void menuLogin(){
    printf("+--------- L O G I N --------+\n");
    printf("| (1) - entrar               |\n");
    printf("| (2) - realizar cadastro    |\n");
    printf("+----------------------------+\n");

    int opcaoMenuLogin = 0;

    printf("digite o numero da opcao que deseja: ");
    scanf("%d", &opcaoMenuLogin);

    //verificacao da opcao
    while(opcaoMenuLogin != 2 && opcaoMenuLogin != 1){
        printf("opcao invalida, digite um numero valido.\n");
        printf("digite o numero da opcao que deseja: ");
        scanf("%d", &opcaoMenuLogin);
    }

    //direcionando para opcao desejada
    if(opcaoMenuLogin == 1) login();
    else criarCadastro(); 
}

void criarCadastro(){
    Usuario novoUsuario;
    printf("+--------- C A D A S T R O --------+\n");
    printf("digite seu nome: ");
    scanf(" %s", novoUsuario.nome);
    printf("digite seu apelido: ");
    scanf(" %s", novoUsuario.apelido);

    //cadastro de senha
    char senhaNovoUsuario[16];
    printf("digite uma senha de no minimo 8 caracteres e no maximo 16: ");
    scanf(" %s", senhaNovoUsuario);

    //verificacao tamanho da senha
    while(strlen(senhaNovoUsuario) < 8 || strlen(senhaNovoUsuario) > 16){
        printf("tamanho da senha invalido\n");
        printf("digite uma senha de no minimo 8 caracteres e no maximo 16: ");
        scanf(" %s", senhaNovoUsuario);
    }

    //confirmacao de senha
    char senhaDeConfirmacao[16];
    printf("digite novamente sua senha: ");
    scanf(" %s", senhaDeConfirmacao);

    //verificando se as senhas estao iguais
    while(strcmp(senhaDeConfirmacao, senhaNovoUsuario) != 0){
        printf("as senhas estao diferentes.\n");
        printf("digite novamente sua senha: ");
        scanf(" %s", senhaDeConfirmacao);
    }

    //criptografando senha
    //hash simples para mudar senha original
    int tamanhoSenha = strlen(senhaDeConfirmacao);
    for(int i = 0; i < tamanhoSenha; i++){
        if(i % 2 == 0) novoUsuario.senha[i] = senhaDeConfirmacao[i] + 13;
        else novoUsuario.senha[i] = senhaDeConfirmacao[i] - 5;
    }
    novoUsuario.senha[tamanhoSenha-1] = '\0';
    //inicializando outras variaveis do novo usuario
    novoUsuario.nivel = 0;
    novoUsuario.vitorias = 0;
    novoUsuario.partidas = 0;

    salvarNovoUsuario(&novoUsuario);

    printf("cadastro realizado com sucesso.\n");
    menuLogin();
}

void login(){
    //leitura de apelido e senha
    char apelido[20];
    printf("digite seu apelido: ");
    scanf(" %s", apelido);

    char senha[16];
    printf("digite sua senha: ");
    scanf(" %s", senha);

    //aplicando hash na senha
    int tamanhoSenha = strlen(senha);
    for(int i = 0; i < tamanhoSenha; i++){
        if(i % 2 == 0) senha[i] = senha[i] + 13;
        else senha[i] = senha[i] - 5;
    }
    senha[tamanhoSenha-1] = '\0'; 

    if(verificacaoLogin(apelido, senha)){
        Usuario * usuario = malloc(sizeof(Usuario));
        usuario = UsuarioAtual(apelido);
        telaInicial(usuario);
    }else{
        menuLogin();
    }
}

