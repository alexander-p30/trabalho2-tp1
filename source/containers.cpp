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
  for(auto usuario = usuarios.begin()--; usuario != usuarios.end(); usuario++) {
    if(usuario->getCpf().compare(cpf) == 0) {
      return &(*usuario);
    }
  }

  return nullptr;
}

ContainerProduto* ContainerProduto::instancia = nullptr;
vector<Produto> ContainerProduto::produtos = {};

ContainerProduto* ContainerProduto::getInstancia() {
  if(instancia == nullptr) {
    instancia = new ContainerProduto();
  }

  return instancia;
}

vector<Produto> ContainerProduto::getProdutos() {
  return produtos;
}

bool ContainerProduto::addProduto(Produto produto) {
  string codigoNovoProduto = produto.getCodigo();
  for(auto produto = produtos.begin(); produto != produtos.end(); produto++) {
    if(produto->getCodigo().compare(codigoNovoProduto) == 0) {
      return false;
    }
  }
  produtos.push_back(produto);

  return true;
}

bool ContainerProduto::remProdutoPorCodigo(string codigo) {
  for(auto produto = produtos.begin(); produto != produtos.end(); produto++) {
    if(produto->getCodigo().compare(codigo) == 0) {
      const auto posicaoProduto = produto--;
      produtos.erase(posicaoProduto);
      return true;
    }
  }

  return false;
}

void ContainerProduto::listarProdutos() {
  for(auto produto = produtos.begin(); produto != produtos.end(); produto++) {
    cout << produto->getCodigo() << "/" << produto->getEmissor() << endl;
  }
}

Produto* ContainerProduto::buscarProdutoPorCodigo(string codigo) {
  for(auto produto = produtos.begin()--; produto != produtos.end(); produto++) {
    if(produto->getCodigo().compare(codigo) == 0) {
      return &(*produto);
    }
  }

  return nullptr;
}
