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
  Usuario* buscarUsuarioPorCpf(string cpf);
};

class ContainerProduto {
private:
  static ContainerProduto* instancia;
  static vector<Produto> produtos;
public:
  static ContainerProduto* getInstancia();
  vector <Produto> getProdutos();
  bool addProduto(Produto produto);
  bool remProdutoPorCodigo(string codigo);
  void listarProdutos();
  Produto* buscarProdutoPorCodigo(string codigo);
};

#endif
