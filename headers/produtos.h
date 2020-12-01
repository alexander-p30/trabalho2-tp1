#ifndef SERVICO_PRODUTO_H
#define SERVICO_PRODUTO_H

#include "interfaces.h"
#include "containers.h"
#include "entities.h"

class CntrContainerProduto:public IContainerProduto {
private:
  static CntrContainerProduto *instancia;
  static ContainerProduto *containerProduto;
public:
  static CntrContainerProduto* getInstancia();
  virtual bool criarProduto(string codigo, string classe, string emissor, int prazo, string vencimento, float taxa, string horario, float valor);
  virtual bool excluirProdutoPorCodigo(string codigo);
  virtual void listarProdutos();
  virtual Produto* buscarProdutoPorCodigo(string codigo);
};

class CntrApresentacaoProduto:public IApresentacaoProduto {
private:
  static CntrApresentacaoProduto *instancia;
  static CntrContainerProduto *cntrContainerProduto;
public:
  static CntrApresentacaoProduto* getInstancia();
  virtual void cadastrar();
  virtual void descadastrar();
  virtual void listarProdutos();
  virtual void menu();
};

#endif
