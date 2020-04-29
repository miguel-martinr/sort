/**********************************************************************
* Project           : Sorting Methods
*
* Function          : Quick Sort (logarítimica)
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
void quickSort(std::vector<Clave> &sec, int ini, int fin, int mode = 1) {
  int i = ini, f = fin;
  Clave p = sec[(i+f)/2];
  Clave aux;

  if (mode == 0) {
    std::cout << "Presione una tecla para continuar..." << std::endl;
    getchar();
    std::cout << "Pivote:" << p << ", i = " << i << ", f = " << f << std::endl;
    for (int k = 0; k < sec.size(); k++)
      if (k == i)
        std::cout << termcolor::blue << ' ' << sec[k] << termcolor::reset;
        else if (k == f)
        std::cout << termcolor::red << ' ' << sec[k] << termcolor::reset;
        else
        std::cout << ' ' << sec[k];

    std::cout << std::endl;
  }

  while (i <= f) {


    while (sec[i] < p) {
      i++;
      if (mode == 0) {
        getchar();
        std::cout << "Pivote" << p << ", i = " << i << ", f = " << f << std::endl;
        for (int k = 0; k < sec.size(); k++)
          if (k == i)
            std::cout << termcolor::blue << ' ' << sec[k] << termcolor::reset;
            else if (k == f)
            std::cout << termcolor::red << ' ' << sec[k] << termcolor::reset;
            else
            std::cout << ' ' << sec[k];
        std::cout << std::endl;
      }
    }

      while (sec[f] > p) {
        f--;
        if (mode == 0) {
          getchar();
          std::cout << "Pivote: " << p << ", i = " << i << ", f = " << f <<std::endl;
          for (int k = 0; k < sec.size(); k++)
            if (k == i)
              std::cout << termcolor::blue << ' ' << sec[k] << termcolor::reset;
              else if (k == f)
              std::cout << termcolor::red << ' ' << sec[k] << termcolor::reset;
              else
              std::cout << ' ' << sec[k];
          std::cout << std::endl;
        }
      }


      if (i <= f) {
        aux = sec[i];
        sec[i] = sec[f];
        sec[f] = aux;
        i++, f--;
        if (mode == 0) {
          getchar();
          std::cout << "Pivote: " << p << ", i = " << i << ", f = " << f << std::endl;
          for (int k = 0; k < sec.size(); k++)
            if (k == i)
              std::cout << termcolor::blue << ' ' << sec[k] << termcolor::reset;
              else if (k == f)
              std::cout << termcolor::red << ' ' << sec[k] << termcolor::reset;
              else
              std::cout << ' ' << sec[k];
          std::cout << std::endl;
        }
      }
  }
  if( ini < f)
      quickSort(sec,ini,f);
  if( i < fin )
      quickSort(sec,i,fin);

}
