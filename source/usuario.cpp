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

  bool usuarioCriado = containerUsuario->addUsuario(*usuario);
  if(usuarioCriado) {
    cout << "Usuário criado com sucesso!" << endl;
  } else {
    cout << "Falha ao criar usuário: cpf " << cpf << " já utilizado." << endl;
  }
  return usuarioCriado;
}

bool CntrContainerUsuario::excluirUsuarioPorCpf(string cpf) {
  if(containerUsuario->remUsuarioPorCpf(cpf)) {
    cout << "Usuário com cpf " << cpf << " excluído com sucesso!" << endl;
    return true;
  }

  cout << "Nenhum usuário com cpf " << cpf << " encontrado. Verifique o cpf fornecido e tente novamente." << endl;
  return false;
}

void CntrContainerUsuario::listarUsuarios() {
  containerUsuario->listarUsuarios();
}

Usuario* CntrContainerUsuario::buscarUsuarioPorCpf(string cpf) {
  return containerUsuario->buscarUsuarioPorCpf(cpf);
}
