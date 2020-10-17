#include "../headers/domains.h"
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
  static const string SENHA_VALIDA[3];
  static const string SENHA_INVALIDA;

  int estado;
  Senha *senha;

  void cenarioValido();
  void cenarioInvalido();
public:
  TUSenha();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de valores de aplicação.
*/
class TUValorDeAplicacao {
  static const float VALOR_VALIDO[3];
  static const float VALOR_INVALIDO;

  int estado;
  ValorDeAplicacao *aplicacao;

  void cenarioValido();
  void cenarioInvalido();
public:
  TUValorDeAplicacao();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Classe.
*/
class TUClasse {
  static const string VALOR_VALIDO[5];
  static const string VALOR_INVALIDO;

  int estado;
  Classe *classe;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUClasse();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Classe.
*/
class TUCodigoDeAplicacao {
  static const string VALOR_VALIDO[3];
  static const string VALOR_INVALIDO;

  int estado;
  CodigoDeAplicacao *codigo;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUCodigoDeAplicacao();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Codigo de Produto.
*/
class TUCodigoDeProduto{
  static const string VALOR_VALIDO[3];
  static const string VALOR_INVALIDO;

  int estado;
  CodigoDeProduto *codigo;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUCodigoDeProduto();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Data.
*/
class TUData
{
  static const string VALOR_VALIDO[3];
  static const string VALOR_INVALIDO;

  int estado;
  Data *data;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUData();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Endereço.
*/
class TUEndereco
{
  static const string VALOR_VALIDO[3];
  static const string VALOR_INVALIDO;

  int estado;
  Endereco *endereco;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUEndereco();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Nome.
*/
class TUNome
{
  static const string VALOR_VALIDO[3];
  static const string VALOR_INVALIDO;

  int estado;
  Nome *nome;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUNome();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Prazo.
*/
class TUPrazo
{
  static const int VALOR_VALIDO[12];
  static const int VALOR_INVALIDO;

  int estado;
  Prazo *prazo;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUPrazo();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Taxa.
*/
class TUTaxa
{
  static const float VALOR_VALIDO[3];
  static const float VALOR_INVALIDO;

  int estado;
  Taxa *taxa;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUTaxa();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

/**
 * Classe de teste para domínio de Valor Minimo.
*/
class TUValorMinimo
{
  static const float VALOR_VALIDO[4];
  static const float VALOR_INVALIDO;

  int estado;
  ValorMinimo *valor;

  void cenarioValido();
  void cenarioInvalido();

public:
  TUValorMinimo();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};

class TestesDeDominio {
private:
  TUCep *tuCep;
  TUCodigoDeAgencia *tuCodigoDeAgencia;
  TUCodigoDeBanco *tuCodigoDeBanco;
  TUCpf *tuCpf;
  TUEmissor *tuEmissor;
  TUHorario *tuHorario;
  TUNumeroDeConta *tuNumeroDeConta;
  TUSenha *tuSenha;
  TUValorDeAplicacao *tuValorDeAplicacao;
  TUClasse *tuClasse;
  TUCodigoDeAplicacao *tuCodigoDeAplicacao;
  TUCodigoDeProduto *tuCodigoDeProduto;
  TUData *tuData;
  TUEndereco *tuEndereco;
  TUNome *tuNome;
  TUPrazo *tuPrazo;
  TUTaxa *tuTaxa;
  TUValorMinimo *tuValorMinimo;

  int estado;
public:
  TestesDeDominio();
  int executar();
  static const int SUCESSO = 1;
  static const int FALHA = 0;
};
