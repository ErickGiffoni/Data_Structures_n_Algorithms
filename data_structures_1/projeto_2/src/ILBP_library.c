#include "ILBP_library.h"

int s_function(int pixel, int avg_pixel){
  if(pixel - avg_pixel >= 0) return 1;
  else return 0;
}
