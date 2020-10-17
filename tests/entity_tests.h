#include "../headers/entities.h"

/**
 * Classe para teste unitário de classe Usuario.
*/
class TUUsuario {
private:
  static const string NOME_VALIDO[3];
  static const string ENDERECO_VALIDO[3];
  static const int CEP_VALIDO[3];
  static const string CPF_VALIDO[3];
  static const string SENHA_VALIDA[3];

  static const string NOME_INVALIDO[3];
  static const string ENDERECO_INVALIDO[3];
  static const int CEP_INVALIDO[3];
  static const string CPF_INVALIDO[3];
  static const string SENHA_INVALIDA[3];

  void cenarioValido();
  void cenarioInvalido();

  int estado;
  Usuario *usuario;
public:
  TUUsuario();
  int executar();

  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

class TUConta {
private:
  static const string BANCO_VALIDO[3];
  static const string AGENCIA_VALIDA[3];
  static const string NUMERO_VALIDO[3];

  static const string BANCO_INVALIDO[3];
  static const string AGENCIA_INVALIDA[3];
  static const string NUMERO_INVALIDO[3];

  void cenarioValido();
  void cenarioInvalido();

  int estado;
  Conta *conta;
public:
  TUConta();
  int executar();

  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

class TestesDeEntidade {
private:
  TUUsuario *tuUsuario;
  TUConta *tuConta;

  int estado;
public:
  TestesDeEntidade();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};
