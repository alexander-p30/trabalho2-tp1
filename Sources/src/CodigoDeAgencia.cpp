#include "CodigoDeAgencia.h"
#include <iostream>
using namespace std;

/** 
 * Método construtor da classe CodigoDeAgencia.
 * @param code Representa o código de agência. Deve estar no formato XXXX, numérico, diferente de 0000.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
CodigoDeAgencia::CodigoDeAgencia(string code) {
  try{
    if(validar(code)){ 
      this->code = code;
    } else {
      throw invalid_argument("valor informado para Código de Agência não é válido.");
    }
  } catch(const invalid_argument& err) {
    cerr << "Argumento inválido: " << err.what();
  } 
}

bool CodigoDeAgencia::validar(string code) const {
  if(code.length() != 4 || code == "0000") {
    return false;
  }

  return true;
}

/** 
 * Método que retorna string do código de agência.
 * @return String do código de agência
*/
string CodigoDeAgencia::getCode() const {
  return code;
}
