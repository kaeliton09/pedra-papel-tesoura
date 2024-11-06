#include "login.h"
#include "arquivo.h"


//menu login
void menu_login(){
    printf("+--------- L O G I N --------+\n");
    printf("| (1) - entrar               |\n");
    printf("| (2) - realizar cadastro    |\n");
    printf("+----------------------------+\n");

    int opcao_menu_login = 0;

    printf("digite o numero da opcao que deseja: ");
    scanf("%d", &opcao_menu_login);

    //verificacao da opcao
    while(opcao_menu_login != 2 && opcao_menu_login != 1){
        printf("opcao invalida, digite um numero valido.\n");
        printf("digite o numero da opcao que deseja: ");
        scanf("%d", &opcao_menu_login);
    }

    //direcionando para opcao desejada
    if(opcao_menu_login == 1) ;
    else criar_cadastro(); 
}

void criar_cadastro(){
    Usuario novo_usuario;
    printf("+--------- C A D A S T R O --------+\n");
    printf("digite seu nome: ");
    scanf(" %s", novo_usuario.nome);
    printf("digite seu apelido: ");
    scanf(" %s", novo_usuario.apelido);

    //cadastro de senha
    char senha_novo_usuario[16];
    printf("digite uma senha de no minimo 8 caracteres e no maximo 16: ");
    scanf(" %s", senha_novo_usuario);

    //verificacao tamanho da senha
    while(strlen(senha_novo_usuario) < 8 && strlen(senha_novo_usuario) > 16){
        printf("tamanho da senha invalido\n");
        printf("digite uma senha de no minimo 8 caracteres e no maximo 16: ");
        scanf(" %s", novo_usuario.senha);
    }

    //confirmacao de senha
    char senha_de_confrimacao[16];
    printf("digite novamente sua senha: ");
    scanf(" %s", senha_de_confrimacao);

    //verificando se as senhas estao iguais
    while(strcmp(senha_de_confrimacao, senha_novo_usuario) != 0){
        printf("as senhas estao diferentes.\n");
        printf("digite novamente sua senha: ");
        scanf(" %s", senha_de_confrimacao);
    }

    //criptografando senha
    //hash simples para mudar senha original
    int tamanho_senha = strlen(senha_de_confrimacao);
    for(int i = 0; i < tamanho_senha; i++){
        if(i % 2 == 0) novo_usuario.senha[i] = senha_de_confrimacao[i] + 13;
        else novo_usuario.senha[i] = senha_de_confrimacao[i] - 5;
    }

    //inicializando outras variaveis do novo usuario
    novo_usuario.nivel = 0;
    novo_usuario.vitorias = 0;
    novo_usuario.partidas = 0;

    salvar_novo_usuario(&novo_usuario);

    printf("cadastro realizado com sucesso.\n");
}

/*void login(){
    char apelido[20];
    char senha_login[16];
    printf("digite seu apelido: ");
    scanf(" %S", apelido);
    printf("digite sua senha: ");
    scanf(" %s", senha_login);

    //verificando no arquivo
    verificacao_login(apelido, senha_login);
}*/

void ordenarVetorComLLSE(int *vetor, int n) {
    Lista lista;
    inicializarLLSE(&lista); // Inicializa a lista vazia

    // Insere cada elemento do vetor na lista de forma ordenada
    for (int i = 0; i < n; i++) {
        inserirOrdenadoLLSE(&lista, vetor[i]);
    }

    // Extrai os elementos da lista para o vetor, agora em ordem crescente
    No *atual = lista.inicio;
    for (int i = 0; i < n && atual != NULL; i++) {
        vetor[i] = atual->dado;   // Copia o valor do nó para o vetor
        atual = atual->proximo;   // Avança para o próximo nó
    }

    liberarLLSE(&lista); // Libera a memória da lista
}

void inserirOrdenadoLLSE(Lista *const plista, int elemento) {
    No *novo = malloc(sizeof(No)); // Aloca um novo nó
    inicializarNo(novo, elemento); // Inicializa o nó com o valor

    // Caso 1: Lista vazia ou o elemento é menor que o primeiro
    if (plista->inicio == NULL || plista->inicio->dado >= elemento) {
        novo->proximo = plista->inicio;  // Coloca o novo nó antes do primeiro
        plista->inicio = novo;           // Atualiza o início da lista
        if (plista->tamanho == 0) {
            plista->fim = novo;          // Se lista estava vazia, fim aponta para o novo nó
        }
    } else {
        // Caso 2: Encontrar a posição correta no meio ou final
        No *atual = plista->inicio;
        while (atual->proximo != NULL && atual->proximo->dado < elemento) {
            atual = atual->proximo; // Avança até encontrar onde inserir
        }
        novo->proximo = atual->proximo; // Insere o novo nó no ponto correto
        atual->proximo = novo;

        if (novo->proximo == NULL) {    // Se foi inserido no final, atualizar fim
            plista->fim = novo;
        }
    }
    plista->tamanho++; // Aumenta o tamanho da lista
}