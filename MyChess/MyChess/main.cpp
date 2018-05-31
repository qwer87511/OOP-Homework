/*#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void Window()
{
    namedWindow("window", WINDOW_NORMAL);
}
void EnterImg()
{
    Mat enterImg = imread(string("enter.jpg"), CV_LOAD_IMAGE_COLOR);
    imshow("window", enterImg);
}
void GamePreImg()
{
    Mat mat(500, 500, CV_8UC3, Scalar(255, 222, 173)); // ­I´º
    putText(mat, string("Junwei Huang is so handsome"), Point(0, 280), 0, 1, Scalar(0, 0, 0), 3);
    imshow("window", mat);
}
int main()
{
    Window();
    EnterImg();

    while (cvWaitKey() != 13);

    GamePreImg();

    while (cvWaitKey() != 13);

    system("pause");
    return 0;
}*/
#include <opencv/highgui.h>
#include <opencv/cv.h>

int win_size = 10;
const int MAX_COUNT = 500;
CvPoint2D32f* points[2] = { 0,0 }, *swap_points;
char* status = 0;
int count = 0;
int flags;
int init = 1;

int main()
{
    CvCapture* cap = cvCreateCameraCapture(0);
    IplImage* frame = cvQueryFrame(cap);
    IplImage* image = cvCloneImage(frame);
    IplImage* grey = cvCreateImage(cvGetSize(image), 8, 1);
    IplImage* prev_grey = cvCloneImage(grey);
    IplImage* pyramid = cvCloneImage(grey);
    IplImage* prev_pyramid = cvCloneImage(grey);
    IplImage* swap_temp;
    points[0] = (CvPoint2D32f*)cvAlloc(MAX_COUNT * sizeof(points[0][0]));
    points[1] = (CvPoint2D32f*)cvAlloc(MAX_COUNT * sizeof(points[0][0]));
    status = (char*)cvAlloc(MAX_COUNT);
    flags = 0;

    while (1) {
        frame = cvQueryFrame(cap);
        cvCopy(frame, image, 0);
        cvCvtColor(image, grey, CV_BGR2GRAY);

        if (init) {
            init = 0;
            IplImage* eig = cvCreateImage(cvGetSize(grey), 32, 1);
            IplImage* temp = cvCreateImage(cvGetSize(grey), 32, 1);
            double quality = 0.01;
            double min_distance = 10;
            count = MAX_COUNT;
            cvGoodFeaturesToTrack(grey, eig, temp, points[1], &count,
                                  quality, min_distance, 0, 3, 0, 0.04);
            cvFindCornerSubPix(grey, points[1], count,
                               cvSize(win_size, win_size), cvSize(-1, -1),
                               cvTermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03));
            //cvConvertScaleAbs(eig,grey);
            //cvShowImage("eig",grey);
            printf("count:%d\n", count);
            cvWaitKey(0);
            cvReleaseImage(&eig);
            cvReleaseImage(&temp);
        }
        else if (count>0) {
            cvCalcOpticalFlowPyrLK(prev_grey, grey, prev_pyramid, pyramid,
                                   points[0], points[1], count, cvSize(win_size, win_size), 3, status, 0,
                                   cvTermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03), flags);
            flags |= CV_LKFLOW_PYR_A_READY;
            printf("count:%d\n", count);
            cvWaitKey(0);
            int k = 0;

            for (int i = 0; i < count; i++)
            {
                if (!status[i])
                    continue;

                points[1][k++] = points[1][i];
                cvCircle(image, cvPointFrom32f(points[1][i]), 3, CV_RGB(0, 255, 0), -1, 8, 0);

                if (i<23) {
                    printf("%f %f\n", points[1][i].x, points[1][i].y);
                }
            }

            count = k;
        }

        CV_SWAP(prev_grey, grey, swap_temp);
        CV_SWAP(prev_pyramid, pyramid, swap_temp);
        CV_SWAP(points[0], points[1], swap_points);
        cvShowImage("a", image);
        int key = cvWaitKey(33);

        if (key == 27) break;

        if (key == 'r') init = 1;
    }

    cvReleaseCapture(&cap);
    cvReleaseImage(&image);
    return 0;
}