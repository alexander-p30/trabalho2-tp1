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
 * Método de execução de teste de unidade para domínio CodigoDeAgencia. São executados dois testes:
 * - Um para valor válido para código de agência;
 * - Um para valor inválido para código de agência.
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
 * Método construtor para a classe de teste de unidade para CódigoDeBanco.
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
 * Método de execução de teste de unidade para domínio CodigoDeBanco. São executados dois testes:
 * - Um para valor válido para código de banco;
 * - Um para valor inválido para código de banco
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCodigoDeBanco::executar() {
  cenarioValido();
  cenarioInvalido();
  delete banco;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de CPF.
const string TUCpf::CPF_VALIDO[3] = {"031.360.531-92",
                                     "733.119.790-87",
                                     "153.364.230-33"};
const string TUCpf::CPF_INVALIDO = "002";

/** 
 * Método construtor para a classe de teste de unidade para CPF.
*/
TUCpf::TUCpf() {
  estado = SUCESSO;
  cpf = new Cpf();
}

void TUCpf::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cpf->setNumero(CPF_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCpf::cenarioInvalido() {
  try {
    cpf->setNumero(CPF_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio CPF. São executados dois testes:
 * - Um para valor válido para CPF;
 * - Um para valor inválido para CPF.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCpf::executar() {
  cenarioValido();
  cenarioInvalido();
  delete cpf;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de código emissor.
const string TUEmissor::CODIGO_VALIDO[3] = {"ABCD39-SA.K A8HDASD88",
                                            "-BChdu",
                                            "LQPcs178dba6d-BC hdu"};
const string TUEmissor::CODIGO_INVALIDO = "cDUAYEVABnc92813-v";

/** 
 * Método construtor para a classe de teste de unidade para Emissor.
*/
TUEmissor::TUEmissor() {
  estado = SUCESSO;
  emissor = new Emissor();
}

void TUEmissor::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      emissor->setCodigo(CODIGO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUEmissor::cenarioInvalido() {
  try {
    emissor->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio Emissor. São executados dois testes:
 * - Um para valor válido para código de emissor;
 * - Um para valor inválido para código de emissor.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUEmissor::executar() {
  cenarioValido();
  cenarioInvalido();
  delete emissor;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de horário.
const string TUHorario::HORARIO_VALIDO[3] = {"13:59",
                                            "15:00",
                                            "17:00"};
const string TUHorario::HORARIO_INVALIDO = "17:01";

/** 
 * Método construtor para a classe de teste de unidade para Horario.
*/
TUHorario::TUHorario() {
  estado = SUCESSO;
  horario = new Horario();
}

void TUHorario::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      horario->setHorario(HORARIO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUHorario::cenarioInvalido() {
  try {
    horario->setHorario(HORARIO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio Horario. São executados dois testes:
 * - Um para valor válido para horário;
 * - Um para valor inválido para horário.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUHorario::executar() {
  cenarioValido();
  cenarioInvalido();
  delete horario;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de número de conta.
const string TUNumeroDeConta::NUMERO_VALIDO[3] = {"000650-9",
                                                  "008880-6",
                                                  "109230-5"};
const string TUNumeroDeConta::NUMERO_INVALIDO = "109230-1";

/** 
 * Método construtor para a classe de teste de unidade para NumeroDeConta.
*/
TUNumeroDeConta::TUNumeroDeConta() {
  estado = SUCESSO;
  conta = new NumeroDeConta();
}

void TUNumeroDeConta::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      conta->setNumero(NUMERO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUNumeroDeConta::cenarioInvalido() {
  try {
    conta->setNumero(NUMERO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio NumeroDeConta. São executados dois testes:
 * - Um para valor válido para número de conta;
 * - Um para valor inválido para número de conta.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUNumeroDeConta::executar() {
  cenarioValido();
  cenarioInvalido();
  delete conta;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de número de conta.
const string TUSenha::SENHA_VALIDA[3] = {"876543",
                                        "132650",
                                        "946127"};
const string TUSenha::SENHA_INVALIDA = "516277";

/** 
 * Método construtor para a classe de teste de unidade para NumeroDeConta.
*/
TUSenha::TUSenha() {
  estado = SUCESSO;
  senha = new Senha();
}

void TUSenha::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      senha->setSenha(SENHA_VALIDA[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUSenha::cenarioInvalido() {
  try {
    senha->setSenha(SENHA_INVALIDA);
    estado = FALHA;
  } catch(const invalid_argument& err) {
    return;
  }
}

/** 
 * Método de execução de teste de unidade para domínio Senha. São executados dois testes:
 * - Um para valor válido para senha;
 * - Um para valor inválido para senha.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUSenha::executar() {
  cenarioValido();
  cenarioInvalido();
  delete senha;

  return estado;
}
