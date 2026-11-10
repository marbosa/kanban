#include "apresentacao_pessoa.h"
#include <iostream>
#include <string>

using namespace std;

static string pedir(const string& rotulo) {
    string s;
    cout << rotulo << ": ";
    getline(cin, s);
    return s;
}

// ------------------------------------------------------------
// Autenticacao
// ------------------------------------------------------------
bool CntrApresentacaoAutenticacao::autenticar(Email* email, Papel* papel) {
    Email e;
    Senha s;
    try {
        e.setValor(pedir("Email"));
        s.setValor(pedir("Senha"));
    } catch (const invalid_argument&) {
        cout << "Dado em formato invalido." << endl;
        return false;
    }
    if (!cntrServico->autenticar(e, s, papel)) {
        cout << "Email ou senha incorretos." << endl;
        return false;
    }
    *email = e;
    return true;
}

// ------------------------------------------------------------
// Pessoa
// ------------------------------------------------------------
void CntrApresentacaoPessoa::cadastrar() {
    Pessoa p;
    Email e;
    Nome n;
    Senha s;
    Papel pa;
    try {
        e.setValor(pedir("Email"));
        n.setNome(pedir("Nome (ate 15, so letras)"));
        s.setValor(pedir("Senha (5 caracteres, letras e digitos)"));
        pa.setValor(pedir("Papel (GESTOR/DESENVOLVEDOR)"));
    } catch (const invalid_argument&) {
        cout << "Dado em formato invalido. Conta nao criada." << endl;
        return;
    }
    p.setEmail(e);
    p.setNome(n);
    p.setSenha(s);
    p.setPapel(pa);
    cout << (cntrServico->criar(p) ? "Conta criada." : "Ja existe pessoa com esse email.") << endl;
}

void CntrApresentacaoPessoa::ler() {
    Email e;
    Pessoa p;
    try {
        e.setValor(pedir("Email da pessoa"));
    } catch (const invalid_argument&) {
        cout << "Email invalido." << endl;
        return;
    }
    p.setEmail(e);
    if (!cntrServico->ler(&p)) {
        cout << "Pessoa nao encontrada." << endl;
        return;
    }
    cout << "Email: " << p.getEmail().getValor() << "\n"
         << "Nome: "  << p.getNome().getNome() << "\n"
         << "Senha: " << p.getSenha().getValor() << "\n"
         << "Papel: " << p.getPapel().getValor() << endl;
}

void CntrApresentacaoPessoa::atualizar(const Email& email) {
    Pessoa p;
    Nome n;
    Senha s;
    Papel pa;
    p.setEmail(email);  // email (chave primaria) nao e editavel
    if (!cntrServico->ler(&p)) {
        cout << "Pessoa nao encontrada." << endl;
        return;
    }
    try {
        n.setNome(pedir("Novo nome"));
        s.setValor(pedir("Nova senha"));
        pa.setValor(pedir("Novo papel"));
    } catch (const invalid_argument&) {
        cout << "Dado em formato invalido. Nada alterado." << endl;
        return;
    }
    p.setNome(n);
    p.setSenha(s);
    p.setPapel(pa);
    cout << (cntrServico->atualizar(p) ? "Atualizado." : "Falha ao atualizar.") << endl;
}

bool CntrApresentacaoPessoa::excluir(const Email& email) {
    if (cntrServico->excluir(email)) {
        cout << "Conta excluida." << endl;
        return true;
    }
    cout << "Nao foi possivel excluir (inexistente ou possui vinculos)." << endl;
    return false;
}

void CntrApresentacaoPessoa::listar() {
    list<Email> l;
    cntrServico->listar(&l);
    if (l.empty()) {
        cout << "Nenhuma pessoa cadastrada." << endl;
        return;
    }
    for (const Email& e : l) {
        cout << e.getValor() << endl;
    }
}

bool CntrApresentacaoPessoa::executar(const Email& email) {
    while (true) {
        cout << "\n--- PESSOA ---\n1 Ler pessoa\n2 Atualizar meus dados\n3 Excluir minha conta\n"
                "4 Listar pessoas\n0 Voltar\nOpcao: ";
        string op;
        getline(cin, op);
        if (op == "1") {
            ler();
        } else if (op == "2") {
            atualizar(email);
        } else if (op == "3") {
            if (excluir(email)) {
                return false;
            }
        } else if (op == "4") {
            listar();
        } else if (op == "0") {
            return true;
        } else {
            cout << "Opcao invalida." << endl;
        }
    }
}
