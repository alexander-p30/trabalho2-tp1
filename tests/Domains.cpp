#include <iostream>
#include "Domains.h"
using namespace std;

// Inicialização das variáveis de classe para teste unitário de CEP.
const int TUCep::CEP_VALIDO[6] = {1234567, 8123456, 21234567, 70234567, 41234567, 60234567};
const int TUCep::CEP_INVALIDO = 123456;

/** 
 * Método construtor para a classe de teste de unidade para CEP.
*/
TUCep::TUCep() {
  estado = SUCESSO;
  cep = new Cep();
}

void TUCep::cenarioValido() {
  try {
    const int tamanhoArr = sizeof(CEP_VALIDO)/sizeof(CEP_VALIDO[0]);
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cep->setNumero(CEP_VALIDO[i]);
    }
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

// Inicialização das variáveis de classe para teste unitário de código de agência.
const string TUCodigoDeAgencia::CODIGO_VALIDO[3] = {"1234", "8413", "9999"};
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
    const int tamanhoArr = sizeof(CODIGO_VALIDO)/sizeof(CODIGO_VALIDO[0]);
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      agencia->setCodigo(CODIGO_VALIDO[i]);
    }
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

// Inicialização das variáveis de classe para teste unitário de código de banco.
const string TUCodigoDeBanco::CODIGO_VALIDO[5] = {"001", "033", "104", "237", "341"};
const string TUCodigoDeBanco::CODIGO_INVALIDO = "002";

/** 
 * Método construtor para a classe de teste de unidade para CódigoDeAgencia.
*/
TUCodigoDeBanco::TUCodigoDeBanco() {
  estado = SUCESSO;
  banco = new CodigoDeBanco();
}

void TUCodigoDeBanco::cenarioValido() {
  try {
    const int tamanhoArr = 5;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      banco->setCodigo(CODIGO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCodigoDeBanco::cenarioInvalido() {
  try {
    banco->setCodigo(CODIGO_INVALIDO);
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
int TUCodigoDeBanco::executar() {
  cenarioValido();
  cenarioInvalido();
  delete banco;

  return estado;
}
