import com.googlecode.javacv.*;
import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;

public class detectionpresence {

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
		  
		//INITIALISATION 1ere image//
		  frame=cvQueryFrame(capture); 
		  if(frame == null) {
		   System.out.println("ERR=No video file"); }
		  CvSize dim=cvGetSize(frame);
		  wi=dim.width(); he=dim.height();
		  /*FrameRecorder record=new OpenCVFrameRecorder("Out.AVI",wi,he);
		  record.setVideoCodec(CV_FOURCC('M','J','P','G'));
		  record.setFrameRate(15);
		  record.setPixelFormat(0); //ATT:0=NdG,N&B; OU: 1=couleur
		  record.start();*/
		  cvNamedWindow("VideoIn",CV_WINDOW_AUTOSIZE);
		  cvNamedWindow("VideoOut",CV_WINDOW_AUTOSIZE);
		  grayimg=cvCreateImage(dim,IPL_DEPTH_8U,1);
		  CvMat matrice= cvCreateMat(he,wi,CV_8UC1);
		  //PRETRAITEMENT//
		  IplImage gray0=cvCreateImage(dim,IPL_DEPTH_8U,1);
		  CvMat matric0= cvCreateMat(he,wi,CV_8UC1);
		  int traitement=0; //0=fct OPENCV; sinon:ALGO PERSO
		  
		  switch(traitement){
		  case 0:
		   cvCvtColor(frame,gray0,CV_BGR2GRAY);
		  break;
		  default:
		   for (int l=0; l< he; l++)
		    for(int c=0; c< wi; c++){
		     CvScalar pixel0 = cvGet2D(frame.asCvMat(), l, c);
		     matric0.put((l*wi + c), pixel0.green());
		    }
		   break; 
		  }
		  
		  cvNamedWindow("Video0",1);
		  cvNamedWindow("Video",CV_WINDOW_AUTOSIZE);
		  
		//IMAGES FOND + NOIRE POUR INCRUSTATION
		  String rep1="";
		  IplImage bckg=cvLoadImage(rep1+"plage.jpg");
		  IplImage in0=cvCreateImage(cvGetSize(bckg),IPL_DEPTH_8U,1);
		  IplImage fond=cvCreateImage(dim,IPL_DEPTH_8U,1);
		  IplImage imgNoire=cvCreateImage(dim,IPL_DEPTH_8U,1);
		  cvCvtColor(bckg,in0,CV_BGR2GRAY);
		  cvResize(in0,fond,CV_INTER_AREA);//2);//
		  for (int l=0; l<he; l++) 
		   for (int c=0; c<wi; c++)
			matrice.put((l*wi + c), 0); 
		  imgNoire = matrice.asIplImage();
		  IplImage msk=cvCreateImage(dim,IPL_DEPTH_8U,1);
		  int seuil=5;//15;//20;////3;//6;//   
		  //BOUCLE TEMPORELLE: DETECTION MVT 
		  
		  
		  for(;;) {
		   frame=cvQueryFrame(capture);
		   if(frame == null) {
		    System.out.println("ERR=No video file");
		    break;
		   }

		   //traitement Detection presence TP2
		   
		   cvCvtColor(frame,grayimg,CV_BGR2GRAY);
		   cvAbsDiff(gray0,grayimg,msk);//src1, src2, dst
		   cvThreshold(msk,msk,seuil,255,CV_THRESH_BINARY_INV);//src,dst,seuil,max seuil, type seuil
		   cvMorphologyEx(msk,msk,gray0,null,CV_MOP_OPEN,1);
		   cvMorphologyEx(msk,msk,gray0,null,CV_MOP_CLOSE,1);
		   gray0=grayimg.clone();
		   cvSub(fond,imgNoire,grayimg,msk);//src1, src2, dst,. If the array mask is non-NULL, then only those 
		   //elements of dst corresponding to nonzero elements of mask are computed
		    
		   cvShowImage("Video0",frame);
		   cvShowImage("Video",grayimg);
		   char c=(char) cvWaitKey(50);
		   if(c=='q') break;
			   
		  }

	}
}