#include <iostream>
#include <cstdlib>
#include "complex_number.h"
#include <cassert>
#include <float.h>

using namespace std;

int main()
{
  complex_number c1(2.3, 4.8);
  assert (c1.get_real_part() == 2.3);
  assert (c1.get_imag_part() == 4.8);

  complex_number c2 (2.6);
  assert (c2.get_real_part() == 2.6);
  assert (c2.get_imag_part() == 0.0);
  
  complex_number c3;
  assert (c3.get_real_part() == 0.0);
  assert (c3.get_imag_part() == 0.0);

  assert (conjugate(c1).get_real_part() == 2.3);
  assert (conjugate(c1).get_imag_part() == -4.8);

  assert (abs (complex_modulus (c1) - 5.322593353) < FLT_EPSILON);
  
  complex_number c4 (2.3, 4.8);
  assert (c1 == c4);

  assert (c1 != c2);

  complex_number c5 (1.3, -4.1);

  complex_number c6 = c4 + c5;
  assert (abs (c6.get_real_part() -  3.6) < FLT_EPSILON);
  assert (abs (c6.get_imag_part() - 0.7) < FLT_EPSILON);

  complex_number c7 = c4 - c5;
  assert (abs (c7.get_real_part() - 1.0) < FLT_EPSILON);
  assert (abs (c7.get_imag_part() - 8.9) < FLT_EPSILON);

  complex_number c8 = c4 * c5;
  assert (abs (c8.get_real_part() - 22.67) < FLT_EPSILON);
  assert (abs (c8.get_imag_part() + 3.19) < FLT_EPSILON);

  complex_number c9 = c4 / c5;
  assert (abs (c9.get_real_part() + 0.902162162) < FLT_EPSILON);
  assert (abs (c9.get_imag_part() - 0.847027027) < FLT_EPSILON);

  cout << "all tests passed - do end zone touchdown dance!" << endl;
  return EXIT_SUCCESS;
}