/**********************************************************************
* Project           : Sorting Methods
*
* Function          : Insertion Sort (Inserción, cuadrática)
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
void insertionSort(std::vector<Clave> &sec, int mode = 1){
  Clave aux;
  int j;
  for (int i = 1; i < sec.size(); i++) {
    aux = sec[i];

    switch (mode) {

      case 0: { // Modo demostración
        std::cout << std::endl << "i = " << i << " ";
        for (int k = 0; k < sec.size(); k++)
          if (k < i)
            std::cout << termcolor::green << sec[k] << " " << termcolor::reset;
            else if (k == i)
            std::cout << termcolor::red << sec[k] << " " << termcolor::reset;
            else
            std::cout << " " << sec[k] << " ";
        break;
      }

      default: {
        break;
      }
    }

    j = i -1;

    while ( (j >= 0) && (aux < sec[j]) ) {
      sec[j+1] = sec[j];
      j--;
    }

    if (mode == 0)
      std::cout << " j = " << j+1;
    sec[j+1] = aux;

  }
}
