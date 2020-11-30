#ifndef SERVICO_USUARIO_H
#define SERVICO_USUARIO_H

#include "interfaces.h"
#include "containers.h"

class CntrContainerUsuario:public IContainerUsuario {
private:
  static CntrContainerUsuario *instancia;
  static ContainerUsuario *usuarios;
public:
  static CntrContainerUsuario* getInstancia();
  virtual bool criarUsuario(string nome, string endereco, int cep, string cpf, string senha);
  virtual bool excluirUsuarioPorCpf(string cpf);
  virtual void listarUsuarios();
};

#endif
