#include <stdio.h>
#include "cs1300bmp.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Filter.h"

using namespace std;

#include "rdtsc.h"

//
// Forward declare the functions
//
Filter * readFilter(string filename);
double applyFilter(Filter *filter, cs1300bmp *input, cs1300bmp *output);

int
main(int argc, char **argv)
{

  if ( argc < 2) {
    fprintf(stderr,"Usage: %s filter inputfile1 inputfile2 .... \n", argv[0]);
  }

  //
  // Convert to C++ strings to simplify manipulation
  //
  string filtername = argv[1];

  //
  // remove any ".filter" in the filtername
  //
  string filterOutputName = filtername;
  string::size_type loc = filterOutputName.find(".filter");
  if (loc != string::npos) {
    //
    // Remove the ".filter" name, which should occur on all the provided filters
    //
    filterOutputName = filtername.substr(0, loc);
  }

  Filter *filter = readFilter(filtername);

  double sum = 0.0;
  int samples = 0;

  for (int inNum = 2; inNum < argc; inNum++) {
    string inputFilename = argv[inNum];
    string outputFilename = "filtered-" + filterOutputName + "-" + inputFilename;
    struct cs1300bmp *input = new struct cs1300bmp;
    struct cs1300bmp *output = new struct cs1300bmp;
    int ok = cs1300bmp_readfile( (char *) inputFilename.c_str(), input);

    if ( ok ) {
      double sample = applyFilter(filter, input, output);
      sum += sample;
      samples++;
      cs1300bmp_writefile((char *) outputFilename.c_str(), output);
    }
    delete input;
    delete output;
  }
  fprintf(stdout, "Average cycles per sample is %f\n", sum / samples);

}

class Filter *
readFilter(string filename)
{
  ifstream input(filename.c_str());

  if ( ! input.bad() ) {
    int size = 0;
    input >> size;
    Filter *filter = new Filter(size);
    int div;
    input >> div;
    filter -> setDivisor(div);
    for (int i=0; i < size; i++) {
      for (int j=0; j < size; j++) {
	int value;
	input >> value;
	filter -> set(i,j,value);
      }
    }
    return filter;
  } else {
    cerr << "Bad input in readFilter:" << filename << endl;
    exit(-1);
  }
}


double
applyFilter(class Filter *filter, cs1300bmp *input, cs1300bmp *output)
{

  long long cycStart, cycStop;

  cycStart = rdtscll();
    
    int inputWidth = input -> width;
    int inputHeight = input -> height;
    int filterDevisor = filter -> getDivisor();
    int traversalHeight = inputHeight - 1;
    int traversalWidth = inputWidth - 1;

  output -> width = inputWidth;
  output -> height = inputHeight;
    
    int dataFilter[9] = {
        filter->get(0,0), filter->get(0,1), filter->get(0,2),
        filter->get(1,0), filter->get(1,1), filter->get(1,2),
        filter->get(2,0), filter->get(2,1), filter->get(2,2)
    };
    
    int varPRC;
    int varPRC2;
    double newVar = 1.0/filterDevisor;


  for(int p = 0; p < 3; p++) {
    for(int r = 1; r < (traversalHeight); r++) { //loop unrolling on row
      for(int c = 1; c < (traversalWidth); c = c+2) {

          int* valuePixel1 = &input->color[p][r-1][c-1];
          int* valuefilter1 = &dataFilter[0];
          int* valuePixel = &input->color[p][r-1][c];
          int* valuefilter = &dataFilter[0];
          varPRC = *(valuePixel1++)**(valuefilter1++);
          varPRC2 = *(valuePixel++)**(valuefilter++);
          varPRC += *(valuePixel1++)**(valuefilter1++);
          varPRC2 += *(valuePixel++)**(valuefilter++);
          varPRC += *(valuePixel1)**(valuefilter1++);
          varPRC2 += *(valuePixel)**(valuefilter++);
          valuePixel1 = &input->color[p][r][c-1];
          valuePixel = &input->color[p][r][c];
          varPRC += *(valuePixel1++)**(valuefilter1++);
          varPRC2 += *(valuePixel++)**(valuefilter++);
          varPRC += *(valuePixel1++)**(valuefilter1++);
          varPRC2 += *(valuePixel++)**(valuefilter++);
          varPRC += *(valuePixel1)**(valuefilter1++);
          varPRC2 += *(valuePixel)**(valuefilter++);
          valuePixel1 = &input->color[p][r+1][c-1];
          valuePixel = &input->color[p][r+1][c];
          varPRC += *(valuePixel1++)**(valuefilter1++);
          varPRC2 += *(valuePixel++)**(valuefilter++);
          varPRC += *(valuePixel1++)**(valuefilter1++);
          varPRC2 += *(valuePixel++)**(valuefilter++);
          varPRC += *(valuePixel1)**(valuefilter1);
          varPRC2 += *(valuePixel)**(valuefilter);
	varPRC = varPRC * newVar;

    varPRC = ( varPRC  > 255 ) ? 255 : varPRC;
	varPRC = ( varPRC  < 0 ) ? 0 : varPRC;
        
        
    output -> color[p][r][c] = varPRC; //update output value

	varPRC2 = varPRC2 * newVar;

    //more efficeient than if/else statement
    varPRC2 = ( varPRC2  > 255 ) ? 255 : varPRC2;
	varPRC2 = ( varPRC2  < 0 ) ? 0 : varPRC2;
        
        
    output -> color[p][r][c+1] = varPRC2; //update output value
      }
    }
  }

  cycStop = rdtscll();
  double diff = cycStop - cycStart;
  double diffPerPixel = diff / (inputWidth * inputHeight);
  fprintf(stderr, "Took %f cycles to process, or %f cycles per pixel\n",
	  diff, diff / (inputWidth * inputHeight));
  return diffPerPixel;
}