#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/faces.jpg";
	Mat img = imread(path);

	CascadeClassifier face;
	face.load("Resources/haarcascade_frontalface_default.xml");

	vector<Rect> faces;
	face.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 0), 5);
	}

	imshow("Images", img);
	waitKey(0);
}