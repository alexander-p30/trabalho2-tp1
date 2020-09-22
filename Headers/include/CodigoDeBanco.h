#include <string>
using namespace std;

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
