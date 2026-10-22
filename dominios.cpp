#include "dominios.h"

#include <stdexcept>
#include <string>

// ============================================================
// DOMINIOS DA ENTIDADE PESSOA: Email, Senha, Papel
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE PROJETO: Texto, Identificador
// ============================================================
// Verifica se o ano e bissexto.
static bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Verifica se o caractere e uma letra (A-Z ou a-z).
static bool ehLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Verifica se o caractere e um digito (0-9).
static bool ehDigito(char c) {
    return c >= '0' && c <= '9';
}

// Converte uma string de digitos em inteiro (ex.: "2026" -> 2026).
static int paraInt(const string& s) {
    if (s.empty()) {
        throw invalid_argument("Numero invalido.");
    }
    int r = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (!ehDigito(s[i])) {
            throw invalid_argument("Numero invalido.");
        }
        r = r * 10 + (s[i] - '0');
    }
    return r;
}

// Verifica se o caractere e um sinal de pontuacao permitido:
static bool ehPontuacao(char c) {
    return c == ',' || c == ';' || c == '.' ||
           c == ':' || c == '?' || c == '!';
}

// ------------------------------------------------------------
// Dominio: Identificador
// Regra: 6 caracteres, 3 letras seguidas de 3 digitos
// ------------------------------------------------------------
void Identificador::validar(const string& v) {
    if (v.size() != 6) {
        throw invalid_argument("Identificador invalido.");
    }
    for (int i = 0; i < 3; i++) {
        if (!((v[i] >= 'a' && v[i] <= 'z') || (v[i] >= 'A' && v[i] <= 'Z'))) {
            throw invalid_argument("Identificador invalido.");
        }
    }
    for (int i = 3; i < 6; i++) {
        if (!(v[i] >= '0' && v[i] <= '9')) {
            throw invalid_argument("Identificador invalido.");
        }
    }
}

void Identificador::setValor(const string& v) {
    validar(v);
    valor = v;
}

string Identificador::getValor() const {
    return valor;
}

// ------------------------------------------------------------
// Dominio: Nome
// Regra: ate 15 caracteres, letras e espacos; espaco seguido
// de letra; nao comeca nem termina com espaco
// ------------------------------------------------------------
void Nome::validar(const string& v) {
    if (v.size() < 1 || v.size() > 15) {
        throw invalid_argument("Nome invalido.");
    }

    if (v[0] == ' ' || v[v.size() - 1] == ' ') {
        throw invalid_argument("Nome invalido.");
    }

    for (size_t i = 0; i < v.size(); i++) {
        char c = v[i];
        bool letra = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');

        if (!letra && c != ' ') {
            throw invalid_argument("Nome invalido.");
        }

        if (c == ' ') {
            char prox = v[i + 1];
            bool proxLetra = (prox >= 'a' && prox <= 'z') || (prox >= 'A' && prox <= 'Z');
            if (!proxLetra) {
                throw invalid_argument("Nome invalido.");
            }
        }
    }
}

void Nome::setValor(const string& v) {
    validar(v);
    valor = v;
}

string Nome::getValor() const {
    return valor;
}

// ------------------------------------------------------------
// Dominio: Texto
// Regra: ate 30 caracteres; letras, digitos, espaco e pontuacao;
// pontuacao nao seguida de pontuacao; inicia com maiuscula;
// termina com ponto
// ------------------------------------------------------------
void Texto::validar(const string& v) {

    if (v.size() < 1 || v.size() > 30) {
        throw invalid_argument("Texto invalido.");
    }

    if (!(v[0] >= 'A' && v[0] <= 'Z')) {
        throw invalid_argument("Texto invalido.");
    }

    if (v[v.size() - 1] != '.') {
        throw invalid_argument("Texto invalido.");
    }

    for (size_t i = 0; i < v.size(); i++) {
        char c = v[i];

        if (!ehLetra(c) && !ehDigito(c) && c != ' ' && !ehPontuacao(c)) {
            throw invalid_argument("Texto invalido.");
        }

        if (ehPontuacao(c) && i + 1 < v.size() && ehPontuacao(v[i + 1])) {
            throw invalid_argument("Texto invalido.");
        }
    }
}

void Texto::setValor(const string& v) {
    validar(v);
    valor = v;
}

string Texto::getValor() const {
    return valor;
}

// ------------------------------------------------------------
// Dominio: Timestamp
// Regra: DIA-MES-ANO-HH:MM, com data valida (considera bissexto)=
// ------------------------------------------------------------

void Timestamp::validar(const string& v) {
    // 1. separar em 4 partes pelo hifen
    string partes[4];
    int n = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == '-') {
            n++;
            if (n > 3) {
                throw invalid_argument("Timestamp invalido.");
            }
        } else {
            partes[n] += v[i];
        }
    }
    if (n != 3) {
        throw invalid_argument("Timestamp invalido.");
    }

    // 2. dia
    if (partes[0].size() < 1 || partes[0].size() > 2) {
        throw invalid_argument("Timestamp invalido.");
    }
    int dia = paraInt(partes[0]);

    // 3. ano
    if (partes[2].size() != 4) {
        throw invalid_argument("Timestamp invalido.");
    }
    int ano = paraInt(partes[2]);
    if (ano < 2000 || ano > 2099) {
        throw invalid_argument("Timestamp invalido.");
    }

    // 4. mes (guarda a posicao 0 a 11)
    const string siglas[12] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
                               "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    int mes = -1;
    for (int i = 0; i < 12; i++) {
        if (partes[1] == siglas[i]) {
            mes = i;
        }
    }
    if (mes == -1) {
        throw invalid_argument("Timestamp invalido.");
    }

    // 5. dia valido para o mes (considera bissexto)
    int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 1 && ehBissexto(ano)) {
        diasNoMes[1] = 29;
    }
    if (dia < 1 || dia > diasNoMes[mes]) {
        throw invalid_argument("Timestamp invalido.");
    }

    // 6. horario HH:MM
    const string& h = partes[3];
    if (h.size() != 5 || h[2] != ':') {
        throw invalid_argument("Timestamp invalido.");
    }
    int hora = paraInt(h.substr(0, 2));
    int minuto = paraInt(h.substr(3, 2));
    if (hora > 23 || minuto > 59) {
        throw invalid_argument("Timestamp invalido.");
    }
}

void Timestamp::setValor(const string& v) {
    validar(v);
    valor = v;
}

string Timestamp::getValor() const {
    return valor;
}



// ============================================================
// DOMINIOS DA ENTIDADE QUADRO: Nome, Limite
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE CARTAO DE ATIVIDADE: Timestamp, Prioridade, Estado, Tamanho
// ============================================================
