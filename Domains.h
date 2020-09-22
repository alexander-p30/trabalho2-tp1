#include <string>
using namespace std;
/** 
 * Classe de números de CPF
*/
class Cep {
private:
  int number;
  bool validar(int cepNumber);
public:
  Cep(int cepNumber);
  int getNumber();
};

class CodigoDeAgencia {
private:
  string code;
  bool validar(string code);
public:
  CodigoDeAgencia(string code);
  string getCode();
};

class CodigoDeBanco {

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
