#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef TEST_FUNCGIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return gray;
}

#endif

//Modify below this line and use code from HW10 for IMGTOGRAY()

#ifdef TEST_IMGTOGRAY

BMPImage * ImgToGray(BMPImage * image){

	int width = (image->header).width;
	int height = (image->header).height;
	
	// allocate space for the image
	// the image has the same size
	// therefore the header has to stay the same
	// check for memory allocation failure 

	BMPImage *gray_image = malloc(sizeof(BMPImage));
	if (gray_image == NULL)
	{
	  //fprintf(stderr, "malloc fail\n");
	  return NULL;
	}
	//gray_image can be the name of the new image memory allotment
	gray_image->header = image->header;
	
	//Assign the the imagesize as height * width
	(gray_image->header).imagesize = width * height * 3;
	
	gray_image->data = malloc(sizeof(unsigned char)*(gray_image->header).imagesize);
	//check for data allocation failure using :
	if (gray_image->data == NULL)
	{
	  //fprintf(stderr, "malloc fail\n");
	  return NULL;
	}
	
	int pixel=0;
	int gray_val;
	//Run loop for all pixels using height and width
	while(pixel < (gray_image->header).imagesize){
	//convert each pixel of all channels to gray using the given RGB2GRAY function
	    gray_val = RGB2Gray(image -> data[pixel+2],image -> data[pixel + 1],image -> data[pixel]);
	//assign values to all pixels of gray_image for each channel
	    gray_image->data[pixel+2] = gray_val;
	    gray_image->data[pixel+1] = gray_val;
	    gray_image->data[pixel] = gray_val;
	//pixel+=3 to move on to the next 3 channel combination
	    pixel += 3;
	}
	
	//return the result
	return gray_image;

}

#endif

//Write your own code for Adaptive Thresholding Function
#ifdef TEST_ADAPTIVETHRESHOLDING

BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
	// the image has the same size(height and width)
	// therefore the header has to stay the same
	BMPImage *adaptive = malloc(sizeof(BMPImage));
	if (adaptive == NULL)
	{
	  fprintf(stderr, "malloc fail\n");
	  return NULL;
	}
	
	adaptive->header = grayImage->header;
	// (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
	if ((adaptive->data = malloc(sizeof(unsigned char)*(adaptive->header).imagesize)) == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		free(adaptive);
		return NULL;
	}

	int pixel=0;
	int width = (adaptive->header).width;
	int height = (adaptive->header).height;
	//Run a nested loop for all elements using height and width
	for (int row = 0; row < height; row++){
	  for (int col = 0; col < width; col++){
        //Find the maximum of top row, bottom rpw, left column and right column using radius
	    //Calculate the avergage of all pixels
	    int toprow = MAX(0, row-radius);
	    int bottomrow = MIN(height-1, row+radius);
	    int leftcol = MAX(0, col-radius);
	    int rightcol = MIN(width-1, col+radius);
	    int datavalue = 0;
	    int counter = 0;
	    //Run loop from toprow to bottom row
	    for (int rows = toprow; rows <= bottomrow; rows++){
	  //Inside which run a loop from left column to right column
	      for (int cols = leftcol; cols <= rightcol; cols++){
		 //calculate the location of each pixel using (row2*width + col2)*3;
		  pixel = (rows * width + cols) * 3;
         	//add all data values at every location point in data
		  datavalue += grayImage->data[pixel];
		//keep a counter for averaging
		  counter ++;
	      }
	    }
	//Outside the second nested loop: 
	//calculate averge (using int)
	    int average = datavalue / counter;
	//check if average-epsilon is greater than grayImage->data[at that pixel point]
	    int centerpixel = (row * width + col) * 3;
	    
	    if ((average - epsilon) > grayImage->data[centerpixel]){
	//then assign adaptive thresholding image data as 0(black) for data value at pixel, pixel+1, pixel+2
	      adaptive->data[centerpixel+2] = 0;
	      adaptive->data[centerpixel+1] = 0;
	      adaptive->data[centerpixel] = 0;
        // else if average is lower then color shall be white(255) for data value at pixel, pixel+1, pixel+
	    }
	    else {
	      adaptive->data[centerpixel+2] = 255;
	      adaptive->data[centerpixel+1] = 255;
	      adaptive->data[centerpixel] = 255;
	    }
	  }
	}
	  
//return the image after adaptive thresholding
return adaptive;
}


#endif
