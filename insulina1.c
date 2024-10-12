#include <stdio.h>

double baixa(double num)
{
       if (num >= 0 && num <= 50)
              return 1;
       if (num > 50 && num < 125)
              return ((125 - num) / 75);
       return 0;
}
double normal(double num)
{
       if (num > 50 && num < 100)
              return ((num - 50) / 50);
       if (num >= 100 && num <= 150)
              return 1;
       if (num > 150 && num < 200)
              return ((200 - num) / 50);
       // if ((num >= 0 && num <= 50) || (num >= 200))
       return 0;
}
double alta(double num)
{
       if (num > 125 && num < 200)
              return ((num - 125) / 75);
       if (num >= 200)
              return 1;
       // if (num <= 125)
       return 0;
}

double decaindo(double x)
{
       if (x > -3 && x <= 0)
              return (-x / 3);
       return 0;
}

double estavel(double x)
{
       if (x > -1 && x < 0)
              return x + 1;
       if (x >= 0 && x < 1)
              return 1 - x;
       return 0;
}

double aumentando(double x)
{
       if (x > 0 && x <= 3)
              return (x / 3);
       return 0;
}

double pequena(double x)
{
       if (x >= 0 && x <= 15)
              return 1;
       if (x > 15 && x < 30)
              return (30 - x) / 15;
       return 0;
}

double media(double x)
{
       if (x >= 20 && x < 50)
              return (x - 20) / 30;
       if (x >= 50 && x < 80)
              return (80 - x) / 30;
       return 0;
}

double grande(double x)
{
       if (x >= 70 && x < 85)
              return (x - 70) / 15;
       if (x >= 85 && x <= 100)
              return 1;
       return 0;
}

double menor_3(double x1, double x2, double x3)
{
       double menor = x1;
       if (x2 < menor)
              menor = x2;
       if (x3 < menor)
              return x3;
       return menor;
}
int main()
{
       double glicose, taxa_glicose, carboidrato;
       double regras[10][1];

       printf("%lf\n", menor_3(1, 0, 3));

       printf("Digite os dados para Nivel de Glicose [0 ; 210]:  ");
       scanf("%lf", &glicose);
       printf("Taxa da Variacao do Nível de Glicose  [-3 ; 3]:  ");
       scanf("%lf", &taxa_glicose);
       printf("Quantidade de Carboidratos Ingeridos [0 ; 100]:  ");
       scanf("%lf", &carboidrato);

       printf("O nivel de glicose %lf tem as seguintes pertinencias:\n %lf - baixa \n %lf - normal \n %lf - alta\n\n", glicose, baixa(glicose), normal(glicose), alta(glicose));
       printf("O taxa de variacao de glicose %lf tem as seguintes pertinencias:\n %lf - decaindo: \n %lf - estavel \n %lf - aumentando \n\n", taxa_glicose, decaindo(taxa_glicose), estavel(taxa_glicose), aumentando(taxa_glicose));
       printf("O quantidade de carboidrato %lf tem as seguintes pertinencias:\n %lf - baixa \n %lf - moderada \n %lf - alta\n\n", carboidrato, pequena(carboidrato), media(carboidrato), grande(carboidrato));

       // R1
       regras[0][0] = menor_3(baixa(glicose), decaindo(taxa_glicose), pequena(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[0][0], baixa(glicose), decaindo(taxa_glicose), pequena(carboidrato));
       regras[1][0] = menor_3(normal(glicose), estavel(taxa_glicose), grande(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[1][0], normal(glicose), estavel(taxa_glicose), grande(carboidrato));
       regras[2][0] = menor_3(10, alta(glicose), estavel(taxa_glicose));
       printf("%lf - %d %lf %lf\n", regras[2][0], 10, alta(glicose), estavel(taxa_glicose));
       regras[3][0] = menor_3(alta(glicose), aumentando(taxa_glicose), media(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[3][0], alta(glicose), aumentando(taxa_glicose), media(carboidrato));
       regras[4][0] = menor_3(10, normal(glicose), media(carboidrato));
       printf("%lf - %d %lf %lf\n", regras[4][0], 10, normal(glicose), media(carboidrato));
       regras[5][0] = menor_3(10, aumentando(taxa_glicose), grande(carboidrato));
       printf("%lf - %d %lf %lf\n", regras[5][0], 10, aumentando(taxa_glicose), grande(carboidrato));
       regras[6][0] = menor_3(baixa(glicose), estavel(taxa_glicose), grande(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[6][0], baixa(glicose), estavel(taxa_glicose), grande(carboidrato));
       regras[7][0] = menor_3(normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[7][0], normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));
       regras[8][0] = menor_3(alta(glicose), decaindo(taxa_glicose), grande(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[8][0], alta(glicose), decaindo(taxa_glicose), grande(carboidrato));
       regras[9][0] = menor_3(normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[9][0], normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));

       for (int i = 0; i < 10; i++)
       {
              printf("%lf \n", regras[i][0]);
       }
}
