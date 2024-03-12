#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

    Mat image = Mat::zeros(500, 500, CV_8UC3);

    putText(image, "Width: " + to_string(image.cols), Point(230, 420), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 2);
    putText(image, "Height: " + to_string(image.rows), Point(230, 450), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 2);

    line(image, Point(400, 90), Point(470, 90), Scalar(0, 204, 255), 2);
    circle(image, Point(image.cols / 2, image.rows / 2), 50, Scalar(204, 0, 204), -1);
    circle(image, Point(430, 410), 50, Scalar(0, 0, 255), 1);
    rectangle(image, Rect(10, image.rows - 150, 100, 100), Scalar(255, 0, 0), -1);
    rectangle(image, Rect(10, image.rows - 450, 100, 100), Scalar(30, 120, 0), 1);

    imshow("Изображение с фигурами", image);

    Mat segment1 = image(Rect(0, 0, 500 / 2, 500 / 2));
    Mat segment2 = image(Rect(500 / 2, 0, 500 / 2, 500 / 2));
    Mat segment3 = image(Rect(0, 500 / 2, 500 / 2, 500 / 2));
    Mat segment4 = image(Rect(500 / 2, 500 / 2, 500 / 2, 500 / 2));

    namedWindow("Сегмент 1", WINDOW_NORMAL);
    imshow("Сегмент 1", segment1);

    namedWindow("Сегмент 2", WINDOW_NORMAL);
    imshow("Сегмент 2", segment2);

    namedWindow("Сегмент 3", WINDOW_NORMAL);
    imshow("Сегмент 3", segment3);

    namedWindow("Сегмент 4", WINDOW_NORMAL);
    imshow("Сегмент 4", segment4);

    Mat mask(image.size(), CV_8UC1, Scalar(0));
    circle(mask, Point(350, 180), 130, Scalar(255), -1);

    Mat segmented;
    image.copyTo(segmented, mask);

    namedWindow("Маска", WINDOW_NORMAL);
    imshow("Маска", segmented);

    waitKey(0);

    return 0;
}
