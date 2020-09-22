#include <string>
using namespace std;
/** 
 * Classe de domínio para números de Cep.
*/
class Cep {
private:
  int number;
  bool validar(int cepNumber) const;
public:
  Cep(int cepNumber);
  int getNumber() const;
};

/** 
 * Classe de domínio para códigos de agência.
*/
class CodigoDeAgencia {
private:
  string code;
  bool validar(string code) const;
public:
  CodigoDeAgencia(string code);
  string getCode() const;
};

/** 
 * Classe de domínio para códigos de banco.
*/
class CodigoDeBanco {
private:
  string code;
  bool validar(string code) const;
public:
  CodigoDeBanco(string code);
  string getCode() const;
};

class CPF {

};

class Emissor {

};

class Horario {

};

class Numero {

};

class Senha {

};

class ValorDeAplicacao {

};
