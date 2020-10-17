#include <iostream>
#include "entity_tests.h"

const string TUUsuario::NOME_VALIDO[3] = {"Lucas Azuma", "Estevan Alexander", "Fernando Chacon"};
const string TUUsuario::ENDERECO_VALIDO[3] = {"Rua da Batata", "Bairro Sul", "Bairro Norte"};
const int TUUsuario::CEP_VALIDO[3] = {1234567, 8123456, 21234567};
const string TUUsuario::CPF_VALIDO[3] = {"031.360.531-92", "733.119.790-87", "928.199.170-54"};
const string TUUsuario::SENHA_VALIDA[3] = {"876543", "132650", "946127"};

const string TUUsuario::NOME_INVALIDO[3] = {"Lucas azuma", "Estevan  Alexander", "Fernando Ch4con"};
const string TUUsuario::ENDERECO_INVALIDO[3] = {"Rua da Batata ", "rua Minúscula", "Bairro Norte com Nome muito grande"};
const int TUUsuario::CEP_INVALIDO[3] = {8599999, 19999999, 212345617};
const string TUUsuario::CPF_INVALIDO[3] = {"031.360.531-91", "733.119.790-80", "928.199.170-51"};
const string TUUsuario::SENHA_INVALIDA[3] = {"876A43", "132656", "9961A7"};

TUUsuario::TUUsuario() {
  estado = SUCESSO;
  usuario = new Usuario();
}

int TUUsuario::executar() {
  cout << "\t> Executando teste unitário de usuário:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete usuario;
  cout << "\t> Teste unitário de usuário finalizado." << endl << endl;

  return estado;
}

void TUUsuario::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando nome válido " << NOME_VALIDO[i] << endl;
      usuario->setNome(NOME_VALIDO[i]);
      cout << "\t\tNome válido setado com sucesso." << endl;

      cout << "\t\tTestando endereço válido " << ENDERECO_VALIDO[i] << endl;
      usuario->setEndereco(ENDERECO_VALIDO[i]);
      cout << "\t\tEndereço válido setado com sucesso." << endl;

      cout << "\t\tTestando CEP válido " << CEP_VALIDO[i] << endl;
      usuario->setCep(CEP_VALIDO[i]);
      cout << "\t\tCEP válido setado com sucesso." << endl;

      cout << "\t\tTestando CPF válido " << CPF_VALIDO[i] << endl;
      usuario->setCpf(CPF_VALIDO[i]);
      cout << "\t\tCPF válido setado com sucesso." << endl;

      cout << "\t\tTestando senha válida " << SENHA_VALIDA[i] << endl;
      usuario->setSenha(SENHA_VALIDA[i]);
      cout << "\t\tSenha válido setado com sucesso." << endl;
    }
  } catch (const invalid_argument &err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUUsuario::cenarioInvalido() {
  const int tamanhoArr = 3;
  int i = 0;
  for (i = 0; i <= tamanhoArr - 1; i++) {
    try {
      cout << "\t\tTestando nome inválido " << NOME_INVALIDO[i] << endl;
      usuario->setNome(NOME_INVALIDO[i]);
      cout << "\t\tNome inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tNome inválido rejeitado com sucesso." << endl;
    }
    
    try {
      cout << "\t\tTestando endereço inválido " << ENDERECO_INVALIDO[i] << endl;
      usuario->setEndereco(ENDERECO_INVALIDO[i]);
      cout << "\t\tEndereço inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tEndereço inválido rejeitado com sucesso." << endl;
    }
    
    try {
      cout << "\t\tTestando CEP inválido " << CEP_INVALIDO[i] << endl;
      usuario->setCep(CEP_INVALIDO[i]);
      cout << "\t\tCEP inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tCEP inválido rejeitado com sucesso." << endl;
    }
    
    try {
      cout << "\t\tTestando CPF inválido " << CPF_INVALIDO[i] << endl;
      usuario->setCpf(CPF_INVALIDO[i]);
      cout << "\t\tCPF inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tCPF inválido rejeitado com sucesso." << endl;
    }
    
    try {
      cout << "\t\tTestando senha inválida " << SENHA_INVALIDA[i] << endl;
      usuario->setSenha(SENHA_INVALIDA[i]);
      cout << "\t\tSenha inválida setada. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tSenha inválida rejeitada com sucesso." << endl;
    }
  }
}

  const string TUConta::BANCO_VALIDO[3] = {"001", "104", "341"};
  const string TUConta::AGENCIA_VALIDA[3] = {"1234", "8413", "9999"};
  const string TUConta::NUMERO_VALIDO[3] = {"000650-9", "008880-6", "109230-5"};

  const string TUConta::BANCO_INVALIDO[3] = {"000", "1242", "985"};
  const string TUConta::AGENCIA_INVALIDA[3] = {"12345", "123", "9A99"};
  const string TUConta::NUMERO_INVALIDO[3] = {"000650-2", "0A8880-3", "109230-4"};

TUConta::TUConta() {
  estado = SUCESSO;
  conta = new Conta();
}

int TUConta::executar() {
  cout << "\t> Executando teste unitário de conta:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete conta;
  cout << "\t> Teste unitário de conta finalizado." << endl << endl;

  return estado;
}

void TUConta::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando código de banco válido " << BANCO_VALIDO[i] << endl;
      conta->setBanco(BANCO_VALIDO[i]);
      cout << "\t\tCódigo de banco válido setado com sucesso." << endl;

      cout << "\t\tTestando código de agência válido " << AGENCIA_VALIDA[i] << endl;
      conta->setAgencia(AGENCIA_VALIDA[i]);
      cout << "\t\tCódigo de agência válido setado com sucesso." << endl;

      cout << "\t\tTestando número de conta válido " << NUMERO_VALIDO[i] << endl;
      conta->setNumero(NUMERO_VALIDO[i]);
      cout << "\t\tNúmero de conta válido setado com sucesso." << endl;
    }
  } catch (const invalid_argument &err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUConta::cenarioInvalido() {
  const int tamanhoArr = 3;
  int i = 0;
  for (i = 0; i <= tamanhoArr - 1; i++) {
    try {
      cout << "\t\tTestando código de banco inválido " << BANCO_INVALIDO[i] << endl;
      conta->setBanco(BANCO_INVALIDO[i]);
      cout << "\t\tCódigo de banco inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tCódigo de banco inválido rejeitado com sucesso." << endl;
    }
    
    try {
      cout << "\t\tTestando código de agência inválido " << AGENCIA_INVALIDA[i] << endl;
      conta->setAgencia(AGENCIA_INVALIDA[i]);
      cout << "\t\tCódigo de agência inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tCódigo de agência inválido rejeitado com sucesso." << endl;
    }
    
    try {
      cout << "\t\tTestando número de conta inválido " << NUMERO_INVALIDO[i] << endl;
      conta->setNumero(NUMERO_INVALIDO[i]);
      cout << "\t\tNúmero de conta inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tNúmero de conta inválido rejeitado com sucesso." << endl;
    }
  }
}

TestesDeEntidade::TestesDeEntidade() {
  estado = SUCESSO;
  tuUsuario = new TUUsuario();
  tuConta = new TUConta();
}

int TestesDeEntidade::executar() {
  const int quantidadeTestes = 2;
  string feedbacks[quantidadeTestes];
  int i = 0;

  cout << "> Executando testes de entidade:" << endl;

  switch(tuUsuario->executar()) {
    case TUUsuario::SUCESSO:
      feedbacks[i] = "X Teste de usuário bem sucedido!";
      break;
    case TUUsuario::FALHA:
      feedbacks[i] = "O Teste de usuário apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;

  switch(tuConta->executar()) {
    case TUConta::SUCESSO:
      feedbacks[i] = "X Teste de conta bem sucedido!";
      break;
    case TUConta::FALHA:
      feedbacks[i] = "O Teste de conta apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;

  cout << "> Fim dos testes de entidade." << endl << endl;

  cout << "> Resumo dos testes de unidade de entidade:" << endl;
  for(i = 0; i < quantidadeTestes; i++) {
    cout << "\t" << feedbacks[i] << endl;
  }

  return estado;
}
