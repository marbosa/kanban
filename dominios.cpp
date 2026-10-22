#include "dominios.h"
#include "utilitarios.h"
#include <stdexcept>
#include <string>

using namespace std;

// ------------------------------------------------------------
// Dominio: Identificador
// Regra: 6 caracteres (3 letras seguidas de 3 digitos)
// ------------------------------------------------------------
void Identificador::validar(const string& v) {
    if (v.size() != 6) {
        throw invalid_argument("Identificador invalido.");
    }
    for (int i = 0; i < 3; i++) {
        if (!ehLetra(v[i])) {
            throw invalid_argument("Identificador invalido.");
        }
    }
    for (int i = 3; i < 6; i++) {
        if (!ehDigito(v[i])) {
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
// Dominio: Texto
// Regra: ate 30 chars; inicia com maiuscula, termina com ponto; sem pontuacao dupla
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
// Regra: DIA-MES-ANO-HH:MM (data e horario validos; considera bissexto)
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

// ------------------------------------------------------------
// Dominio: Limite
// Regra: Valor inteiro no intervalo de 1 a 25
// ------------------------------------------------------------
void Limite::validar(const int valor) {
    if (valor < LIMITE_MIN || valor > LIMITE_MAX) {
        throw invalid_argument("Limite invalido!");
    }
}

void Limite::setLimite(int valor) {
    validar(valor);
    this->valor = valor;
}

int Limite::getLimite() const {
    return valor;
}

// ------------------------------------------------------------
// Dominio: Nome
// Regra: 1 a 15 chars (letras e espacos; sem espacos nas pontas/duplos)
// ------------------------------------------------------------
void Nome::validar(const string& nome) {
    const string CARACTERES_PERMITIDOS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";

    if (nome.size() < NOME_MIN || nome.size() > NOME_MAX) {
        throw invalid_argument("Nome invalido!");
    }

    if (nome.front() == ' ' || nome.back() == ' ') {
        throw invalid_argument("Nome invalido!");
    }

    for (size_t i = 0; i < nome.size(); i++) {
        if (CARACTERES_PERMITIDOS.find(nome[i]) == string::npos) {
            throw invalid_argument("Nome invalido!");
        }
        if (nome[i] == ' ' && i + 1 < nome.size() && nome[i + 1] == ' ') {
            throw invalid_argument("Nome invalido!");
        }
    }
}

void Nome::setNome(const string& nome) {
    validar(nome);
    this->nome = nome;
}

string Nome::getNome() const {
    return nome;
}

// ------------------------------------------------------------
// Dominio: Prioridade
// Regra: Opcoes validas restritas a "ALTA", "MEDIA" ou "BAIXA"
// ------------------------------------------------------------
void Prioridade::validar(const string& prioridade) {
    for (const char* OPCAO : OPCOES) {
        if (prioridade == OPCAO) {
            return;
        }
    }
    throw invalid_argument("Prioridade invalida!");
}

void Prioridade::setPrioridade(const string& prioridade) {
    validar(prioridade);
    this->prioridade = prioridade;
}

string Prioridade::getPrioridade() const {
    return prioridade;
}

// ------------------------------------------------------------
// Dominio: Estado
// Regra: Opcoes validas restritas a "A FAZER", "FAZENDO" ou "FEITO"
// ------------------------------------------------------------
void Estado::validar(const string& estado) {
    for (const char* OPCAO : OPCOES) {
        if (estado == OPCAO) {
            return;
        }
    }
    throw invalid_argument("Estado invalido!");
}

void Estado::setEstado(const string& estado) {
    validar(estado);
    this->estado = estado;
}

string Estado::getEstado() const {
    return estado;
}

// ------------------------------------------------------------
// Dominio: Tamanho
// Regra: Opcoes validas restritas a "GRANDE", "MEDIO" ou "PEQUENO"
// ------------------------------------------------------------
void Tamanho::validar(const string& tamanho) {
    for (const char* OPCAO : OPCOES) {
        if (tamanho == OPCAO) {
            return;
        }
    }
    throw invalid_argument("Tamanho invalido!");
}

void Tamanho::setTamanho(const string& tamanho) {
    validar(tamanho);
    this->tamanho = tamanho;
}

string Tamanho::getTamanho() const {
    return tamanho;
}