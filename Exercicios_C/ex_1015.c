#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double calcular_distancia(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
  // Declaração das variáveis
  double x1, y1, x2, y2, distancia;

  // Leitura dos pontos
  scanf("%lf %lf", &x1, &y1);
  scanf("%lf %lf", &x2, &y2);

  // Cálculo da distância
  distancia = calcular_distancia(x1, y1, x2, y2);

  // Impressão do resultado
  printf("%.4lf\n", distancia);
  return 0;
}