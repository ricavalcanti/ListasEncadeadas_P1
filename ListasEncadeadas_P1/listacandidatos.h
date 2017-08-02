#include <fstream>
#include <cstring>
#include <iostream>
#include "Candidato.h"
#include "nocandidato.h"

using namespace std;

class ListaCandidatos
{
public:
    NoCandidato *head=NULL;
    ListaCandidatos(){}
    ListaCandidatos(const string &nome_arq)
    {
        ifstream arq(nome_arq.c_str());
        string dados;

        arq >> dados;
        cout << "criacao da lista de candidatos de: " << dados << endl;
        while(getline(arq,dados))
        {
            if(dados != "")
            {
                Candidato *c = new Candidato(dados);
                adicioneComoHead(c);
            }
        }
    }

    bool estaVazia()
    {
        return this->head == NULL;
    }
    void adicioneComoHead(Candidato* c)
    {
        head = new NoCandidato(c,head);
    }
    int tamanho()
    {
        int tam = 0;

        NoCandidato *aux = head;
        while(aux != NULL)
        {
            tam++;
            aux = aux->next;

        }
        return tam;

    }

    string toString()
    {
        stringstream stream;
        NoCandidato *aux = this->head;
        if(!this->tamanho())
        {
            stream << "0";
        }
        else
        {
            stream << aux->toString();
        }

        return stream.str();
    }
    bool remove(string nome, string sobrenome)
    {
        NoCandidato *aux = head;
        NoCandidato *anterior;
        while(aux != NULL)
        {
            if(aux->conteudo->igual(nome,sobrenome))
            {
                if(aux == head)
                {
                    head = aux->next;
                    delete aux;
                    return true;
                }
                anterior->next = aux->next;
                delete aux;
                return true;
            }
            anterior = aux;
            aux = aux->next;
        }
        return false;
    }
};
