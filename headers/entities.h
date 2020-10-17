#include "domains.h"

/** 
 * Classe de entidade para usuário
*/
class Usuario {
private:
  Nome nome;
  Endereco endereco;
  Cep cep;
  Cpf cpf;
  Senha senha;
public:
  // Constructors
  Usuario(
    Nome nome,
    Endereco endereco,
    Cep cep,
    Cpf cpf,
    Senha senha
  );
  Usuario() {};

  // Getters and setters
  string getNome(string nome) const;
  void setNome();
  string getEndereco(string endereco) const;
  void setEndereco();
  string getCep(string Cep) const;
  void setCep();
  string getCpf(string cpf) const;
  void setCpf();
  string getSenha(string senha) const;
  void setSenha();
};

/**
 * Classe de entidade para conta 
*/
class Conta {
private:
  CodigoDeBanco banco;
  CodigoDeAgencia agencia;
  NumeroDeConta numero;
public:
  // Constructors
  Conta(
    CodigoDeBanco banco, 
    CodigoDeAgencia agencia, 
    NumeroDeConta numero
  );
  Conta() {};

  // Getters and setters
  string getBanco(string banco) const;
  void setBanco();
  string getAgencia(string agencia) const;
  void setAgencia();
  string getConta(string conta) const;
  void setConta();
};
