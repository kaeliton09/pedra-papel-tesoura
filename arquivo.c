#include "arquivo.h"

void salvarNovoUsuario(Usuario const * novoUsuario){
    //abrindo arquivos de usuarios 
    FILE *arquivo = fopen("usuarios.txt", "a+");
    if(arquivo == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return ;
    }

    //escrevendo a struc no arquivo
    fwrite(novoUsuario, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);

    //lendo a quantidade de usuarios
    FILE *arquivoContagem = fopen("contagem.txt", "r");
    if(arquivoContagem == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return ;
    }
    int quantidadeUsuarios = 0;
    fscanf(arquivoContagem, "%d", &quantidadeUsuarios);
    fclose(arquivoContagem);

    quantidadeUsuarios++;

    //arindo arquivo para gravacao
    FILE *arquivoContagem1 = fopen("contagem.txt", "w+");
    if(arquivoContagem1 == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return ;
    }

    fprintf(arquivoContagem1, "%d", quantidadeUsuarios);
    fclose(arquivoContagem1);
}

int verificacaoLogin(char * apelido, char * senha){
    //abrindo arquivo com quantidade de usuarios
    //lendo a quantidade de usuarios
    FILE *arquivoContagem = fopen("contagem.txt", "r");
    if(arquivoContagem == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return 0;
    }
    int quantidadeUsuarios = 0;
    fscanf(arquivoContagem, "%d", &quantidadeUsuarios);
    fclose(arquivoContagem);


    //abrindo arquivo para leitura de dados
    FILE * arquivo = fopen("usuarios.txt", "r");
    if(arquivo == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    //criando um ponteiro que aponta para um usurario
    Usuario usuariosLogin[quantidadeUsuarios];
    //lendo os usuarios do arquivo 
    fread(usuariosLogin, sizeof(Usuario), quantidadeUsuarios, arquivo);

    //verificacao apelido
    int verificaApelido = 0;
    int id = 0;
    for(int i = 0; i < quantidadeUsuarios; i++){
        if(strcmp(usuariosLogin[i].apelido, apelido) == 0){
            verificaApelido = 1;
            printf(" %s\n", usuariosLogin[i].senha);
            printf(" %s\n", senha);
            id = i;
        } 
    }
    if(verificaApelido == 0){
        printf("usuario ou senhas invalidos.\n");
        return 0;
    }
    //verificacao senha
    if(strcmp(usuariosLogin[id].senha, senha) != 0){
        printf("usuario ou senhas invalidos.\n");
        return 0;
    }
    //operacao realizada com sucesso
    return 1;
}

Usuario* UsuarioAtual(char * apelido){
    //abrindo arquivo com quantidade de usuarios
    //lendo a quantidade de usuarios
    FILE *arquivoContagem = fopen("contagem.txt", "r");
    if(arquivoContagem == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return NULL;
    }
    int quantidadeUsuarios = 0;
    fscanf(arquivoContagem, "%d", &quantidadeUsuarios);
    fclose(arquivoContagem);


    //abrindo arquivo para leitura de dados
    FILE * arquivo = fopen("usuarios.txt", "r");
    if(arquivo == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return NULL;
    }

    //criando um ponteiro que aponta para um usurario
    Usuario usuariosLogin[quantidadeUsuarios];
    //lendo os usuarios do arquivo 
    fread(usuariosLogin, sizeof(Usuario), quantidadeUsuarios, arquivo);

    //verificacao apelido
    for(int i = 0; i < quantidadeUsuarios; i++){
        if(strcmp(usuariosLogin[i].apelido, apelido) == 0){
            Usuario* usuarioEncontrado = malloc(sizeof(Usuario));
            *usuarioEncontrado = usuariosLogin[i];
            return usuarioEncontrado;
        } 
    }
    return NULL;
}
