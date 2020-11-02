#include <opencv2/opencv.hpp>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonTest_clicked()
{
    cv::VideoCapture vc(0);
    if (!vc.isOpened())
        return;
    while (true) {
        cv::Mat frame;
        vc >> frame;

        if (frame.empty())
            break;

        cv::imshow("Frame", frame);

        if (cv::waitKey(25) == 27)
            break;
    }
    vc.release();
    cv::destroyAllWindows();
}
