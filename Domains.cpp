#include "Domains.h"
#include <iostream>

/** 
 * Método construtor da classe Cep.
 * @param cepNumber Número de cpf a ser guardado na classe.
 * @throw invalid_argument Se o método de validação do número falhar, lança exceção.
 * 
*/
Cep::Cep(int cepNumber) {
  try{
    if(validate(cepNumber)){ 
      number = cepNumber;
    } else {
      throw std::invalid_argument("valor informado para CEP não condiz com nenhuma das faixas.");
    }
  } catch(const std::invalid_argument& err) {
    std::cerr << "Argumento inválido: " << err.what();
  } 
}


/**
 * Valida o número de entrada para a criação de CPF.
 * @param cepNumber É um número inteiro, que deve estar contido em um dos seguintes invervalos: [1000000,5999999], 
 [8000000,8499999], 
 [20000000,26600999], 
 [70000000,70999999], 
 [40000000,41999999],
 [60000000,60999999]
 * @return true Se o parâmetro está contido em algum dos intervalos possíveis.
 * @return false Se o valor parâmetro não se encaixou em nenhum dos intervalos possíveis. 
*/
bool Cep::validate(int cepNumber) {
  const int numDeFaixas = 6;
  const int faixas[numDeFaixas][2] = {
    1000000,5999999,
    8000000,8499999,
    20000000,26600999,
    70000000,70999999,
    40000000,41999999,
    60000000,60999999
  };

  int i = 0;

  for(i = 0; i <= numDeFaixas - 1; i++) {
    if(cepNumber >= faixas[i][0] && cepNumber <= faixas[i][1]) {
      return true;
    }
  }
  return false;
}

/** 
 * Método para acessar o número de Cep guardado.
 * @return Inteiro com número do Cep.
*/
int Cep::getNumber() {
  return number;
}