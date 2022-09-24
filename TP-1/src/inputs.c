#include "inputs.h"

int getInt(char mensaje[])
{
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    return entero;
}
