#include <string>
using namespace std;

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
