import com.googlecode.javacv.*;
import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;

public class shencastan {

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

		   //traitement shen et castan
		  int[] tabPix= new int[wi*he];
		  int[] tabOut= new int[wi*he];
		  for (int l=0; l<he; l++)
		     for (int c=0; c<wi; c++)
		       tabPix[l*wi+c]=(int)cvGet2D(frame.asCvMat(), l, c).green();
		  double seuil=10;
		  double alpha=0.8;
     
		  int taille=tabPix.length;
		  int hauteur=taille/wi;
		  int pixel;
		  double b=Math.exp(-alpha); 
		  double d=1-b;
		  int lm2=wi-2;
		  int hm2=hauteur-2;
		  double[] tabTemp=new double[wi*hauteur];
		  double[] tabTmp2=new double[wi*hauteur];
		  double[] tabTmp3=new double[wi*hauteur];
  
  		//Traitement du tableau de pixels (derivation selon X)
  		  for (int l = 0; l < hauteur; l++) {
   			for (int c = 1; c < wi; c++)
    				tabTemp[l*wi + c]=-d*tabPix[l*wi + c]+b*tabTemp[l*wi + c-1];
   			for (int c = lm2; c >= 0; c--)
    				tabTmp2[l*wi + c]=d*tabPix[l*wi + c]+b*tabTmp2[l*wi + c+1];
   			for (int c = 0; c < wi; c++)
    				tabTemp[l*wi + c]=tabTmp2[l*wi + c]+tabTemp[l*wi + c];
 						 }
  		//Derivee selon Y
  		  for (int c= 0; c < wi; c++) {
   			for (int l = 1; l < hauteur; l++)
    				tabTmp2[l*wi + c]= -d*tabPix[l*wi + c]+b*tabTmp2[(l-1)*wi + c];
   			for (int l = hm2; l >= 0; l--)
    				tabTmp3[l*wi + c]= d*tabPix[l*wi + c]+b*tabTmp3[(l+1)*wi + c];
   			for (int l = 0; l < hauteur; l++)
    				tabTmp2[l*wi + c]=tabTmp2[l*wi + c]+tabTmp3[l*wi + c];
  						}
  		//Calcul du module du gradient et seuillage
  		  for (int l = 0; l < hauteur; l++)
   			for (int c = 0; c < wi; c++) {
    				pixel=255;
    				tabTmp3[l*wi + c]=Math.sqrt(tabTemp[l*wi + c]*tabTemp[l*wi + c]
    				+tabTmp2[l*wi + c]*tabTmp2[l*wi + c]);
    				if(tabTmp3[l*wi + c]>seuil)
     					pixel=0;
    				tabOut[l*wi+c]=pixel;//NB:POUR test comp.connexes OU pour test RF, prendre: 255-pixel 
  						 }
   
   		  CvMat MatriceDest= cvCreateMat(he,wi,CV_8UC1);
     		  for (int l=0; l<he; l++)
      			for (int c=0; c<wi; c++)
       				MatriceDest.put((l*wi + c), tabOut[l*wi + c]);
     			grayimg = MatriceDest.asIplImage();
		     
		  cvShowImage("Video0",frame);
		  cvShowImage("Video",grayimg);
		  char c=(char) cvWaitKey(50);
		  if(c=='q') break;
			   
		  }

	}
}