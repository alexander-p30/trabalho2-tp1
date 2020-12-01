#include "../headers/produtos.h"
#include "../headers/containers.h"
#include <iostream>

using namespace std;

CntrContainerProduto* CntrContainerProduto::instancia = nullptr;
ContainerProduto* CntrContainerProduto::containerProduto = ContainerProduto::getInstancia();

CntrContainerProduto* CntrContainerProduto::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrContainerProduto();
  }

  return instancia;
}

bool CntrContainerProduto::criarProduto(string codigo, string classe, string emissor, int prazo, string vencimento, float taxa, string horario, float valor) {
  Produto *produto = nullptr;
  try {
    produto = new Produto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  } catch(const invalid_argument& err) {
    cerr << err.what() << endl;
    return false;
  }

  bool produtoCriado = containerProduto->addProduto(*produto);
  if(produtoCriado) {
    cout << "Produto criado com sucesso!" << endl;
  } else {
    cout << "Falha ao criar produto: codigo " << codigo << " já utilizado." << endl;
  }
  return produtoCriado;
}

bool CntrContainerProduto::excluirProdutoPorCodigo(string codigo) {
  if(containerProduto->remProdutoPorCodigo(codigo)) {
    cout << "Produto com codigo " << codigo << " excluído com sucesso!" << endl;
    return true;
  }

  cout << "Nenhum produto com codigo " << codigo << " encontrado. Verifique o codigo fornecido e tente novamente." << endl;
  return false;
}

void CntrContainerProduto::listarProdutos() {
  containerProduto->listarProdutos();
}

Produto* CntrContainerProduto::buscarProdutoPorCodigo(string codigo) {
  return containerProduto->buscarProdutoPorCodigo(codigo);
}
