#include <estia-image.h>
#include <stddef.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */


pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){
    
    if((x>width))
    return NULL;

    if((y>height))
    return NULL;

    if(data==NULL)
    return NULL;

    return (pixelRGB *) &data[(y*width +x)*n];
    
}

void setPixel(unsigned char* data
                   , const unsigned int width
                   , const unsigned int height
                   , const unsigned int n
                   , const unsigned int x
                   , const unsigned int y 
                   , pixelRGB* pixel) {

    data[ (y * width + x)*n ] = pixel->R;
    data[ (y * width + x)*n + 1] = pixel->G;
    data[ (y * width + x)*n + 2] = pixel->B;
}
