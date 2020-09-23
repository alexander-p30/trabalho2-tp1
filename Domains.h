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
  Cep() {}
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
