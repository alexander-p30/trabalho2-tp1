#ifndef SERVICO_USUARIO_H
#define SERVICO_USUARIO_H

#include "interfaces.h"
#include "containers.h"
#include "entities.h"

class CntrContainerUsuario:public IContainerUsuario {
private:
  static CntrContainerUsuario *instancia;
  static ContainerUsuario *containerUsuario;
public:
  static CntrContainerUsuario* getInstancia();
  virtual bool criarUsuario(string nome, string endereco, int cep, string cpf, string senha);
  virtual bool excluirUsuarioPorCpf(string cpf);
  virtual void listarUsuarios();
  virtual Usuario* buscarUsuarioPorCpf(string cpf);
};

#endif
