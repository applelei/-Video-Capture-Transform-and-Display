#include "Avi.h"
//main函数数框架设计 雷磊
int main(int argc,char** argv)  
{

	Avi x("test.avi");
	CvCapture* capture = x.ReadAvi ();

	IplImage* pFrImg_cur = NULL;
	IplImage* pFrImg_pre = NULL;
	int nFrmNum = 0;

	while(pFrImg_cur = cvQueryFrame(capture))
	{
		nFrmNum ++;

		//显示原始图像
 		x.ShowOriginImage(nFrmNum,pFrImg_cur);	
		
		
		if(nFrmNum == 1)
		{
			pFrImg_pre = cvCreateImage(cvSize(pFrImg_cur->width,pFrImg_cur->height),IPL_DEPTH_8U,3);
			cvCopy(pFrImg_cur,pFrImg_pre,NULL);
		}
		else
		{	
			//帧差法检测运动目标，保存处理后的图像 雷磊 (函数见avi.cpp)																					
 			x.SaveImage (x.writer_counter, x.ShowCounterImage (nFrmNum,pFrImg_cur,pFrImg_pre));	
			cvCopy(pFrImg_cur,pFrImg_pre,NULL);
		}
		
		//混合高斯背景建模，背景差分，保存处理后的图像 忻颖(函数见avi.cpp)
		x.SaveImage(x.writer_GaussBg, x.ShowGaussBgImage (nFrmNum,pFrImg_cur));
		
	}
	cvReleaseVideoWriter(&x.writer_counter );
	cvReleaseVideoWriter(&x.writer_GaussBg );
	return 0;
}