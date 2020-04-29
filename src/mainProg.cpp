/**********************************************************************
* Project           : Sorting methods
*
* File              : Main
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200415
*
* References  :
*    https://campusvirtual.ull.es/1920/mod/resource/view.php?id=146970
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200415    miguel-martinr      1      Para Hash table (P4 AEDA)
*
**********************************************************************/
#include "../include/sortMethods/sortMethods.hpp"
#include "../include/experimento/exp.hpp"
#include "../include/DNI.hpp"

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;


void demoThis(int size, int id) {
  vector<DNI> myV(size);
  float alpha = -1;
  srand(myV[0]);
  for (int i = 1; i < myV.size(); i++) {
    srand(myV[i-1]);
    myV[i] = rand() % 100000000;
  }
  switch (id) {
    case 1:
      cout << "InsertionSort " << endl << endl;
      insertionSort(myV, 0);
      break;

    case 2:
      cout << "BubbleSort " << endl << endl;
      bubbleSort(myV, 0);
      break;

    case 3:
      cout << "HeapSort " << endl << endl;
      heapSort(myV, 0);
      for (auto dni : myV)
        cout << dni << " ";
      cout << endl;
      break;

    case 4:
      cout << "QuickSort " << endl << endl;
      quickSort(myV, 0, myV.size()-1, 0);
      break;
    case 5:
      cout << "ShellSort " << endl << endl;
      while (alpha <= 0 || alpha >= 1) {
       cout << "Introduzca la constante de reducción alfa (0 < alfa < 1)>"; cin >> alpha;
      }
      shellSort(alpha, myV, 0);
      break;

    default:
      break;
  }

}

int main (int argc, char* argv[]) {

  char exit = 'n';
  while (exit != 'y') {
    int mode, size = -1;

    cout << "\n\nMétodos de Ordenación" << endl << endl;
    cout << "Seleccione un modo:" << endl
         << "  0. Demostración" << endl
         << "  1. Estadístico" << endl
         << ">"; cin >> mode;

    if (mode == 0) { //Demo
      cout << "\nModo Demostración" << endl << endl;
      while (size <= 0 || size > 25) {
        cout << "Tamaño de la secuencia a ordenar (máx 25) >"; cin >> size;
      }
      int meth = -1;
      while (meth <= 0 || meth > 5) {
        cout << "Seleccione un algoritmo:" << endl
             << "1. Inserción" << endl
             << "2. BubbleSort" << endl
             << "3. heapSort" << endl
             << "4. QuickSort" << endl
             << "5. ShellSort" << endl
             << ">"; cin >> meth;
      }
      demoThis(size, meth);
    } else {

      cout << "\nModo Estadístico" << endl << endl;
      int nPruebas = -1;
      while (nPruebas <= 0) {
        cout << "Introduzca el número de pruebas a ejecutar >"; cin >> nPruebas;
      }
      while (size <= 0) {
        cout << "Tamaño de la secuencia a ordenar >"; cin >> size;
      }
      float alpha = -1;
      while (alpha <= 0 || alpha >= 1) {
       cout << "Introduzca la constante de reducción alfa (0 < alfa < 1)>"; cin >> alpha;
      }
      exp myExp(nPruebas, size, alpha, 0);
      myExp.run(cout);
    }

    cout << "\n\nSalir? [y/n] >"; cin >> exit;
}

  return 0;
}
