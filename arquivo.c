#include "arquivo.h"

void salvar_novo_usuario(Usuario const * novo_usuario){
    //abrindo arquivos de usuarios 
    FILE *arquivo = fopen("usuarios.txt", "a+");
    if(arquivo == NULL){
        printf("nao foi possivel abrir o arquivo.\n");
        return ;
    }

    //escrevendo a struc no arquivo
    fwrite(novo_usuario, sizeof(Usuario), 1, arquivo);

    fclose(arquivo);

}

int verificacao_login(char apelido[20], char senha[16]){
    
}