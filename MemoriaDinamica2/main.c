#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int* pVector;
    int* aux;
    int i;

    pVector = (int*) malloc(sizeof(int)*TAM);

    if(pVector!=NULL)
    {
        for(i=0;i<TAM;i++)
        {
            *(pVector+i) = i+1;
        }

        for(i=0;i<TAM;i++)
        {
            printf("%d\n", *(pVector+i));
        }
        aux = (int*) realloc(pVector, sizeof(int)*(TAM*2));

        if(aux!=NULL)
        {
            pVector = aux;

            for(i=TAM;i<TAM*2;i++)
            {
                *(pVector+i) = i+1;
            }
            printf("Luego del realloc\n");
            for(i=0;i<TAM*2;i++)
            {
                printf("%d\n", *(pVector+i));
            }

            aux = (int*) realloc(pVector, sizeof(int)*4);
            if(aux!=NULL)
            {
                pVector=aux;
                printf("Luego del realloc por menos\n");

                for(i=0;i<TAM*2;i++)
                {
                    printf("%d\n", *(pVector+i));
                }
            }
        }
    }

    return 0;
}
