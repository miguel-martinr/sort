/**********************************************************************
* Project           : Sorting Methods
*
* Function          : Heap Sort (montículos, logarítmica)
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
#pragma once

#include "../termcolor.hpp"

#include <iostream>
#include <vector>

// mode == 0 -> Demostración
// mode == 1 -> Estadística

//extern int mode;

template <class Clave>
void heapBaja(int i, std::vector<Clave> &sec, int n, int mode) {
  int larg = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  switch (mode) {
    case 0: { // Demo
      std::cout << "Presione una tecla para continuar..." << std::endl;
      getchar();
      for (int k = 0; k < n; k++) {
        if (k == larg)
          std::cout << termcolor::red << sec[k] << ' ' << termcolor::reset;
          else if(k == left)
          std::cout << termcolor::blue << sec[k] << ' ' << termcolor::reset;
          else if (k == right)
          std::cout << termcolor::yellow << sec[k] << ' ' << termcolor::reset;
          else
          std::cout << sec[k] << ' ';
      }
      std::cout << std::endl;
      break;
    }

    default:
      break;
  }

  if (left < n && sec[left] > sec[larg])
    larg = left;


  if (right < n && sec[right] > sec[larg])
    larg = right;

  if (larg != i) {
    Clave x = sec[i];
    sec[i] = sec[larg];
    sec[larg] = x;
    heapBaja(larg,sec, n, mode);
  }
}

template <class Clave>
void heapSort(std::vector<Clave> &sec, int mode = 1){
  for (int i = (sec.size()/2) - 1; i >= 0; i--)
    heapBaja(i,sec, sec.size(), mode);
  for (int i = sec.size()-1; i >= 0; i--) {
    Clave aux = sec[0];
    sec[0] = sec[i];
    sec[i] = aux;
    heapBaja(0,sec,i, mode);
  }
}
