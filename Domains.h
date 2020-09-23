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
  void setCodigo(string codigo);
  string getCodigo() const;
};

class Cpf {
private:
  string cpfNumber;
  bool validar(string cpfNumber) const;
public:
  Cpf(string cpfNumber);
  void setNumero(string cpfNumber);
  string getNumero() const;
};

class Emissor {
private:
  string codigo;
  bool validar(string codigo) const;
public:
  Emissor(string codigo);
  void setCodigo(string codigo);
  string getCodigo() const;
};

class Horario {
private:
  string horario;
  bool validar(string horario) const;
public:
  Horario(string horario);
  void setHorario(string horario);
  string getHorario() const;
};

class Numero {
private:
public:
};

class Senha {
private:
public:
};

class ValorDeAplicacao {
private:
public:
};
