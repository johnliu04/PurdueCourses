#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
  if (argc != 3){
    printf("Wrong arguments\n");
    return EXIT_FAILURE;
  }
  // open the BMP file
  BMPImage *image = BMP_Open(argv[1]);
  if (image == NULL){
    return EXIT_FAILURE;
  }
  
  // convert to gray scale
	BMPImage *grayimage = ImgToGray(image);
	
	// check for error in converting to gray scale
	if(grayimage == NULL){
	  
	  return EXIT_FAILURE;
	}
	
	// write the gray image to file
	if (BMP_Write(argv[2], grayimage) == FALSE){
	  return EXIT_FAILURE;
	}
	
	// free all the images
	BMP_Free(image);
	BMP_Free(grayimage);
	
	return EXIT_SUCCESS;
}

#endif
