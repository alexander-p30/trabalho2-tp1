#include "Domains.h"
#include <iostream>
using namespace std;

/** 
 * Método construtor para classe Cep.
 * @param cepNumber Número inteiro a ser validade pelo método setNumber().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setNumber().
*/
Cep::Cep(int cepNumber) {
  try {
    setNumber(cepNumber);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método setter de número de Cep.
 * @param cepNumber Número de cpf a ser guardado na classe. É um número inteiro, que deve estar contido
 * em um dos seguintes invervalos: [1000000,5999999], 
 * [8000000,8499999], 
 * [20000000,26600999], 
 * [70000000,70999999], 
 * [40000000,41999999],
 * [60000000,60999999]
 * @throw invalid_argument Se o método de validação do número falhar, lança exceção.
 * 
*/
void Cep::setNumber(int cepNumber) {
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

bool Cep::validar(int cepNumber) const {
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
int Cep::getNumber() const {
  return number;
}

/** 
 * Método construtor para classe CodigoDeAgencia.
 * @param code String a ser validada pelo método setCode().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setCode().
*/
CodigoDeAgencia::CodigoDeAgencia(string code) {
  try {
    setCode(code);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método setter para código de agência.
 * @param code Representa o código de agência. Deve estar no formato XXXX, numérico, diferente de 0000.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
void CodigoDeAgencia::setCode(string code) {
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

/** 
 * Método construtor para classe CodigoDeBanco.
 * @param code String a ser validada pelo método setCode().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setCode().
*/
CodigoDeBanco::CodigoDeBanco(string code) {
  try {
    setCode(code);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/** 
 * Método setter para valor de código de banco.
 * @param code Representa o código de banco. Deve estar no formato XXX, numérico, 
 * e deve ser igual a um dos seguintes valores {001, 033, 104, 237, 341}.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
void CodigoDeBanco::setCode(string code) {
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
