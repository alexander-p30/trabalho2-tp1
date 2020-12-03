#ifndef INTERFACES_H
#define INTERFACES_H

#include "entities.h"
#include "containers.h"
#include <string>

// Interfaces para serviços
class IServicoAutenticacao {
public:
  virtual bool autenticar(string cpf, string senha) = 0;
  virtual bool deslogar() = 0;
  virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
  public:
    virtual bool cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha, string banco, string agencia, string numero) = 0;
    virtual ~IServicoPessoal(){}
};

class IContainerUsuario {
public:
  virtual bool criarUsuario(string nome, string endereco, int cep, string cpf, string senha) = 0;
  virtual bool cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha, string banco, string agencia, string numero) = 0;
  virtual bool excluirUsuarioPorCpf(string cpf) = 0;
  virtual void listarUsuarios() = 0;
  virtual Usuario* buscarUsuarioPorCpf(string cpf) = 0;
  virtual ~IContainerUsuario(){}
};

class IContainerProduto {
public:
  virtual bool criarProduto(string codigo, string classe, string emissor, int prazo, string vencimento, float taxa, string horario, float valor) = 0;
  virtual bool excluirProdutoPorCodigo(string codigo) = 0;
  virtual void listarProdutos() = 0;
  virtual Produto* buscarProdutoPorCodigo(string codigo) = 0;
  virtual ~IContainerProduto(){}
};

// Interfaces para apresentação
class IApresentacaoAutenticacao {
public:
  virtual void autenticar() = 0;
  virtual void deslogar() = 0;
  virtual void menu() = 0;
  virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
  public:
    //virtual void executar(string cpf) = 0;
    virtual void cadastrar() = 0;
    virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
    //virtual void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*) = 0;
    virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoProduto {
public:
  virtual void cadastrar() = 0;
  virtual void descadastrar() = 0;
  virtual void listarProdutos() = 0;
  virtual void menu() = 0;
  virtual ~IApresentacaoProduto(){};
};

class IApresentacaoPrincipal {
public:
  virtual void menu() = 0;
  virtual ~IApresentacaoPrincipal(){}
};


#endif
