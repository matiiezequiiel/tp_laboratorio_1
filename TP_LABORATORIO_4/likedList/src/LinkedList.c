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


}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{

}


void* ll_get(LinkedList* this, int index)
{

}


int ll_set(LinkedList* this, int index,void* pElement)
{


}


int ll_remove(LinkedList* this,int index)
{

}


int ll_clear(LinkedList* this)
{

}


int ll_deleteLinkedList(LinkedList* this)
{

}


int ll_indexOf(LinkedList* this, void* pElement)
{

}


int ll_isEmpty(LinkedList* this)
{

}


int ll_push(LinkedList* this, int index, void* pElement)
{

}


void* ll_pop(LinkedList* this,int index)
{

}


int ll_contains(LinkedList* this, void* pElement)
{

}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{

}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{

}


LinkedList* ll_clone(LinkedList* this)
{

}


int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{

}

