#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include "interfaces.h"
#include "domains.h"
#include "usuario.h"

class CntrServicoAutenticacao:public IServicoAutenticacao {
private:  
  static CntrServicoAutenticacao *instancia;
  static CntrContainerUsuario *servidor;
public:
  virtual bool autenticar(string cpf, string senha);
  static CntrServicoAutenticacao* getInstancia();
};

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao {
private:
  static CntrApresentacaoAutenticacao *instancia;
  static CntrServicoAutenticacao *servidor;
public:
  virtual bool autenticar();
  static CntrApresentacaoAutenticacao* getInstancia();
};

#endif
