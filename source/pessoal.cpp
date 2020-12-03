
#include "../headers/pessoal.h"
#include "../utils/tela.h"
#include "../headers/containers.h"
#include "../headers/usuario.h"
#include "../headers/autenticacao.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <curses.h>

using namespace std;

CntrServicoPessoal* CntrServicoPessoal::instancia = nullptr;
CntrApresentacaoPessoal* CntrApresentacaoPessoal::instancia = nullptr;
CntrContainerUsuario* CntrServicoPessoal::cntrContainerUsuario = CntrContainerUsuario::getInstancia();




CntrServicoPessoal* CntrServicoPessoal::getInstancia() {
  if(instancia == nullptr){
    instancia = new CntrServicoPessoal();
  }
  return instancia;
}

bool CntrServicoPessoal::cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha, string banco, string agencia, string numero){
  CntrContainerUsuario *cntrContainerUsuario = CntrContainerUsuario::getInstancia();

  return cntrContainerUsuario->cadastrarUsuario(nome, endereco, cep, cpf, senha, banco, agencia, numero);
}

CntrApresentacaoPessoal* CntrApresentacaoPessoal::getInstancia() {
  if(instancia == nullptr){
    instancia = new CntrApresentacaoPessoal();
  }
  return instancia;
}

void CntrApresentacaoPessoal::cadastrar(){
    CntrServicoPessoal *cntrServicoPessoal = CntrServicoPessoal::getInstancia();
    char texto1[] ="Preencha os seguintes campos para completar seu cadastramento: ";
    char texto2[] ="Nome            :";
    char texto3[] ="Endereco        :";
    char texto4[] ="CEP             :";
    char texto5[] ="CPF             :";
    char texto6[] ="Senha           :";
    char texto7[] ="Numero de conta :";
    char texto8[] ="Agencia         :";
    char texto9[] ="Banco           :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    string campo1, campo2, campo4, campo5;
    string campo6, campo7, campo8;
    int campo3;
    cout << texto1 << endl;
    cout << texto2 << " ";
    getline(cin, campo1);
    cout << texto3 << " ";
    getline(cin, campo2);
    cout << texto4;
    cin >> campo3;
    cout << texto5 << " ";
    cin >> campo4;
    cout << texto6 << " ";
    cin >> campo5;
    cout << texto7 << " ";
    cin >> campo6;
    cout << texto8 << " ";
    cin >> campo7;
    cout << texto9 << " ";
    cin >> campo8;

    if(cntrServicoPessoal->cadastrarUsuario(campo1, campo2, campo3, campo4, campo5, campo8, campo7, campo6)){
        cout << "usuario e conta cadastrados com sucesso, digite algo para retornar" << endl;
        waitInput();
        return;
    }
    cout << "falha no cadastramento, digite algo para retornar"<< endl;
    waitInput();
    return;
}

void CntrApresentacaoPessoal::consultarDadosPessoais(){
    CntrServicoAutenticacao *cntrServicoAutenticacao = CntrServicoAutenticacao::getInstancia();
    if(cntrServicoAutenticacao->getUsuarioAtual() != nullptr) {
        Usuario *current_user = cntrServicoAutenticacao->getUsuarioAtual();
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
        cout << "digite algo para retornar" << endl;
        waitInput();
        return;
    }else{
        cout << "faça login para ver seus dados pessoais" << endl;
        cout << "digite algo para fechar" << endl;
        waitInput();
        return;
    }

}

void CntrApresentacaoPessoal::executar(){
    int campo;
    bool apresentar = true;

    while(apresentar){

        clearscr();
        cout << "Gerenciamento Pessoal" << endl;
        cout << "1. Consultar dados pessoais\n2. Cadastrar Usuario e Conta\n3. Retornar\n" << endl;
        cin >> campo;
        cin.clear();
        cin.ignore();
        switch(campo){
            case 1: consultarDadosPessoais();
                    break;
            case 2: cadastrar();
                    break;
            case 3: apresentar = false;
                    break;
        }
    }
}
