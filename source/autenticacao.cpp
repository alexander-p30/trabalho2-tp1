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

void CntrApresentacaoAutenticacao::autenticar() {
  clearscr();
  if(cntrServicoAutenticacao->getUsuarioAtual() != nullptr) {
    cout << "Você está logado como " << cntrServicoAutenticacao->getUsuarioAtual()->getNome() << "." << endl;
    cout << "Deslogue antes de autenticar-se com outro usuário." << endl;
    waitInput();
    return;
  }

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

  cout << "Autenticação realizada com sucesso!" << endl;
  cout << "Bem-vindo(a), " << cntrServicoAutenticacao->getUsuarioAtual()->getNome() << "!" << endl;
  waitInput();
}

void CntrApresentacaoAutenticacao::deslogar() {
  clearscr();
  if(cntrServicoAutenticacao->getUsuarioAtual() == nullptr) {
    cout << "Não há usuário logado no momento. Autentique-se para poder deslogar." << endl;
    waitInput();
    return;
  }

  int op;

  cout << "Deseja mesmo deslogar, " << cntrServicoAutenticacao->getUsuarioAtual()->getNome() << "?" << endl;
  cout << "1. Confirmar\n2. Cancelar" << endl;
  cin >> op;

  string mensagemDeResultado;

  if(op == 1) {
    if(cntrServicoAutenticacao->deslogar()) {
      mensagemDeResultado = "Deslogado com sucesso!";
    } else {
      mensagemDeResultado = "Falha ao deslogar! Certifique-se de que há um usuário logado.";
    }
    cout << mensagemDeResultado << endl;
  }
  waitInput();
}

void CntrApresentacaoAutenticacao::menu() {
  bool executar = true;
  int op;

  while(executar) {
    clearscr();
    cout << "Gereciamento de autenticação" << endl;
    cout << "1. Autenticar\n2. Deslogar\n0. Voltar" << endl;
    cin >> op;
    switch(op) {
      case 1:
        autenticar();
        break;
      case 2:
        deslogar();
        break;
      case 0:
        executar = false;
        break;
    }
  }
}
