#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/** \brief  OBTIENE UN NODO DE LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param index int INDICE DEL NODO A OBTENER
 * \return Node* RETORNA (NULL) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
                         (PELEMENT) SI FUNCIONO CORRECTAMENTE
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief AGREGA Y ENLAZA UN NUEVO NODO A LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACION DONDE SE AGREGARA EL NUEVO NODO
 * \param pElement void* PUNTERO AL ELEMENTO A SER CONTENIDO POR EL NUEVO NODO
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
                        ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* nuevaLinkedList=NULL;

    nuevaLinkedList=(LinkedList*)malloc(sizeof(LinkedList));

    if(nuevaLinkedList != NULL)
    {
        nuevaLinkedList->pFirstNode= NULL;
        nuevaLinkedList ->size = 0;
    }

    return nuevaLinkedList;

}


int ll_len(LinkedList* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        retorno=this->size;
    }

    return retorno;
}



static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;

    if( (this != NULL && ll_len(this)>0) && (nodeIndex>=0 && nodeIndex<ll_len(this)) )
    {

        if(nodeIndex == 0)
        {
            pNodo = this->pFirstNode;
        }
        else
        {
            pNodo = this->pFirstNode;
            for(int i=0;i<nodeIndex;i++)
            {
               pNodo=pNodo->pNextNode;
            }
        }

    }

    return pNodo;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node* pNuevoNodo=NULL;
    Node* pNodoAnterior=NULL;
    Node* pNodoSiguiente=NULL;
    int retorno=-1;

    if( this != NULL && nodeIndex>=0 && nodeIndex<=ll_len(this) )
    {

        pNuevoNodo=(Node*)malloc(sizeof(Node));
        pNuevoNodo->pElement=pElement;

        if(nodeIndex == 0)
        {
            pNodoAnterior=this->pFirstNode;
            this->pFirstNode=pNuevoNodo;
            pNuevoNodo->pNextNode=pNodoAnterior;
            retorno=0;
            this->size++;

        }
        else
        {
            pNodoAnterior=getNode(this,nodeIndex-1);
            pNodoSiguiente=getNode(this,nodeIndex+1);
            pNodoAnterior->pNextNode=pNuevoNodo;
            pNuevoNodo->pNextNode=pNodoSiguiente;
            retorno=0;
            this->size++;
        }

   }

    return retorno;

}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int retorno=-1;


    if(this != NULL )
    {
        addNode(this,ll_len(this),pElement);
        retorno=0;

    }
    return retorno;

}


void* ll_get(LinkedList* this, int index)
{
    Node* pNodo=NULL;
    void* returnAux=NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        pNodo=getNode(this,index);
        returnAux=pNodo->pElement;


    }
    return returnAux;


}


int ll_set(LinkedList* this, int index,void* pElement)
{
    Node* pNodo=NULL;
    int retorno=-1;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        pNodo=getNode(this,index);
        pNodo->pElement=pElement;
        retorno=0;

    }
    return retorno;


}


int ll_remove(LinkedList* this,int index)
{
    Node* pNodo=NULL;
    Node* pNodoAnterior=NULL;
    Node* pNodoSiguiente=NULL;
    int retorno=-1;

    if( this != NULL && index>=0 && index<ll_len(this) )
    {

        if(index == 0)
        {
            pNodo=this->pFirstNode;
            this->pFirstNode=pNodo->pNextNode;
            retorno=0;
            this->size--;

        }
        else
        {
            pNodoAnterior=getNode(this,index-1);
            pNodoSiguiente=getNode(this,index+1);
            pNodoAnterior->pNextNode=pNodoSiguiente;
            retorno=0;
            this->size--;
        }

   }

    return retorno;



}


int ll_clear(LinkedList* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        for(int i=0;i<ll_len(this);i++)
        {
            ll_remove(this,i);
        }
        retorno=0;
    }

    return retorno;

}


int ll_deleteLinkedList(LinkedList* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;

}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno=-1;
    Node* pNodo=NULL;

    if(this != NULL )
    {
        pNodo=this->pFirstNode;

        for(int i=0;i<ll_len(this);i++)
        {
            if(pNodo->pElement != pElement)
            {
                pNodo=pNodo->pNextNode;

            }
            else
            {
                retorno=i;
            }

        }

    }

    return retorno;

}


int ll_isEmpty(LinkedList* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        if(ll_len(this)==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;

}


int ll_push(LinkedList* this, int index, void* pElement)
{

    return addNode(this,index,pElement);

}


void* ll_pop(LinkedList* this,int index)
{
    void* pElement= NULL;
    Node* pNode=NULL;

    if( this != NULL && index>=0 && index<ll_len(this) )
    {
        pNode=getNode(this,index);
        pElement=pNode->pElement;
        ll_remove(this,index);

    }

    return pElement;

}


int ll_contains(LinkedList* this, void* pElement)
{

    int retorno=-1;
    Node* pNodo=NULL;

    if(this != NULL )
    {
        if(ll_len(this)==0)
        {
            retorno=0;

        }

        pNodo=this->pFirstNode;
        for(int i=0;i<ll_len(this);i++)
        {
            if(pNodo->pElement != pElement)
            {
                pNodo=pNodo->pNextNode;
                retorno=0;

            }
            else
            {
                retorno=1;
                break;

            }

        }

    }

    return retorno;


}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno=-1;
    Node* pNodoThis=NULL;
    Node* pNodoThis2=NULL;

    if(this != NULL && this2 != NULL)
    {
        if(ll_len(this) >= ll_len(this2) || ll_len(this)>0 || ll_len(this2)>0) //SI LA LISTA 2 ES MAYOR NO PUEDE ESTAR CONTENIDA TODA EN LA LISTA 1.
        {
            retorno=0;
        }

        pNodoThis2=this2->pFirstNode;
        for(int i=0;i<ll_len(this2);i++)
        {
            pNodoThis=this->pFirstNode;
            for(int j=0;j<ll_len(this);j++)
            {
                if(pNodoThis2->pElement != pNodoThis->pElement)
                {
                    pNodoThis=pNodoThis->pNextNode;
                }
                else
                {
                    retorno=1;
                    break;
                }
                retorno=0;

            }
            if(retorno==0)
            {
                break;
            }
            pNodoThis2=pNodoThis2->pNextNode;
        }


    }
    return retorno;

}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* pNuevall=NULL;
    Node* pAuxNodo=NULL;
    int j=0;
    void* auxElement=NULL;


    if(this != NULL && (from>=0 && from<ll_len(this)) && (to>= from && to<=ll_len(this)) )
    {
        pNuevall=ll_newLinkedList();

        for(int i=0;i<ll_len(this);i++)
        {
            pAuxNodo=getNode(this,i);
            auxElement=pAuxNodo->pElement;

            if(i==from || j<to)
            {
                addNode(pNuevall,j,auxElement);
                j++;
            }

        }

    }
    return pNuevall;

}


LinkedList* ll_clone(LinkedList* this)
{

}


int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{

}

