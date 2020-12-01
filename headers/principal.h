#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "interfaces.h"
#include "usuario.h"
#include "produtos.h"
#include "autenticacao.h"

class CntrApresentacaoPrincipal {
private:
  static CntrApresentacaoPrincipal *instancia;
  static CntrApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
  static CntrApresentacaoProduto *cntrApresentacaoProduto;
public:
  static CntrApresentacaoPrincipal* getInstancia();
  virtual void menu();
};

#endif
