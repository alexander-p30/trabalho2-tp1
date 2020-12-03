#include "../headers/principal.h"
#include "../utils/tela.h"
#include <iostream>

CntrApresentacaoPrincipal* CntrApresentacaoPrincipal::instancia = nullptr;
CntrApresentacaoAutenticacao* CntrApresentacaoPrincipal::cntrApresentacaoAutenticacao = CntrApresentacaoAutenticacao::getInstancia();
CntrApresentacaoProduto* CntrApresentacaoPrincipal::cntrApresentacaoProduto = CntrApresentacaoProduto::getInstancia();
CntrApresentacaoPessoal* CntrApresentacaoPrincipal::cntrApresentacaoPessoal = CntrApresentacaoPessoal::getInstancia();

CntrApresentacaoPrincipal* CntrApresentacaoPrincipal::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrApresentacaoPrincipal();
  }

  return instancia;
}

void CntrApresentacaoPrincipal::menu() {
  bool executar = true;
  int op;

  while(executar) {
    clearscr();
    cout << "Seja bem-vindo(a)!" << endl;
    cout << "1. Autenticação\n2. Produtos\n3. Pessoal\n0. Fechar" << endl;
    cin >> op;
    switch(op) {
      case 1:
        cntrApresentacaoAutenticacao->menu();
        break;
      case 2:
        cntrApresentacaoProduto->menu();
        break;
      case 3:
        cntrApresentacaoPessoal->executar();
        break;
      case 0:
        executar = false;
        break;
    }
  }
}
