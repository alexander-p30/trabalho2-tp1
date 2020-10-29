#ifndef ENTITIES_H
#define ENTITIES_H

#include "domains.h"

/**
 * Classe de entidade para usuário
*/
class Usuario {
private:
  Nome nome;
  Endereco endereco;
  Cep cep;
  Cpf cpf;
  Senha senha;
public:
  // Construtores
  Usuario(
    string nome,
    string endereco,
    int cep,
    string cpf,
    string senha
  );
  Usuario() {};

  // Getters e setters
  string getNome() const;
  void setNome(string nome);
  string getEndereco() const;
  void setEndereco(string endereco);
  int getCep() const;
  void setCep(int cep);
  string getCpf() const;
  void setCpf(string cpf);
  string getSenha() const;
  void setSenha(string senha);
};

/**
 * Classe de entidade para conta
*/
class Conta {
private:
  CodigoDeBanco banco;
  CodigoDeAgencia agencia;
  NumeroDeConta numero;
public:
  // Constructors
  Conta(
    string banco,
    string agencia,
    string numero
  );
  Conta() {};

  // Getters and setters
  string getBanco() const;
  void setBanco(string banco);
  string getAgencia() const;
  void setAgencia(string agencia);
  string getNumero() const;
  void setNumero(string numero);
};

/**
 * Classe de entidade para Produto
*/

class Produto{
private:
    CodigoDeProduto codigo;
    Classe classe;
    Emissor emissor;
    Prazo prazo;
    Data vencimento;
    Taxa taxa;
    Horario horario;
    ValorMinimo valor;
public:
    Produto(
        string codigo,
        string classe,
        string emissor,
        int prazo,
        string vencimento,
        float taxa,
        string horario,
        float valor
    );
    Produto() {};
    string getCodigo() const;
    void setCodigo(string codigo);
    string getClasse() const;
    void setClasse(string classe);
    string getEmissor() const;
    void setEmissor(string emissor);
    int getPrazo() const;
    void setPrazo(int prazo);
    string getVencimento() const;
    void setVencimento(string vencimento);
    float getTaxa() const;
    void setTaxa(float taxa);
    string getHorario() const;
    void setHorario(string horario);
    float getValor() const;
    void setValor(float valor);
};

/**
 * Classe de entidade para Aplicação
*/

class Aplicacao{
private:
    CodigoDeAplicacao codigo;
    ValorDeAplicacao valor;
    Data data;
public:
    Aplicacao(
        string codigo,
        float valor,
        string Data
    );
    Aplicacao() {};
    string getCodigo() const;
    void setCodigo(string codigo);
    float getValor() const;
    void setValor(float valor);
    string getData() const;
    void setData(string data);
};
#endif
