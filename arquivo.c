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

}

int verificacao_login(char apelido[20], char senha[16]){
    
}