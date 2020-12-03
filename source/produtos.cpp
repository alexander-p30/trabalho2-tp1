#include "../headers/produtos.h"
#include "../headers/containers.h"
#include "../utils/tela.h"
#include <iostream>

using namespace std;

CntrContainerProduto* CntrContainerProduto::instancia = nullptr;
ContainerProduto* CntrContainerProduto::containerProduto = ContainerProduto::getInstancia();

CntrContainerProduto* CntrContainerProduto::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrContainerProduto();
  }

  return instancia;
}

bool CntrContainerProduto::criarProduto(string codigo, string classe, string emissor, int prazo, string vencimento, float taxa, string horario, float valor) {
  Produto *produto = nullptr;
  try {
    produto = new Produto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor);
  } catch(const invalid_argument& err) {
    cerr << err.what() << endl;
    return false;
  }

  return containerProduto->addProduto(*produto);
}

bool CntrContainerProduto::excluirProdutoPorCodigo(string codigo) {
  return containerProduto->remProdutoPorCodigo(codigo);
}

void CntrContainerProduto::listarProdutos() {
  containerProduto->listarProdutos();
}

Produto* CntrContainerProduto::buscarProdutoPorCodigo(string codigo) {
  return containerProduto->buscarProdutoPorCodigo(codigo);
}

CntrApresentacaoProduto* CntrApresentacaoProduto::instancia = nullptr;
CntrContainerProduto* CntrApresentacaoProduto::cntrContainerProduto = CntrContainerProduto::getInstancia();

CntrApresentacaoProduto* CntrApresentacaoProduto::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrApresentacaoProduto();
  }

  return instancia;
}

void CntrApresentacaoProduto::cadastrar() {
  string codigo, classe, emissor, vencimento, horario; 
  int prazo;
  float taxa, valor;
  while(true) {
    clearscr();
    cout << "Cadastro de produto" << endl;
    cout << "Insira o código do produto: ";
    cin.clear();
    cin >> codigo;
    cout << "Insira a classe do produto: ";
    cin.clear();
    cin >> classe;
    cout << "Insira o emissor do produto: ";
    cin.clear();
    cin >> emissor;
    cout << "Insira a data de vencimento do produto: ";
    cin.clear();
    cin >> vencimento;
    cout << "Insira o horário de vencimento do produto: ";
    cin.clear();
    cin >> horario;
    cout << "Insira o prazo do produto: ";
    cin.clear();
    cin >> prazo;
    cout << "Insira a taxa do produto: ";
    cin.clear();
    cin >> taxa;
    cout << "Insira o valor do produto: ";
    cin.clear();
    cin >> valor;
    if(cntrContainerProduto->criarProduto(codigo, classe, emissor, prazo, vencimento, taxa, horario, valor)) {
      break;
    }
    cout << "Erro ao criar produto. Por favor, tente novamente." << endl;
    waitInput();
  }

  cout << "Produto cadastrado com sucesso!." << endl;
  waitInput();  
}

void CntrApresentacaoProduto::descadastrar() {
  string codigo, mensagemDeResultado;
  clearscr();
  cout << "Descadastramento de produto" << endl;
  cout << "Digite o código do produto a ser descadastrado: ";
  cin >> codigo;
  if(cntrContainerProduto->excluirProdutoPorCodigo(codigo)) {
    mensagemDeResultado = "Produto com código " + codigo + " descadastrado com sucesso";
  } else {
    mensagemDeResultado = "Produto com código " + codigo + " não encontrado.";
  }
  cout << mensagemDeResultado << endl;
  waitInput();
}

void CntrApresentacaoProduto::listarProdutos() {
  clearscr();
  cntrContainerProduto->listarProdutos();
  waitInput();
}

void CntrApresentacaoProduto::menu() {
  bool executar = true;
  int op;

  while(executar) {
    clearscr();
    cout << "Gereciamento de produtos" << endl;
    cout << "1. Cadastrar\n2. Descadastrar\n3. Listar\n0. Voltar" << endl;
    cin >> op;
    switch(op) {
      case 1:
        cadastrar();
        break;
      case 2:
        descadastrar();
        break;
      case 3:
        listarProdutos();
        break;
      case 0:
        executar = false;
        break;
    }
  }
}
