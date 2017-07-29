#include "Candidato.h"
#include "nocandidato.h"

class ListaCandidatos
{
public:
    NoCandidato *head;

    ListaCandidatos()
    {
        this->head = NULL;
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
};
