#include "dominios.h"
#include <string.h>
#include <excpt.h>
#include <stdbool.h>

using namespace std;

void CodigoDeEvento::validar(string codigodeevento) throw (invalid_argument){
    int tamanho_vetor = codigodeevento.size();

    if(tamanho_vetor > TAM_MAX_CODIGO){
        throw invalid_argument;
    }
    if(tamanho_vetor > STRING_VAZIA && tamanho_vetor < TAM_MAX_CODIGO){
        throw invalid_argument;
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument;
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(codigodeevento[i] < '0' || codigodeevento[i] > '9'){
            throw invalid_argument;
        }
    }//testa cada um dos caracteres, se nao for um numero de 1 a 9, retorna um erro
}

void CodigoDeEvento::set_codigodeevento(string codigodeevento) throw (invalid_argument){
    validar(codigodeevento);
    this->codigodeevento = codigodeevento;
}

/*------------------------------------------------------------------------------------------*/

void CodigoDeApresentacao::validar(string codigodeapresentacao) throw (invalid_argument){
    int tamanho_vetor = codigodeapresentacao.size();

    if(tamanho_vetor > TAM_MAX_CODIGO){
        throw invalid_argument;
    }
    if(tamanho_vetor > STRING_VAZIA && tamanho_vetor < TAM_MAX_CODIGO){
        throw invalid_argument;
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument;
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(codigodeapresentacao[i] < '0' || codigodeapresentacao[i] > '9'){
            throw invalid_argument;
        }
    }//testa cada um dos caracteres, se nao for um numero de 1 a 9, retorna um erro
}

void CodigoDeApresentacao::set_codigodeapresentacao(string codigodeapresentacao) throw (invalid_argument){
    validar(codigodeapresentacao);
    this->codigodeapresentacao = codigodeapresentacao;
}

/*--------------------------------------------------------------------------------------------------------*/

void CodigoDeIngresso::validar(string codigodeingresso) throw (invalid_argument){
    int tamanho_vetor = codigodeingresso.size();

    if(tamanho_vetor > TAM_MAX_CODIGO){
        throw invalid_argument;
    }
    if(tamanho_vetor > STRING_VAZIA && tamanho_vetor < TAM_MAX_CODIGO){
        throw invalid_argument;
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument;
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(codigodeingresso[i] < '0' || codigodeingresso > '9'){
            throw invalid_argument;
        }
    }//testa cada um dos caracteres, se nao for um numero de 1 a 9, retorna um erro
}

void CodigoDeIngresso::set_codigodeingresso(string codigodeingresso) throw (invalid_argument){
    validar(codigodeingresso);
    this->codigodeingresso = codigodeingresso;
}

/*--------------------------------------------------------------------------------------------*/

void NomeDeEvento::validar(string nomedeevento) throw (invalid_argument){
    int tamanho_vetor = nomedeevento.size();
    bool possui_letra = FALSE;

    if(tamanho_vetor > TAM_MAX_NOME){
        throw invalid_argument;
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument;
    }
    for(int i=0; i<tamanho_vetor; i++){
        if(nomedeevento[i] < '0' && nomedeevento[i] > '9' && nomedeevento[i] < 'a' && nomedeevento[i] > 'z'
           nomedeevento[i] < 'A' && nomedeevento[i] > 'Z' && nomedeevento[i] != ' '){
            throw invalid_argument;
        }
        if((nomedeevento[i] > 'a' && nomedeevento[i] < 'z') || (nomedeevento[i] > 'A' && nomedeevento[i] < 'Z')){
            possui_letra = TRUE;
        }
        if(nomedeevento[i] == ' ' && nomedeevento[i+1] == ' ' && i<tamanho_vetor){
            throw invalid_argument;
        }
    }//testa cada caractere, se for algo diferente de letra, numetro ou espaco, retorna erro
    //retorna erro se tiverem dois espacos seguidos

    if(possui_letra == FALSE){
        throw invalid_argument;
    }//retorna erro caro nao tenha ao menos uma letra no nome;
}

void NomeDeEvento::set_nomedeevento(string nomedeevento) throw (invalid_argument){
    validar(nomedeevento);
    this->nomedeevento = nomedeevento;
}

/*-------------------------------------------------------------------------------------------------------------------*/
