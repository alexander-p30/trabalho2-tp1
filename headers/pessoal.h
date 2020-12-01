#ifndef PESSOAL_H
#define PESSOAL_H

#include "interfaces.h"
#include "domains.h"


class CntrServicoPessoal:public IServicoPessoal {
    private:
        static CntrServicoPessoal *instancia;
    public:
        bool cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha);
        static CntrServicoPessoal* getInstancia();
};

class CntrApresentacaoPessoal:public IApresentacaoPessoal{
    private:
        IServicoPessoal *cntrServicoPessoal;
        static CntrApresentacaoPessoal *instancia;
        void consultarDadosPessoais();
        /*IServicoProdutosFinanceiros *cntrServicoProdutosFinanceiros;*/
    public:
        void executar(Cpf);
        void cadastrar();
        void setCntrServicoPessoal(IServicoPessoal*);
        static CntrApresentacaoPessoal* getInstancia();

        /*void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*)*/
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
};

/*inline void CntrApresentacaoPessoal::setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros *cntr){
    cntrServicoProdutosFinanceiros = cntr;
}*/
#endif

