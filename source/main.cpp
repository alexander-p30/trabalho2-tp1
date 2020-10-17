#include "../tests/domain_tests.h"
#include <iostream>

int main() {
  TestesDeDominio testesDominio;
  cout.precision(15);

  switch (testesDominio.executar())
  {
  case TestesDeDominio::SUCESSO:
    cout << endl << "Todos os testes de domínio foram bem sucedidos!" << endl;
    break;
  case TestesDeDominio::FALHA:
    cout << endl << "Algum dos testes de domínio apresentou falha!" << endl;
    break;
  }

  return 0;
}
