#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regularly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}


void dimension(char *source_path){
//Function to return dimension of the image

    int width, height;
    unsigned char *data;
    int channel_count; 

    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension : %d, %d\n",width, height ); 
    free_image_data(data);
}

void first_pixel(char *source_path){
//Function to return R,G,B component of the first pixel

    int width, height;
    unsigned char r,g,b;
    unsigned char *data;
    int channel_count; 

    read_image_data(source_path, &data, &width, &height, &channel_count);
    r = data[0];
    g = data[1];
    b = data[2]; 

    printf("first pixel : %d, %d, %d\n", r,g,b);
    free_image_data(data);
    }

void tenth_pixel(char *source_path){
//Function to return R,G,B component of the tenth pixel

    int width, height;
    unsigned char *data;
    int channel_count; 
    unsigned char r,g,b;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    r = data[(9*channel_count)+0];
    g = data[(9*channel_count)+1];
    b = data[(9*channel_count)+2]; 

    printf("tenth pixel : %d, %d, %d\n", r,g,b);
    free_image_data(data);
}

void second_line(char *source_path){
//Function to return R,G,B component of the first pixel of the second line

    int width, height;
    unsigned char *data;
    int channel_count; 
    unsigned char r,g,b;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    r = data[3*width];
    g = data[3*width+1];
    b = data[3*width+2]; 

    printf("second line : %d, %d, %d\n", r,g,b);
    free_image_data(data);

}

void print_pixel(char *source_path, int x, int y){
//Function to return R,G,B component of a pixel done with coordinate
    
    int width, height;
    unsigned char *data;
    int n; 
    unsigned char r,g,b;

    read_image_data(source_path, &data, &width, &height, &n);

    pixelRGB *pixel = get_pixel(data, width, height, n, x,  y );
    if(pixel==NULL)
    printf("pixel hors scope, utiliser dimension pour connaitre la taille\n");
    else{
    r = pixel->R;
    g = pixel->G;
    b = pixel->B;

    printf("print_pixel (%d,%d) : %d, %d, %d\n", x,y,r,g,b);
    }
    free_image_data(data);
}

void max_pixel(char *source_path){
//Function to find and return the max value of each component in an image

    int max = 0;
    int i,j,x,y;

    int width, height;
    unsigned char *data;
    int n; 
    pixelRGB *maxpixel, *curpixel;

    read_image_data(source_path, &data, &width, &height, &n);
    maxpixel = get_pixel(data, width, height, n, 0,0);
    x=0;
    y=0;

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            curpixel = get_pixel(data, width, height, n, j,  i );

            if(max<(curpixel->R+curpixel->B+curpixel->G)){
            max = (curpixel->R+curpixel->B+curpixel->G);
            maxpixel = curpixel;
            x = j;
            y = i;
            }

        }

    }
    printf("max_pixel (%d, %d) :%d, %d, %d\n", x,y,maxpixel->R,maxpixel->G,maxpixel->B);
    free_image_data(data);
}

void min_pixel(char *source_path){
//Function to find and return the min value of each component in an image

    int min = 3*255+1;
    int i,j,x,y;

    int width, height;
    unsigned char *data;
    int n; 
    pixelRGB *curpixel, *minpixel;

    read_image_data(source_path, &data, &width, &height, &n);
    minpixel = get_pixel(data, width, height, n, 0,0 );

    x=0;
    y=0;

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            curpixel = get_pixel(data, width, height, n, j,  i );

            if(min>(curpixel->R + curpixel->B + curpixel->G)){
                min = curpixel->R + curpixel->B + curpixel->G;
                minpixel = curpixel;
                x = j;
                y = i;
            }

        }

    }
    printf("min_pixel (%d, %d) :%d, %d, %d\n", x,y,minpixel->R,minpixel->G,minpixel->B);
    free_image_data(data);

}

void max_component(char *source_path, unsigned char component){
//Function to find and return the max of a component in an image done in argument

    int max = 0;
    int i,j,x,y;

    int width, height;
    unsigned char *data;
    int n; 
    pixelRGB *curpixel;

    read_image_data(source_path, &data, &width, &height, &n);
    x=0;
    y=0;

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            curpixel = get_pixel(data, width, height, n, j,  i );
            if(component == 'R')
            {
                if(max<curpixel->R){
                max = curpixel->R;
                x = j;
                y = i;
                }
            }
          if(component == 'G')
            {
                if(max<curpixel->G){
                max = curpixel->G;
                x = j;
                y = i;
                }
            }
            if(component == 'B')
            {
                if(max<curpixel->B){
                max = curpixel->B;
                x = j;
                y = i;
                }
            }
            

        }

    }
    
    printf("max_component [%c] (%d, %d) :%d\n",component, x,y,max);
    free_image_data(data);
    
}

void min_component(char *source_path, unsigned char component){
//Function to find and return the min of a component in an image done in argument

    int min = 256;
    int i,j,x,y;

    int width, height;
    unsigned char *data;
    int n; 
    pixelRGB *curpixel;

    read_image_data(source_path, &data, &width, &height, &n);
    x=0;
    y=0;

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            curpixel = get_pixel(data, width, height, n, j,  i );
            if(component == 'R')
            {
                if(min>curpixel->R){
                min = curpixel->R;
                x = j;
                y = i;
                }
            }
          if(component == 'G')
            {
                if(min>curpixel->G){
                min = curpixel->G;
                x = j;
                y = i;
                }
            }
            if(component == 'B')
            {
                if(min>curpixel->B){
                min = curpixel->B;
                x = j;
                y = i;
                }
            }
            

        }

    }
    
    printf("min_component [%c] (%d, %d) :%d\n",component, x,y,min);
    free_image_data(data);

}

void stat_report(char *source_path){
//Function to print a report with min, max, ...

FILE * statfile;
const char* filename = "stat_file.txt";
statfile = freopen(filename,"w",stdout);
max_pixel(source_path);
min_pixel(source_path);
max_component(source_path,'R');
max_component(source_path,'G');
max_component(source_path,'B');
min_component(source_path, 'R');
min_component(source_path, 'G');
min_component(source_path, 'B');

fclose(statfile);
}

void color_red(char *source_path){
//Function to keep only red component in an image

    int i,j;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";

    read_image_data(source_path, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width, height, channel_count, 0,0 );
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i );
            pixel->G = 0;
            pixel->B = 0;
        }
    }

    write_image_data(filename,data,width,height);
    free_image_data(data);

}

void color_blue(char *source_path){
//Function to keep only the blue component in an image

    int i,j;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";

    read_image_data(source_path, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width, height, channel_count, 0,0 );
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i );
            pixel->G = 0;
            pixel->R = 0;
        }
    }

    write_image_data(filename,data,width,height);
    free_image_data(data);

}

void color_green(char *source_path){
//Function to keep only the red component in an image

    int i,j;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";

    read_image_data(source_path, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width, height, channel_count, 0,0 );
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i );
            pixel->R = 0;
            pixel->B = 0;
        }
    }

    write_image_data(filename,data,width,height);
    free_image_data(data);

}

void color_gray(char *source_path){
//Function to transform image in gray 

    int i,j;
    unsigned char value;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i );
            value = (pixel->R + pixel->G + pixel->B)/3;
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
     write_image_data(filename,data,width,height);
     free_image_data(data);
}

void color_invert(char *source_path){
//Function to invert color in image 

     int i,j;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i ); 
            pixel->R = 255 - pixel->R;
            pixel->G = 255 - pixel->G;
            pixel->B = 255 - pixel->B;
        }
    }
     write_image_data(filename,data,width,height);
     free_image_data(data);
}

void color_gray_luminance(char *source_path){
//Function to change luminance

    int i,j;
    unsigned char value;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i );
            value = (0.21*pixel->R + 0.72*pixel->G + 0.07*pixel->B);
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
     write_image_data(filename,data,width,height);
     free_image_data(data);
}

unsigned char get_min(unsigned char a, unsigned char b) {

    unsigned char res;
    res = a>b?b:a;
    return res;
}

unsigned char get_max(unsigned char a, unsigned char b) {
    unsigned char res;
    res = a>b?a:b;
    return res;
}

void desaturate(char *source_path){
//Function to desaturate the image

    int i,j, a,b,c,tmp;
    unsigned char value;
    int min=0, max=256;

    int width, height;
    unsigned char *data;
    int channel_count; 
    pixelRGB *pixel;
    const char *filename = "image_out.bmp";
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel = get_pixel(data, width, height, channel_count, j,i );
            a = pixel->R;
            b = pixel->G;
            c = pixel->B;
            if(b<a)
            {
                tmp=b;
                b=a;
                a=tmp;
            }
            if(c<b)
            {
                tmp = c;
                c=b;
                b=tmp;
            }
            if(b<a)
            {
                tmp=b;
                b=a;
                a=tmp;
            }
            min = a;
            max = c;


            value = (min + max) /2;
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
     write_image_data(filename,data,width,height);
     free_image_data(data); 
}

void rotate_cw(char *source_path){
//Function to rotate image in clock-width 

    int width, height;
    unsigned char *data;
    int channel_count;
    int i,j;
    pixelRGB *src_pixel;
    pixelRGB *dst_pixel;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width*height*channel_count);

    const char *filename = "image_cw.bmp";
    
    
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            src_pixel = get_pixel(data,width,height,channel_count,j,i);
            dst_pixel = get_pixel(new_data,height,width,channel_count,height-1-i,j);
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }
    write_image_data(filename,new_data,height,width);
    free_image_data(data);
    free(new_data);

}

void rotate_acw(char *source_path){
//Function to rotate image in anti clock-width

    int width, height;
    unsigned char *data;
    int channel_count;
    int i,j;
    pixelRGB *src_pixel;
    pixelRGB *dst_pixel;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width*height*channel_count);

    const char *filename = "image_acw.bmp";
    
    
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            src_pixel = get_pixel(data,width,height,channel_count,j,i);
            dst_pixel = get_pixel(new_data,height,width,channel_count,i,width-1-j);
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }
    write_image_data(filename,new_data,height,width);
    free_image_data(data);
    free(new_data);
}

void mirror_horizontal(char *source_path){
//Function to apply horizontal mirror transformation

    int width, height;
    unsigned char *data;
    int channel_count;
    int i,j;
    pixelRGB *src_pixel;
    pixelRGB *dst_pixel;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width*height*channel_count);

    const char *filename = "image_mh.bmp";

     for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            src_pixel = get_pixel(data,width,height,channel_count,j,i);
            dst_pixel = get_pixel(new_data,width,height,channel_count,width-1-j,i);
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }

    write_image_data(filename,new_data,width,height);
    free_image_data(data);
    free(new_data);

}

void mirror_vertical(char *source_path){
//Function to apply vertical mirror transformation

    int width, height;
    unsigned char *data;
    int channel_count;
    int i,j;
    pixelRGB *src_pixel;
    pixelRGB *dst_pixel;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width*height*channel_count);

    const char *filename = "image_mv.bmp";

     for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            src_pixel = get_pixel(data,width,height,channel_count,j,i);
            dst_pixel = get_pixel(new_data,width,height,channel_count,j,height-1-i);
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }

    write_image_data(filename,new_data,width,height);
    free_image_data(data);
    free(new_data);

}

void mirror_total(char *source_path){
//Function to apply mirror transformation 

    int width, height;
    unsigned char *data;
    int channel_count;
    int i,j;
    pixelRGB *src_pixel;
    pixelRGB *int_pixel;
    pixelRGB *dst_pixel;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char *int_data = malloc(width*height*channel_count);
    unsigned char *new_data = malloc(width*height*channel_count);

    const char *filename = "image_mt.bmp";

     for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            src_pixel = get_pixel(data,width,height,channel_count,j,i);
            int_pixel = get_pixel(int_data,width,height,channel_count,width-1-j,i);
            int_pixel->R = src_pixel->R;
            int_pixel->G = src_pixel->G;
            int_pixel->B = src_pixel->B;
        }
    }

     for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            int_pixel = get_pixel(int_data,width,height,channel_count,j,i);
            dst_pixel = get_pixel(new_data,width,height,channel_count,j,height-1-i);
            dst_pixel->R = int_pixel->R;
            dst_pixel->G = int_pixel->G;
            dst_pixel->B = int_pixel->B;
        }
    }

    write_image_data(filename,new_data,width,height);
    free_image_data(data);
    free(new_data);
}

void scale_nearest(char *source_path, float scale){
//Function to resize the image

    const char *filename = "image_sn.bmp";

    int width, height;
    int new_width,new_height;
    unsigned char *data;
    int channel_count;
    int i,j;
    int x,y;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    new_height = height * scale;
    new_width = width * scale;

    pixelRGB *src_pixel;
    pixelRGB *dst_pixel;

    unsigned char *new_data = malloc(new_width*new_height*channel_count);

    
     for(i=0;i<new_height;i++)
    {
        for(j=0;j<new_width;j++)
        {
            x = (int)(floor(j/scale));
            y = (int)(floor(i/scale));
            src_pixel = get_pixel(data,width,height,channel_count,x,y);
            dst_pixel = get_pixel(new_data,new_width,new_height,channel_count,j,i);
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }


    write_image_data(filename,new_data,new_width,new_height);
    free_image_data(data);
    free_image_data(new_data);
    free(new_data);
}

void scale_bilinear(char *source_path, float scale){
//Function to resize image by bilinear transformation

    const char *filename = "image_sb.bmp";

    int width, height;
    int new_width,new_height;
    unsigned char *data;
    int channel_count;
    int i,j;
    double old_i, old_j;

    int x1,y1,x2,y2;
    pixelRGB *Q11, *Q12, *Q21, *Q22;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    new_height = height * scale;
    new_width = width * scale;

    unsigned char *new_data = malloc(new_width*new_height*channel_count);

    for(i=0;i<new_height;i++)
    {
        old_i = i / scale;

        for(j=0;j<new_width;j++)
        {
            old_j = j/scale;

            x1 = floor(old_i) < width-1?floor(old_i):width-1;
            y1 = floor(old_j) < height-1?floor(old_j):height-1;
            x2 = ceil(old_i) < width-1?ceil(old_i):width-1;
            y2 = ceil(old_j) < height-1?ceil(old_j):height-1;

            Q11 = get_pixel(data,width,height,channel_count,x1,y1);
            Q12 = get_pixel(data,width,height,channel_count,x2,y1);
            Q21 = get_pixel(data,width,height,channel_count,x1,y2);
            Q22 = get_pixel(data,width,height,channel_count,x2,y2);

           // Interpolating P1 and P2
            pixelRGB* P1 = (pixelRGB*)malloc(sizeof(pixelRGB));
            pixelRGB* P2 = (pixelRGB*)malloc(sizeof(pixelRGB));
            pixelRGB* P = (pixelRGB*)malloc(sizeof(pixelRGB));

            // Check otherwise scale=0.5 gives black image (same pixels)
            if ((x1 == x2) && (y1 == y2)) {
                setPixel(new_data, new_width, new_height, channel_count, i, j, get_pixel(data, width, height, channel_count, x1, y1));
                continue;
            }
            // check special cases
            // otherwise black pixels (and low luminosity)
            else if (x1 == x2) {
                P1 = Q11;
                P2 = Q21;

                // Interpolating P
                P->R = (y2 - old_j) * P1->R + (old_j - y1) * P2->R;
                P->G = (y2 - old_j) * P1->G + (old_j - y1) * P2->G;
                P->B = (y2 - old_j) * P1->B + (old_j - y1) * P2->B;
            }
            else if (y1 == y2){
                P1 = Q11;
                P2 = Q12;

                // Interpolating P
                P->R = (x2 - old_i) * P1->R + (old_i - x1) * P2->R;
                P->G = (x2 - old_i) * P1->G + (old_i - x1) * P2->G;
                P->B = (x2 - old_i) * P1->B + (old_i - x1) * P2->B;
            }
            else {
                // normal case
                P1->R = (x2 - old_i) * Q11->R + (old_i - x1) * Q12->R;
                P1->G = (x2 - old_i) * Q11->G + (old_i - x1) * Q12->G;
                P1->B = (x2 - old_i) * Q11->B + (old_i - x1) * Q12->B;

                P2->R = (x2 - old_i) * Q21->R + (old_i - x1) * Q22->R;
                P2->G = (x2 - old_i) * Q21->G + (old_i - x1) * Q22->G;
                P2->B = (x2 - old_i) * Q21->B + (old_i - x1) * Q22->B;

                // Interpolating P
                P->R = (y2 - old_j) * P1->R + (old_j - y1) * P2->R;
                P->G = (y2 - old_j) * P1->G + (old_j - y1) * P2->G;
                P->B = (y2 - old_j) * P1->B + (old_j - y1) * P2->B;
            }
           setPixel(new_data, new_width,new_height, channel_count, i, j, P);
        }
    }

    write_image_data(filename, new_data, new_width,new_height);
    free_image_data(data);
    free_image_data(new_data);
    free(new_data);

}


void scale_crop(char *source_path, int center_x, int center_y, int width, int height){
//Function to apply crop transformation 

    const char *filename = "image_crop.bmp";

    int old_width, old_height, w2,h2,x,y;
    w2 = width/2;
    h2 = height/2;

x= center_x;
y=center_y;
    unsigned char *data;
    int channel_count;
    int i,j;

    read_image_data(source_path, &data, &old_width, &old_height, &channel_count);
    unsigned char *new_data = malloc(width*height*channel_count);

    pixelRGB *src_pixel;
    pixelRGB *dst_pixel;

    if((x-w2)<0){
    x = w2;
    printf("X : %d\n",x);
    }
    
    if((x+w2)>old_width){
    x = old_width-w2;
    printf("X : %d\n",x);
    }
    
    if((y-h2)<0){
    y = h2;
    printf("Y : %d\n",y);
    }
    
    if((y+h2)>old_height){
    y = old_height-h2;
    printf("Y : %d\n",y);
    }
    

printf("center x : %d, center y : %d, width : %d, height : %d", x, y, width,height);
    for(i=y-h2;i<y+h2;i++)
    {
        for(j=x-w2;j<x+w2;j++)
        {
            src_pixel = get_pixel(data,old_width,old_height,channel_count,j,i);
            dst_pixel = get_pixel(new_data,width,height,channel_count,j-(x-w2),i-(y-h2));
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }


    write_image_data(filename, new_data, width, height);
    free_image_data(data);
    free_image_data(new_data);
    free(new_data);

}