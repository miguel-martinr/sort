/**********************************************************************
* Project           : Sorting Methods
*
* Function          : Bubble Sort (intercambio, cuadrática)
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
void bubbleSort(std::vector<Clave> &sec, int mode = 1){
  Clave aux;
  int j;
  for (int i = 1; i < sec.size(); i++) {
    for (j = sec.size() -1; j >= i; j--) {

      switch (mode) {
        case 0: {
          std::cout << std::endl << "position: (" << j << ',' << j-1 << ") ";
          for (int k = 0; k < sec.size(); k++)
            if ((k == j) || (k == j-1))
              std::cout << termcolor::red << ' ' << sec[k] << termcolor::reset;
              else
              std::cout << ' ' << sec[k];
          break;

        default:
          break;
        }

        std::cout << std::endl;
      }

      if (sec[j] < sec[j-1]) {
        aux = sec[j-1];
        sec[j-1] = sec[j];
        sec[j] = aux;

        if (mode == 0) {
          std::cout << " Intercambio:";
          for (int k = 0; k < sec.size(); k++)
            if ((k == j) || (k == j+1))
              std::cout << termcolor::green << ' ' << sec[k] << termcolor::reset;
              else
              std::cout << ' ' << sec[k];
        }
      }
    }
  }
}
