#include "CodigoDeBanco.h"
#include <iostream>
using namespace std;

/** 
 * Método construtor da classe CodigoDeBanco.
 * @param code Representa o código de banco. Deve estar no formato XXX, numérico, 
 * e deve ser igual a um dos seguintes valores {001, 033, 104, 237, 341}.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
CodigoDeBanco::CodigoDeBanco(string code) {
  try{
    if(validar(code)){ 
      this->code = code;
    } else {
      throw invalid_argument("valor informado para Código de Banco não é válido.");
    }
  } catch(const invalid_argument& err) {
    cerr << "Argumento inválido: " << err.what();
  }
}

bool CodigoDeBanco::validar(string code) const {
  const string codigosDeBanco[] = {"001", "033", "104", "237", "341"};
  const int numDeCodigos = sizeof(codigosDeBanco)/sizeof(codigosDeBanco[0]);

  int i = 0;

  for(i = 0; i <= numDeCodigos - 1; i++) {
    if(code == codigosDeBanco[i]) {
      return true;
    }
  }

  return false;
}

/** 
 * Método que retorna string do código de banco.
 * @return String do código de banco
*/
string CodigoDeBanco::getCode() const {
  return code;
}
