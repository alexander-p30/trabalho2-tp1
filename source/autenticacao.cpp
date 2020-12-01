#include "../headers/autenticacao.h"
#include "../utils/tela.h"
#include <iostream>
#include <string>

using namespace std;

CntrServicoAutenticacao* CntrServicoAutenticacao::instancia = nullptr;
CntrContainerUsuario* CntrServicoAutenticacao::servidor = CntrContainerUsuario::getInstancia();

CntrServicoAutenticacao* CntrServicoAutenticacao::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrServicoAutenticacao();
  }

  return instancia;
}

bool CntrServicoAutenticacao::autenticar(string cpf, string senha) {
  Usuario *usuario = servidor->buscarUsuarioPorCpf(cpf); 
  if(usuario == nullptr) {
    return false; 
  }

  return usuario->getSenha().compare(senha) == 0;
}

CntrApresentacaoAutenticacao* CntrApresentacaoAutenticacao::instancia = nullptr;
CntrServicoAutenticacao* CntrApresentacaoAutenticacao::servidor = CntrServicoAutenticacao::getInstancia();

CntrApresentacaoAutenticacao* CntrApresentacaoAutenticacao::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrApresentacaoAutenticacao();
  }

  return instancia;
}

bool CntrApresentacaoAutenticacao::autenticar() {
  string cpf, senha;
  while(true) {
    clearscr();
    cout << "Login de usuário" << endl;
    cout << "Insira o cpf do usuário(incluindo os caracteres '.' e '-'): ";
    cin >> cpf;
    cout << "Insira a senha do usuário: ";
    cin >> senha;
    if(servidor->autenticar(cpf,senha)) {
      break;
    }
    cout << "Autenticação falhou. Por favor, tente novamente." << endl;
    waitInput();    
  }

  return true;  
}
