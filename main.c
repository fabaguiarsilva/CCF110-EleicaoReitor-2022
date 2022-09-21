/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on September 14, 2022, 10:22 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int nVotosCandidato1 = 0,
        nVotosCandidato2 = 0,
        nVotosCandidato3 = 0;
    
    int nVotosNulos = 0;
    
    //Ler Votos
    int nEleitores;
    printf("Digite o número de eleitores:");
    scanf("%d",&nEleitores);
    
    int voto;
    for(int i=0; i<nEleitores; i++){
        printf("Digite o voto do eleitor %d! ",(i+1));
        scanf("%d",&voto);
        if(voto == 1){
            nVotosCandidato1++;
        }else if(voto == 2){
            nVotosCandidato2++;
        }else if(voto == 3){
            nVotosCandidato3++;
        }else{
            nVotosNulos++;
        }        
    }
        
    
    //Apurar votação
    printf("Votos Nulos: %d\n",nVotosNulos);
    if(nVotosCandidato1 > nVotosCandidato2
       && nVotosCandidato1 > nVotosCandidato3){
        printf("Candidato 1 é o vencedor com %d "
                "voto(s)",nVotosCandidato1);        
    }else if(nVotosCandidato2 > nVotosCandidato1
       && nVotosCandidato2 > nVotosCandidato3){
        printf("Candidato 2 é o vencedor com %d "
                "voto(s)",nVotosCandidato2);               
    }else if(nVotosCandidato3 > nVotosCandidato1
       && nVotosCandidato3 > nVotosCandidato2){
        printf("Candidato 3 é o vencedor com %d "
                "voto(s)",nVotosCandidato3);                       
    }else{
        printf("Empate! Repita a votação!");
    }
    
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}

