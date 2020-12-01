
#include "../headers/pessoal.h"
#include "../headers/tela.h"
#include "../headers/containers.h"
#include "../headers/usuario.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <curses.h>

CntrServicoPessoal* CntrServicoPessoal::instancia = nullptr;


CntrServicoPessoal* CntrServicoPessoal::getInstancia() {
  if(instancia == nullptr){
    instancia = new CntrServicoPessoal();
  }
  return instancia;
}


bool CntrServicoPessoal::cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha){
  CntrContainerUsuario *cntrContainerUsuario = CntrContainerUsuario::getInstancia();

  return cntrContainerUsuario->criarUsuario(nome, endereco, cep, cpf, senha);
}

void CntrApresentacaoPessoal::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

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

    char campo1[80], campo2[80], campo4[80], campo5[80];                            // Cria campos para entrada dos dados.
    char campo6[80], campo7[80], campo8[80];
    int campo3;                                                    // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Endereco endereco;
    Cep cep;
    Cpf cpf;
    Senha senha;
    NumeroDeConta numero;
    CodigoDeAgencia agencia;
    CodigoDeBanco banco;

    // Apresenta tela de cadastramento.

    clearscr();

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    cout << texto3 << " ";
    cin >> campo2;
    cout << texto4 << " ";
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

    try{
        nome.setNome(string(campo1));
        endereco.setEndereco(string(campo2));
        cep.setNumero(campo3);
        cpf.setNumero(string(campo4));
        senha.setSenha(string(campo5));
        numero.setNumero(string(campo6));
        agencia.setCodigo(string(campo7));
        banco.setCodigo(string(campo8));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;
        waitInput();
        return;
    }

    Usuario usuario;

    usuario.setNome(string(campo1));
    usuario.setEndereco(string(campo2));
    usuario.setCep(int(campo3));
    usuario.setCpf(string(campo4));
    usuario.setSenha(string(campo5));

    Conta conta;

    conta.setNumero(string(campo6));
    conta.setAgencia(string(campo7));
    conta.setBanco(string(campo8));
    /*conta.setCpf(string(campo4));

    if(cntrServicoPessoal->cadastrarUsuario(Usuario)){
        if(cntrServicoProdutosFinanceiros->cadastrarConta(conta)){
            cout << texto11 << endl;
            return;
        }
      }
    */

    if(cntrServicoPessoal->cadastrarUsuario(campo1, campo2, campo3, campo4, campo5)){
        cout << texto11 << endl;
        return;
    }

    cout << texto12 << endl;
    waitInput();

    return;
}

/*void CntrApresentacaoPessoal::consultarDadosPessoais(){
    char texto2[] ="digite o seu cpf"
    string cpf;
    cout << texto2 << " ";
    cin >> cpf;

}*/
