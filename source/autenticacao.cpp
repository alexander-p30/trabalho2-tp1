#include "../headers/autenticacao.h"
#include "../utils/tela.h"
#include <iostream>
#include <string>

using namespace std;

CntrServicoAutenticacao* CntrServicoAutenticacao::instancia = nullptr;
CntrContainerUsuario* CntrServicoAutenticacao::cntrContainerUsuario = CntrContainerUsuario::getInstancia();
Usuario* CntrServicoAutenticacao::usuarioAtual = nullptr;

CntrServicoAutenticacao* CntrServicoAutenticacao::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrServicoAutenticacao();
  }

  return instancia;
}

bool CntrServicoAutenticacao::autenticar(string cpf, string senha) {
  Usuario *usuario = cntrContainerUsuario->buscarUsuarioPorCpf(cpf); 
  if(usuario == nullptr) {
    return false; 
  }

  bool login = usuario->getSenha().compare(senha) == 0;

  usuarioAtual = login ? usuario : nullptr;

  return login;
}

bool CntrServicoAutenticacao::deslogar() {
  if(usuarioAtual == nullptr) {
    return false;
  }

  usuarioAtual = nullptr;

  return true;
}

Usuario* CntrServicoAutenticacao::getUsuarioAtual() {
  return usuarioAtual;
}

CntrApresentacaoAutenticacao* CntrApresentacaoAutenticacao::instancia = nullptr;
CntrServicoAutenticacao* CntrApresentacaoAutenticacao::cntrServicoAutenticacao = CntrServicoAutenticacao::getInstancia();

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
    if(cntrServicoAutenticacao->autenticar(cpf,senha)) {
      break;
    }
    cout << "Autenticação falhou. Por favor, tente novamente." << endl;
    waitInput();    
  }

  return true;  
}
