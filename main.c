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
    
    int candidatoMaisVotos = 1;
    int nMaisVotos = nVotosCandidato1;
    int empate = 0; // 1: empate, 0: sem empate
    
    if(nVotosCandidato2 > nMaisVotos){
        nMaisVotos = nVotosCandidato2;
        candidatoMaisVotos=2;
        empate = 0;
    }else if(nVotosCandidato2 == nMaisVotos){
        empate = 1;
    }
    
    if(nVotosCandidato3 > nMaisVotos){
        nMaisVotos = nVotosCandidato3;
        candidatoMaisVotos=3;
        empate = 0;
    }else if(nVotosCandidato3 == nMaisVotos){
        empate = 1;
    }

    
    printf("Votos Nulos: %d\n",nVotosNulos);
    if(empate == 0){
        printf("Candidato %d é vencedor com %d votos",
            candidatoMaisVotos, nMaisVotos);
    }else{
        printf("Empate!");
    }
    
    return (EXIT_SUCCESS);
}

