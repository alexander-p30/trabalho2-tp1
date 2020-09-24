#include <iostream>
#include "DomainTests.h"
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
      cep->setNumero(CEP_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCep::cenarioInvalido() {
  try {
    cep->setNumero(CEP_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete cep;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de código de agência.
const string TUCodigoDeAgencia::CODIGO_VALIDO[3] = {"1234", "8413", "9999"};
const string TUCodigoDeAgencia::CODIGO_INVALIDO = "0000";

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
      agencia->setCodigo(CODIGO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCodigoDeAgencia::cenarioInvalido() {
  try {
    agencia->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete agencia;

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
      banco->setCodigo(CODIGO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCodigoDeBanco::cenarioInvalido() {
  try {
    banco->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete banco;

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
      cpf->setNumero(CPF_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUCpf::cenarioInvalido() {
  try {
    cpf->setNumero(CPF_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete cpf;

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
      emissor->setCodigo(CODIGO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUEmissor::cenarioInvalido() {
  try {
    emissor->setCodigo(CODIGO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete emissor;

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
      horario->setHorario(HORARIO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUHorario::cenarioInvalido() {
  try {
    horario->setHorario(HORARIO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete horario;

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
      conta->setNumero(NUMERO_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUNumeroDeConta::cenarioInvalido() {
  try {
    conta->setNumero(NUMERO_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete conta;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de senha.
const string TUSenha::SENHA_VALIDA[3] = {"876543",
                                        "132650",
                                        "946127"};
const string TUSenha::SENHA_INVALIDA = "516277";

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
      senha->setSenha(SENHA_VALIDA[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUSenha::cenarioInvalido() {
  try {
    senha->setSenha(SENHA_INVALIDA);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete senha;

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
      aplicacao->setValor(VALOR_VALIDO[i]);
    }
  } catch(const invalid_argument& err) {
    estado = FALHA;
  }
}

void TUValorDeAplicacao::cenarioInvalido() {
  try {
    aplicacao->setValor(VALOR_INVALIDO);
    estado = FALHA;
  } catch(const invalid_argument& err) {
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
  cenarioValido();
  cenarioInvalido();
  delete aplicacao;

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

void TUClasse::cenarioValido()
{
  try
  {
    const int tamanhoArr = 5;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      classe->setText(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUClasse::cenarioInvalido()
{
  try
  {
    classe->setText(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUClasse::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete classe;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Codigo de Aplicação.
const string TUCodigoDeAplicacao::VALOR_VALIDO[3] = {"11111", "12355", "37590"};

const string TUCodigoDeAplicacao::VALOR_INVALIDO = "00000";

/**
 * Método construtor para a classe de teste de unidade para Codigo de Aplicação.
*/
TUCodigoDeAplicacao::TUCodigoDeAplicacao()
{
  estado = SUCESSO;
  codigo = new CodigoDeAplicacao();
}

void TUCodigoDeAplicacao::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      codigo->setCodigoDeAplicacao(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
    cout << "cenario valido" << endl;
  }
}

void TUCodigoDeAplicacao::cenarioInvalido()
{
  try
  {
    codigo->setCodigoDeAplicacao(VALOR_INVALIDO);
    estado = FALHA;
     cout << "cenario invalido" << endl;
  }
  catch (const invalid_argument &err)
  {
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
int TUCodigoDeAplicacao::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete codigo;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Codigo de Produto.
const string TUCodigoDeProduto::VALOR_VALIDO[3] = {"111", "123", "375"};

const string TUCodigoDeProduto::VALOR_INVALIDO = "000";

/**
 * Método construtor para a classe de teste de unidade para Codigo de Produto.
*/
TUCodigoDeProduto::TUCodigoDeProduto()
{
  estado = SUCESSO;
  codigo = new CodigoDeProduto();
}

void TUCodigoDeProduto::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      codigo->setCodigoDeProduto(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUCodigoDeProduto::cenarioInvalido()
{
  try
  {
    codigo->setCodigoDeProduto(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUCodigoDeProduto::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete codigo;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Data.
const string TUData::VALOR_VALIDO[3] = {"26/09/2021", "28/01/2021", "29/02/2024"};

const string TUData::VALOR_INVALIDO = "32/03/2021";

/**
 * Método construtor para a classe de teste de unidade para Data.
*/
TUData::TUData()
{
  estado = SUCESSO;
  data = new Data();
}

void TUData::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      data->setData(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUData::cenarioInvalido()
{
  try
  {
    data->setData(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUData::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete data;

  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Endereço.
const string TUEndereco::VALOR_VALIDO[3] = {"Rua da Batata", "Bairro Sul", "Bairro Norte"};

const string TUEndereco::VALOR_INVALIDO = "Rua da Batata ";

/**
 * Método construtor para a classe de teste de unidade para Endereço.
*/
TUEndereco::TUEndereco()
{
  estado = SUCESSO;
  endereco = new Endereco();
}

void TUEndereco::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      endereco->setEndereco(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUEndereco::cenarioInvalido()
{
  try
  {
    endereco->setEndereco(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUEndereco::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete endereco;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Nome.
const string TUNome::VALOR_VALIDO[3] = {"Lucas Azuma", "Estevan Alexander", "Fernando Chacon"};

const string TUNome::VALOR_INVALIDO = "lucas Azuma ";

/**
 * Método construtor para a classe de teste de unidade para Nome.
*/
TUNome::TUNome()
{
  estado = SUCESSO;
  nome = new Nome();
}

void TUNome::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      nome->setNome(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUNome::cenarioInvalido()
{
  try
  {
    nome->setNome(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUNome::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete nome;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Prazo.
const int TUPrazo::VALOR_VALIDO[12] = {6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72};

const int TUPrazo::VALOR_INVALIDO = 15;

/**
 * Método construtor para a classe de teste de unidade para Prazo.
*/
TUPrazo::TUPrazo()
{
  estado = SUCESSO;
  prazo = new Prazo();
}

void TUPrazo::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      prazo->setPrazo(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUPrazo::cenarioInvalido()
{
  try
  {
    prazo->setPrazo(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUPrazo::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete prazo;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Taxa.
const float TUTaxa::VALOR_VALIDO[3] = {0, 2.5, 100.14};

const float TUTaxa::VALOR_INVALIDO = -1;

/**
 * Método construtor para a classe de teste de unidade para Taxa.
*/
TUTaxa::TUTaxa()
{
  estado = SUCESSO;
  taxa = new Taxa();
}

void TUTaxa::cenarioValido()
{
  try
  {
    const int tamanhoArr = 3;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      taxa->setTaxa(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUTaxa::cenarioInvalido()
{
  try
  {
    taxa->setTaxa(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUTaxa::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete taxa;
  return estado;
}

// Inicialização das variáveis de classe para teste unitário de Valor Minimo.
const float TUValorMinimo::VALOR_VALIDO[4] = {1000, 5000, 10000, 50000};

const float TUValorMinimo::VALOR_INVALIDO = -1;

/**
 * Método construtor para a classe de teste de unidade para Valor Minimo.
*/
TUValorMinimo::TUValorMinimo()
{
  estado = SUCESSO;
  valor = new ValorMinimo();
}

void TUValorMinimo::cenarioValido()
{
  try
  {
    const int tamanhoArr = 4;
    int i = 0;
    for (i = 0; i <= tamanhoArr - 1; i++)
    {
      valor->setValorMinimo(VALOR_VALIDO[i]);
    }
  }
  catch (const invalid_argument &err)
  {
    estado = FALHA;
  }
}

void TUValorMinimo::cenarioInvalido()
{
  try
  {
    valor->setValorMinimo(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch (const invalid_argument &err)
  {
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
int TUValorMinimo::executar()
{
  cenarioValido();
  cenarioInvalido();
  delete valor;
  return estado;
}
