#include "../headers/store.h"
#include <vector>

UserStore* UserStore::instancia = nullptr;

UserStore* UserStore::getInstancia() {
  if(instancia == nullptr) {
    instancia = new UserStore();
  }

  return instancia;
}

void UserStore::addUsuario(Usuario usuario) {
  usuarios.push_back(usuario);
}

void UserStore::removeUsuarioPorCpf(string cpf) {
  for(auto usuario : usuarios) {
    
  }
}
