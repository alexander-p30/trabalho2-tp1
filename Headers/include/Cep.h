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
