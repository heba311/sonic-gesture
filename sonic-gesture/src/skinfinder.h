
#ifndef _SKINFINDER_H
#define	_SKINFINDER_H

#include "histogram.h"


using namespace cv;
using namespace std;

class SkinFinder {
public:
    SkinFinder();
    vector<vector<Point> > compute(const Mat& frame);
    vector<vector<Point> > contours;

    // required to know which con
    Point face_center;

    // images used in the steps. public so can be used for visualization
    Mat frame, hsv, bw, facepixels, backproj, mask, blur, thresh;

private:
    Mat kernel;
    Histogram histogram;
    CascadeClassifier haar;
    vector<Rect> faces;
    Rect face;
    void prepare();
    void find_face();
    void make_histogram();
    void make_backproject();
    void make_mask();
    void find_contours();
    void find_limbs();
    void step();
};


#endif

