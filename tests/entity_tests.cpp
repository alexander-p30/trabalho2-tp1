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

const string TUProduto::CODIGO_VALIDO[3] = {"111", "123", "375"};
const string TUProduto::CODIGO_INVALIDO[3] = {"000", "1111", "0000"};
const string TUProduto::CLASSE_VALIDA[3] = {"CDB", "LCA", "LCI"};
const string TUProduto::CLASSE_INVALIDA[3] = {"BAT", "AAA", "123"};
const string TUProduto::EMISSOR_VALIDO[3] = {"ABCD39-SA.K A8HDASD88","-BChdu","LQPcs178dba6d-BC hdu"};
const string TUProduto::EMISSOR_INVALIDO[3] = {"cDUAYEVABnc92813-v", "cDUAYEVABnc9283-v", "cDUAYEVABnc913-v"};
const int TUProduto::PRAZO_VALIDO[3] = {6, 12, 18};
const int TUProduto::PRAZO_INVALIDO[3] = {15, 17, 21};
const string TUProduto::VENCIMENTO_VALIDO[3] = {"26/09/2021", "28/01/2021", "29/02/2024"};
const string TUProduto::VENCIMENTO_INVALIDO[3] = {"32/03/2021", "33/03/2021", "34/03/2021"};
const float TUProduto::TAXA_VALIDO[3] = {0, 2.5, 100.14};
const float TUProduto::TAXA_INVALIDO[3] = {-1, -2, -3};
const string TUProduto::HORARIO_VALIDO[3] = {"13:59","15:00","17:00"};
const string TUProduto::HORARIO_INVALIDO[3] = {"17:01", "17:02", "17:03"};
const float TUProduto::VALOR_VALIDO[3] = {1000, 5000, 10000};
const float TUProduto::VALOR_INVALIDO[3] = {-1, -2, -3};

TUProduto::TUProduto() {
    estado = SUCESSO;
    produto = new Produto();
}

int TUProduto::executar() {
    cout << "\t> Executando teste unitário de produto:" << endl;
    cenarioValido();
    cenarioInvalido();
    delete produto;
    cout << "\t> Teste unitário de produto finalizado." << endl << endl;
    return estado;

}

void TUProduto::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando codigo válido " << CODIGO_VALIDO[i] << endl;
      produto->setCodigo(CODIGO_VALIDO[i]);
      cout << "\t\tCodigo válido setado com sucesso." << endl;

      cout << "\t\tTestando classe válida " << CLASSE_VALIDA[i] << endl;
      produto->setClasse(CLASSE_VALIDA[i]);
      cout << "\t\tClasse válido setado com sucesso." << endl;

      cout << "\t\tTestando emissor válido" << EMISSOR_VALIDO[i] << endl;
      produto->setEmissor(EMISSOR_VALIDO[i]);
      cout << "\t\tEmissor válido setado com sucesso." << endl;

      cout << "\t\tTestando prazo válido " << PRAZO_VALIDO[i] << endl;
      produto->setPrazo(PRAZO_VALIDO[i]);
      cout << "\t\tPrazo válido setado com sucesso." << endl;

      cout << "\t\tTestando vencimento válido " << VENCIMENTO_VALIDO[i] << endl;
      produto->setVencimento(VENCIMENTO_VALIDO[i]);
      cout << "\t\tVencimento válido setado com sucesso." << endl;

      cout << "\t\tTestando taxa válida " << TAXA_VALIDO[i] << endl;
      produto->setTaxa(TAXA_VALIDO[i]);
      cout << "\t\tTaxa válido setado com sucesso." << endl;

      cout << "\t\tTestando horario válido " << HORARIO_VALIDO[i] << endl;
      produto->setHorario(HORARIO_VALIDO[i]);
      cout << "\t\tHorario válido setado com sucesso." << endl;

      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      produto->setValor(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;


    }
  } catch (const invalid_argument &err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUProduto::cenarioInvalido() {
  const int tamanhoArr = 3;
  int i = 0;
  for (i = 0; i <= tamanhoArr - 1; i++) {
    try {
      cout << "\t\tTestando codigo inválido " << CODIGO_INVALIDO[i] << endl;
      produto->setCodigo(CODIGO_INVALIDO[i]);
      cout << "\t\tCodigo inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tCodigo inválido rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando classe inválida" << CLASSE_INVALIDA[i] << endl;
      produto->setClasse(CLASSE_INVALIDA[i]);
      cout << "\t\tClasse inválida setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tClasse inválida rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando emissor inválido " << EMISSOR_INVALIDO[i] << endl;
      produto->setEmissor(EMISSOR_INVALIDO[i]);
      cout << "\t\tEmissor inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tEmissor inválido rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando prazo inválido " << PRAZO_INVALIDO[i] << endl;
      produto->setPrazo(PRAZO_INVALIDO[i]);
      cout << "\t\tPrazo inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tPrazo inválido rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando vencimento inválido " << VENCIMENTO_INVALIDO[i] << endl;
      produto->setVencimento(VENCIMENTO_INVALIDO[i]);
      cout << "\t\tVencimento inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tVencimento inválido rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando taxa inválida " << CODIGO_INVALIDO[i] << endl;
      produto->setTaxa(TAXA_INVALIDO[i]);
      cout << "\t\tTaxa inválida setada. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tTaxa inválida rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando horario inválido " << HORARIO_INVALIDO[i] << endl;
      produto->setHorario(HORARIO_INVALIDO[i]);
      cout << "\t\tHorario inválido setada. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tHorario inválido rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando valor inválida " << VALOR_INVALIDO[i] << endl;
      produto->setValor(VALOR_INVALIDO[i]);
      cout << "\t\tValor inválido setada. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tValor inválido rejeitado com sucesso." << endl;
    }
  }
}

const string TUAplicacao::CODIGO_VALIDO[3] = {"11111", "12355", "37590"};
const string TUAplicacao::CODIGO_INVALIDO[3] = {"00000", "11111111", "64286428"};
const float TUAplicacao::VALOR_VALIDO[3] = {556127.1913, 0.0, 1000000.00};
const float TUAplicacao::VALOR_INVALIDO[3] = {-1, -2, -3};
const string TUAplicacao::DATA_VALIDA[3] = {"26/09/2021", "28/01/2021", "29/02/2024"};
const string TUAplicacao::DATA_INVALIDA[3] = {"32/03/2021", "33/03/2021", "34/03/2021"};

TUAplicacao::TUAplicacao() {
    estado = SUCESSO;
    aplicacao = new Aplicacao();
}

void TUAplicacao::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando codigo válido " << CODIGO_VALIDO[i] << endl;
      aplicacao->setCodigo(CODIGO_VALIDO[i]);
      cout << "\t\tCodigo válida setada com sucesso." << endl;

      cout << "\t\tTestando data válida " << DATA_VALIDA[i] << endl;
      aplicacao->setData(DATA_VALIDA[i]);
      cout << "\t\tData válida setada com sucesso." << endl;

      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      aplicacao->setValor(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;

    }
  } catch (const invalid_argument &err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUAplicacao::cenarioInvalido() {
  const int tamanhoArr = 3;
  int i = 0;
  for (i = 0; i <= tamanhoArr - 1; i++) {
    try {
      cout << "\t\tTestando codigo inválido" << CODIGO_INVALIDO[i] << endl;
      aplicacao->setCodigo(CODIGO_INVALIDO[i]);
      cout << "\t\tCodigo inválido setado. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tCodigo inválido rejeitado com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando data inválida " << DATA_INVALIDA[i] << endl;
      aplicacao->setData(DATA_INVALIDA  [i]);
      cout << "\t\tData inválida setada. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tData inválida rejeitada com sucesso." << endl;
    }

    try {
      cout << "\t\tTestando valor inválido " << VALOR_INVALIDO[i] << endl;
      aplicacao->setValor(VALOR_INVALIDO[i]);
      cout << "\t\tValor inválido setada. Erro em teste." << endl;
      estado = FALHA;
      return;
    } catch (const invalid_argument &err) {
      cout << "\t\tValor inválido rejeitado com sucesso." << endl;
    }
  }
}

int TUAplicacao::executar() {
    cout << "\t> Executando teste unitário de aplicacao:" << endl;
    cenarioValido();
    cenarioInvalido();
    delete aplicacao;
    cout << "\t> Teste unitário de aplicacao finalizado." << endl << endl;
    return estado;

}


TestesDeEntidade::TestesDeEntidade() {
  estado = SUCESSO;
  tuUsuario = new TUUsuario();
  tuConta = new TUConta();
  tuProduto = new TUProduto();
  tuAplicacao = new TUAplicacao();
}

int TestesDeEntidade::executar() {
  const int quantidadeTestes = 4;
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

  switch(tuProduto->executar()) {
    case TUProduto::SUCESSO:
      feedbacks[i] = "X Teste de produto bem sucedido!";
      break;
    case TUProduto::FALHA:
      feedbacks[i] = "O Teste de produto apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;

  switch(tuAplicacao->executar()) {
    case TUAplicacao::SUCESSO:
      feedbacks[i] = "X Teste de aplicacao bem sucedido!";
      break;
    case TUAplicacao::FALHA:
      feedbacks[i] = "O Teste de aplicacao apresentou falha!";
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




