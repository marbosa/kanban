#ifndef KANBAN_DOMINIOS_H
#define KANBAN_DOMINIOS_H

#include <string>
#include <stdexcept>
using namespace std;
// ============================================================
// DOMINIOS DA ENTIDADE PESSOA: Email, Senha, Papel
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE PROJETO: Texto, Identificador
// ============================================================
// ------------------------------------------------------------
// Dominio: Identificador
// Regra: 6 caracteres, 3 letras seguidas de 3 digitos
// ------------------------------------------------------------

class Identificador {
private:
    string valor;
    void validar(const string&);
public:
    void setValor(const string&);
    string getValor() const;
};

// ------------------------------------------------------------
// Dominio: Nome
// Regra: ate 15 caracteres, letras e espacos; espaco seguido
// de letra; nao comeca nem termina com espaco
// ------------------------------------------------------------

class Nome {
private:
    string valor;
    void validar(const string&);
public:
    void setValor(const string&);
    string getValor() const;
};

// ------------------------------------------------------------
// Dominio: Texto
// Regra: ate 30 caracteres; letras, digitos, espaco e pontuacao;
// pontuacao nao seguida de pontuacao; inicia com letra maiuscula;
// termina com ponto
// ------------------------------------------------------------
class Texto {
private:
    string valor;
    void validar(const string&);
public:
    void setValor(const string&);
    string getValor() const;
};
// ------------------------------------------------------------
// Dominio: Timestamp
// Regra: DIA-MES-ANO-HH:MM, com data valida (considera bissexto)
// ------------------------------------------------------------
class Timestamp {
private:
    string valor;
    void validar(const string&);
public:
    void setValor(const string&);
    string getValor() const;
};

// ============================================================
// DOMINIOS DA ENTIDADE QUADRO: Nome, Limite
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE CARTAO DE ATIVIDADE: Timestamp, Prioridade, Estado, Tamanho
// ============================================================

#endif //KANBAN_DOMINIOS_H
