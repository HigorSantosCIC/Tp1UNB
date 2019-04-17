#ifndef __DOMINIOS_H__
#define __DOMINIOS_H__

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string.h>

using namespace std;

class CodigoDeEvento{;
    private:
        string codigodeevento;
        const static int TAM_MAX_CODIGO = 3;
        const static int STRING_VAZIA = 0;
        void validar(string) throw (invalid_argument);

    public:
        void set_codigodeevento(string codigodeevento) throw (invalid_argument);
        string get_codigodeevento() const{
            return codigodeevento;
        }
};

class CodigoDeApresentacao{
    private:
        string codigodeapresentacao;
        const static int TAM_MAX_CODIGO = 4;
        const static int STRING_VAZIA = 0;
        void validar(string) throw (invalid_argument);

    public:
        void set_codigodeapresentacao(string codigodeapresentacao) throw (invalid_argument);
        string get_codigodeapresentacao() const{
            return codigodeapresentacao;
        }
};

class CodigoDeIngresso{
    private:
        string codigodeingresso;
        const static int TAM_MAX_CODIGO = 5;
        const static int STRING_VAZIA = 0;
        void validar(string) throw (invalid_argument);

    public:
        void set_codigodeingresso(string codigodeingresso) throw (invalid_argument);
        string get_codigodeingresso() const{
            return codigodeingresso;
        }
};

class NomeDeEvento{
    private:
        string nomedeevento;
        const static int TAM_MAX_NOME = 20;
        const static int STRING_VAZIA = 0;
        void validar(string) throw (invalid_argument);

    public:
        void set_nomedeevento(string nomedeevento) throw (invalid_argument);
        string get_nomedeevento() const{
            return nomedeevento;
        }
};

class Data{
    private:
        string data;
        const static int DIA_MAX = 31, DIA_MIN = 1, MES_MAX = 12, MES_MIN = 1, ANO_MAX = 99, ANO_MIN = 0, DIA_MAX_FEVEREIRO = 28;
        const static int POS_BARRA_DIA = 2, POS_BARRA_MES = 5;
        const static int TAM_DATA_MAX = 8, STRING_VAZIA = 0;
        const static int JANEIRO = 1, FEVEREIRO = 2, MARCO = 3, ABRIL = 4, MAIO = 5, JUNHO = 6;
        const static int JULHO = 7, AGOSTO = 8, SETEMBRO = 9, OUTUBRO = 10, NOVEMBRO = 11, DEZEMBRO = 12;
        void validar(string) throw (invalid_argument);

    public:
        void set_data(string) throw (invalid_argument);
        string get_data() const{
            return data;
        }
};

class Horario{
    private:
        string horario;
        const static int HORA_MIN = 7, HORA_MAX = 22, MIN_0 = 0, MIN_15 = 15, MIN_30 = 30, MIN_45 = 45;
        const static int TAM_MAX = 5, STRING_VAZIA = 0;
        const static int POS_DOIS_PONTOS = 2;
        void validar(string) throw (invalid_argument);

    public:
        void set_horario(string horario) throw (invalid_argument);
        string get_horario() const{
            return horario;
        }
};

class Preco{
    private:
        float preco;
        constexpr static float PRECO_MAX = 1000;
        constexpr static float PRECO_MIN = 0;
        void validar(float) throw (invalid_argument);
    public:
        void set_preco(int preco) throw (invalid_argument);
        float get_preco() const{
            return preco;
        }
};

class NumeroDeSala{
    private:
        int numerodesala;
        const static int NUM_MIN = 1, NUM_MAX = 10;
        void validar(int) throw (invalid_argument);

    public:
        void set_numerodesala(int numerodesala) throw (invalid_argument);
        int get_numerodesala() const{
            return numerodesala;
        }
};

class Cidade{
    private:
        string cidade;
        const static int STRING_VAZIA = 0, TAM_MAX = 15;
        void validar(string) throw (invalid_argument);

    public:
        void set_cidade(string cidade) throw (invalid_argument);
        string get_cidade() const{
            return cidade;
        }
};

class Estado{
    private:
        string estado;
        const static int TAM_MAX = 2, STRING_VAZIA = 0;
        string AC = "AC", AL = "AL", AP = "AP", AM = "AM", BA = "BA", CE = "CE", DF = "DF", ES = "ES";
        string GO = "GO", MA = "MA", MT = "MT", MS = "MS", MG = "MG", PA = "PA", PB = "PB", PR = "PR";
        string PE = "PE", PI = "PI", RJ = "RJ", RN = "RN", RS = "RS", RO = "RO", RR = "RR", SC = "SC";
        string SP = "SP", SE = "SE", TO = "TO";
        void validar(string) throw (invalid_argument);

    public:
        void set_estado(string estado) throw (invalid_argument);
        string get_estado() const{
            return estado;
        }
};

class Disponibilidade{
    private:
        int disponibilidade;
        const static int NUM_MAX = 250, NUM_MIN = 0;
        void validar(int) throw (invalid_argument);

    public:
        void set_disponibilidade(int disponibilidade) throw (invalid_argument);
        int get_disponibilidade() const{
            return disponibilidade;
        }
};

class ClasseDeEvento{
    private:
        int classedeevento;
        const static int NUM_MAX = 4, NUM_MIN = 1;
        void validar(int) throw (invalid_argument);

    public:
        void set_classedeevento(int classedeevento) throw (invalid_argument);
        int get_classedeevento() const{
            return classedeevento;
        }
};
#endif // __DOMINIOS_H__
