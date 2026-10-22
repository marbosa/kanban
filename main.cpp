#include <iostream>
#include "dominios.h"
#include "entidades.h"
using namespace std;
//main teste tem nada de significante,  so teste msm
int total = 0;
int passou = 0;

// Testa um dominio: tenta setValor e compara com o resultado esperado.
template <class T>
void testar(const string& entrada, bool esperado) {
    T d;
    bool aceitou = true;
    string valorGuardado;

    try {
        d.setValor(entrada);
        valorGuardado = d.getValor();
    } catch (invalid_argument&) {
        aceitou = false;
    }

    // Se aceitou, o get deve devolver exatamente o que foi atribuido.
    bool ok = (aceitou == esperado) && (!aceitou || valorGuardado == entrada);

    total++;
    if (ok) passou++;

    cout << (ok ? "OK     " : "FALHOU ")
         << "| \"" << entrada << "\"" << endl;
}

int main() {
    // ============================================================
    // DOMINIOS
    // ============================================================

    cout << "\n--- Identificador (3 letras + 3 digitos) ---" << endl;
    testar<Identificador>("abc123", true);
    testar<Identificador>("ABC999", true);
    testar<Identificador>("aBc000", true);
    testar<Identificador>("123abc", false);   // ordem invertida
    testar<Identificador>("abc12", false);    // curto
    testar<Identificador>("abc1234", false);  // longo
    testar<Identificador>("ab1234", false);   // so 2 letras
    testar<Identificador>("abcd12", false);   // 4 letras
    testar<Identificador>("abc12a", false);   // letra no fim
    testar<Identificador>("ab-123", false);   // simbolo
    testar<Identificador>("", false);

    cout << "\n--- Nome (ate 15, letras e espacos) ---" << endl;
    testar<Nome>("Maria", true);
    testar<Nome>("Maria Souza", true);
    testar<Nome>("a", true);
    testar<Nome>("Abcdefghijklmno", true);    // 15 letras
    testar<Nome>("Abcdefghijklmnop", false);  // 16 letras
    testar<Nome>(" Maria", false);            // comeca com espaco
    testar<Nome>("Maria ", false);            // termina com espaco
    testar<Nome>("Maria  Souza", false);      // dois espacos
    testar<Nome>("Maria3", false);            // digito
    testar<Nome>("Maria-Souza", false);       // hifen
    testar<Nome>("", false);

    cout << "\n--- Texto (ate 30, maiuscula no inicio, ponto no fim) ---" << endl;
    testar<Texto>("Ola.", true);
    testar<Texto>("A.", true);
    testar<Texto>("Ola, mundo.", true);
    testar<Texto>("Projeto 2.", true);
    testar<Texto>("Quem e voce? Eu sou Ana.", true);
    testar<Texto>("Abcdefghij Abcdefghij Abcdefg.", true);   // 30
    testar<Texto>("Abcdefghij Abcdefghij Abcdefgh.", false); // 31
    testar<Texto>("ola.", false);             // minuscula no inicio
    testar<Texto>("Ola", false);              // sem ponto final
    testar<Texto>("Ola,. mundo.", false);     // duas pontuacoes
    testar<Texto>("Ola!.", false);            // ! seguido de .
    testar<Texto>("Ola-mundo.", false);       // hifen
    testar<Texto>(".", false);                // nao comeca com maiuscula
    testar<Texto>("", false);

    cout << "\n--- Timestamp (DIA-MES-ANO-HH:MM) ---" << endl;
    testar<Timestamp>("15-JAN-2026-23:59", true);
    testar<Timestamp>("5-JAN-2026-08:00", true);      // dia com 1 digito
    testar<Timestamp>("29-FEV-2024-10:30", true);     // bissexto
    testar<Timestamp>("29-FEV-2000-10:30", true);     // 2000 e bissexto
    testar<Timestamp>("01-JAN-2000-00:00", true);     // limite inferior
    testar<Timestamp>("31-DEZ-2099-23:59", true);     // limite superior
    testar<Timestamp>("30-ABR-2026-12:00", true);
    testar<Timestamp>("29-FEV-2023-10:30", false);    // nao bissexto
    testar<Timestamp>("29-FEV-2100-10:30", false);    // ano fora
    testar<Timestamp>("31-ABR-2024-10:30", false);    // abril tem 30
    testar<Timestamp>("32-JAN-2026-10:30", false);    // dia 32
    testar<Timestamp>("00-JAN-2026-10:30", false);    // dia 0
    testar<Timestamp>("15-XYZ-2026-10:30", false);    // mes invalido
    testar<Timestamp>("15-jan-2026-10:30", false);    // mes minusculo
    testar<Timestamp>("15-JAN-1999-10:30", false);    // ano < 2000
    testar<Timestamp>("15-JAN-2100-10:30", false);    // ano > 2099
    testar<Timestamp>("15-JAN-26-10:30", false);      // ano com 2 digitos
    testar<Timestamp>("15-JAN-2026-24:00", false);    // hora 24
    testar<Timestamp>("15-JAN-2026-10:60", false);    // minuto 60
    testar<Timestamp>("15-JAN-2026-1:30", false);     // horario mal formado
    testar<Timestamp>("15-JAN-2026-10-30", false);    // hifen no lugar de :
    testar<Timestamp>("15-JAN-2026", false);          // sem horario
    testar<Timestamp>("15-JAN-2026-10:30-X", false);  // parte extra
    testar<Timestamp>("", false);

    // ============================================================
    // ENTIDADE PROJETO
    // ============================================================

    cout << "\n--- Projeto ---" << endl;

    Identificador id;
    id.setValor("abc123");

    Nome n;
    n.setValor("Meu Projeto");

    Texto d;
    d.setValor("Descricao do projeto.");

    Timestamp ini, fim;
    ini.setValor("01-JAN-2026-08:00");
    fim.setValor("31-DEZ-2026-18:00");

    Projeto p;
    p.setIdentificador(id);
    p.setNome(n);
    p.setDescricao(d);
    p.setInicio(ini);
    p.setTermino(fim);

    // Compara cada get com o valor esperado.
    struct Caso { string rotulo; string obtido; string esperado; };
    Caso casos[5] = {
        {"identificador", p.getIdentificador().getValor(), "abc123"},
        {"nome",          p.getNome().getValor(),          "Meu Projeto"},
        {"descricao",     p.getDescricao().getValor(),     "Descricao do projeto."},
        {"inicio",        p.getInicio().getValor(),        "01-JAN-2026-08:00"},
        {"termino",       p.getTermino().getValor(),       "31-DEZ-2026-18:00"}
    };

    for (int i = 0; i < 5; i++) {
        bool ok = (casos[i].obtido == casos[i].esperado);
        total++;
        if (ok) passou++;
        cout << (ok ? "OK     " : "FALHOU ")
             << "| " << casos[i].rotulo << " = " << casos[i].obtido << endl;
    }

    // Alterar um atributo nao pode afetar os outros.
    Timestamp novoFim;
    novoFim.setValor("15-JUN-2027-12:00");
    p.setTermino(novoFim);

    bool inicioIntacto = (p.getInicio().getValor() == "01-JAN-2026-08:00");
    bool terminoMudou  = (p.getTermino().getValor() == "15-JUN-2027-12:00");
    total += 2;
    if (inicioIntacto) passou++;
    if (terminoMudou) passou++;
    cout << (inicioIntacto ? "OK     " : "FALHOU ")
         << "| setTermino nao altera inicio" << endl;
    cout << (terminoMudou ? "OK     " : "FALHOU ")
         << "| setTermino altera termino" << endl;

    // ============================================================
    // RESUMO
    // ============================================================
    cout << "\n==============================" << endl;
    cout << "Passou " << passou << " de " << total << " testes." << endl;
    if (passou == total) {
        cout << "Tudo certo!" << endl;
    } else {
        cout << "Ha testes falhando, procure as linhas FALHOU." << endl;
    }

    return 0;
}