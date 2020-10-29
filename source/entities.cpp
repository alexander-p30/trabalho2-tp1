#include "../headers/entities.h"
#include <iostream>

/**
 * Método construtor de entidade Usuario.
 * @param nome String com nome do usuário, a ser verificada pelo metodo Nome::setNome().
 * @param endereco String com endereço do usuário, a ser verificada pelo metodo Endereco::setEndereco().
 * @param cep Inteiro com número de CEP do usuário, a ser verificado pelo metodo Cep::setNumero().
 * @param cpf String com número de CPF do usuário, a ser verificada pelo metodo Cpf::setNumero().
 * @param senha String com senha do usuário, a ser verificada pelo metodo Senha::SetSenha().
 * @throw invalid_argument Se o método de validação de algum dos parâmetros falhar, lança exceção.
 *
*/
Usuario::Usuario(
    string nome,
    string endereco,
    int cep,
    string cpf,
    string senha
  ) {
  try {
    setNome(nome);
    setEndereco(endereco);
    setCep(cep);
    setCpf(cpf);
    setSenha(senha);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para nome de usuário.
 * @return String contendo o nome do usuário.
*/
string Usuario::getNome() const {
  return this->nome.getNome();
}

/** Método setter para nome de usuário.
 * @param nome String contendo nome do usuário, a ser validada pelo método Nome::setNome().
*/
void Usuario::setNome(string nome) {
  try {
    this->nome.setNome(nome);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para endereço de usuário.
 * @return String contendo o endereço do usuário.
*/
string Usuario::getEndereco() const {
  return this->endereco.getEndereco();
}

/** Método setter para endereço de usuário.
 * @param endereco String contendo endereço do usuário, a ser validada pelo método Endereco::setEndereco().
*/
void Usuario::setEndereco(string endereco) {
  try {
    this->endereco.setEndereco(endereco);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para CEP de usuário.
 * @return Inteiro contendo o CEP do usuário.
*/
int Usuario::getCep() const {
  return this->cep.getNumero();
}

/** Método setter para CEP de usuário.
 * @param endereco Inteiro contendo CEP do usuário, a ser validado pelo método Cep::setNumero().
*/
void Usuario::setCep(int cep) {
  try {
    this->cep.setNumero(cep);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para CPF de usuário.
 * @return String contendo o CPF do usuário.
*/
string Usuario::getCpf() const {
  return this->cpf.getNumero();
}

/** Método setter para CPF de usuário.
 * @param endereco String contendo CPF do usuário, a ser validada pelo método Cpf::setNumero().
*/
void Usuario::setCpf(string cpf) {
  try {
    this->cpf.setNumero(cpf);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para senha de usuário.
 * @return String contendo o senha do usuário.
*/
string Usuario::getSenha() const {
  return this->senha.getSenha();
}

/** Método setter para senha de usuário.
 * @param senha String contendo senha do usuário, a ser validada pelo método Senha::setSenha().
*/
void Usuario::setSenha(string senha) {
  try {
    this->senha.setSenha(senha);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método construtor de entidade Conta.
 * @param banco String com código de banco da conta, a ser verificada pelo metodo CodigoDeBanco::setCodigo().
 * @param agencia String com código de agência da conta, a ser verificada pelo metodo CodigoDeAgencia::setCodigo().
 * @param numero String com número da conta, a ser verificada pelo metodo NumeroDeConta::setNumero().
 * @throw invalid_argument Se o método de validação de algum dos parâmetros falhar, lança exceção.
*/
Conta::Conta(
    string banco,
    string agencia,
    string numero
  ) {
    try {
    setBanco(banco);
    setAgencia(agencia);
    setNumero(numero);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para código de banco da conta.
 * @return String contendo o código de banco da conta.
*/
string Conta::getBanco() const {
  return this->banco.getCodigo();
}

/** Método setter o código de banco da conta.
 * @param banco String contendo código de banco da conta, a ser validada pelo método CodigoDeBanco::setCodigo().
*/
void Conta::setBanco(string banco) {
  try {
    this->banco.setCodigo(banco);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para código de agência da conta.
 * @return String contendo o código de agência da conta.
*/
string Conta::getAgencia() const {
  return this->agencia.getCodigo();
}

/** Método setter o código de agência da conta.
 * @param banco String contendo código de agência da conta, a ser validada pelo método CodigoDeAgencia::setCodigo().
*/
void Conta::setAgencia(string agencia) {
  try {
    this->agencia.setCodigo(agencia);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método getter para o número da conta.
 * @return String contendo o número da conta.
*/
string Conta::getNumero() const {
  return this->numero.getNumero();
}

/** Método setter o número da conta.
 * @param banco String contendo número da conta, a ser validada pelo método NumeroDeConta::setNumero().
*/
void Conta::setNumero(string numero) {
  try {
    this->numero.setNumero(numero);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método construtor de entidade Produto.
 * @param codigo String com codigo de produto, a ser verificada pelo metodo Codigo::setCodigoDeProduto().
 * @param classe String com calsse de produto a ser verificada pelo metodo Classe::setText().
 * @param emissor String com emissor de produto, a ser verificado pelo metodo Emissor::setCodigo().
 * @param prazo Inteiro com prazo de produto, a ser verificado pelo metodo Prazo::setPrazo().
 * @param vencimento String com vencimento do produto, a ser verificado pelo metodo Data::setData().
 * @param taxa Float com taxa do produto, a ser verificada pelo metodo Taxa::setTaxa().
 * @param horario String com horario do produto, a ser verificado pelo metodo Horario::setHorario().
 * @param valor Float com valor do produto, a ser verificado pelo metodo Valor::setValor().
 * @throw invalid_argument Se o método de validação de algum dos parâmetros falhar, lança exceção.
 *
*/

Produto::Produto(
            string codigo,
            string classe,
            string emissor,
            int prazo,
            string vencimento,
            float taxa,
            string horario,
            float valor
        ){
        try{
            setCodigo(codigo);
            setClasse(classe);
            setEmissor(emissor);
            setPrazo(prazo);
            setVencimento(vencimento);
            setTaxa(taxa);
            setHorario(horario);
            setValor(valor);
        }catch(const invalid_argument& err) {
            throw invalid_argument(err.what());
        }
}

/**
 * Método getter para nome de codigo de produto.
 * @return String contendo o codigo do produto.
*/

string Produto::getCodigo() const{
   return this->codigo.getCodigoDeProduto();
}

/**
 * Método setter para codigo de produto.
 * @param codigo String contendo codigo do produto, a ser validado pelo método CodigoDeProduto::setCodigoDeProduto().
*/

void Produto::setCodigo(string codigo){
    try{
        this->codigo.setCodigoDeProduto(codigo);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para nome de classe de produto.
 * @return String contendo o classe do produto.
*/

string Produto::getClasse() const{
    return this->classe.getText();
}

/**
 * Método setter para classe de produto.
 * @param classe String contendo classe do produto, a ser validado pelo método Classe::setText().
*/


void Produto::setClasse(string classe){
    try{
        this->classe.setText(classe);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para nome de emissor de produto.
 * @return String contendo o emissor do produto.
*/

string Produto::getEmissor() const{
    return this->emissor.getCodigo();
}

/**
 * Método setter para emissor de produto.
 * @param emissor String contendo emissor do produto, a ser validado pelo método Emissor::setCodigo().
*/


void Produto::setEmissor(string emissor){
    try{
        this->emissor.setCodigo(emissor);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para nome de prazo de produto.
 * @return Int contendo o prazo do produto.
*/

int Produto::getPrazo() const{
    return this->prazo.getPrazo();
}

/**
 * Método setter para prazo de produto.
 * @param prazo Int contendo prazo do produto, a ser validado pelo método Prazo::setPrazo().
*/


void Produto::setPrazo(int prazo){
    try{
        this->prazo.setPrazo(prazo);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para nome de vencimento de produto.
 * @return String contendo o vencimento do produto.
*/

string Produto::getVencimento() const{
    return this->vencimento.getData();
}

/**
 * Método setter para vencimento de produto.
 * @param vencimento String contendo vencimento do produto, a ser validado pelo método Data::setData().
*/


void Produto::setVencimento(string vencimento){
    try{
        this->vencimento.setData(vencimento);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para nome de taxa de produto.
 * @return Float contendo a taxa do produto.
*/

float Produto::getTaxa() const{
    return this->taxa.getTaxa();
}

/**
 * Método setter para taxa de produto.
 * @param taxa Float contendo taxa do produto, a ser validada pelo método Taxa::setTaxa().
*/


void Produto::setTaxa(float taxa){
    try{
        this->taxa.setTaxa(taxa);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para nome de horario de produto.
 * @return String contendo o horario do produto.
*/

string Produto::getHorario() const{
    return this->horario.getHorario();
}

/**
 * Método setter para horário de produto.
 * @param horário String contendo horário do produto, a ser validado pelo método Horario::setHorario().
*/


void Produto::setHorario(string horario){
    try{
        this->horario.setHorario(horario);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter valor de produto.
 * @return Float contendo o valor do produto.
*/

float Produto::getValor() const{
    return this->valor.getValorMinimo();
}

/**
 * Método setter para valor de produto.
 * @param valor Float contendo valor do produto, a ser validado pelo método ValorMinimo::setValorMinimo().
*/


void Produto::setValor(float valor){
    try{
        this->valor.setValorMinimo(valor);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método construtor de entidade Aplicação.
 * @param codigo String com codigo de aplicação, a ser verificado pelo metodo CodigoDeAplicacao::setCodigoDeAplicacao().
 * @param valor Float com valor de aplicação a ser verificada pelo metodo ValorDeAplicacao::setValor().
 * @param Data String com data de aplicação a ser verificada pelo metodo Data::setData().
 * @throw invalid_argument Se o método de validação de algum dos parâmetros falhar, lança exceção.
 *
*/

Aplicacao::Aplicacao(
            string codigo,
            float valor,
            string data
        ){
        try{
            setCodigo(codigo);
            setValor(valor);
            setData(data);
        }catch(const invalid_argument& err) {
            throw invalid_argument(err.what());
        }
}

/**
 * Método getter para codigo de aplicação.
 * @return String contendo o codigo de aplicaçao.
*/

string Aplicacao::getCodigo() const{
    return this->codigo.getCodigoDeAplicacao();
}

/**
 * Método setter para codigo de aplicação.
 * @param codigo String contendo codigo de aplicação, a ser validado pelo método CodigoDeAplicacao::setCodigoDeAplicacao().
*/


void Aplicacao::setCodigo(string codigo){
    try{
        this->codigo.setCodigoDeAplicacao(codigo);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para valor de aplicação.
 * @return Float contendo o valor de aplicaçao.
*/

float Aplicacao::getValor() const{
    return this->valor.getValor();
}

/**
 * Método setter para valor de aplicação.
 * @param valor Float contendo valor de aplicação, a ser validado pelo método ValorDeAplicacao::setValor().
*/


void Aplicacao::setValor(float valor){
    try{
        this->valor.setValor(valor);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}

/**
 * Método getter para data de aplicação.
 * @return String contendo a data de aplicaçao.
*/

string Aplicacao::getData() const{
  return this->data.getData();
}

/**
 * Método setter para data de aplicação.
 * @param data String contendo data de aplicação, a ser validada pelo método Data::setData().
*/


void Aplicacao::setData(string data){
    try{
        this->data.setData(data);
    }catch(const invalid_argument& err){
        throw invalid_argument(err.what());
    }
}



