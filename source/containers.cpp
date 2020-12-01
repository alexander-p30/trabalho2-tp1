#include "../headers/containers.h"
#include <vector>
#include <iostream>

using namespace std;

ContainerUsuario* ContainerUsuario::instancia = nullptr;
vector<Usuario> ContainerUsuario::usuarios = {};

ContainerUsuario *ContainerUsuario::getInstancia() {
  if (instancia == nullptr) {
    instancia = new ContainerUsuario();
  }

  return instancia;
}

bool ContainerUsuario::addUsuario(Usuario usuario) {
  string cpfNovoUsuario = usuario.getCpf();
  for(auto usuario = usuarios.begin(); usuario != usuarios.end(); usuario++) {
    if(usuario->getCpf().compare(cpfNovoUsuario) == 0) {
      return false;
    }
  }
  usuarios.push_back(usuario);

  return true;
}

bool ContainerUsuario::remUsuarioPorCpf(string cpf) {
  for(auto usuario = usuarios.begin(); usuario != usuarios.end(); usuario++) {
    if(usuario->getCpf().compare(cpf) == 0) {
      const auto posicaoUsuario = usuario--;
      usuarios.erase(posicaoUsuario);
      return true;
    }
  }

  return false;
}

void ContainerUsuario::listarUsuarios() {
  for(auto usuario = usuarios.begin(); usuario != usuarios.end(); usuario++) {
    cout << usuario->getNome() << " - " << usuario->getCpf() << endl;
  }
}

Usuario* ContainerUsuario::buscarUsuarioPorCpf(string cpf) {
  for(auto usuario = usuarios.begin(); usuario != usuarios.end(); usuario++) {
    if(usuario->getCpf().compare(cpf) == 0) {
      return &(*usuario);
    }
  }

  return nullptr;
}
