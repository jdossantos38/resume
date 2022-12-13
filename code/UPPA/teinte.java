import com.googlecode.javacv.*;
import com.googlecode.javacv.cpp.opencv_core.CvScalar;

import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;
import static com.googlecode.javacv.cpp.opencv_core.cvGet2D;
import java.awt.*;


public class teinte {

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

		   //traitement teinte

		   int[] tabOut= new int[wi*he];
		   double r,g,b,somRGB;
		   double qPlus,qMoins,w, seuil=0.004;
		   double Au=-1.3767, bu=1.0743,cu=0.1452;
		   double Ad=-0.776, bd=0.5601,cd=0.1766;
		   
		   wi=frame.width(); 
		   he=frame.height();
		   for (int l=0; l<he; l++)
		    for(int c=0; c<wi; c++) {
		     CvScalar pixel=cvGet2D(frame.asCvMat(), l, c);// on recupere le pixel
		     r = pixel.red(); 
		     g = pixel.green(); 
		     b = pixel.blue();
		     somRGB=r+g+b; // algo p189 composante normalisee
		     r=r/somRGB;
		     g=g/somRGB;
		     tabOut[l*wi+c] = 0; //non chair par defaut
		     
		     if(r>=0.2 && r<=0.6) { //On calcule Q+, Q-, w
		      qPlus = Au*Math.pow(r, 2) + bu*r + cu;
		      qMoins = Ad*Math.pow(r, 2) + bd*r + cd;
		      w = Math.pow(r-0.33,2) + Math.pow(g-0.33,2);
		      if(g<qPlus && g>qMoins && w>seuil) //on teste
		       tabOut[l*wi+c] =255; //chair
		     }
		    }
		   CvMat MatriceDest= cvCreateMat(he,wi,CV_8UC1);//on recree l'image grace a la matrice
		     for (int l=0; l<he; l++)
		      for (int c=0; c<wi; c++)
		       MatriceDest.put((l*wi + c), tabOut[l*wi + c]);
		     grayimg = MatriceDest.asIplImage();
		     
		   cvShowImage("Video0",frame);
		   cvShowImage("Video",grayimg);
		   char x=(char) cvWaitKey(50);
		   if(x=='q') break;
			   
		  }

	}

}