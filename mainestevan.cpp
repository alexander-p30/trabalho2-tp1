#include <iostream>
#include "tests/DomainTests.h"

int main () {
  TUCep testeCep;
  switch(testeCep.executar()) {
    case TUCep::SUCESSO:
      cout << "X Teste de CEP bem sucedido!" << endl;
      break;
    case TUCep::FALHA:
      cout << "O Teste de CEP apresentou falha!" << endl;
      break;
  }

  TUCodigoDeAgencia testeAgencia;
  switch(testeAgencia.executar()) {
    case TUCodigoDeAgencia::SUCESSO:
      cout << "X Teste de código de agência bem sucedido!" << endl;
      break;
    case TUCodigoDeAgencia::FALHA:
      cout << "O Teste de código de agência apresentou falha!" << endl;
      break;
  }

  TUCodigoDeBanco testeBanco;
  switch(testeBanco.executar()) {
    case TUCodigoDeBanco::SUCESSO:
      cout << "X Teste de código de banco bem sucedido!" << endl;
      break;
    case TUCodigoDeBanco::FALHA:
      cout << "O Teste de código de banco apresentou falha!" << endl;
      break;
  }

  TUCpf testeCpf;
  switch(testeCpf.executar()) {
    case TUCpf::SUCESSO:
      cout << "X Teste de número de CPF bem sucedido!" << endl;
      break;
    case TUCpf::FALHA:
      cout << "O Teste de número de CPF apresentou falha!" << endl;
      break;
  }

  TUEmissor testeEmissor;
  switch(testeEmissor.executar()) {
    case TUEmissor::SUCESSO:
      cout << "X Teste de código de emissor bem sucedido!" << endl;
      break;
    case TUEmissor::FALHA:
      cout << "O Teste de código de emissor apresentou falha!" << endl;
      break;
  }

  TUHorario testeHorario;
  switch(testeHorario.executar()) {
    case TUHorario::SUCESSO:
      cout << "X Teste de horário bem sucedido!" << endl;
      break;
    case TUHorario::FALHA:
      cout << "O Teste de horário apresentou falha!" << endl;
      break;
  }

  TUNumeroDeConta testeConta;
  switch(testeConta.executar()) {
    case TUNumeroDeConta::SUCESSO:
      cout << "X Teste de número de conta bem sucedido!" << endl;
      break;
    case TUNumeroDeConta::FALHA:
      cout << "O Teste de número de conta apresentou falha!" << endl;
      break;
  }

  TUSenha testeSenha;
  switch(testeSenha.executar()) {
    case TUSenha::SUCESSO:
      cout << "X Teste de senha bem sucedido!" << endl;
      break;
    case TUSenha::FALHA:
      cout << "O Teste de senha apresentou falha!" << endl;
      break;
  }

  TUValorDeAplicacao testeAplicacao;
  switch(testeAplicacao.executar()) {
    case TUValorDeAplicacao::SUCESSO:
      cout << "X Teste de valor de aplicação bem sucedido!" << endl;
      break;
    case TUValorDeAplicacao::FALHA:
      cout << "O Teste de valor de aplicação apresentou falha!" << endl;
      break;
  }

  return 0;
}
