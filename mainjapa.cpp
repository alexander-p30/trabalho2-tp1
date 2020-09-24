#include <iostream>
#include "tests/DomainTests.h"
#include <string>

using namespace std;

int main()
{
  TUClasse classe;
  switch(classe.executar()){
    case TUClasse::SUCESSO: cout << "SUCESSO"; break;
    case TUClasse::FALHA: cout << "FALHA"; break;
  }

  TUCodigoDeAplicacao codigo_ap;
  switch (codigo_ap.executar())
  {
  case TUCodigoDeProduto::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUCodigoDeProduto::FALHA:
    cout << "FALHA";
    break;
  }

  TUCodigoDeProduto codigo_pro;
  switch (codigo_pro.executar())
  {
  case TUCodigoDeProduto::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUCodigoDeProduto::FALHA:
    cout << "FALHA";
    break;
  }

  TUData data;
  switch (data.executar())
  {
  case TUData::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUData::FALHA:
    cout << "FALHA";
    break;
  }

  TUNome nome;
  switch (nome.executar())
  {
  case TUNome::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUNome::FALHA:
    cout << "FALHA";
    break;
  }

  TUEndereco endereco;
  switch (endereco.executar())
  {
  case TUEndereco::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUEndereco::FALHA:
    cout << "FALHA";
    break;
  }

  TUPrazo prazo;
  switch (prazo.executar())
  {
  case TUPrazo::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUPrazo::FALHA:
    cout << "FALHA";
    break;
  }

  TUTaxa taxa;
  switch (taxa.executar())
  {
  case TUTaxa::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUTaxa::FALHA:
    cout << "FALHA";
    break;
  }

  TUValorMinimo valor;
  switch (valor.executar())
  {
  case TUValorMinimo::SUCESSO:
    cout << "SUCESSO";
    break;
  case TUValorMinimo::FALHA:
    cout << "FALHA";
    break;
  }

  return 0;
}

