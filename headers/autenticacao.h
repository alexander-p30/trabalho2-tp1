#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include "interfaces.h"
#include "domains.h"

class CntrServicoAutenticacao:public IServicoAutenticacao {
private:  
  static CntrServicoAutenticacao *instancia;
public:
  virtual bool autenticar(string cpf, string senha);
  static CntrServicoAutenticacao* getInstancia();
};

#endif
