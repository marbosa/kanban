#ifndef KANBAN_DOMINIOS_H
#define KANBAN_DOMINIOS_H

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
        bool setLimite(int valor);
        int getLimite() const;
};

// ============================================================
// DOMINIOS DA ENTIDADE CARTAO DE ATIVIDADE: Timestamp, Prioridade, Estado, Tamanho
// ============================================================

#endif //KANBAN_DOMINIOS_H
