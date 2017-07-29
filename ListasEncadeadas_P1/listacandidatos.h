#include "Candidato.h"
#include "nocandidato.h"

class ListaCandidatos
{
public:
    NoCandidato *head;
    ListaCandidatos()
    {
        this->head =NULL;
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
    }
};
