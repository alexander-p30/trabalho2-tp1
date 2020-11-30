#include "../headers/autenticacao.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  CntrServicoAutenticacao *cntrServicoAutenticacao = CntrServicoAutenticacao::getInstancia();
  string cpf, senha;

  cout << "Digite seu CPF: ";
  cin >> cpf;
  cout << "Digite sua senha: ";
  cin >> senha;

  if(cntrServicoAutenticacao->autenticar(cpf, senha)) {
    cout << "Login bem sucedido!" << endl;
  } else {
    cout << "Login mal sucedido!" << endl;
  }

  return 0;
}
