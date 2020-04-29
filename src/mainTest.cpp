/**********************************************************************
* Project           : Sorting Methods
*
* Function          : Programa para pruebas rápidas de los métodos
*                     bin/mainTest A B C
*                     A: método sleccionado, B: modo, C: alpha de shellSort
*                     B: 0->Demo, 1->Estadística
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200429
*
* References  :
*    https://campusvirtual.ull.es/1920/mod/resource/view.php?id=146970
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200429    miguel-martinr      1      ...
*
**********************************************************************/
#include "../include/sortMethods/sortMethods.hpp"
#include "../include/DNI.hpp"
#include "../include/experimento/exp.hpp"

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void unsort(vector<DNI> &myV, ifstream &myF) {
    for (auto &aux : myV) {
      int num;
      myF >> num;
      aux = DNI(num);
    }
    cout << endl;
    for (auto aux : myV)
      cout << aux << endl;
}


int main(int argc, char* argv[]) {
  vector<DNI> myV(5);
  ifstream myF("DNItests.txt", ios::in);
  int mode = stoi(argv[2]);

  switch (stoi(argv[1])) {

    case 1: { //Insertion Sort

      unsort(myV, myF),
      insertionSort(myV, mode);
      cout << endl << endl;
      for (auto aux : myV)
        cout << aux << endl;

      break;
    }

    case 2: { // Bubble sort
      unsort(myV, myF);
      bubbleSort(myV, mode);
      cout << endl << endl;
      for (auto aux : myV)
        cout << aux << endl;
      break;
    }

    case 3: { // Heapsort
      unsort(myV, myF);
      heapSort(myV, mode);
      cout << endl << endl;
      for (auto aux : myV)
        cout << aux << endl;
      break;
    }

    case 4: { //quickSort
      unsort(myV, myF);
      quickSort(myV, 0, myV.size()-1, mode);
      cout << endl << endl;
      for (auto aux : myV)
        cout << aux << endl;
      break;
    }

    case 5: { // shellSort
      unsort(myV, myF);
      shellSort(stof(argv[3]), myV, mode);
      cout << endl << endl;
      for (auto aux : myV)
        cout << aux << endl;
      break;
    }
    default:
      break;
  }

  return 0;
}
