#ifndef KANBAN_DOMINIOS_H
#define KANBAN_DOMINIOS_H

#include <string>
#include <array>

using namespace std;

// ============================================================
// DOMINIOS DA ENTIDADE PESSOA: Email, Senha, Papel
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE PROJETO: Texto, Identificador
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE QUADRO: Nome, Limite
// ============================================================
class Limite {
    private:
        static constexpr int LIMITE_MIN = 1;
        static constexpr int LIMITE_MAX = 25;
        int valor = 1;
        static void validar(int valor) ;
    public:
        void setLimite(int valor);
        int getLimite() const;
};

class Nome {
    private:
        static constexpr int NOME_MIN = 1;
        static constexpr int NOME_MAX = 15;
        string nome;
        static void validar(const string& nome) ;
    public:
        void setNome(const string& nome);
        string getNome() const;
};

// ============================================================
// DOMINIOS DA ENTIDADE CARTAO DE ATIVIDADE: Timestamp, Prioridade, Estado, Tamanho
// ============================================================
class Prioridade {
    private:
        inline static constexpr array<const char *, 3> OPCOES = { "ALTA", "MEDIA", "BAIXA" };
        string prioridade;
        static void validar(const string& prioridade) ;
    public:
        void setPrioridade(const string& prioridade);
        string getPrioridade() const;
};

class Estado {
private:
    inline static constexpr array<const char *, 3> OPCOES = { "A FAZER", "FAZENDO", "FEITO" };
    string estado;
    static void validar(const string& estado) ;
public:
    void setEstado(const string& estado);
    string getEstado() const;
};

class Tamanho {
private:
    inline static constexpr array<const char *, 3> OPCOES = { "GRANDE", "MEDIO", "PEQUENO" };
    string tamanho;
    static void validar(const string& tamanho) ;
public:
    void setTamanho(const string& tamanho);
    string getTamanho() const;
};

#endif //KANBAN_DOMINIOS_H
