/*
 *  Quick Sort
 *  "Estratéria Dividir para Conquistar"
 * Chamamos um elemento de pivô e todos os elementos à esquerda dele devem ser
 * menores e os elementos à direita dele deve ser maiores.
 * Melhor caso e caso
 * médio: O(N log N)
 * Pior caso: O(N²), o pior caso do quickSort ocorre quando o
 * array já está ordenado, uma situação onde a complexidade é O(N) no insertion
 * sort
 */

int particiona(int* V, int inicio, int n) {}

void quickSort(int* V, int inicio, int fim) {
  int pivo;
  if (fim > inicio) {
    pivo = particiona(V, inicio, fim);
    quickSort(V, inicio, pivo - 1);
    quickSort(V, pivo + 1, fim);
  }
}