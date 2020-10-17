#ifndef ENTITIES_H
#define ENTITIES_H

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
  // Construtores
  Usuario(
    string nome,
    string endereco,
    int cep,
    string cpf,
    string senha
  );
  Usuario() {};

  // Getters e setters
  string getNome() const;
  void setNome(string nome);
  string getEndereco() const;
  void setEndereco(string endereco);
  int getCep() const;
  void setCep(int cep);
  string getCpf() const;
  void setCpf(string cpf);
  string getSenha() const;
  void setSenha(string senha);
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
    string banco, 
    string agencia, 
    string numero
  );
  Conta() {};

  // Getters and setters
  string getBanco() const;
  void setBanco(string banco);
  string getAgencia() const;
  void setAgencia(string agencia);
  string getNumero() const;
  void setNumero(string numero);
};

#endif
