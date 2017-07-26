#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void cargar_datos(char Archiv);
int indice(int x , int y);
//float get_radio(int x0, int x1, int y0, int y1);
float radius(int posx,int posy, int *posicion);
int sampleo_mc(void);
int aleatorio_x();
int aleatorio_y();

int largo = 744;
int alto = 500;
int i ;
int j ;

int main(void)
{
	int *posicion = malloc((largo*alto)*sizeof(int));
	FILE *in;
	char mapa[20] = "map_data.txt";
	in = fopen(mapa,"r");
	for(j=0;j<alto;j++)
	{
		for(i=0;i<largo;i++)
		{
		fscanf(in,"%d\n",&posicion[indice(i,j)]);
		//printf("posicion %d\n",posicion[indice(i,j)]);
		}
	}

	int xa = aleatorio_x();
	int ya = aleatorio_y();
	float ra = radius(480,136,posicion);
	printf("ra = %f\n",ra);
	
	//printf("aleatorios = %d %d\n",x_a,y_a);

	//printf("posicion = %d\n",posicion[indice(217,236)]); //=0
	//printf("posicion = %d\n",posicion[indice(230,234)]); //=1
return 0;
}

int indice(int x, int y)
{
	if(x<0)
	{x= largo + x%largo;}
	else if(x>largo)
	{x=x%largo;}
	if(y<0)
	{y = alto + y%alto;}
	else if(y>alto)
	{y=y%largo;}

int ind = alto*x+y;

return ind;
}

int aleatorio_x()
{
	int x_alea = rand()% largo/5 ;
	return x_alea;
}
int aleatorio_y()
{
	int y_alea = rand()% alto/5 ;
	return y_alea;
}
float radius(int posx,int posy, int *posicion)
{
	int posix; 
	int posiy;
	if(posicion[indice(posx,posy)]== 1)
	{
	posix = aleatorio_x();
	posiy = aleatorio_y();
	printf("se fue a la mierda");
	}
	else
	{
	posix = posx;
	posiy = posy;
	printf("fueron los mismos");
	}
	
	float comp;
	float r_max;
	float r ;
	for(r = 1; r < alto/4 ; r++)
	{
		for(i=0;i<r;i++)
		{
			for(j = 0; j< r;j++)
			{
				if(((i*i)+(j*j))<r*r)
				{
					//if(posicion[indice(posix+i,posiy+j)]==0 && posicion[indice(posix-i,posiy-j)]==0 && posicion[indice(posix+i,posiy-j)]==0 && posicion[indice(posix-i,posiy+j)]==0)
					if(posicion[indice(posix+i,posiy)]==0 && posicion[indice(posix,posiy+j)]==0 && posicion[indice(posix-i,posiy)]==0 && posicion[indice(posix,posiy-j)]==0 && posicion[indice(posix+i,posiy+j)]==0 && posicion[indice(posix-i,posiy-j)]==0 && posicion[indice(posix+i,posiy-j)]==0 && posicion[indice(posix-i,posiy+j)]==0)
					{
						//if(posicion[indice(posix+i,posiy+j)]==0 && posicion[indice(posix-i,posiy-j)]==0 && posicion[indice(posix+i,posiy-j)]==0 && posicion[indice(posix-i,posiy+j)]==0)			{
					r_max = r;
					//	}
					
					}
					else
					{
					r_max = r;
					comp = r_max;
					break;
					}
				}
			if(comp == r_max){break;}
			}		
		if(comp == r_max){break;}
		}
	if(comp == r_max){break;}
	}
	return r_max;	

}















