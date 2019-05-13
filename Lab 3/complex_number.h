#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_N_

#include <iostream>

class complex_number
{
public:
  complex_number (double r = 0.0, double i = 0.0);
  // postcondition: complex with given components has been created
  double get_real_part () const;
  // returned: real part of complex number
  double get_imag_part () const;
  // returned: imaginary part of complex number
private:
  double real_part;
  double imag_part;
};


complex_number operator + (const complex_number& c1, const complex_number& c2);
// returned: sum of c1 and c2

complex_number operator - (const complex_number& c1, const complex_number& c2);
// returned: difference of c1 and c2

complex_number operator * (const complex_number& c1, const complex_number& c2);
// returned: product of c1 and c2

complex_number operator / (const complex_number& c1, const complex_number& c2);
// precondition: c2 is not the zero of complex numbers
// returned: quotient of c1 and c2

complex_number conjugate (const complex_number& c);
// returned: conjugate of c

double complex_modulus (const complex_number& c);
// returned: modulus of c

bool operator == (const complex_number& c1, const complex_number& c2);
// returned whether c1 and c2 are equal to each other

bool operator != (const complex_number& c1, const complex_number& c2);
// returned whether c1 and c2 are not equal to each other

std::ostream& operator << (std::ostream& output, const complex_number& c);
// postcondition: c has been put on the output stream output
// returned: modified output stream output

#endif