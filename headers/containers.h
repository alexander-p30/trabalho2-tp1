#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "entities.h"
#include <string>
#include <vector>

using namespace std;

class ContainerUsuario {
private:
  static ContainerUsuario* instancia;
  static vector<Usuario> usuarios;
public:
  static ContainerUsuario* getInstancia();
  vector <Usuario> getUsuarios();
  bool addUsuario(Usuario usuario);
  bool remUsuarioPorCpf(string cpf);
  void listarUsuarios();
};

#endif
