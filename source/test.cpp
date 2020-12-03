#include "../headers/autenticacao.h"
#include "../headers/usuario.h"
#include "../headers/produtos.h"
#include "../headers/pessoal.h"
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
  CntrServicoAutenticacao *cntrServicoAutenticacao = CntrServicoAutenticacao::getInstancia();
  CntrApresentacaoAutenticacao *cntrApresentacaoAutenticacao = CntrApresentacaoAutenticacao::getInstancia();
  CntrApresentacaoPessoal *cntrApresentacaoPessoal = CntrApresentacaoPessoal::getInstancia();
  CntrServicoPessoal *cntrServicoPessoal = CntrServicoPessoal::getInstancia();
  CntrContainerUsuario *cntrContainerUsuario = CntrContainerUsuario::getInstancia();


  buildTesteUsuarios();
  buildTesteProdutos();
  buildTestePessoal();


  /*cntrApresentacaoPessoal->cadastrar();
  Usuario *current_user;
  current_user = cntrContainerUsuario->buscarUsuarioPorCpf("031.360.531-92");
  cout << "dados pessoais" << endl;
    cout << "Nome: ";
    cout << current_user->getNome() << endl;
    cout << "Endereco: ";
    cout << current_user->getEndereco() << endl;
    cout << "Cep: ";
    cout << current_user->getCep() << endl;
    cout << "Cpf: ";
    cout << current_user->getCpf() << endl;
    cout << "Senha: ";
    cout << current_user->getSenha() << endl;
    cout << "Numero de conta ";
    cout << current_user->account->getNumero() << endl;
    cout << "Codigo de agencia ";
    cout << current_user->account->getAgencia() << endl;
    cout << "Codigo de banco ";
    cout << current_user->account->getBanco() << endl;
  cntrApresentacaoAutenticacao->autenticar();
  cout << cntrServicoAutenticacao->getUsuarioAtual()->getNome() << endl;
  cout << cntrServicoAutenticacao->getUsuarioAtual()->getCpf() << endl;
  cntrApresentacaoPessoal->executar();


  /*a->cadastrar();
  cntrApresentacaoAutenticacao->autenticar();
  cout << cntrServicoAutenticacao->getUsuarioAtual()->getNome() << endl;
  cout << cntrServicoAutenticacao->getUsuarioAtual()->getCpf() << endl;*/

  return 0;
}
