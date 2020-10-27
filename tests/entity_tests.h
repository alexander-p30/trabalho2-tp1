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

class TUProduto {
private:
    static const string CODIGO_VALIDO[3];
    static const string CLASSE_VALIDA[3];
    static const string EMISSOR_VALIDO[3];
    static const int PRAZO_VALIDO[3];
    static const string VENCIMENTO_VALIDO[3];
    static const float TAXA_VALIDO[3];
    static const string HORARIO_VALIDO[3];
    static const float VALOR_VALIDO[3];

    static const string CODIGO_INVALIDO[3];
    static const string CLASSE_INVALIDA[3];
    static const string EMISSOR_INVALIDO[3];
    static const int PRAZO_INVALIDO[3];
    static const string VENCIMENTO_INVALIDO[3];
    static const float TAXA_INVALIDO[3];
    static const string HORARIO_INVALIDO[3];
    static const float VALOR_INVALIDO[3];

    void cenarioValido();
    void cenarioInvalido();

    int estado;
    Produto *produto;
public:
    TUProduto();
    int executar();

    static const int SUCESSO = 1;
    static const int FALHA = 0;
};

class TUAplicacao{
private:
    static const string CODIGO_VALIDO[3];
    static const float VALOR_VALIDO[3];
    static const string DATA_VALIDA[3];

    static const string CODIGO_INVALIDO[3];
    static const float VALOR_INVALIDO[3];
    static const string DATA_INVALIDA[3];

    void cenarioValido();
    void cenarioInvalido();

    int estado;
    Aplicacao *aplicacao;
public:
    TUAplicacao();
    int executar();

    static const int SUCESSO = 1;
    static const int FALHA = 0;

};

class TestesDeEntidade {
private:
  TUUsuario *tuUsuario;
  TUConta *tuConta;
  TUProduto *tuProduto;
  TUAplicacao *tuAplicacao;

  int estado;
public:
  TestesDeEntidade();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};
