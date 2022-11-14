#include <stdio.h>
#include <string.h>
#define direcoes "NLSO" //direcoes 0 = Norte, 1 = Leste, 2 = Sul e 3 = Oeste
#define E "E"
#define D "D"



int main(){
    
    FILE *file;
    file = fopen("entrada.txt","r");
    if(file == NULL){
        printf("Arquivo não encontrado!\n");
        return 0;
    }

    int tamanhox, tamanhoy, x=0, y=0;
    int direcao_atual = 0; //inicial, 0 = Norte
    
    fscanf(file, "%i %i ", &tamanhox, &tamanhoy); //lê o tamanho do espaço


    fseek(file, 0, SEEK_CUR); 
    int caract_espaco = ftell(file); //numero de caracteres usados para definir tamanho do ambiente
    fseek(file, 0, SEEK_END);
    int caract_movimentos = ftell(file)+1; //numero de caracteres usados para os movimentos
    fseek(file, caract_espaco, SEEK_SET);
    char movimentos[caract_movimentos-caract_espaco];

    while(fgets(movimentos, caract_movimentos-caract_espaco, file) != NULL){
        
    }
    

    for(int count = 0 ; count < caract_movimentos ; count ++){  //direcao_atual 0 = Norte 1 = Leste 2 = Sul 3 = Oeste
        if(movimentos[count] == 'E'){
            direcao_atual --;
        }else if(movimentos[count] == 'D'){
            direcao_atual ++;
        }
        if(direcao_atual < 0){
            direcao_atual = 3;
        }else if(direcao_atual > 3){
            direcao_atual = 0;
        }
        if(movimentos[count] == 'F'){
            if(direcao_atual == 0){
                y++;
            }else if(direcao_atual == 1){
                x++;
            }else if(direcao_atual == 2){ //verificar valores negativos!!!! unsigned?
                y--;
            }else if(direcao_atual == 3){
                x--;
            }
        }else if(movimentos[count] == 'T'){
            if(direcao_atual == 0){
                y--;
            }else if(direcao_atual == 1){
                x--;
            }else if(direcao_atual == 2){ //verificar valores negativos!!!! unsigned?
                y++;
            }else if(direcao_atual == 3){
                x++;
            }
        }
        if(x < 0){ //Não permite atravessar a parede
            x = 0;
        }else if(x>tamanhox){
            x = tamanhox;
        }else if(y<0){
            y = 0;
        }else if(y>tamanhoy){
            y = tamanhoy;
        }
    }
    if(direcao_atual == 0){
        printf("N ");
    }else if(direcao_atual == 1){
        printf("L ");
    }if(direcao_atual == 2){
        printf("S ");
    }if(direcao_atual == 3){
        printf("O ");
    }

    printf("%i %i\n", x, y);
    fclose(file);
    return 0;
    
}
