#include "hw11.h"
//Modify this file
#ifdef TEST_MAIN

int main(int argc, char **argv){
  // check the arguments - please read readme about validity of arguments
  if (argc != 5){
    printf("Wrong arguments\n");
    return EXIT_FAILURE;
  }
  // check radius and epsilon values -  read readme for the validity of argument
  int radius = strtol(argv[3], NULL, 10);
  int epsilon = strtol(argv[4], NULL, 10);
  if (&radius == NULL || &epsilon == NULL){
    printf("Wrong inputs\n");
    return EXIT_FAILURE;
  }
  
  // open the BMP file
  BMPImage * image = BMP_Open(argv[1]);
  if (image == NULL){
    printf("Error opening BMP file");
    return EXIT_FAILURE;
  }
  // convert to gray scale
  BMPImage *grayimage = ImgToGray(image);
	// check for error in converting to gray scale
	if(grayimage == NULL){
	  //BMP_Free(image);
	  return EXIT_FAILURE;
	}
	
  // call adaptive threshold function
  BMPImage *adaptive = AdaptiveThresholding(grayimage, radius, epsilon);
  // check for errors after calling adaptive threshold
  if(adaptive == NULL){
     // BMP_Free(image);
    //  BMP_Free(grayimage);
      return EXIT_FAILURE;
  }
	
	// write the adaptive threshold image to file
	if (BMP_Write(argv[2], adaptive) == FALSE){
	  //BMP_Free(image);
	  //BMP_Free(grayimage);
	  //BMP_Free(adaptive);
	  return EXIT_FAILURE;
	}
	
	// free all the images
	BMP_Free(image);
	BMP_Free(grayimage);
	BMP_Free(adaptive);
	return EXIT_SUCCESS;
}

#endif
