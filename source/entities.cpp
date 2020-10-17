#include "../headers/entities.h"
#include <iostream>

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

string Usuario::getNome() const {
  return this->nome.getNome();
}

void Usuario::setNome(string nome) {
  try {
    this->nome.setNome(nome);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

string Usuario::getEndereco() const {
  return this->endereco.getEndereco();
}
void Usuario::setEndereco(string endereco) {
  try {
    this->endereco.setEndereco(endereco);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}
int Usuario::getCep() const {
  return this->cep.getNumero();
}
void Usuario::setCep(int cep) {
  try {
    this->cep.setNumero(cep);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}
string Usuario::getCpf() const {
  return this->cpf.getNumero();
}
void Usuario::setCpf(string cpf) {
  try {
    this->cpf.setNumero(cpf);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}
string Usuario::getSenha() const {
  return this->senha.getSenha();
}
void Usuario::setSenha(string senha) {
  try {
    this->senha.setSenha(senha);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}
