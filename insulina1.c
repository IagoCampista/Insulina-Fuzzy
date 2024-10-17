#include <stdio.h>
#define QTD_REGRAS 13

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

double maior_3(double x1, double x2, double x3)
{
       double maior = x1;
       if (x2 > maior)
              maior = x2;
       if (x3 > maior)
              return x3;
       return maior;
}

double inv_baixa_insulina(double y)
{
       if (y == 0)
              return 0;
       return (-4 * y) + 4;
}

double inv_moderada_insulina(double y)
{
       if (y == 0)
              return 0;
       double x1, x2;
       x1 = (4 * y) + 2;
       x2 = (-4 * y) + 10;
       return (x1 + x2) / 2;
}

double inv_alta_insulina(double y)
{
       if (y == 0)
              return 0;
       return (4 * y) + 8;
}

int main()
{
       double glicose, taxa_glicose, carboidrato;
       double regras[QTD_REGRAS][2];

       printf("Digite os dados para Nivel de Glicose [0 ; 210]:  ");
       scanf("%lf", &glicose);
       printf("Taxa da Variacao do Nível de Glicose  [-3 ; 3]:  ");
       scanf("%lf", &taxa_glicose);
       printf("Quantidade de Carboidratos Ingeridos [0 ; 100]:  ");
       scanf("%lf", &carboidrato);

       printf("O nivel de glicose %lf tem as seguintes pertinencias:\n %lf - baixa \n %lf - normal \n %lf - alta\n\n", glicose, baixa(glicose), normal(glicose), alta(glicose));
       printf("O taxa de variacao de glicose %lf tem as seguintes pertinencias:\n %lf - decaindo: \n %lf - estavel \n %lf - aumentando \n\n", taxa_glicose, decaindo(taxa_glicose), estavel(taxa_glicose), aumentando(taxa_glicose));
       printf("O quantidade de carboidrato %lf tem as seguintes pertinencias:\n %lf - baixa \n %lf - moderada \n %lf - alta\n\n", carboidrato, pequena(carboidrato), media(carboidrato), grande(carboidrato));

       // Se o nível de glicose é Baixo E a variação é Decaindo E os carboidratos ingeridos são Pequena, ENTÃO a dose de insulina é Baixa.
       regras[0][0] = menor_3(baixa(glicose), decaindo(taxa_glicose), pequena(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[0][0], baixa(glicose), decaindo(taxa_glicose), pequena(carboidrato));

       //Se o nível de glicose é Normal E a variação é Estável E os carboidratos ingeridos são Grande, ENTÃO a dose de insulina é Moderada.
       regras[1][0] = menor_3(normal(glicose), estavel(taxa_glicose), grande(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[1][0], normal(glicose), estavel(taxa_glicose), grande(carboidrato));

       //Se o nível de glicose é Alto E a variação é Estável, ENTÃO a dose de insulina é Alta.
       regras[2][0] = menor_3(10, alta(glicose), estavel(taxa_glicose));
       printf("%lf - %d %lf %lf\n", regras[2][0], 10, alta(glicose), estavel(taxa_glicose));

       //Se o nível de glicose é Alto E a variação é Aumentando E os carboidratos ingeridos são Média, ENTÃO a dose de insulina é Alta.
       regras[3][0] = menor_3(alta(glicose), aumentando(taxa_glicose), media(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[3][0], alta(glicose), aumentando(taxa_glicose), media(carboidrato));

       //Se o nível de glicose é Normal E os carboidratos ingeridos são Média, ENTÃO a dose de insulina é Moderada.
       regras[4][0] = menor_3(10, normal(glicose), media(carboidrato));
       printf("%lf - %d %lf %lf\n", regras[4][0], 10, normal(glicose), media(carboidrato));

       //Se a variação é Aumentando E os carboidratos ingeridos são Grande, ENTÃO a dose de insulina é Alta.
       regras[5][0] = menor_3(10, aumentando(taxa_glicose), grande(carboidrato));
       printf("%lf - %d %lf %lf\n", regras[5][0], 10, aumentando(taxa_glicose), grande(carboidrato));

       //Se o nível de glicose é Baixo E a variação é Estável E os carboidratos ingeridos são Grande, ENTÃO a dose de insulina é Baixa.
       regras[6][0] = menor_3(baixa(glicose), estavel(taxa_glicose), grande(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[6][0], baixa(glicose), estavel(taxa_glicose), grande(carboidrato));

       //Se o nível de glicose é Normal E a variação é Aumentando E os carboidratos ingeridos são Pequena, ENTÃO a dose de insulina é Baixa.
       regras[7][0] = menor_3(normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[7][0], normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));

       //Se o nível de glicose é Alto E a variação é Decaindo E os carboidratos ingeridos são Grande, ENTÃO a dose de insulina é Moderada.
       regras[8][0] = menor_3(alta(glicose), decaindo(taxa_glicose), grande(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[8][0], alta(glicose), decaindo(taxa_glicose), grande(carboidrato));

       //Se o nível de glicose é Normal E a variação é Aumentando rapidamente E os carboidratos ingeridos são Pequena, ENTÃO a dose de insulina é Alta.
       regras[9][0] = menor_3(normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));
       printf("%lf - %lf %lf %lf\n", regras[9][0], normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));

       // Se Glicose é alta ou Variação da Glicose é aumentando, então Insulina é alta.
       regras[10][0] = maior_3(alta(glicose), aumentando(taxa_glicose), -1);
       printf("%lf - %lf %lf \n", regras[10][0], alta(glicose), aumentando(taxa_glicose));


       // Se Glicose é baixa ou Variação da Glicose é decaindo, então Insulina é baixa.
       regras[11][0] = maior_3(baixa(glicose), decaindo(taxa_glicose), -1);
       printf("%lf - %lf %lf \n", regras[11][0], baixa(glicose), decaindo(taxa_glicose));


       // Se (Glicose é normal e Variação da Glicose é aumentando) ou Ingestão de Carboidrato é pequena, então Insulina é moderada.
       regras[12][0] = maior_3((menor_3(normal(glicose), aumentando(taxa_glicose), 10)), pequena(carboidrato), -1);
       printf("%lf - %lf %lf %lf\n", regras[12][0], normal(glicose), aumentando(taxa_glicose), pequena(carboidrato));

       printf("\n\n");

       printf("aqui vai o final\n\n");

       regras[0][1] = inv_baixa_insulina(regras[0][0]);
       printf("%lf - %lf  - baixa \n", regras[0][0], regras[0][1]);

       regras[1][1] = inv_moderada_insulina(regras[1][0]);
       printf("%lf - %lf - moderada \n", regras[1][0], regras[1][1]);

       regras[2][1] = inv_alta_insulina(regras[2][0]);
       printf("%lf - %lf - alta\n", regras[2][0], regras[2][1]);

       regras[3][1] = inv_alta_insulina(regras[3][0]);
       printf("%lf - %lf - alta\n", regras[3][0], regras[3][1]);

       regras[4][1] = inv_moderada_insulina(regras[4][0]);
       printf("%lf - %lf - moderada\n", regras[4][0], regras[4][1]);

       regras[5][1] = inv_alta_insulina(regras[5][0]);
       printf("%lf - %lf - alta \n", regras[5][0], regras[5][1]);

       regras[6][1] = inv_baixa_insulina(regras[6][0]);
       printf("%lf - %lf - baixa\n", regras[6][0], regras[6][1]);

       regras[7][1] = inv_baixa_insulina(regras[7][0]);
       printf("%lf - %lf - baixa\n", regras[7][0], regras[7][1]);

       regras[8][1] = inv_moderada_insulina(regras[8][0]);
       printf("%lf - %lf - moderada\n", regras[8][0], regras[8][1]);

       regras[9][1] = inv_alta_insulina(regras[9][0]);
       printf("%lf - %lf - alta\n", regras[9][0], regras[9][1]);

       regras[10][1] = inv_alta_insulina(regras[10][0]);
       printf("%lf - %lf - alta\n", regras[10][0], regras[10][1]);

       regras[11][1] = inv_baixa_insulina(regras[11][0]);
       printf("%lf - %lf - baixa\n", regras[11][0], regras[11][1]);

       regras[12][1] = inv_moderada_insulina(regras[12][0]);
       printf("%lf - %lf - moderada\n\n\n", regras[12][0], regras[12][1]);

       double numerador = 0;
       double denominador = 0;
       double doses = 0;

       for (int i = 0; i < QTD_REGRAS; i++)
       {
              if (regras[i][0] != 0)
              {
                     numerador = numerador + (regras[i][0] * regras[i][1]);
                     denominador = denominador + regras[i][0];
              }
       }
       doses = (numerador / denominador);

       printf("\n\nDoses: %lf \n", doses);
}
