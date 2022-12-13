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

public class morphomath {

	public static void main(String[] args) {
		
		  int wi=320; //largeur
		  int he=240; //hauteur
		  CvCapture capture;
		  IplImage frame, grayimg, edge;
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
		    String fic="pieton.avi";//fic="video_intro.mpg";//
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

		   //traitement Morpho Math
		   grayimg=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		   edge=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		   cvCvtColor(frame,grayimg,CV_BGR2GRAY);// on travail sur des images NdG
     		   cvMorphologyEx(grayimg,edge,null,null,CV_MOP_TOPHAT,1); //src,dst,arg3 uniquement pour certaines operations, arg4 element structurant avec null = matrice 3*3 centree, tophat et iteration
     		//cvMorphologyEx(grayimg,edge,grayimg,null,CV_MOP_OPEN,1);
   		 //cvDilate(grayimg,grayimg,null,1); // argument identique excepte pas d'arg 3 et d'operations
     		//cvErode(grayimg,grayimg,null,1);
		     
		    cvShowImage("Video0",frame);
		    cvShowImage("Video",edge);
		    char c=(char) cvWaitKey(100);
	  	    if(c=='q') break;
			   
		  }

	
}	
	}