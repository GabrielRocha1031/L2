#include <stdio.h>
#include <string.h>




int main(){
    
    FILE *file;
    file = fopen("entrada.txt","r");
    if(file == NULL){
        printf("Arquivo não encontrado!\n");
        return 0;
    }

    int x, y;
    
    fscanf(file, "%i %i ", &x, &y);
    printf("%i %i\n", x, y);


    fseek(file, 0, SEEK_CUR); 
    int caract_espaco = ftell(file); //numero de caracteres usados para definir tamanho do ambiente
    fseek(file, 0, SEEK_END);
    int caract_movimentos = ftell(file); //numero de caracteres usados para os movimentos
    fseek(file, caract_espaco, SEEK_SET);
    char movimentos[caract_movimentos-caract_espaco];

    while(fgets(movimentos, caract_movimentos-caract_espaco, file) != NULL){
        printf("%s", movimentos);
    }
    

    fclose(file);
    return 0;
}