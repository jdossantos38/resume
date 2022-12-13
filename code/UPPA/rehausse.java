import com.googlecode.javacv.*;
import static com.googlecode.javacv.cpp.opencv_calib3d.*;
import static com.googlecode.javacv.cpp.opencv_objdetect.*;
/**/
import static com.googlecode.javacv.cpp.opencv_core.*;
import static com.googlecode.javacv.cpp.opencv_imgproc.*;
import static com.googlecode.javacv.cpp.opencv_highgui.*;
import static com.googlecode.javacv.cpp.opencv_legacy.*;

public class rehausse {

	public static void main(String[] args) {
		  int wi=320; //largeur
		  int he=240; //hauteur
		  CvCapture capture;
		  IplImage frame, grayimg;
		  CvTermCriteria term=cvTermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS,20,.3);

		  
		  //CHOIX VIDEO SOURCE:
		  int choix=1; //(choix=0)=>camera SINON video
		  int choix_traitement = 12;
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

		   //traitement rehaussement details algo p186
		   
		   int[] tabPix= new int[wi*he];
		   int[] tabOut= new int[wi*he];
		   int C = wi;
		     
		   for (int l=0; l<he; l++)
		      for (int c=0; c<wi; c++)
		       tabPix[l*wi+c]=(int)cvGet2D(frame.asCvMat(), l, c).green();
		   double A=0.5;
		   int[][] H=new int[5][5];
		   for( int k=0; k<H[0].length; k++)
		      for( int l=0; l<H[0].length; l++)
		       H[k][l]=1;
		     
		   //A=ponderation (de 0 a 1)
		   //H=filtre carre de taille NxN (typ. N=5)
		   int N=H[0].length;
		   int d=(N-1)/2;
		   int taille=tabPix.length;
		   int L=taille/C; //C=largeur=nb colonnes ; L=nb de lignes
		   int[] mFlou=new int[taille];
		      
		   //voisinage de chaque pixel
		   for (int y=0;y<L;y++){ //boucle sur les lignes
		      int ymin=(int)Math.max(0,y-d);
		      int ymax=(int)Math.min(L-1,y+d);
		      for(int x=0;x<C;x++){ //boucle sur les colonnes
		       int xmin=(int)Math.max(0,x-d);
		       int xmax=(int)Math.min(C-1,x+d);
		       
		       //coefficient du voisin dans matrice centree sur pixel
		       double tmp=0.;
		       int den=0;
		       for(int j=ymin;j<=ymax;j++){
		        int vy=j-y+d;
		        for(int i=xmin;i<=xmax;i++) {
		         int vx=i-x+d;
		         int coeff=H[vx][vy];
		         tmp+=(double)tabPix[j*C+i]*coeff;
		         den+=coeff;
		        }
		       }
		       mFlou[y*C+x]=(int)(tmp/den);//calcul du masque flou
		      }
		     }
		     
		     //rehaussement de l'image
		     double Min=255, Max=0, epsilon=1e-2;
		     int [] tabTmp=new int[taille];
		     for (int i = 0; i < taille; i++) {
		      int detail=(int)(tabPix[i]-mFlou[i]); //details
		      int pixi;
		      switch(choix_traitement) {
		       case 1:
		        pixi=(int)Math.log(detail+epsilon);
		       break;
		       case 2:
		        pixi=(int)Math.exp(detail);
		       break;
		       default:
		        pixi=detail;
		       break;
		      }
		      pixi=(int)(A*tabPix[i]+(1-A)*pixi);
		      if(pixi<Min) Min=pixi;
		      if(pixi>Max) Max=pixi;
		      tabTmp[i]=pixi;
		     }
		    //System.out.println("min="+Min+" max="+Max);
		     for (int i = 0; i < taille; i++) {
		      int pix=tabTmp[i];
		    //  pix=(int)(255.*(tabTmp[i]-Min)/(double)(Max-Min));
		      tabOut[i]=(int)pix;
		     }
		     
		     CvMat MatriceDest= cvCreateMat(he,wi,CV_8UC1);
		     for (int l=0; l<he; l++)
		      for (int c=0; c<wi; c++)
		       MatriceDest.put((l*wi + c), tabOut[l*wi + c]);
		     grayimg = MatriceDest.asIplImage();
		   
		     cvShowImage("Video0",frame);
		     cvShowImage("Video",grayimg);
		     char x=(char) cvWaitKey(100);
		     if(x=='q') break;
			   
		  }

	}
}