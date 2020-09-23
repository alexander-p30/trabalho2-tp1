#include "../Domains.h"
#include <string>
using namespace std;

/** 
 * Classe de teste para domínio de números de Cep.
*/
class TUCep {
private:
  static const int CEP_VALIDO[6];
  static const int CEP_INVALIDO;
  
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
  static const string CODIGO_VALIDO[3];
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
  static const string CODIGO_VALIDO[5];
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
  static const string CPF_VALIDO[3];
  static const string CPF_INVALIDO;
  
  int estado;
  Cpf *cpf;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUCpf();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/** 
 * Classe de teste para domínio de códigos de Emissor.
*/
class TUEmissor {
private:
  static const string CODIGO_VALIDO[3];
  static const string CODIGO_INVALIDO;
  
  int estado;
  Emissor *emissor;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUEmissor();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/** 
 * Classe de teste para domínio de Horários.
*/
class TUHorario {
private:
  static const string HORARIO_VALIDO[3];
  static const string HORARIO_INVALIDO;
  
  int estado;
  Horario *horario;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUHorario();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/** 
 * Classe de teste para domínio de números de conta.
*/
class TUNumeroDeConta {
private:
  static const string NUMERO_VALIDO[3];
  static const string NUMERO_INVALIDO;
  
  int estado;
  NumeroDeConta *conta;
  
  void cenarioValido();
  void cenarioInvalido();
public:
  TUNumeroDeConta();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
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
