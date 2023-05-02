#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   QtCharts::QPieSeries *series=new QtCharts::QPieSeries;
   series->append("Electronic",80);
   series->append("Electrical",70);
   series->append("Civil",60);
   series->append("It",40);
   series->append("Mechanical",90);

//   QtCharts::QCharts *chartView = new QCharts();
   QtCharts::QChart *qc=new QtCharts::QChart;
   qc->addSeries(series);
   qc->setTitle("PieChart Display");

   QtCharts::QChartView *cv=new QtCharts::QChartView(qc);
   cv->setParent(ui->horizontalFrame);

   QtCharts::QPieSlice *qp=series->slices().at(4);
   qp->setExploded(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

