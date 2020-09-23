#include <iostream>
#include "Domains.h"
using namespace std;

/** 
 * Método construtor para a classe de teste de unidade para CEP.
*/
TUCep::TUCep() {
  estado = SUCESSO;
  cep = new Cep();
}

void TUCep::cenarioValido() {
  try {
    cep->setNumero(CEP_VALIDO);
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCep::cenarioInvalido() {
  try {
    cep->setNumero(CEP_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio CEP. São executados dois testes:
 * - Um para valor válido para CEP;
 * - Um para valor inválido para CEP
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCep::executar() {
  cenarioValido();
  cenarioInvalido();
  delete cep;

  return estado;
}

const string TUCodigoDeAgencia::CODIGO_VALIDO = "1234";
const string TUCodigoDeAgencia::CODIGO_INVALIDO = "0000";

/** 
 * Método construtor para a classe de teste de unidade para CódigoDeAgencia.
*/
TUCodigoDeAgencia::TUCodigoDeAgencia() {
  estado = SUCESSO;
  agencia = new CodigoDeAgencia();
}

void TUCodigoDeAgencia::cenarioValido() {
  try {
    agencia->setCodigo(CODIGO_VALIDO);
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCodigoDeAgencia::cenarioInvalido() {
  try {
    agencia->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio CEP. São executados dois testes:
 * - Um para valor válido para CEP;
 * - Um para valor inválido para CEP
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCodigoDeAgencia::executar() {
  cenarioValido();
  cenarioInvalido();
  delete agencia;

  return estado;
}
