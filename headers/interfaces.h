#ifndef INTERFACES_H
#define INTERFACES_H

#include "entities.h"
#include "containers.h"
#include <string>

class IServicoAutenticacao {
public:
  virtual bool autenticar(string cpf, string senha) = 0;
  virtual ~IServicoAutenticacao(){}
};

class IContainerUsuario {
public:
  virtual bool criarUsuario(string nome, string endereco, int cep, string cpf, string senha) = 0;
  virtual bool excluirUsuarioPorCpf(string cpf) = 0;
  virtual ~IContainerUsuario(){}
};

class IServicoPessoal{
  public:
        virtual bool cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha) = 0;
        virtual ~IServicoPessoal(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(string cpf) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        //virtual void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoPessoal(){}
};


#endif
