#include "../headers/autenticacao.h"
#include "../headers/usuario.h"
#include "../headers/pessoal.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

  CntrServicoAutenticacao *cntrServicoAutenticacao = CntrServicoAutenticacao::getInstancia();
  CntrContainerUsuario *cntrContainerUsuario = CntrContainerUsuario::getInstancia();
  CntrServicoPessoal *cntrServicoPessoal = CntrServicoPessoal::getInstancia();
  CntrApresentacaoAutenticacao *cntrApresentacaoAutenticacao = CntrApresentacaoAutenticacao::getInstancia();

  string nome = "Estevan Alexander";
  string endereco = "Rua da batata";
  int cep = 1234567;
  string cpf = "031.360.531-92";
  string senha = "876543";
  cntrContainerUsuario->criarUsuario(nome, endereco, cep, cpf, senha);
  nome = "Lucas Azuma";
  cpf = "733.119.790-87";
  cntrContainerUsuario->criarUsuario(nome, endereco, cep, cpf, senha);
  nome = "Fernando Chacon";
  cpf = "928.199.170-54";
  cntrContainerUsuario->criarUsuario(nome, endereco, cep, cpf, senha);
  cntrContainerUsuario->criarUsuario(nome, endereco, cep, cpf, senha);

  cout << "-------------------------" << endl;
  cntrContainerUsuario->listarUsuarios();
  cout << "-------------------------" << endl;

  cntrContainerUsuario->excluirUsuarioPorCpf("031.360.531-92");

  cout << "-------------------------" << endl;
  cntrContainerUsuario->listarUsuarios();
  cout << "-------------------------" << endl;

  cntrApresentacaoAutenticacao->autenticar();

  cout << cntrServicoAutenticacao->getUsuarioAtual()->getNome() << endl;
  cout << cntrServicoAutenticacao->getUsuarioAtual()->getCpf() << endl;

  return 0;
}
