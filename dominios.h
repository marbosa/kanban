#ifndef KANBAN_DOMINIOS_H
#define KANBAN_DOMINIOS_H

#include <string>
#include <array>
#include <stdexcept>

using namespace std;

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
// Regra: 1 a 15 chars (letras e espacos; sem espacos nas pontas/duplos)
// ------------------------------------------------------------
class Nome {
    private:
        static constexpr int NOME_MIN = 1;
        static constexpr int NOME_MAX = 15;
        string nome;
        static void validar(const string& nome);
    public:
        void setNome(const string& nome);
        string getNome() const;
};

// ------------------------------------------------------------
// Dominio: Texto
// Regra: ate 30 chars; inicia com maiuscula, termina com ponto; sem pontuacao dupla
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
// Regra: DIA-MES-ANO-HH:MM (data e horario validos; considera bissexto)
// ------------------------------------------------------------
class Timestamp {
    private:
        string valor;
        void validar(const string&);
    public:
        void setValor(const string&);
        string getValor() const;
};

// ------------------------------------------------------------
// Dominio: Limite
// Regra: Valor inteiro no intervalo de 1 a 25
// ------------------------------------------------------------
class Limite {
    private:
        static constexpr int LIMITE_MIN = 1;
        static constexpr int LIMITE_MAX = 25;
        int valor = 1;
        static void validar(int valor);
    public:
        void setLimite(int valor);
        int getLimite() const;
};

// ------------------------------------------------------------
// Dominio: Prioridade
// Regra: Opcoes validas restritas a "ALTA", "MEDIA" ou "BAIXA"
// ------------------------------------------------------------
class Prioridade {
    private:
        inline static constexpr array<const char *, 3> OPCOES = { "ALTA", "MEDIA", "BAIXA" };
        string prioridade;
        static void validar(const string& prioridade);
    public:
        void setPrioridade(const string& prioridade);
        string getPrioridade() const;
};

// ------------------------------------------------------------
// Dominio: Estado
// Regra: Opcoes validas restritas a "A FAZER", "FAZENDO" ou "FEITO"
// ------------------------------------------------------------
class Estado {
private:
    inline static constexpr array<const char *, 3> OPCOES = { "A FAZER", "FAZENDO", "FEITO" };
    string estado;
    static void validar(const string& estado);
public:
    void setEstado(const string& estado);
    string getEstado() const;
};

// ------------------------------------------------------------
// Dominio: Tamanho
// Regra: Opcoes validas restritas a "GRANDE", "MEDIO" ou "PEQUENO"
// ------------------------------------------------------------
class Tamanho {
private:
    inline static constexpr array<const char *, 3> OPCOES = { "GRANDE", "MEDIO", "PEQUENO" };
    string tamanho;
    static void validar(const string& tamanho);
public:
    void setTamanho(const string& tamanho);
    string getTamanho() const;
};

#endif // KANBAN_DOMINIOS_H
