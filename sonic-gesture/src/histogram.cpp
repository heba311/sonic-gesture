
#include "histogram.h"


Histogram::Histogram() {
    first = true;
    int hbins = 30;
    int sbins = 32;
    int histSize[] = {hbins, sbins};
     
    // init histogram stuff
    this->histogram.create(2, histSize, CV_32F);
    this->histogram = Scalar(0);    
};

Histogram::~Histogram() {
};

void Histogram::update(Mat image) {
    int hbins = 30;
    int sbins = 32;
    float hranges[] = { 0, 180 };
    float sranges[] = { 0, 256 };
    const float* ranges[] = { hranges, sranges };
    int histSize[] = {hbins, sbins};
    int channels[] = {0, 1};
    
    if (first) {
        calcHist( &image,  1, channels, Mat(), histogram, 2,  histSize, ranges,  true, false );
        normalize(histogram, histogram, 255);
        new_hist = histogram;
        first = false;
    } else {
        old_hist = new_hist;
        calcHist( &image,  1, channels, Mat(), new_hist, 2,  histSize, ranges,  true, false );
        assert(new_hist.type() == old_hist.type());
        //double diff = compareHist(new_hist, old_hist, CV_COMP_BHATTACHARYYA);
        // TODO: check if this is actually correct:
        add(new_hist, old_hist, histogram);
        //histogram = new_hist;
        normalize(histogram, histogram, 255);
    }
};

Mat Histogram::backproject(Mat image) {
    float hranges[] = { 0, 180 };
    float sranges[] = { 0, 256 };
    const float* ranges[] = { hranges, sranges };
    int channels[] = {0, 1};
    
    Mat backprojection;
    calcBackProject( &image, 1, channels, histogram, backprojection, ranges );
    return backprojection;
};