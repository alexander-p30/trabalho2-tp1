#include "../headers/autenticacao.h"
#include "../headers/usuario.h"
#include "../headers/produtos.h"
#include "../headers/pessoal.h"
#include "../utils/tela.h"
#include "../headers/principal.h"
#include <iostream>
#include <string>

using namespace std;

void buildTesteUsuarios() {
  CntrContainerUsuario *cntrContainerUsuario = CntrContainerUsuario::getInstancia();

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
}

void buildTesteProdutos() {
  CntrContainerProduto *cntrContainerProduto = CntrContainerProduto::getInstancia();

  string codigo = "111", classe = "CDB", emissor = "ABCD39-SA.K A8HDASD88", vencimento = "26/09/2021", horario = "13:59";
  int prazo = 6;
  float taxa = 2.3, valor = 1000;

  cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  codigo = "123";
  cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  codigo = "321";
  cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  codigo = "666";
  cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);

  cntrContainerProduto->listarProdutos();

  cout << endl;

  cntrContainerProduto->excluirProdutoPorCodigo("321");

  cntrContainerProduto->listarProdutos();

  cout << endl;

  Produto *produto = cntrContainerProduto->buscarProdutoPorCodigo("123");

  cout << produto->getCodigo() << "/" << produto->getEmissor();
}

void buildTestePessoal() {
  CntrApresentacaoAutenticacao *cntrApresentacaoAutenticacao = CntrApresentacaoAutenticacao::getInstancia();
  CntrApresentacaoPessoal *cntrApresentacaoPessoal = CntrApresentacaoPessoal::getInstancia();
  cntrApresentacaoPessoal->cadastrar();
  cntrApresentacaoAutenticacao->autenticar();
  cntrApresentacaoPessoal->executar();
}


int main() {
  CntrApresentacaoPrincipal *cntrApresentacaoPrincipal = CntrApresentacaoPrincipal::getInstancia();

  buildTesteUsuarios();
  buildTesteProdutos();

  cntrApresentacaoPrincipal->menu();

  return 0;
}
