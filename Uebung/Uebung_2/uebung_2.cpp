#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
    Mat h(256,1,CV_32F, Scalar(0));
    Mat Lut(256,1,CV_8U, Scalar(0));
    Mat bild;
    double minVal, maxVal;

    bild = imread("//home//forall//Downloads//London.bmp", 0);
    imshow("Vorher", bild);
    minMaxLoc(bild, &minVal, &maxVal);
    for (int i = 0; i < 256; ++i) {
        Lut.at<uchar>(i) = (i - minVal) * 255 /  (maxVal - minVal); // Lineare Skalierung per Hand
    }
    for(int i = 0; i<bild.rows; i++){
        for (int j = 0; j < bild.cols ; ++j) {
            bild.at<uchar>(i,j) = Lut.at<uchar>(bild.at<uchar>(i,j)); // Lineare Skalierung Anwendung
        }
    }
    imshow("Nachher", bild);
    for (int i = 0; i < 256; ++i) {
        double Gamma = 0.5;
        Lut.at<uchar>(i) = 255 * (i/ 255.0) * Gamma; // Gammakorrektur per Hand
    }
    for(int i = 0; i<bild.rows; i++){
        for (int j = 0; j < bild.cols ; ++j) {
            bild.at<uchar>(i,j) = Lut.at<uchar>(bild.at<uchar>(i,j)); // Gamma Korrektur Anwendung
        }
    }
    imshow("Gamma", bild);
    waitKey(0);
    return 0;

}
