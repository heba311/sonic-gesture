
#include <stdlib.h>
#include "opencv/cv.h"
#include "settings.h"
#include "finder.h"

int main(int, char**) {
    VideoCapture cap(DEVICE);
    Finder finder(cap);
    finder.mainloop();
    return EXIT_SUCCESS;
}