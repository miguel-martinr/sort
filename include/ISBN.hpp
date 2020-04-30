/**********************************************************************
* Project           : Sorting methods
*
* Class             : ISBN (modificación)
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200430
*
* References  :
*    https://campusvirtual.ull.es/1920/pluginfile.php/209080/mod_resource/content/10/AEDA-pract04.pdf (Hash table)
*    https://campusvirtual.ull.es/1920/mod/resource/view.php?id=146970 (Sort methods)
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200430    miguel-martinr      1      ...
*
**********************************************************************/
#pragma once

#include <cstdlib>
#include <ctime>

class ISBN {
 public:

   ISBN(void);
   ISBN(unsigned long num);
   ~ISBN(void) {}

   static unsigned long cmpCount_;


   unsigned long getNum(void) const { return num_; }
   void setNum(unsigned long num) { num_ = num; }

   void operator=(const ISBN& A);
   bool operator==(const ISBN& A);
   bool operator<(const ISBN& A);
   bool operator>(const ISBN& A);

   operator unsigned long() const {
     return getNum();
   }


 private:
   unsigned long num_;
};
