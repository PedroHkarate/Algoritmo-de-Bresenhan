#include <stdio.h>
#include <string.h>


int calc_coordenadas(int p_inicio[2], int p_fim[2], int x, int y, int dx, int dy)
{
    int d = (2 * dy) - dx;
    int delta_E = 2 * dy;
    int delta_NE = 2 * (dy - dx);
    printf("(%d,%d)\n", x, y);
    
    while(x != p_fim[0] && y != p_fim[1])
    {
        if (d > 0)
        {
            d = d + delta_NE;
            x+=1;
            y+=1;
        }
        else if (d < 0)
        {
            d = d + delta_E;
            x+=1;
        }
        else
        {
            printf("d = 0, escolha entre NE e E!\n");
            char *direcao;
            scanf("%s", direcao);

            if(!strcmp(direcao, "E")) {
                d = d + delta_E;
                x+=1;     
            } else {
                d = d + delta_NE;
                x+=1;
                y+=1;   
            }
        }
        printf("(%d,%d)\n", x, y);
    }
}

void entradas(int p_inicio[2], int p_fim[2], int i, int j)
{
    if (i == 2)
    {
        if (j == 2)
        {
            int dx = p_fim[0] - p_inicio[0];
            int dy = p_fim[1] - p_inicio[1];
            //printf("dx = %d | dy = %d\n", dx, dy);
            int x = p_inicio[0];
            int y = p_inicio[1];

            calc_coordenadas(p_inicio, p_fim, x, y, dx, dy);
            
            return;
        }
        scanf("%d", &p_fim[j]);
        entradas(p_inicio, p_fim, i, j+1);
    }
    else
    {
        scanf("%d", &p_inicio[i]);
        entradas(p_inicio, p_fim, i+1, j);
    }
}

int main() {

    int p_inicio[2];
    int p_fim[2];

    entradas(p_inicio, p_fim, 0, 0);
    
    return 0;
}