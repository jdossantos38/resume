/**
import com.googlecode.javacv.*;
import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;

public class cany {

	public static void main(String[] args) {
		  int wi=320; //largeur
		  int he=240; //hauteur
		  CvCapture capture;
		  IplImage frame, grayimg;
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

		   //traitement CANY
		   grayimg=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		   cvCvtColor(frame,grayimg,CV_BGR2GRAY);//on travaille sur des images NdG
		   cvSetImageROI(grayimg, cvRect(90,40,120,100));//selectionne la region d'interet suivant un carre positionne a x=90 y=40 et de taille 120*100
		   cvCanny(grayimg,grayimg,100,100,3); //60,80,3);//NB:on peut avoir E=S; il applique canny avec seuil low et high a 100 et aperture par defaut a 3 
		   cvResetImageROI(grayimg);//il est dit qu'il faut reset la ROI a la fin
		     
		   cvShowImage("Video0",frame);
		   cvShowImage("Video",grayimg);
		   char c=(char) cvWaitKey(50);
		   if(c=='q') break;
			   
		  }

	}
}