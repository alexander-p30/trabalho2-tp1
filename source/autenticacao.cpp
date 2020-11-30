#include "../headers/autenticacao.h"
#include <iostream>
#include <string>

CntrServicoAutenticacao* CntrServicoAutenticacao::instancia = nullptr;

CntrServicoAutenticacao* CntrServicoAutenticacao::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrServicoAutenticacao();
  }

  return instancia;
}

bool CntrServicoAutenticacao::autenticar(string cpf, string senha) {
  string defValue = "123";
  bool validCpf = cpf.compare(defValue) == 0;
  bool validSenha = senha.compare(defValue) == 0;
  return validCpf && validSenha;
}
