#include <iostream>
#include <fstream>
#include <opencl/haval.h>
#include <opencl/encoder.h>
#include <opencl/filters.h>

int main(int argc, char* argv[])
   {
   if(argc < 2)
      {
      std::cout << "Usage: haval <filenames>" << std::endl;
      return 1;
      }

   OpenCL::Pipe pipe(new OpenCL::HashFilter<OpenCL::HAVAL_160>,
                     new OpenCL::HexEncoder);

   for(int j = 1; argv[j] != 0; j++)
      {
      std::ifstream file(argv[j]);
      if(!file)
         {
         std::cout << "ERROR: could not open " << argv[j] << std::endl;
         continue;
         }
      file >> pipe;
      file.close();
      pipe.close();
      std::cout << pipe << "  " << argv[j] << std::endl;
      }
   return 0;
   }

