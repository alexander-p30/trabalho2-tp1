#include <string>
using namespace std;

/**
 * Classe de domínio para números de Cep.
*/
class Cep {
private:
  int number;
  bool validar(int numeroCep) const;
public:
  Cep(int numeroCep);
  Cep() {};
  void setNumero(int numeroCep);
  int getNumero() const;
};

/**
 * Classe de domínio para códigos de agência.
*/
class CodigoDeAgencia {
private:
  string codigo;
  bool validar(string codigo) const;
public:
  CodigoDeAgencia(string codigo);
  CodigoDeAgencia() {}
  void setCodigo(string codigo);
  string getCodigo() const;
};

/**
 * Classe de domínio para códigos de banco.
*/
class CodigoDeBanco {
private:
  string codigo;
  bool validar(string codigo) const;
public:
  CodigoDeBanco(string codigo);
  CodigoDeBanco() {}
  void setCodigo(string codigo);
  string getCodigo() const;
};

/**
 * Classe de domínio para números de CPF.
*/
class Cpf {
private:
  string cpfNumber;
  bool validar(string cpfNumber) const;
public:
  Cpf(string cpfNumber);
  Cpf() {}
  void setNumero(string cpfNumber);
  string getNumero() const;
};

/**
 * Classe de domínio para códigos de Emissor.
*/
class Emissor {
private:
  string codigo;
  bool validar(string codigo) const;
public:
  Emissor(string codigo);
  Emissor() {}
  void setCodigo(string codigo);
  string getCodigo() const;
};

/**
 * Classe de domínio para Horários.
*/
class Horario {
private:
  string horario;
  bool validar(string horario) const;
public:
  Horario(string horario);
  Horario() {}
  void setHorario(string horario);
  string getHorario() const;
};

/**
 * Classe de domínio para números de conta.
*/
class NumeroDeConta {
private:
  string numero;
  bool validar(string numero) const;
public:
  NumeroDeConta(string numero);
  NumeroDeConta() {}
  void setNumero(string numero);
  string getNumero() const;
};

/**
 * Classe de domínio para senhas.
*/
class Senha {
private:
  string senha;
  bool validar(string senha) const;
public:
  Senha(string senha);
  Senha() {}
  void setSenha(string senha);
  string getSenha() const;
};

/**
 * Classe de domínio para valores de aplicação.
*/
class ValorDeAplicacao {
private:
  float valor;
  bool validar(float valor) const;
public:
  ValorDeAplicacao(float valor);
  ValorDeAplicacao() {}
  void setValor(float valor);
  float getValor() const;
};

/**
 * Classe de domínio para Classe.
*/
class Classe{
private:
  string text;
  bool validar(string text) const;

public:
  Classe(string text);
  Classe() {}
  string getText() const;
  void setText(string text);
};

/**
 * Classe de domínio para Codigo de Aplicação.
*/
class CodigoDeAplicacao{
private:
  string code;
  bool validar(string code) const;

public:
  CodigoDeAplicacao(string code);
  CodigoDeAplicacao() {}
  string getCodigoDeAplicacao() const;
  void setCodigoDeAplicacao(string code);
};

/**
 * Classe de domínio para Codigo de Produto.
*/

class CodigoDeProduto{
private:
  string code;
  bool validar(string code) const;

public:
  CodigoDeProduto(string code);
  CodigoDeProduto() {}
  string getCodigoDeProduto() const;
  void setCodigoDeProduto(string code);
};

/**
 * Classe de domínio para Data.
*/
class Data{
private:
  string data;
  bool validar(string data) const;

public:
  Data(string data);
  Data() {}
  string getData() const;
  void setData(string data);
};

/**
 * Classe de domínio para Endereco.
*/
class Endereco{
private:
  string endereco;
  bool validar(string endereco) const;

public:
  Endereco(string endereco);
  Endereco() {};
  string getEndereco() const;
  void setEndereco(string endereco);
};
/**
 * Classe de domínio para Nome.
*/

class Nome{
private:
  string nome;
  bool validar(string nome) const;

public:
  Nome(string nome);
  Nome() {};
  string getNome() const;
  void setNome(string nome);
};

/**
 * Classe de domínio para Prazo.
*/

class Prazo{
private:
  int prazo;
  bool validar(int prazo) const;

public:
  Prazo(int prazo);
  Prazo() {};
  int getPrazo() const;
  void setPrazo(int meses);
};

/**
 * Classe de domínio para Taxa.
*/

class Taxa{
private:
  float taxa;
  bool validar(float taxa) const;

public:
  Taxa(float taxa);
  Taxa() {};
  float getTaxa() const;
  void setTaxa(float taxa);
};

/**
 * Classe de domínio para Valor Minimo.
*/

class ValorMinimo{
private:
  float valor;
  bool validar(float valor) const;

public:
  ValorMinimo(float valor);
  ValorMinimo() {};
  float getValorMinimo() const;
  void setValorMinimo(float valor);
};
