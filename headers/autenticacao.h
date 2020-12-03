#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include "interfaces.h"
#include "domains.h"
#include "usuario.h"

class CntrServicoAutenticacao:public IServicoAutenticacao {
private:
  static CntrServicoAutenticacao *instancia;
  static CntrContainerUsuario *cntrContainerUsuario;
  static Usuario *usuarioAtual;
public:
  virtual bool autenticar(string cpf, string senha);
  virtual bool deslogar();
  virtual Usuario* getUsuarioAtual();
  static CntrServicoAutenticacao* getInstancia();
};

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao {
private:
  static CntrApresentacaoAutenticacao *instancia;
  static CntrServicoAutenticacao *cntrServicoAutenticacao;
public:
  virtual void autenticar();
  virtual void deslogar();
  virtual void menu();
  static CntrApresentacaoAutenticacao* getInstancia();
};

#endif
