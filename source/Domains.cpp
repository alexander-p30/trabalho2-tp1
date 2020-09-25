#include "../headers/Domains.h"
#include <iostream>
#include <ctype.h>
using namespace std;

/**
 * Método construtor para classe Cep.
 * @param numeroCep Número inteiro a ser validade pelo método setNumero().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setNumero().
*/
Cep::Cep(int numeroCep) {
  try {
    setNumero(numeroCep);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter de número de Cep.
 * @param numeroCep Número de cpf a ser guardado na classe. É um número inteiro, que deve estar contido
 * em um dos seguintes invervalos: [1000000,5999999],
 * [8000000,8499999],
 * [20000000,26600999],
 * [70000000,70999999],
 * [40000000,41999999],
 * [60000000,60999999]
 * @throw invalid_argument Se o método de validação do número falhar, lança exceção.
 *
*/
void Cep::setNumero(int numeroCep) {
  if(validar(numeroCep)){
    number = numeroCep;
  } else {
    throw invalid_argument("valor informado para CEP não condiz com nenhuma das faixas.");
  }
}

bool Cep::validar(int numeroCep) const {
  const int numDeFaixas = 6;
  const int faixas[numDeFaixas][2] = {
    1000000,5999999,
    8000000,8499999,
    20000000,26600999,
    70000000,70999999,
    40000000,41999999,
    60000000,60999999
  };

  int i = 0;

  for(i = 0; i <= numDeFaixas - 1; i++) {
    if(numeroCep >= faixas[i][0] && numeroCep <= faixas[i][1]) {
      return true;
    }
  }

  return false;
}

/**
 * Método para acessar o número de Cep guardado.
 * @return Inteiro com número do Cep.
*/
int Cep::getNumero() const {
  return number;
}

/**
 * Método construtor para classe CodigoDeAgencia.
 * @param codigo String a ser validada pelo método setCodigo().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setCodigo().
*/
CodigoDeAgencia::CodigoDeAgencia(string codigo) {
  try {
    setCodigo(codigo);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para código de agência.
 * @param codigo Representa o código de agência. Deve estar no formato XXXX, numérico, diferente de 0000.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
void CodigoDeAgencia::setCodigo(string codigo) {
  if(validar(codigo)){
    this->codigo = codigo;
  } else {
    throw invalid_argument("valor informado para Código de Agência não é válido.");
  }
}


bool CodigoDeAgencia::validar(string codigo) const {
  if(codigo.length() != 4 || codigo == "0000") {
    return false;
  }

  return true;
}

/**
 * Método que retorna string do código de agência.
 * @return String do código de agência
*/
string CodigoDeAgencia::getCodigo() const {
  return codigo;
}

/**
 * Método construtor para classe CodigoDeBanco.
 * @param codigo String a ser validada pelo método setCodigo().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setCodigo().
*/
CodigoDeBanco::CodigoDeBanco(string codigo) {
  try {
    setCodigo(codigo);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para valor de código de banco.
 * @param codigo Representa o código de banco. Deve estar no formato XXX, numérico,
 * e deve ser igual a um dos seguintes valores {001, 033, 104, 237, 341}.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
void CodigoDeBanco::setCodigo(string codigo) {
  if(validar(codigo)){
    this->codigo = codigo;
  } else {
    throw invalid_argument("valor informado para Código de Banco não é válido.");
  }
}

bool CodigoDeBanco::validar(string codigo) const {
  const string codigosDeBanco[] = {"001", "033", "104", "237", "341"};
  const int numDeCodigos = sizeof(codigosDeBanco)/sizeof(codigosDeBanco[0]);

  int i = 0;

  for(i = 0; i <= numDeCodigos - 1; i++) {
    if(codigo == codigosDeBanco[i]) {
      return true;
    }
  }

  return false;
}

/**
 * Método que retorna string do código de banco.
 * @return String do código de banco
*/
string CodigoDeBanco::getCodigo() const {
  return codigo;
}

/**
 * Método construtor para classe Cpf.
 * @param Number String a ser validada pelo método setNumero().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setNumero().
*/
Cpf::Cpf(string cpfNumber) {
  try {
    setNumero(cpfNumber);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para número de Cpf.
 * @param cpfNumber String a ser validada segundo os dígitos verificadores de Cpf.
 * @throw invalid_argument Lança exceção caso os dígitos verificadores não estejam corretos.
*/
void Cpf::setNumero(string cpfNumber) {
  if(validar(cpfNumber)){
    this->cpfNumber = cpfNumber;
  } else {
    throw invalid_argument("valor informado para CPF não se adequa às condições mínimas.");
  }
}

bool Cpf::validar(string cpfNumber) const {
  const int numCaracteresCpf = 14;
  const int numDigitosCpf = 11;

  int i = 0, j = 0, ultimoDigito = 0, penultimoDigito = 0;
  int digitosCpf[11] = {};

  for(i = 0; i <= numCaracteresCpf - 1; i++) {
    if(cpfNumber[i] != '.' && cpfNumber[i] != '-') {
      digitosCpf[j] = cpfNumber[i] - '0';
      j++;
    }
  }

  i = 0;
  j = 0;

  for(i = 0; i <= numDigitosCpf - 3; i++) {
    ultimoDigito += digitosCpf[i] * (11 - j);
    penultimoDigito += digitosCpf[i] * (10 - j);
    j++;
  }

  ultimoDigito = ultimoDigito + (digitosCpf[numDigitosCpf - 2] * 2);
  ultimoDigito = ultimoDigito > 1 ? 11 - ultimoDigito % 11 : 0;
  penultimoDigito = penultimoDigito > 1 ? 11 - penultimoDigito % 11 : 0;

  for(i = 0; i <= numDigitosCpf - 1; i++) {
  }

  bool validaUltimDig = ultimoDigito == digitosCpf[numDigitosCpf - 1];
  bool validaPenultimDig = penultimoDigito == digitosCpf[numDigitosCpf - 2];

  if(!validaUltimDig || !validaPenultimDig) {
    return false;
  }

  return true;
}

/**
 * Método getter para número de cpf
 * @return Retorna string no formato "XXX.XXX.XXX-XX", em que X é um número de 0 a 9.
*/
string Cpf::getNumero() const {
  return cpfNumber;
}

/**
 * Método construtor para a classe Emissor.
 * @param codigo String a ser validada pelo método setCodigo().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setCodigo().
*/
Emissor::Emissor(string codigo) {
  try {
    setCodigo(codigo);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para código de emissor.
 * @param codigo Representa o código de emissor. Texto de 5 a 30 caracteres, com letras, números,
 * hífen, ponto ou espaço, em que apenas letras ou números podem estar em sequência.
 * @throw invalid_argument Lança exceção se formato do parâmetro não estiver correto.
*/
void Emissor::setCodigo(string codigo) {
  if(validar(codigo)){
    this->codigo = codigo;
  } else {
    throw invalid_argument("valor informado para código de emissor em formato incorreto.");
  }
}

bool Emissor::validar(string codigo) const {
  const int comprimentoCodigo = codigo.length();

  int i = 0, contCaracInval = 0;

  bool validaComprimento = !(comprimentoCodigo >= 5 && comprimentoCodigo <= 30);
  bool validaPrimeiroCarac = isalpha(codigo[0]) && islower(codigo[0]);

  if(validaComprimento || validaPrimeiroCarac) {
    return false;
  }

  for(i = 0; i <= comprimentoCodigo - 1; i++) {
    if(codigo[i] == '-' || codigo[i] == '.' || codigo[i] == ' ') {
      contCaracInval++;
    } else {
      contCaracInval = 0;
    }

    if(contCaracInval == 2) {
      return false;
    }
  }

  return true;
}

/**
 * Método getter para código de emissor.
 * @return Retorna string com comprimento de 5 a 30 caracteres contendo o código do emissor.
*/
string Emissor::getCodigo() const {
  return codigo;
}

/**
 * Método construtor para classe Horario.
 * @param hora String a ser validada pelo método setHora().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setHora().
*/
Horario::Horario(string horario) {
  try {
    setHorario(horario);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para horário.
 * @param horario String a ser validada com uma hora válida entre 13:00 e 17:00. Logo, os minutos devem
 * estar entre 0 e 59, e as horas, entre 13 e 17.
 * @throw invalid_argument Lança exceção caso algum dos intervalos, seja o de hora ou o de minutos,
 * seja extrapolado.
*/
void Horario::setHorario(string horario) {
  if(validar(horario)){
    this->horario = horario;
  } else {
    throw invalid_argument("valor informado para horário em formato incorreto.");
  }
}

bool Horario::validar(string horario) const {
  const int tamanhoHora = horario.length();

  if(tamanhoHora != 5) {
    return false;
  }

  string horas = "00", minutos = "00";
  horas[0] = horario[0];
  horas[1] = horario[1];
  minutos[0] = horario[3];
  minutos[1] = horario[4];

  int horasInt = stoi(horas), minutosInt = stoi(minutos);

  bool validaHoras = (horasInt >= 13 && horasInt < 17) || (horasInt == 17 && minutosInt == 0);
  bool validaMinutos = minutosInt >= 0 && minutosInt <=59;

  if(!(validaHoras) || !(validaMinutos)) {
    return false;
  }

  return true;
}

/**
 * Método getter para horário.
 * @return Retorna string com comprimento de 5 caracteres contendo um horário.
*/
string Horario::getHorario() const {
  return horario;
}

/**
 * Método construtor para classe NumeroDeConta.
 * @param hora String a ser validada pelo método setNumero().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setNumero().
*/
NumeroDeConta::NumeroDeConta(string numero) {
  try {
    setNumero(numero);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para número de conta.
 * @param numero String no formato "XXXXXX-Y" composta somente por números (0 a 9), em que Y é o
 * dígito verificador. O dígito verificador Y é calculado utilizando o seguinte algoritmo:
 * Seja o número de conta ABCDEF-G, calculamos x = (A + B + C + D + E + F) % 10 e avaliamos o resultado.
 * Se o resultado for maior que 0, G será 10 - x, caso for 0, G será 0.
 * @throw invalid_argument Lança exceção caso o formato não seja obedecido, ou o dígito verificador
 * seja inválido.
*/
void NumeroDeConta::setNumero(string numero) {
  if(validar(numero)){
    this->numero = numero;
  } else {
    throw invalid_argument("valor informado para número de conta em formato incorreto ou dígito verificador não confere.");
  }
}

bool NumeroDeConta::validar(string numero) const {
  const int tamanhoNumero = numero.length();

  if(tamanhoNumero != 8) {
    return false;
  }

  int i = 0, soma = 0;

  for(i = 0; i <= tamanhoNumero - 3; i++) {
    soma += numero[i] - '0';
  }

  int verificador = soma % 10 == 0 ? 0 : 10 - soma % 10;

  if(verificador != (numero[tamanhoNumero - 1] - '0')) {
    return false;
  }

  return true;
}

/**
 * Método getter para número de conta.
 * @return Retorna string com formato "XXXXXX-Y", sendo composto somente por dígitos e sendo Y
 * o dígito verificador.
*/
string NumeroDeConta::getNumero() const {
  return numero;
}

/**
 * Método construtor para classe Senha.
 * @param senha String a ser validada pelo método setSenha().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setSenha().
*/
Senha::Senha(string senha) {
  try {
    setSenha(senha);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para senha.
 * @param senha String no formato "XXXXXX" composta somente por dígitos (0 a 9) não repetidos.
 * @throw invalid_argument Lança exceção caso o formato não seja obedecido, ou o dígito verificador
 * seja inválido.
*/
void Senha::setSenha(string senha) {
  if(validar(senha)){
    this->senha = senha;
  } else {
    throw invalid_argument("valor informado para senha não condiz com requisitos mínimos.");
  }
}

bool Senha::validar(string senha) const {
  const int tamanhoSenha = senha.length();

  if(tamanhoSenha != 6) {
    return false;
  }

  int i = 0, j = 0;

  for(i = 0; i <= tamanhoSenha - 2; i++) {
    for(j = i + 1; j <= tamanhoSenha - 1; j++) {
      if(senha[i] == senha[j]) {
        return false;
      }
    }
  }

  return true;
}

/**
 * Método getter para senha.
 * @return Retorna string com formato "XXXXXX", sendo composto somente por dígitos (0 a 9) não repetidos.
*/
string Senha::getSenha() const {
  return senha;
}

/**
 * Método construtor para classe ValorDeAplicacao.
 * @param valor Float a ser validado pelo método setValor().
 * @throw invalid_argument Lança exceção caso parâmetro não esteja de acordo com o método setValor().
*/
ValorDeAplicacao::ValorDeAplicacao(float valor) {
  try {
    setValor(valor);
  } catch(const invalid_argument& err) {
    throw invalid_argument(err.what());
  }
}

/**
 * Método setter para valor.
 * @param valor Float entre 0 e 1.000.000.
 * @throw invalid_argument Lança exceção caso os limites não sejam atendidos.
*/
void ValorDeAplicacao::setValor(float valor) {
  if(validar(valor)){
    valor = int(valor * 100);
    this->valor = valor/100.0;
  } else {
    throw invalid_argument("valor informado para valor não se encaixa nos limites (0 a 1.000.000).");
  }
}

bool ValorDeAplicacao::validar(float valor) const {
  if(valor < 0.0 || valor > 1000000.0) {
    return false;
  }

  return true;
}

/**
 * Método getter para valor.
 * @return Retorna float entre 0 e 1.000.000 com valor de aplicação.
*/
float ValorDeAplicacao::getValor() const {
  return valor;
}

/**
 * Método construtor da classe Classe.
 * @param text texto a ser guardado na classe. É um texto, que deve ser
 * um dos seguintes : "CDB",
 * "LCA",
 * "LCI",
 * "LF",
 * "LC",
 * @throw invalid_argument Se o método de validação do texto falhar, lança exceção.
 *
*/

Classe::Classe(string text)
{
  setText(text);
};

/**
 * Método para inserir o texto da Classe guardado.Contem metodo de validação
*/

void Classe::setText(string text)
{

    if (validar(text))
    {
      this->text = text;
    }
    else
    {
      throw invalid_argument("valor informado para Classe não é válido.");
    }


};

bool Classe::validar(string text) const
{
  if (text == "CDB" || text == "LCA" || text == "LCI" || text == "LF" || text == "LC")
  {
    return true;
  }
  else
  {
    return false;
  }
};

/**
 * Método para acessar o texto da Classe guardado.
 * @return string com tipo da classe.
*/
string Classe::getText() const
{
  return text;
};

/**
 * Método construtor da classe Codigo de Aplicação.
 * @param code Codigo de Aplicação a ser guardado na classe. É um texto, que deve ter
 * tamanho de 5 caracteres diferentes de 00000,
 * @throw invalid_argument Se o método de validação do texto falhar, lança exceção.
 *
*/

CodigoDeAplicacao::CodigoDeAplicacao(string code)
{
  setCodigoDeAplicacao(code);
};

/**
 * Método para inserir o numero do Codigo de Aplicação guardado.Contem metodo de validação
*/

void CodigoDeAplicacao::setCodigoDeAplicacao(string code)
{

    if (validar(code))
    {
      this->code = code;
    }
    else
    {
      throw invalid_argument("valor informado para o Codigo de Aplicação não é valido");
    }


};

bool CodigoDeAplicacao::validar(string code) const
{
  if (code.length() == 5 && code != "00000")
  {
    return true;
  }
  else
  {
    return false;
  }
};

/**
 * Método para acessar o numero do Codigo de Aplicação guardado.
 * @return string com o numero do Codigo de Aplicação.
*/

string CodigoDeAplicacao::getCodigoDeAplicacao() const
{
  return code;
};

/**
 * Método construtor da classe Codigo de Produto.
 * @param code Codigo de Aplicação a ser guardado na classe. É um texto, que deve ter
 * tamanho de 3 caracteres diferentes de 000,
 * @throw invalid_argument Se o método de validação do numero falhar, lança exceção.
 *
*/

CodigoDeProduto::CodigoDeProduto(string code)
{
  setCodigoDeProduto(code);
};

/**
 * Método para inserir o numero do Codigo de Produto guardado.Contem metodo de validação
*/

void CodigoDeProduto::setCodigoDeProduto(string code)
{

    if (validar(code))
    {
      this->code = code;
    }
    else
    {
      throw invalid_argument("valor informado para o Codigo de Produto não é valido");
    }

};

bool CodigoDeProduto::validar(string code) const
{
  if (code.length() == 3 && code != "000")
  {
    return true;
  }
  else
  {
    return false;
  }
};

/**
 * Método para acessar o numero do Codigo de Produto guardado.
 * @return string com o numero do Codigo de Produto.
*/

string CodigoDeProduto::getCodigoDeProduto() const
{
  return code;
};

/**
 * Método construtor da classe Data.
 * @param data Data a ser guardada na classe. É um texto, que deve ter
 * formato DD/MM/YYYY levando em conta naos bissextos
 * @throw invalid_argument Se o método de validação da data falhar, lança exceção.
 *
*/

Data::Data(string data)
{
  setData(data);
};

/**
 * Método para inserir o texto da Data guardada.Contem metodo de validação
*/

void Data::setData(string data)
{

    if (validar(data))
    {
      this->data = data;
    }
    else
    {
      throw invalid_argument("valor informado para a data não é valido");
    }

};

bool Data::validar(string data) const
{
  string d = "";
  string m = "";
  string a = "";
  int first = data.find("/");
  int last = data.find_last_of("/");
  int i = 0;
  const int tamanhoData = data.length();
  for (i = 0; i < tamanhoData; i++)
  {
    if (i < first)
    {
      d += data[i];
    }
    if (i > first && i < last)
    {
      m += data[i];
    }
    if (i > last)
    {
      a += data[i];
    }
  }
  int dia = stoi(d);
  int mes = stoi(m);
  int ano = stoi(a);
  if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0))
  {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
      if (dia >= 0 && dia <= 31)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
      if (dia >= 0 && dia <= 30)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    if (mes == 02)
    {
      if (dia >= 0 && dia <= 29)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  else
  {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
      if (dia >= 0 && dia <= 31)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
      if (dia >= 0 && dia <= 30)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    if (mes == 2)
    {
      if (dia >= 0 && dia <= 28)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }

  return false;
};

/**
 * Método para acessar o texto da Data guardada.
 * @return string com o texto da data.
*/

string Data::getData() const
{
  return this->data;
};

/**
 * Método construtor da classe Endereco.
 * @param endereco Endereco a ser guardado na classe. É um texto, que deve ter
 * tamanho de 5 a 30 caracteres
 * @throw invalid_argument Se o método de validação do endereco falhar, lança exceção.
 *
*/

Endereco::Endereco(string endereco)
{
  setEndereco(endereco);
};

/**
 * Método para inserir o texto do Endereço guardado.Contem metodo de validação
*/

void Endereco::setEndereco(string endereco)
{
    if (validar(endereco))
    {
      this->endereco = endereco;
    }
    else
    {
      throw invalid_argument("valor informado para o endereco não é valido");
    }
};

bool Endereco::validar(string endereco) const
{
  int i = 0;
  const int tamanhoEndereco = endereco.length();
  if (isupper(endereco[0]) != 0 || isspace(endereco[i]) != 0 || endereco[i] == '.')
  {
    if (tamanhoEndereco >= 5 && tamanhoEndereco <= 20)
    {
      for (i = 1; i < tamanhoEndereco; i++)
      {
        if (isalpha(endereco[i]) != 0 || isspace(endereco[i]) != 0 || endereco[i] == '.')
        {
          if (isspace(endereco[i]) || endereco[i] == '.')
          {
            if (isalpha(endereco[i + 1]) == 0 || isalpha(endereco[i - 1]) == 0)
            {
              return false;
            }
          }
        }
        else
        {
          return false;
        }
      }
    }
    else
    {
      return false;
    }
  }
  else
  {

    return false;
  }
  return true;
};

/**
 * Método para acessar o texto do Endereço guardada.
 * @return string com o texto do Endereço.
*/

string Endereco::getEndereco() const
{
  return this->endereco;
};

/**
 * Método construtor da classe Nome.
 * @param nome Nome a ser guardado na classe. É um texto, que deve ter
 * tamanho de 5 a 30 caracteres
 * @throw invalid_argument Se o método de validação do texto falhar, lança exceção.
 *
*/

Nome::Nome(string nome)
{
  setNome(nome);
};

/**
 * Método para inserir o texto do Nome guardado.Contem metodo de validação
*/

void Nome::setNome(string nome)
{

    if (validar(nome))
    {
      this->nome = nome;
    }
    else
    {
      throw invalid_argument("valor informado para o nome não é valido");
    }
};

bool Nome::validar(string nome) const
{
  int i = 0;
  const int tamanhoNome = nome.length();
  if (isupper(nome[0]) != 0)
  {
    if (tamanhoNome >= 5 && tamanhoNome <= 30)
    {
      for (i = 1; i < tamanhoNome; i++)
      {
        if (isalpha(nome[i]) != 0 || isspace(nome[i]) != 0)
        {
          if (isspace(nome[i]))
          {
            if (isupper(nome[i + 1]) == 0 || isalpha(nome[i - 1]) == 0)
            {
              return false;
            }
          }
        }
        else
        {
          return false;
        }
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
  return true;
};

/**
 * Método para acessar o texto do Nome guardada.
 * @return string com o texto do Nome.
*/

string Nome::getNome() const
{
  return this->nome;
};

/**
 * Método construtor da classe Prazo.
 * @param prazo Prazo a ser guardado na classe. É um numero, que deve ser
 * menor que 72 e multiplo de 6,
 * @throw invalid_argument Se o método de validação do numero falhar, lança exceção.
 *
*/

Prazo::Prazo(int prazo)
{
  setPrazo(prazo);
};

/**
 * Método para inserir o numero do Prazo guardado.Contem metodo de validação
*/

void Prazo::setPrazo(int prazo)
{

    if (validar(prazo))
    {
      this->prazo = prazo;
    }
    else
    {
      throw invalid_argument("valor informado para o prazo não é valido");
    }
};

bool Prazo::validar(int prazo) const
{
  if (prazo <= 72 && prazo % 6 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
};

/**
 * Método para acessar o numero do Prazo guardado.
 * @return string com o numero do prazo.
*/
int Prazo::getPrazo() const
{
  return this->prazo;
};

/**
 * Método construtor da classe Taxa.
 * @param taxa Taxa a ser guardada na classe. É um numero, que deve ter
 * entre 0 e 200,
 * @throw invalid_argument Se o método de validação do numero falhar, lança exceção.
 *
*/

Taxa::Taxa(float taxa)
{
  setTaxa(taxa);
};

/**
 * Método para inserir o numero da Taxa guardada.Contem metodo de validação
*/

void Taxa::setTaxa(float taxa)
{

    if (validar(taxa))
    {
      this->taxa = taxa;
    }
    else
    {
      throw invalid_argument("valor informado para a taxa não é valido");
    }

};

bool Taxa::validar(float taxa) const
{
  if (taxa >= 0 && taxa <= 200)
  {
    return true;
  }
  else
  {
    return false;
  }
};

/**
 * Método para acessar o numero da Taxa guardada.
 * @return string com o numero da taxa.
*/

float Taxa::getTaxa() const
{
  return this->taxa;
};

/**
 * Método construtor da classe Valor Minimo.
 * @param valor Valor Minimo a ser guardado na classe. É um numero, que pode assumir
 * os valores:
 *1000,00
 *5000,00
 *10000,00
 *50000,00
 * @throw invalid_argument Se o método de validação do numero falhar, lança exceção.
 *
*/

ValorMinimo::ValorMinimo(float valor)
{
  setValorMinimo(valor);
};

/**
 * Método para inserir o numero do Valor Minimo guardado.Contem metodo de validação
*/

void ValorMinimo::setValorMinimo(float valor)
{

    if (validar(valor))
    {
      this->valor = valor;
    }
    else
    {
      throw invalid_argument("valor informado para o valor minimo não é valido");
    }

};

bool ValorMinimo::validar(float valor) const
{
  if (valor == 1000.00 || valor == 5000.00 || valor == 10000.00 || valor == 50000.00)
  {
    return true;
  }
  else
  {
    return false;
  }
};

/**
 * Método para acessar o numero do Valor Minimo guardado.
 * @return string com o numero do Valor Minimo.
*/

float ValorMinimo::getValorMinimo() const
{
  return this->valor;
};
