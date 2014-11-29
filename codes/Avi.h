#if !defined _INPUTAVI_H
#define _INPUTAVI_H

#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "cvaux.h"
#include "stdio.h"

#define pi 3.1415926
#define threshold 50
class Avi{

private:
	const char* filename;
	CvSize frame_size;
	int outCompressCodec;
	double fps;

	CvScalar s_fr;
	CvScalar s_bg;
	CvGaussBGModel* bg_model;

public:
	CvVideoWriter* writer_counter;
	CvVideoWriter* writer_GaussBg;
	Avi(const char* file);

	CvCapture* ReadAvi();
	void ShowOriginImage(int nFrmNum,IplImage* frame);
	IplImage* ShowCounterImage(int nFrmNum,IplImage* pFrImg_cur,IplImage* pFrImg_pre);
	IplImage* ShowGaussBgImage(int nFrmNum,IplImage* pFrImg_cur);

	void SaveImage(CvVideoWriter* writer,IplImage* frame);
};

#endif