#include "../headers/entities.h"
#include <iostream>

/**
 * Método construtor de entidade Usuario.
 * @param nome String com nome do usuário, a ser verificada pelo metodo Nome::setNome().
 * @param endereco String com endereço do usuário, a ser verificada pelo metodo Endereco::setEndereco().
 * @param cep Inteiro com número de CEP do usuário, a ser verificado pelo metodo Cep::setNumero().
 * @param cpf String com número de CPF do usuário, a ser verificada pelo metodo Cpf::setNumero().
 * @param senha String com senha do usuário, a ser verificada pelo metodo Senha::SetSenha().
 * @throw invalid_argument Se o método de validação de algum dos parâmetros falhar, lança exceção.
 *
*/
Usuario::Usuario(
    string nome,
    string endereco,
    int cep,
    string cpf,
    string senha
  ) {
  try {
    setNome(nome);
    setEndereco(endereco);
    setCep(cep);
    setCpf(cpf);
    setSenha(senha);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método getter para nome de usuário.
 * @return String contendo o nome do usuário.
*/
string Usuario::getNome() const {
  return this->nome.getNome();
}

/** Método setter para nome de usuário.
 * @param nome String contendo nome do usuário, a ser validada pelo método Nome::setNome().
*/
void Usuario::setNome(string nome) {
  try {
    this->nome.setNome(nome);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método getter para endereço de usuário.
 * @return String contendo o endereço do usuário.
*/
string Usuario::getEndereco() const {
  return this->endereco.getEndereco();
}

/** Método setter para endereço de usuário.
 * @param endereco String contendo endereço do usuário, a ser validada pelo método Endereco::setEndereco().
*/
void Usuario::setEndereco(string endereco) {
  try {
    this->endereco.setEndereco(endereco);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método getter para CEP de usuário.
 * @return Inteiro contendo o CEP do usuário.
*/
int Usuario::getCep() const {
  return this->cep.getNumero();
}

/** Método setter para CEP de usuário.
 * @param endereco Inteiro contendo CEP do usuário, a ser validado pelo método Cep::setNumero().
*/
void Usuario::setCep(int cep) {
  try {
    this->cep.setNumero(cep);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método getter para CPF de usuário.
 * @return String contendo o CPF do usuário.
*/
string Usuario::getCpf() const {
  return this->cpf.getNumero();
}

/** Método setter para CPF de usuário.
 * @param endereco String contendo CPF do usuário, a ser validada pelo método Cpf::setNumero().
*/
void Usuario::setCpf(string cpf) {
  try {
    this->cpf.setNumero(cpf);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método getter para senha de usuário.
 * @return String contendo o senha do usuário.
*/
string Usuario::getSenha() const {
  return this->senha.getSenha();
}

/** Método setter para senha de usuário.
 * @param senha String contendo senha do usuário, a ser validada pelo método Senha::setSenha().
*/
void Usuario::setSenha(string senha) {
  try {
    this->senha.setSenha(senha);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}