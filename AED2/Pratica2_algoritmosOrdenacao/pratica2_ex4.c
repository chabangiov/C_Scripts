int particiona(int v[], int inicio, int fim) {
  int pivo = v[fim];
  int i = inicio - 1;
  int j, temp;
  for (j = inicio; j < fim; j++) {
    if (v[j] <= v[i]) { //
      i++;
      temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
  }
  temp = v[i + 1];
  v[i + 1] = v[fim];
  v[fim] = temp;
  return *v; //
}
void quickSort(int v[], int inicio, int fim) {
  if (inicio < fim) {
    int p = particiona(v, inicio, fim);
    quickSort(v, inicio, fim - 1); //
    quickSort(v, inicio + 1, fim); //
  }
}