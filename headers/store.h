#ifndef STORE_H
#define STORE_H

#include "entities.h"
#include <vector>

class UserStore {
private:
  static UserStore* instancia;
  static vector <Usuario> usuarios;
public:
  UserStore* getInstancia();
  vector <Usuario> getUsuarios();
  void addUsuario(Usuario usuario);
  void removeUsuarioPorCpf(string cpf);
};

#endif
