import com.googlecode.javacv.*;
import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;

public class hornshunck {

	public static void main(String[] args) {
		  int wi=320; //largeur
		  int he=240; //hauteur
		  CvCapture capture;
		  double lambda=1.0;
		  int prev=1;
		  IplImage frame, grayimg, edge, vx, vy;
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
		    String fic="video_intro.mpg";//fic="video_intro.mpg";//
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

		   //traitement Horn Schunck
		   grayimg=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		   edge=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		   vx=cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F,1);
		   vy=cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F,1);
		     
		   cvCvtColor(frame,grayimg,CV_BGR2GRAY); // on travail sur des images NdG
		   cvCalcOpticalFlowHS(grayimg,edge,prev,vx,vy,lambda,term);//vx, vy : vitesse en x et y calculees, prev permet d'utiliser les vitesses obtenues a l'image t-1 pour calculer nouvelle
		    //lambda poids de convergence, 
		    cvConvert(vx,grayimg);
		     
		    cvShowImage("Video0",frame);
		    cvShowImage("Video",grayimg);
		    char c=(char) cvWaitKey(100);
		    if(c=='q') break;
			   
		  }

	}
}