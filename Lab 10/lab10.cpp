#include <cstdlib>
#include <iostream>
#include "expression_tree.h"

using namespace std;


expression_tree build_expression_tree();
// return: expression tree

int main ()
{
  expression_tree t = build_expression_tree();
  int value = t.evaluate();
  cout << "value: " << value << endl;
  return EXIT_SUCCESS;
}

expression_tree build_expression_tree()
{
  expression_tree t1 ("1");
  expression_tree t2 ("2");
  expression_tree t3 ("3");
  expression_tree t4 ("4");
  expression_tree t5 ("5");
  expression_tree t6 ("*", t1, t2);
  expression_tree t7 ("+", t4, t5);
  expression_tree t8 ("*", t3, t7);
  expression_tree t9 ("+", t6, t8);
  return t9;
}
