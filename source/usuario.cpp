#include "../headers/usuario.h"
#include "../headers/containers.h"
#include <iostream>

using namespace std;

CntrContainerUsuario* CntrContainerUsuario::instancia = nullptr;
ContainerUsuario* CntrContainerUsuario::containerUsuario = ContainerUsuario::getInstancia();

CntrContainerUsuario* CntrContainerUsuario::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrContainerUsuario();
  }

  return instancia;
}

bool CntrContainerUsuario::criarUsuario(string nome, string endereco, int cep, string cpf, string senha) {
  Usuario *usuario = nullptr;
  try {
    usuario = new Usuario(nome, endereco, cep, cpf, senha);
  } catch(const invalid_argument& err) {
    cerr << err.what() << endl;
    return false;
  }

  return containerUsuario->addUsuario(*usuario);
}

bool CntrContainerUsuario::excluirUsuarioPorCpf(string cpf) {
  return containerUsuario->remUsuarioPorCpf(cpf);
}

void CntrContainerUsuario::listarUsuarios() {
  containerUsuario->listarUsuarios();
}

Usuario* CntrContainerUsuario::buscarUsuarioPorCpf(string cpf) {
  return containerUsuario->buscarUsuarioPorCpf(cpf);
}
