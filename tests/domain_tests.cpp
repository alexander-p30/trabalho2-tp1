#include <iostream>
#include <string>
#include "domain_tests.h"
using namespace std;

// Inicialização das variáveis de classe para teste unitário de CEP.
const int TUCep::CEP_VALIDO[6] = {1234567, 8123456, 21234567, 70234567, 41234567, 60234567};
const int TUCep::CEP_INVALIDO = 123456;

/**
 * Método construtor para a classe de teste de unidade para CEP.
*/
TUCep::TUCep() {
  estado = SUCESSO;
  cep = new Cep();
}

void TUCep::cenarioValido() {
  try {
    const int tamanhoArr = sizeof(CEP_VALIDO)/sizeof(CEP_VALIDO[0]);
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << CEP_VALIDO[i] << endl;
      cep->setNumero(CEP_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUCep::cenarioInvalido() {
  try {
 
    cout << "\t\tTestando valor inválido " << CEP_INVALIDO << endl;
    cep->setNumero(CEP_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio CEP. São executados dois testes:
 * - Um para valor válido para CEP;
 * - Um para valor inválido para CEP
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCep::executar() {
  cout << "\t> Executando teste de Cep:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete cep;
  cout << "\t> Teste de Cep finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de código de agência.
const string TUCodigoDeAgencia::CODIGO_VALIDO[3] = {"1234", "8413", "9999"};
const string TUCodigoDeAgencia::CODIGO_INVALIDO = "123A";

/**
 * Método construtor para a classe de teste de unidade para CódigoDeAgencia.
*/
TUCodigoDeAgencia::TUCodigoDeAgencia() {
  estado = SUCESSO;
  agencia = new CodigoDeAgencia();
}

void TUCodigoDeAgencia::cenarioValido() {
  try {
    const int tamanhoArr = sizeof(CODIGO_VALIDO)/sizeof(CODIGO_VALIDO[0]);
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << CODIGO_VALIDO[i] << endl;
      agencia->setCodigo(CODIGO_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUCodigoDeAgencia::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << CODIGO_INVALIDO << endl;
    agencia->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio CodigoDeAgencia. São executados dois testes:
 * - Um para valor válido para código de agência;
 * - Um para valor inválido para código de agência.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCodigoDeAgencia::executar() {
  cout << "\t> Executando teste de CodigoDeAgencia:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete agencia;
  cout << "\t> Teste de CodigoDeAgencia finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de código de banco.
const string TUCodigoDeBanco::CODIGO_VALIDO[5] = {"001", "033", "104", "237", "341"};
const string TUCodigoDeBanco::CODIGO_INVALIDO = "002";

/**
 * Método construtor para a classe de teste de unidade para CódigoDeBanco.
*/
TUCodigoDeBanco::TUCodigoDeBanco() {
  estado = SUCESSO;
  banco = new CodigoDeBanco();
}

void TUCodigoDeBanco::cenarioValido() {
  try {
    const int tamanhoArr = 5;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << CODIGO_VALIDO[i] << endl;
      banco->setCodigo(CODIGO_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUCodigoDeBanco::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << CODIGO_INVALIDO << endl;
    banco->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio CodigoDeBanco. São executados dois testes:
 * - Um para valor válido para código de banco;
 * - Um para valor inválido para código de banco
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCodigoDeBanco::executar() {
  cout << "\t> Executando teste de CodigoDeBanco:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete banco;
  cout << "\t> Teste de CodigoDeBanco finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de CPF.
const string TUCpf::CPF_VALIDO[3] = {"031.360.531-92",
                                     "733.119.790-87",
                                     "153.364.230-33"};
const string TUCpf::CPF_INVALIDO = "002";

/**
 * Método construtor para a classe de teste de unidade para CPF.
*/
TUCpf::TUCpf() {
  estado = SUCESSO;
  cpf = new Cpf();
}

void TUCpf::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << CPF_VALIDO[i] << endl;
      cpf->setNumero(CPF_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUCpf::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << CPF_INVALIDO << endl;
    cpf->setNumero(CPF_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio CPF. São executados dois testes:
 * - Um para valor válido para CPF;
 * - Um para valor inválido para CPF.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCpf::executar() {
  cout << "\t> Executando teste de Cpf:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete cpf;
  cout << "\t> Teste de Cpf finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de código emissor.
const string TUEmissor::CODIGO_VALIDO[3] = {"ABCD39-SA.K A8HDASD88",
                                            "-BChdu",
                                            "LQPcs178dba6d-BC hdu"};
const string TUEmissor::CODIGO_INVALIDO = "cDUAYEVABnc92813-v";

/**
 * Método construtor para a classe de teste de unidade para Emissor.
*/
TUEmissor::TUEmissor() {
  estado = SUCESSO;
  emissor = new Emissor();
}

void TUEmissor::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << CODIGO_VALIDO[i] << endl;
      emissor->setCodigo(CODIGO_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUEmissor::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << CODIGO_INVALIDO << endl;
    emissor->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Emissor. São executados dois testes:
 * - Um para valor válido para código de emissor;
 * - Um para valor inválido para código de emissor.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUEmissor::executar() {
  cout << "\t> Executando teste de Emissor:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete emissor;
  cout << "\t> Teste de Emissor finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de horário.
const string TUHorario::HORARIO_VALIDO[3] = {"13:59",
                                            "15:00",
                                            "17:00"};
const string TUHorario::HORARIO_INVALIDO = "17:01";

/**
 * Método construtor para a classe de teste de unidade para Horario.
*/
TUHorario::TUHorario() {
  estado = SUCESSO;
  horario = new Horario();
}

void TUHorario::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << HORARIO_VALIDO[i] << endl;
      horario->setHorario(HORARIO_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUHorario::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << HORARIO_INVALIDO << endl;
    horario->setHorario(HORARIO_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Horario. São executados dois testes:
 * - Um para valor válido para horário;
 * - Um para valor inválido para horário.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUHorario::executar() {
  cout << "\t> Executando teste de Horario:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete horario;
  cout << "\t> Teste de Horario finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de número de conta.
const string TUNumeroDeConta::NUMERO_VALIDO[3] = {"000650-9",
                                                  "008880-6",
                                                  "109230-5"};
const string TUNumeroDeConta::NUMERO_INVALIDO = "109230-1";

/**
 * Método construtor para a classe de teste de unidade para NumeroDeConta.
*/
TUNumeroDeConta::TUNumeroDeConta() {
  estado = SUCESSO;
  conta = new NumeroDeConta();
}

void TUNumeroDeConta::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << NUMERO_VALIDO[i] << endl;
      conta->setNumero(NUMERO_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUNumeroDeConta::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << NUMERO_INVALIDO << endl;
    conta->setNumero(NUMERO_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio NumeroDeConta. São executados dois testes:
 * - Um para valor válido para número de conta;
 * - Um para valor inválido para número de conta.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUNumeroDeConta::executar() {
  cout << "\t> Executando teste de NumeroDeConta:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete conta;
  cout << "\t> Teste de NumeroDeConta finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de senha.
const string TUSenha::SENHA_VALIDA[3] = {"876543",
                                        "134650",
                                        "946127"};
const string TUSenha::SENHA_INVALIDA = "5A6217";

/**
 * Método construtor para a classe de teste de unidade para Senha.
*/
TUSenha::TUSenha() {
  estado = SUCESSO;
  senha = new Senha();
}

void TUSenha::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << SENHA_VALIDA[i] << endl;
      senha->setSenha(SENHA_VALIDA[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUSenha::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << SENHA_INVALIDA << endl;
    senha->setSenha(SENHA_INVALIDA);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Senha. São executados dois testes:
 * - Um para valor válido para senha;
 * - Um para valor inválido para senha.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUSenha::executar() {
  cout << "\t> Executando teste de Senha:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete senha;
  cout << "\t> Teste de Senha finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de valor de aplicação.
const float TUValorDeAplicacao::VALOR_VALIDO[3] = {556127.1913,
                                                  0.0,
                                                  1000000.00};
const float TUValorDeAplicacao::VALOR_INVALIDO = 1000001.0;

/**
 * Método construtor para a classe de teste de unidade para ValorDeAplicacao.
*/
TUValorDeAplicacao::TUValorDeAplicacao() {
  estado = SUCESSO;
  aplicacao = new ValorDeAplicacao();
}

void TUValorDeAplicacao::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for(i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      aplicacao->setValor(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUValorDeAplicacao::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    aplicacao->setValor(VALOR_INVALIDO);
    estado = FALHA;    
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  } catch(const invalid_argument& err) {
    cout << "\t\tValor inválido rejeitado com sucesso!" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio ValorDeAplicacao. São executados dois testes:
 * - Um para valor válido para valor de aplicação;
 * - Um para valor inválido para valor de aplicação.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUValorDeAplicacao::executar() {
  cout << "\t> Executando teste de ValorDeAplicacao:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete aplicacao;
  cout << "\t> Teste de ValorDeAplicacao finalizado." << endl << endl;

  return estado;
}

//dominios do lucas =====================

// Inicialização das variáveis de classe para teste unitário de Class.
const string TUClasse::VALOR_VALIDO[5] = {"CDB", "LCA", "LCI", "LF", "LC"};
const string TUClasse::VALOR_INVALIDO = "BAT";

/**
 * Método construtor para a classe de teste de unidade para Class.
*/
TUClasse::TUClasse(){
  estado = SUCESSO;
  classe = new Classe();
}

void TUClasse::cenarioValido() {
  try {
    const int tamanhoArr = 5;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      classe->setText(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUClasse::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    classe->setText(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Classs. São executados dois testes:
 * - Um para valor válido para Class;
 * - Um para valor inválido para Class.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUClasse::executar() {
  cout << "\t> Executando teste de Classe:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete classe;
  cout << "\t> Teste de Classe finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Codigo de Aplicação.
const string TUCodigoDeAplicacao::VALOR_VALIDO[3] = {"11111", "12355", "37590"};
const string TUCodigoDeAplicacao::VALOR_INVALIDO = "00000";

/**
 * Método construtor para a classe de teste de unidade para Codigo de Aplicação.
*/
TUCodigoDeAplicacao::TUCodigoDeAplicacao() {
  estado = SUCESSO;
  codigo = new CodigoDeAplicacao();
}

void TUCodigoDeAplicacao::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      codigo->setCodigoDeAplicacao(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUCodigoDeAplicacao::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    codigo->setCodigoDeAplicacao(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Codigo de Aplicação. São executados dois testes:
 * - Um para valor válido para Codigo de Aplicação;
 * - Um para valor inválido para Codigo de Aplicação.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCodigoDeAplicacao::executar() {
  cout << "\t> Executando teste de CodigoDeAplicacao:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete codigo;
  cout << "\t> Teste de CodigoDeAplicacao finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Codigo de Produto.
const string TUCodigoDeProduto::VALOR_VALIDO[3] = {"111", "123", "375"};
const string TUCodigoDeProduto::VALOR_INVALIDO = "000";

/**
 * Método construtor para a classe de teste de unidade para Codigo de Produto.
*/
TUCodigoDeProduto::TUCodigoDeProduto() {
  estado = SUCESSO;
  codigo = new CodigoDeProduto();
}

void TUCodigoDeProduto::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      codigo->setCodigoDeProduto(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;
  }
}

void TUCodigoDeProduto::cenarioInvalido() {
  try {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    codigo->setCodigoDeProduto(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Codigo de Produto. São executados dois testes:
 * - Um para valor válido para Codigo de Produto;
 * - Um para valor inválido para Codigo de Produto.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUCodigoDeProduto::executar() {
  cout << "\t> Executando teste de CodigoDeProduto:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete codigo;
  cout << "\t> Teste de CodigoDeProduto finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Data.
const string TUData::VALOR_VALIDO[3] = {"26/09/2021", "28/01/2021", "29/02/2024"};
const string TUData::VALOR_INVALIDO = "32/03/2021";

/**
 * Método construtor para a classe de teste de unidade para Data.
*/
TUData::TUData() {
  estado = SUCESSO;
  data = new Data();
}

void TUData::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      data->setData(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUData::cenarioInvalido() {
  try
  {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    data->setData(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Data. São executados dois testes:
 * - Um para valor válido para Data;
 * - Um para valor inválido para Data.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUData::executar() {
  cout << "\t> Executando teste de Data:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete data;
  cout << "\t> Teste de Data finalizado." << endl << endl;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Endereço.
const string TUEndereco::VALOR_VALIDO[3] = {"Rua da Batata", "Bairro Sul", "Bairro Norte"};
const string TUEndereco::VALOR_INVALIDO = "Rua da Batata ";

/**
 * Método construtor para a classe de teste de unidade para Endereço.
*/
TUEndereco::TUEndereco() {
  estado = SUCESSO;
  endereco = new Endereco();
}

void TUEndereco::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      endereco->setEndereco(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUEndereco::cenarioInvalido() {
  try
  {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    endereco->setEndereco(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Endereço. São executados dois testes:
 * - Um para valor válido para Endereço;
 * - Um para valor inválido para Endereço.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUEndereco::executar() {
  cout << "\t> Executando teste de Endereco:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete endereco;
  cout << "\t> Teste de Endereco finalizado." << endl << endl;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Nome.
const string TUNome::VALOR_VALIDO[3] = {"Lucas Azuma", "Estevan Alexander", "Fernando Chacon"};
const string TUNome::VALOR_INVALIDO = "lucas Azuma ";

/**
 * Método construtor para a classe de teste de unidade para Nome.
*/
TUNome::TUNome() {
  estado = SUCESSO;
  nome = new Nome();
}

void TUNome::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      nome->setNome(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUNome::cenarioInvalido() {
  try
  {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    nome->setNome(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Nome. São executados dois testes:
 * - Um para valor válido para Nome;
 * - Um para valor inválido para Nome.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUNome::executar() {
  cout << "\t> Executando teste de Nome:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete nome;
  cout << "\t> Teste de Nome finalizado." << endl << endl;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Prazo.
const int TUPrazo::VALOR_VALIDO[12] = {6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72};
const int TUPrazo::VALOR_INVALIDO = 15;

/**
 * Método construtor para a classe de teste de unidade para Prazo.
*/
TUPrazo::TUPrazo() {
  estado = SUCESSO;
  prazo = new Prazo();
}

void TUPrazo::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      prazo->setPrazo(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUPrazo::cenarioInvalido() {
  try
  {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    prazo->setPrazo(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Prazo. São executados dois testes:
 * - Um para valor válido para Prazo;
 * - Um para valor inválido para Prazo.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUPrazo::executar() {
  cout << "\t> Executando teste de Prazo:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete prazo;
  cout << "\t> Teste de Prazo finalizado." << endl << endl;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Taxa.
const float TUTaxa::VALOR_VALIDO[3] = {0, 2.5, 100.14};

const float TUTaxa::VALOR_INVALIDO = -1;

/**
 * Método construtor para a classe de teste de unidade para Taxa.
*/
TUTaxa::TUTaxa() {
  estado = SUCESSO;
  taxa = new Taxa();
}

void TUTaxa::cenarioValido() {
  try {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      taxa->setTaxa(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUTaxa::cenarioInvalido() {
  try
  {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    taxa->setTaxa(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Taxa. São executados dois testes:
 * - Um para valor válido para Taxa;
 * - Um para valor inválido para Taxa.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUTaxa::executar() {
  cout << "\t> Executando teste de Taxa:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete taxa;
  cout << "\t> Teste de Taxa finalizado." << endl << endl;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Valor Minimo.
const float TUValorMinimo::VALOR_VALIDO[4] = {1000, 5000, 10000, 50000};
const float TUValorMinimo::VALOR_INVALIDO = -1;

/**
 * Método construtor para a classe de teste de unidade para Valor Minimo.
*/
TUValorMinimo::TUValorMinimo() {
  estado = SUCESSO;
  valor = new ValorMinimo();
}

void TUValorMinimo::cenarioValido() {
  try {
    const int tamanhoArr = 4;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++) {
      cout << "\t\tTestando valor válido " << VALOR_VALIDO[i] << endl;
      valor->setValorMinimo(VALOR_VALIDO[i]);
      cout << "\t\tValor válido setado com sucesso." << endl;
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "\t\t Falha ao setar valor válido." << endl;

  }
}

void TUValorMinimo::cenarioInvalido() {
  try
  {
    cout << "\t\tTestando valor inválido " << VALOR_INVALIDO << endl;
    valor->setValorMinimo(VALOR_INVALIDO);
    estado = FALHA;
    cout << "\t\tValor inválido aceito, cenário inválido falhou!" << endl;
  }
  catch (const invalid_argument &err)
  {
    cout << "\t\tValor inválido rejeitado com sucesso" << endl;
    return;
  }
}

/**
 * Método de execução de teste de unidade para domínio Valor Minimo. São executados dois testes:
 * - Um para valor válido para Valor Minimo;
 * - Um para valor inválido para Valor Minimo.
 * @return 1 Caso todos os testes tenham obtido sucesso.
 * @return 2 Caso pelo menos um dos testes tenha obtido falha.
*/
int TUValorMinimo::executar() {
  cout << "\t> Executando teste de ValorMinimo:" << endl;
  cenarioValido();
  cenarioInvalido();
  delete valor;
  cout << "\t> Teste de ValorMinimo finalizado." << endl << endl;
  return estado;
}

/** 
 * Método construtor para classe que contém todos os testes de unidade juntos.
*/
TestesDeDominio::TestesDeDominio() {
  tuCep = new TUCep();
  tuCodigoDeAgencia = new TUCodigoDeAgencia();
  tuCodigoDeBanco = new TUCodigoDeBanco();
  tuCpf = new TUCpf();
  tuEmissor = new TUEmissor();
  tuHorario = new TUHorario();
  tuNumeroDeConta = new TUNumeroDeConta();
  tuSenha = new TUSenha();
  tuValorDeAplicacao = new TUValorDeAplicacao();
  tuClasse = new TUClasse();
  tuCodigoDeAplicacao = new TUCodigoDeAplicacao();
  tuCodigoDeProduto = new TUCodigoDeProduto();
  tuData = new TUData();
  tuEndereco = new TUEndereco();
  tuNome = new TUNome();
  tuPrazo = new TUPrazo();
  tuTaxa = new TUTaxa();
  tuValorMinimo = new TUValorMinimo();

  estado = SUCESSO;
}

/** 
 * Método que executa todos os testes de unidade de domínio.
 * @return 1 Caso todos os testes obtenham sucesso.
 * @return 0 Caso algum dos testes obtenha falha.
*/
int TestesDeDominio::executar() {
  string feedbacks[18];
  int i = 0;

  cout << "> Executando testes de domínio:" << endl;

  switch(tuCep->executar()) {
    case TUCep::SUCESSO:
      feedbacks[i] = "X Teste de CEP bem sucedido!";
      break;
    case TUCep::FALHA:
      feedbacks[i] = "O Teste de CEP apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuCep;

  switch(tuCodigoDeAgencia->executar()) {
    case TUCodigoDeAgencia::SUCESSO:
      feedbacks[i] = "X Teste de código de agência bem sucedido!";
      break;
    case TUCodigoDeAgencia::FALHA:
      feedbacks[i] = "O Teste de código de agência apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuCodigoDeAgencia;

  switch(tuCodigoDeBanco->executar()) {
    case TUCodigoDeBanco::SUCESSO:
      feedbacks[i] = "X Teste de código de banco bem sucedido!";
      break;
    case TUCodigoDeBanco::FALHA:
      feedbacks[i] = "O Teste de código de banco apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuCodigoDeBanco;

  switch(tuCpf->executar()) {
    case TUCpf::SUCESSO:
      feedbacks[i] = "X Teste de número de CPF bem sucedido!";
      break;
    case TUCpf::FALHA:
      feedbacks[i] = "O Teste de número de CPF apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuCpf;

  switch(tuEmissor->executar()) {
    case TUEmissor::SUCESSO:
      feedbacks[i] = "X Teste de código de emissor bem sucedido!";
      break;
    case TUEmissor::FALHA:
      feedbacks[i] = "O Teste de código de emissor apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuEmissor;

  switch(tuHorario->executar()) {
    case TUHorario::SUCESSO:
      feedbacks[i] = "X Teste de horário bem sucedido!";
      break;
    case TUHorario::FALHA:
      feedbacks[i] = "O Teste de horário apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuHorario;

  switch(tuNumeroDeConta->executar()) {
    case TUNumeroDeConta::SUCESSO:
      feedbacks[i] = "X Teste de número de conta bem sucedido!";
      break;
    case TUNumeroDeConta::FALHA:
      feedbacks[i] = "O Teste de número de conta apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuNumeroDeConta;

  switch(tuSenha->executar()) {
    case TUSenha::SUCESSO:
      feedbacks[i] = "X Teste de senha bem sucedido!";
      break;
    case TUSenha::FALHA:
      feedbacks[i] = "O Teste de senha apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuSenha;

  switch(tuValorDeAplicacao->executar()) {
    case TUValorDeAplicacao::SUCESSO:
      feedbacks[i] = "X Teste de valor de aplicação bem sucedido!";
      break;
    case TUValorDeAplicacao::FALHA:
      feedbacks[i] = "O Teste de valor de aplicação apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuValorDeAplicacao;

  switch(tuClasse->executar()){
    case TUClasse::SUCESSO: 
      feedbacks[i] = "X Teste de classe bem sucedido!";
      break;
    case TUClasse::FALHA: 
      feedbacks[i] = "O Teste de classe apresentou falha!";
      estado = FALHA;
      break;
  }
  i++;
  delete tuClasse;

  switch (tuCodigoDeProduto->executar())
  {
  case TUCodigoDeProduto::SUCESSO:
    feedbacks[i] = "X Teste de código de produto bem sucedido!";
    break;
  case TUCodigoDeProduto::FALHA:
    feedbacks[i] = "O Teste de código de produto apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuCodigoDeProduto;

  switch (tuCodigoDeAplicacao->executar())
  {
  case TUCodigoDeAplicacao::SUCESSO:
    feedbacks[i] = "X Teste de código de aplicação bem sucedido!";
    break;
  case TUCodigoDeAplicacao::FALHA:
    feedbacks[i] = "O Teste de código de aplicação apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuCodigoDeAplicacao;

  switch (tuData->executar())
  {
  case TUData::SUCESSO:
    feedbacks[i] = "X Teste de data bem sucedido!";
    break;
  case TUData::FALHA:
    feedbacks[i] = "O Teste de data apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuData;

  switch (tuNome->executar())
  {
  case TUNome::SUCESSO:
    feedbacks[i] = "X Teste de nome bem sucedido!";
    break;
  case TUNome::FALHA:
    feedbacks[i] = "O Teste de nome apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuNome;

  switch (tuEndereco->executar())
  {
  case TUEndereco::SUCESSO:
    feedbacks[i] = "X Teste de endereço bem sucedido!";
    break;
  case TUEndereco::FALHA:
    feedbacks[i] = "O Teste de endereço apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuEndereco;

  switch (tuPrazo->executar())
  {
  case TUPrazo::SUCESSO:
    feedbacks[i] = "X Teste de prazo bem sucedido!";
    break;
  case TUPrazo::FALHA:
    feedbacks[i] = "O Teste de prazo apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuPrazo;

  switch (tuTaxa->executar())
  {
  case TUTaxa::SUCESSO:
    feedbacks[i] = "X Teste de taxa bem sucedido!";
    break;
  case TUTaxa::FALHA:
    feedbacks[i] = "O Teste de taxa apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuTaxa;

  switch (tuValorMinimo->executar())
  {
  case TUValorMinimo::SUCESSO:
    feedbacks[i] = "X Teste de valor mínimo bem sucedido!";
    break;
  case TUValorMinimo::FALHA:
    feedbacks[i] = "O Teste de valor mínimo apresentou falha!";
    estado = FALHA;
    break;
  }
  i++;
  delete tuValorMinimo;

  cout << "> Fim dos testes de domínio." << endl << endl;

  cout << "> Resumo dos testes de unidade de domínio:" << endl;
  for(i = 0; i <= 17; i++) {
    cout << "\t" << feedbacks[i] << endl;
  }

  return estado;
}
