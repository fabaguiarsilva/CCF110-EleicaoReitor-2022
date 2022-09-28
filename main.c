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

    int nCandidatos = 3;
    
    /*
    int numCandidatos[nCandidatos];
    numCandidatos[0] = 1;
    numCandidatos[1] = 5;
    numCandidatos[2] = 7;
    */
    
    int numCandidatos[] = {1,2,3};

    int votosCandidatos[nCandidatos];
    for(int i=0; i<nCandidatos; i++){
        votosCandidatos[i]=0;
    }
    
    int nVotosNulos = 0;
    
    //Ler Votos
    int nEleitores;
    printf("Digite o número de eleitores:");
    scanf("%d",&nEleitores);
    
    int voto;
    for(int i=0; i<nEleitores; i++){
        printf("Digite o voto do eleitor %d! ",(i+1));
        scanf("%d",&voto);
        
        int flagNulo = 1;
        
        for(int j=0; j<nCandidatos; j++){
            if(voto == numCandidatos[j]){
                votosCandidatos[j]++;
                flagNulo = 0;
            }
        }
        
        if(flagNulo == 1){
            nVotosNulos++;
        }
    }
        
    
    //Apurar votação    
    int indiceVencedor = 0;
    int empate = 0; // 1: empate, 0: sem empate
    
    for(int i=1; i<nCandidatos; i++){
        if(votosCandidatos[i] > 
                votosCandidatos[indiceVencedor]){
            indiceVencedor = i;
            empate = 0;
        }else if(votosCandidatos[i] == 
                votosCandidatos[indiceVencedor]){
            empate = 1;
        }
    }

    
    printf("Votos Nulos: %d\n",nVotosNulos);
    if(empate == 0){
        printf("Candidato %d é vencedor com %d votos",
            numCandidatos[indiceVencedor], 
            votosCandidatos[indiceVencedor]);
    }else{
        printf("Empate!");
    }
    
    return (EXIT_SUCCESS);
}

