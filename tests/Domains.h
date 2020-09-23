#include "../Domains.h"
#include <string>
using namespace std;

/** 
 * Classe de teste para domínio de números de Cep.
*/
class TUCep {
private:
  static const int CEP_VALIDO = 1562348;
  static const int CEP_INVALIDO = 10000;
  
  int estado;
  Cep *cep;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUCep();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/** 
 * Classe de teste para domínio de códigos de agência.
*/
class TUCodigoDeAgencia {
private:
  static const string CODIGO_VALIDO;
  static const string CODIGO_INVALIDO;
  
  int estado;
  CodigoDeAgencia *agencia;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUCodigoDeAgencia();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/** 
 * Classe de teste para domínio de códigos de banco.
*/
class TUCodigoDeBanco {
private:
  static const string CODIGO_VALIDO;
  static const string CODIGO_INVALIDO;
  
  int estado;
  CodigoDeBanco *banco;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUCodigoDeBanco();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/** 
 * Classe de teste para domínio de números de CPF.
*/
class TUCpf {
private:
public:
};

/** 
 * Classe de teste para domínio de códigos de Emissor.
*/
class TUEmissor {
private:
public:
};

/** 
 * Classe de teste para domínio de Horários.
*/
class TUHorario {
private:
public:
};

/** 
 * Classe de teste para domínio de números de conta.
*/
class TUNumeroDeConta {
private:
public:
};

/** 
 * Classe de teste para domínio de senhas.
*/
class TUSenha {
private:
public:
};

/** 
 * Classe de teste para domínio de valores de aplicação.
*/
class TUValorDeAplicacao {
private:
public:
};
