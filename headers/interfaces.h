#ifndef INTERFACES_H
#define INTERFACES_H

#include "domains.h"
#include <string>

class IServicoAutenticacao {
public:
  virtual bool autenticar(string cpf, string senha) = 0;
  virtual ~IServicoAutenticacao(){}
};

#endif
