/**********************************************************************
* Project           : Sorting Methods
*
* Function          : Shell Sort (Ord por incrementos decrecientes)
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
void shellSort(float d, std::vector<Clave> &sec, int mode = 1) {
    Clave aux;
    int j;
    int it = 0;
    d = d * sec.size();
    while( d >= 1){
        d = d/2;
        for(int i = d; i < sec.size(); i++){
          aux = sec[i];
          j = i;
          it++;

          if (mode == 0){
            getchar();
            std::cout << "Iteración: " << it << std::endl;
            for(int k = 0 ; k < sec.size(); k++)
              if(k == j)
                std::cout << termcolor::red << sec[j] << ' ' << termcolor::reset;
                else if(k == (j-d))
                std::cout << termcolor::red << sec[j-d] << ' ' << termcolor::reset;
                else
                std::cout << sec[k] << ' ';
            std::cout << std::endl;
          }

          while((j >= d) && (aux < sec[j-d])){
            sec[j] = sec[j-d];
            j = j - d;
          }
          sec[j] = aux;
        }
    }
}
