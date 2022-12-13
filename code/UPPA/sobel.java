/**
import com.googlecode.javacv.*;
import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;

import com.googlecode.javacv.cpp.opencv_core.CvSize;
import com.googlecode.javacv.cpp.opencv_core.CvTermCriteria;
import com.googlecode.javacv.cpp.opencv_core.IplImage;
import com.googlecode.javacv.cpp.opencv_highgui.CvCapture;

public class sobel {

	public static void main(String[] args) {
		
		  int wi=320; //largeur
		  int he=240; //hauteur
		  CvCapture capture;
		  IplImage frame, grayimg, img2;
		  CvTermCriteria term=cvTermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS,20,.3);

		  
		  //CHOIX VIDEO SOURCE:
		  int choix=1; //(choix=0)=>camera SINON video
		  switch(choix) {
		   case 0:
		    capture=cvCreateCameraCapture(CV_CAP_ANY);//-1); //
		    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH,wi);
		    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT,he);
		   break;
		   default :
		    String rep="";
		    String fic="video_intro.mpg";
		    capture=cvCreateFileCapture(rep+fic);
		    CvSize dim=cvGetSize(cvQueryFrame(capture));
		    wi=dim.width(); he=dim.height(); //recuperation des dimensions
		   break;
		  }
		  
		  cvNamedWindow("Video0",1);
		  cvNamedWindow("Video",CV_WINDOW_AUTOSIZE);
		  
		  for(;;) {
		   frame=cvQueryFrame(capture);
		   if(frame == null) {
		    System.out.println("ERR=No video file");
		    break;
		   }

		   //traitement SOBEL
		   grayimg=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		   img2=cvCreateImage(cvSize(wi/2,he/2),IPL_DEPTH_8U,3);
		   cvCvtColor(frame,grayimg,CV_BGR2GRAY); //on travail sur des images NdG
		   cvPyrDown(frame,img2,CV_GAUSSIAN_5x5);//niveau 1 de la pyramide
		   cvSobel(img2,img2,1,1,5);//applique sobel sur le niveau 1 de la pyramide; 1 et 1 sont les ordres de derivations (de 0 a 2), 5 : aperture
		       
		   cvShowImage("Video2",img2);
		   cvShowImage("Video0",frame);
		   cvShowImage("Video",grayimg);
		   char c=(char) cvWaitKey(150);
		   if(c=='q') break;
			   
		  }

	
}	
	}