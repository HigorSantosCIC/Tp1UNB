#include "dominios.h"
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>

using namespace std;

void CodigoDeEvento::validar(string codigodeevento) throw (invalid_argument){
    int tamanho_vetor = codigodeevento.size();

    if(tamanho_vetor > TAM_MAX_CODIGO){
        throw invalid_argument("Codigo maior que o possivel.\n");
    }
    if(tamanho_vetor > STRING_VAZIA && tamanho_vetor < TAM_MAX_CODIGO){
        throw invalid_argument("Formato errado, o formato correto e XXX(0<X<9).");
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(codigodeevento[i] < '0' || codigodeevento[i] > '9'){
            throw invalid_argument("Formato errado, somente digitos sao permitidos.\n");
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
        throw invalid_argument("Codigo maior que o possivel.\n");
    }
    if(tamanho_vetor > STRING_VAZIA && tamanho_vetor < TAM_MAX_CODIGO){
        throw invalid_argument("Formato errado, o formato correto e XXXX(0<X<9).\n");
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(codigodeapresentacao[i] < '0' || codigodeapresentacao[i] > '9'){
            throw invalid_argument("Somente digitos sao permitidos.\n");
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
        throw invalid_argument("Codigo maior que o possivel.\n");
    }
    if(tamanho_vetor > STRING_VAZIA && tamanho_vetor < TAM_MAX_CODIGO){
        throw invalid_argument("Formato errado, o formato correto e XXXXX(0<X<9).\n");
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(codigodeingresso[i] < '0' || codigodeingresso[i] > '9'){
            throw invalid_argument("Somente digitos sao permitidos.\n");
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
    int possui_letra = 0;

    if(tamanho_vetor > TAM_MAX_NOME){
        throw invalid_argument("Nome muito extenso, o maximo de caracteres sao 20.\n");
    }
    if(tamanho_vetor == STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }
    for(int i=0; i<tamanho_vetor; i++){
        if(nomedeevento[i] < '0' && nomedeevento[i] > '9' && nomedeevento[i] < 'a' && nomedeevento[i] > 'z' &&
           nomedeevento[i] < 'A' && nomedeevento[i] > 'Z' && nomedeevento[i] != ' '){
            throw invalid_argument("Somento sao permitidos letras, digitos ou espaco.\n");
        }
        if((nomedeevento[i] > 'a' && nomedeevento[i] < 'z') || (nomedeevento[i] > 'A' && nomedeevento[i] < 'Z')){
            possui_letra++;
        }
        if(nomedeevento[i] == ' ' && nomedeevento[i-1] == ' ' && i>0){
            throw invalid_argument("Nao sao permitidos espacos em sequencia.\n");
        }
    }//testa cada caractere, se for algo diferente de letra, numetro ou espaco, retorna erro
    //retorna erro se tiverem dois espacos seguidos

    if(possui_letra > 0){
        throw invalid_argument("Nao possui nenhuma letra.\n");
    }//retorna erro caro nao tenha ao menos uma letra no nome;
}

void NomeDeEvento::set_nomedeevento(string nomedeevento) throw (invalid_argument){
    validar(nomedeevento);
    this->nomedeevento = nomedeevento;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void Data::validar(string data) throw (invalid_argument){
    int tamanho_vetor = data.size();
    int ano_bissexto = 0;
    string::size_type sz;

    if(tamanho_vetor < STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }

    if(tamanho_vetor > TAM_DATA_MAX){
        throw invalid_argument("Data muito extensa.\n");
    }

    if(data[POS_BARRA_DIA] != '/'){
        throw invalid_argument("Data no formato errado.\n");
    }

    if(data[POS_BARRA_MES] != '/'){
        throw invalid_argument("Data no formato errado.\n");
    }

    int dia_int = stoi(data, &sz);
    int mes_int = stoi(data.substr(&sz+1), &sz);
    int ano_int = stoi(data.substr(&sz + &sz + 2));

    if(ano_int % 400 == 0 || (ano_int % 4 == 0 && ano_int % 100 != 0)){
        ano_bissexto = 1;
    }

    if((ano_bissexto == 0 && dia_int > DIA_MAX_FEVEREIRO && mes_int == FEVEREIRO) || dia_int > DIA_MAX ||
        dia_int < DIA_MIN || mes_int > MES_MAX || mes_int < MES_MIN || ano_int > ANO_MAX || ano_int < ANO_MIN){
            throw("Data invalida.\n");
        }

    if(dia_int > 30 && (mes_int == ABRIL || mes_int == JUNHO || mes_int == SETEMBRO || mes_int == NOVEMBRO)){
        throw("Dia invalido.\n");
    }
}

void Data::set_data(string data) throw (invalid_argument){
    validar(data);
    this->data = data;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void Horario::validar(string horario) throw (invalid_argument){
    int tamanho_vetor = horario.size();
    int hora_int, minuto_int;
    string::size_type sz;

    if(tamanho_vetor == STRING_VAZIA){
        throw("Nenhum digito foi inserido.\n");
    }

    if(tamanho_vetor > TAM_MAX){
        throw("Horario muito extenso.\n");
    }

    hora_int = stoi(horario, &sz);
    minuto_int = stoi(horario.substr(&sz+1));

    if(hora_int < HORA_MIN && hora_int > HORA_MAX){
        throw("Hora invalida.\n");
    }

    if(minuto_int != MIN_0 && minuto_int != MIN_15 && minuto_int != MIN_30 && minuto_int != MIN_45){
        throw("Minuto invalido.\n");
    }
}

void Horario::set_horario(string horario) throw (invalid_argument){
    validar(horario);
    this->horario = horario;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void Preco::validar(float preco) throw (invalid_argument){
    if(preco < PRECO_MIN){
        throw invalid_argument("Preco menor que 0.\n");
    }
    if(preco > PRECO_MAX){
        throw invalid_argument("Preco maior que 1000.\n");
    }
}

void Preco::set_preco(int preco) throw (invalid_argument){
    validar(preco);
    this->preco = preco;
}

/*--------------------------------------------------------------------------------------------------------------------*/

void NumeroDeSala::validar(int numerodesala) throw (invalid_argument){
    if(numerodesala < NUM_MIN){
        throw("Numero de sala menor que 1.\n");
    }

    if(numerodesala > NUM_MAX){
        throw("Numero de sala maior que 10.\n");
    }
}

void NumeroDeSala::set_numerodesala(int numerodesala) throw (invalid_argument){
    validar(numerodesala);
    this->numerodesala = numerodesala;
}

/*---------------------------------------------------------------------------------------------------------------------*/

void Cidade::validar(string cidade) throw (invalid_argument){
    int tamanho_vetor = cidade.size();
    int num_letras = 0;

    if(tamanho_vetor == STRING_VAZIA){
        throw("Nenhum caracter foi inserido.\n");
    }

    if(tamanho_vetor > TAM_MAX){
        throw("Nome de cidade muito extenso.\n");
    }

    for(int i=0; i<tamanho_vetor; i++){
        if(cidade[i] < 'a' && cidade[i] > 'z' && cidade[i] != ' ' && cidade[i] != '.'){
            throw("Somente sao permitidos letras, espacos e pontos");
        }
        if(cidade[i] > 'a' && cidade[i] < 'z'){
            num_letras++;
        }

        if(cidade[i] == ' ' && cidade[i-1] == ' '){
            throw("Nao podem existir espacos seguidos.\n");
        }

        if(cidade[i] == '.' && cidade[i-1] < 'a' && cidade[i] > 'z'){
            throw("Ponto deve ser precedido de letra.\n");
        }
    }

    if(num_letras == 0){
        throw("Pelo menos um caracter deve ser uma letra.\n");
    }
}

void Cidade::set_cidade(string cidade) throw (invalid_argument){
    validar(cidade);
    this->cidade = cidade;
}

/*----------------------------------------------------------------------------------------------------*/

void Estado::validar(string estado) throw (invalid_argument){
    int tamanho_vetor = estado.size();

    if(tamanho_vetor == STRING_VAZIA){
        throw("Nenhum caracter foi inserido.\n");
    }

    if(tamanho_vetor > TAM_MAX){
        throw("Nome do estado muito extenso.\n");
    }

    if(estado != AC && estado != AL && estado != AP && estado != AM && estado != BA && estado != CE && estado != DF &&
       estado != ES && estado != GO && estado != MA && estado != MT && estado != MS && estado != MG && estado != PA &&
       estado != PB && estado != PR && estado != PE && estado != PI && estado != RJ && estado != RN && estado != RS &&
       estado != RO && estado != RR && estado != SC && estado != SP && estado != SE && estado != TO){
        throw("Estado invalido.\n");
       }
}

void Estado::set_estado(string estado) throw (invalid_argument){
    validar(estado);
    this->estado = estado;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

void Disponibilidade::validar(int disponibilidade) throw (invalid_argument){
    if(disponibilidade < NUM_MIN){
        throw("Disponibilidade menor que 0.\n");
    }

    if(disponibilidade > NUM_MAX){
        throw("Disponibilidade maior que 250.\n");
    }
}

void Disponibilidade::set_disponibilidade(int disponibilidade) throw (invalid_argument){
    validar(disponibilidade);
    this->disponibilidade = disponibilidade;
}

/*------------------------------------------------------------------------------------------------------------------------*/

void ClasseDeEvento::validar(int classedeevento) throw (invalid_argument){
    if(classedeevento > NUM_MAX){
        throw("Numero invalido.\n");
    }

    if(classedeevento < NUM_MIN){
        throw("Numero invalido.\n");
    }
}

void ClasseDeEvento::set_classedeevento(int classedeevento) throw (invalid_argument){
    validar(classedeevento);
    this->classedeevento = classedeevento;
}

/*---------------------------------------------------------------------------------------------------------------------*/
