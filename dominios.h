#ifndef __DOMINIOS_H__
#define __DOMINIOS_H__

#include <excpt.h>
#include <string.h>

class CodigoDeEvento{;
    private:
        string codigodeevento;
        const static int TAM_MAX_CODIGO = 3;
        const static int STRING_VAZIA = 0;
        void validar(string) throw (invalid_argument);

    public:
        void set_codigodeevento(string codigodeevento) throw (invalid_argument);
        void get_codigodeevento() const{
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
        void get_codigodeapresentacao() const{
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
        void get_codigodeingresso() const{
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
        void get_nomedeevento() const{
            return codigodeingresso;
        }
};
#endif // __DOMINIOS_H__
