#include "Domains.h"
#include <iostream>
using namespace std;

/** 
 * Método construtor da classe Cep.
 * @param cepNumber Número de cpf a ser guardado na classe. É um número inteiro, que deve estar contido
 em um dos seguintes invervalos: [1000000,5999999], 
 [8000000,8499999], 
 [20000000,26600999], 
 [70000000,70999999], 
 [40000000,41999999],
 [60000000,60999999]
 * @throw invalid_argument Se o método de validação do número falhar, lança exceção.
 * 
*/
Cep::Cep(int cepNumber) {
  try{
    if(validar(cepNumber)){ 
      number = cepNumber;
    } else {
      throw invalid_argument("valor informado para CEP não condiz com nenhuma das faixas.");
    }
  } catch(const invalid_argument& err) {
    cerr << "Argumento inválido: " << err.what();
  } 
}

bool Cep::validar(int cepNumber) {
  const int numDeFaixas = 6;
  const int faixas[numDeFaixas][2] = {
    1000000,5999999,
    8000000,8499999,
    20000000,26600999,
    70000000,70999999,
    40000000,41999999,
    60000000,60999999
  };

  int i = 0;

  for(i = 0; i <= numDeFaixas - 1; i++) {
    if(cepNumber >= faixas[i][0] && cepNumber <= faixas[i][1]) {
      return true;
    }
  }
  return false;
}

/** 
 * Método para acessar o número de Cep guardado.
 * @return Inteiro com número do Cep.
*/
int Cep::getNumber() {
  return number;
}

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

bool CodigoDeAgencia::validar(string code) {
  if(code.length() != 4 || code == "0000") {
    return false;
  }

  return true;
}

/** 
 * Método que retorna string do código de agência.
 * @return String do código de agência
*/
string CodigoDeAgencia::getCode() {
  return code;
}
