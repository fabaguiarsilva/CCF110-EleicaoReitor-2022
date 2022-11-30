/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on September 14, 2022, 10:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"

int lerNumeroCandidatos();
void zeraVotos(int n, candidato candidatos[]);
void lerDadosCandidatos(int nCandidatos, candidato candidatos[]);
void lerDadosCandidatosArquivo(int nCandidatos, candidato candidatos[]);
void lerVotos(int nCandidatos, candidato candidatos[], int *nNulos);
void apuracao(int nCandidatos, candidato candidatos[], 
                    int *iVencedor,int *isEmpate);
void mostrarResultado(int votosNulos, int empate, 
        candidato vencedor);
void relatorioEleicao(int votosNulos, int empate, int nCandidatos, candidato candidatos[]);

int FLAG_TESTE = 0;

int main() {
        
    int nCandidatos = lerNumeroCandidatos();
    int nVotosNulos = 0;
    
    candidato candidatos[nCandidatos];
    
    zeraVotos(nCandidatos, candidatos);
 
    //Ler dados dos candidatos
    //lerDadosCandidatos(nCandidatos, candidatos);
    lerDadosCandidatosArquivo(nCandidatos, candidatos);
    
    lerVotos(nCandidatos, candidatos, &nVotosNulos);
        
    
    //Apurar votação    
    int indiceVencedor = 0;
    int empate = 0; // 1: empate, 0: sem empate
    apuracao(nCandidatos, candidatos, &indiceVencedor, &empate);

    mostrarResultado(nVotosNulos, empate, candidatos[indiceVencedor]);
    
    relatorioEleicao(nVotosNulos, empate, nCandidatos, candidatos);
    
    return (EXIT_SUCCESS);
}


int lerNumeroCandidatos(){
    int nCandidatos;
    if(FLAG_TESTE == 1){
        nCandidatos = 3;
    }else{
        printf("Digite o número de candidatos: ");
        scanf("%d",&nCandidatos);
    }
    return nCandidatos;    
}

void zeraVotos(int n, candidato candidatos[]){
   for(int i=0; i<n; i++){
        candidatos[i].nVotos=0;
   }    
}

void lerDadosCandidatosArquivo(int nCandidatos, candidato candidatos[]){
    FILE *arquivoCandidatos;
    if((arquivoCandidatos = fopen("candidatos.txt","r")) == NULL){
        printf("Erro ao abrir arquivo. Leitura manual.");
        lerDadosCandidatos(nCandidatos, candidatos);
    }else{
        int numero;
        char nome[30];
        int i=0;
        while(!feof(arquivoCandidatos)){
            fscanf(arquivoCandidatos,"%[A-Za-z0-9];%d;\n",&candidatos[i].nome,&candidatos[i].numero);
            printf("Nome: %s - Num: %d\n",candidatos[i].nome,candidatos[i].numero);
            i++;
        }
    }
    
    fclose(arquivoCandidatos);
}

void lerDadosCandidatos(int nCandidatos, candidato candidatos[]){
    for(int i=0; i<nCandidatos; i++){
        
        if(FLAG_TESTE == 1){            
            candidatos[i].numero = i+1;  
            //TODO
            char num[3];
            sprintf(num, "%d", (i+1));
            strcat(strcpy(candidatos[i].nome, "Candidato "), num);
        }else{
        
            printf("Digite numero candidato %d: ",(i+1));
            scanf("%d",&candidatos[i].numero);
            //fflush(stdin);
            getchar();
            
            printf("Digite nome candidato %d: ",(i+1));
            gets(candidatos[i].nome);
        }
    }    
}

void lerVotos(int nCandidatos, candidato candidatos[], int *nNulos){
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
            if(voto == candidatos[j].numero){
                candidatos[j].nVotos++;
                flagNulo = 0;
            }
        }
        
        if(flagNulo == 1){
            (*nNulos)++;
        }
    }    
}

void apuracao(int nCandidatos, candidato candidatos[], 
                    int *iVencedor,int *isEmpate){
    
    for(int i=1; i<nCandidatos; i++){
        if(candidatos[i].nVotos > 
                candidatos[*iVencedor].nVotos){
            *iVencedor = i;
            *isEmpate = 0;
        }else if(candidatos[i].nVotos == 
                candidatos[*iVencedor].nVotos){
            *isEmpate = 1;
        }
    }    
}

void mostrarResultado(int votosNulos, int empate, 
        candidato vencedor){
    printf("Votos Nulos: %d\n",votosNulos);
    if(empate == 0){
               
        printf("Candidato %s (%d) é vencedor com %d votos",
            vencedor.nome,  
            vencedor.numero, 
            vencedor.nVotos);
    }else{
        printf("Empate!");
    }    
}

void relatorioEleicao(int votosNulos, int empate, int nCandidatos, candidato candidatos[]){
    
    FILE *arquivoRelatorio;
    if((arquivoRelatorio = fopen("relatorio.txt","w")) == NULL){
        printf("erro ao abrir arquivo");
        return;
    }
    
    fprintf(arquivoRelatorio, "Eleicoes Reitor UFV\n");
    fprintf(arquivoRelatorio, "Nulos: %d\n",votosNulos);
    
    for(int i=0; i<nCandidatos; i++){
        fprintf(arquivoRelatorio, "Candidato: %s (%d) teve %d votos\n",
                candidatos[i].nome, candidatos[i].numero, candidatos[i].nVotos);
    }
    
    fclose(arquivoRelatorio);       
}

