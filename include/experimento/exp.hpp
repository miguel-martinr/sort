/**********************************************************************
* Project           : Sorting methods
*
* Class             : Experimento
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
* 20200415    miguel-martinr      1      Creado para Hash table
* 20200426    miguel-martinr      2      Adaptada para sorting methods (P5 AEDA)
**********************************************************************/
#pragma once
#include "Estadistica.hpp"
#include "../DNI.hpp"
#include "../sortMethods/sortMethods.hpp"

#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;



class exp {
 public:
   exp(int nPruebas, int size, float alpha, int mode);
   ~exp(void) {}

   int initBancos(void);


   int run(ostream& os = cout);

   ostream& print(ostream& os = cout);



 private:

   int nPruebas_;
   float alpha_;
   int mode_;
   vector<vector<DNI>> banco_;
   vector<Estadistica> est_;

};

exp::exp(int nPruebas, int size, float alpha, int mode) {
  nPruebas_ = nPruebas;
  alpha_ = alpha;
  mode_ = 1; //Estadístico
  est_.resize(5); // 0.insertion, 1.bubble, 2.heap, 3.quick, 4.shell
  banco_.resize(nPruebas_);
  for (auto &sec : banco_)
    sec.resize(size);
  initBancos();
}

int exp::initBancos (void) {
  srand(banco_[0][0]);
  for (int i = 1; i < banco_.size(); i++) {
    for (int j = 0; j < banco_[i].size(); j++)
      banco_[i][j] = DNI(rand() % 100000000);
    srand(banco_[i][banco_[i].size()-1]);
  }
  return 0;
}

int exp::run(ostream &os) {
  vector<vector<DNI>> bancoAux;

    //Insertion
    est_[0].reset();
    DNI::cmpCount_ = 0;
    bancoAux = banco_;
    for (int j = 0; j < bancoAux.size(); j++) {
      insertionSort(bancoAux[j], mode_);
      est_[0].update(DNI::cmpCount_);
    }

    //Bubble
    est_[1].reset();
    DNI::cmpCount_ = 0;
    bancoAux = banco_;
    for (int j = 0; j < bancoAux.size(); j++) {
      bubbleSort(bancoAux[j], mode_);
      est_[1].update(DNI::cmpCount_);
    }

    //heap
    est_[2].reset();
    DNI::cmpCount_ = 0;
    bancoAux = banco_;
    for (int j = 0; j < bancoAux.size(); j++) {
      heapSort(bancoAux[j], mode_);
      est_[2].update(DNI::cmpCount_);
    }

    //quick
    est_[3].reset();
    DNI::cmpCount_ = 0;
    bancoAux = banco_;
    for (int j = 0; j < bancoAux.size(); j++) {
      quickSort(bancoAux[j], 0, bancoAux[j].size()-1, mode_);
      est_[3].update(DNI::cmpCount_);
    }

    //shell
    est_[4].reset();
    DNI::cmpCount_ = 0;
    bancoAux = banco_;
    for (int j = 0; j < bancoAux.size(); j++) {
      shellSort(alpha_, bancoAux[j], mode_);
      est_[4].update(DNI::cmpCount_);
    }
    print(os);
  return 0;
}












ostream& exp::print(ostream& os) {
  os << "\n\n";
  os << "Número de pruebas (por algoritmo): " << nPruebas_
     << "\nTamaño de secuencia (por prueba): " << banco_[0].size() << endl;
  os << "\n                                     Número de comparaciones\n\n";
  os << "                         Mínimo"
     << "               Medio"
     << "               Máximo" << endl;
  os << ' ';
  os << '\n';
  est_[0].print(os,   "Inserción:   ");
  est_[1].print(os, "\nBubble:      ");
  est_[2].print(os, "\nHeap:        ");
  est_[3].print(os, "\nQuick:       ");
  stringstream shellRot;
  shellRot << "\nShell(alpha = " << alpha_ << "):     ";
  est_[4].print(os, shellRot.str());
  return os;
}
