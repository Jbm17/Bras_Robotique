// camera.cpp
#include "camera.h"
#include <QVBoxLayout>
#include <QImage>
#include <QPixmap>
#include <QDebug>

Camera::Camera(QWidget *parent) : QWidget(parent) {
    label = new QLabel(this);
    label->setFixedSize(640, 480);
    label->setStyleSheet("background: black");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);

    cap.open(0);  // caméra par défaut
    if (!cap.isOpened()) {
        label->setText("❌ Caméra non détectée");
        return;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Camera::updateFrame);
    timer->start(25);  // ~30fps
}

Camera::~Camera() {
    if (cap.isOpened())
        cap.release();
}

void Camera::updateFrame() {
    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) return;

    QImage image = matToQImage(frame);
    if (!image.isNull())
        label->setPixmap(QPixmap::fromImage(image));
}

QImage Camera::matToQImage(const cv::Mat &frame) {
    cv::Mat rgb;
    cv::cvtColor(frame, rgb, cv::COLOR_BGR2RGB);
    return QImage(rgb.data, rgb.cols, rgb.rows, static_cast<int>(rgb.step), QImage::Format_RGB888).copy();
}

QLabel* Camera::getVideoLabel() {
    return label;
}

cv::VideoCapture* Camera::getCapture() {
    return &cap;
}
