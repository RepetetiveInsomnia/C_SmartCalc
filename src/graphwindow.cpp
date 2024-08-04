#include "graphwindow.h"

GraphWindow::GraphWindow(QWidget* parent)
    : QDialog(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::graph(node_calc* src) {
  node_calc* tmp = NULL;
  // tmp = s21_copy_list(&src);
  dstq = s21_copy_list(&src);
  // s21_print_list(src);

  // s21_print_list(dstq);
  ui->widget->clearGraphs();
  x_min_num = ui->d_f_1->value();
  x_max_num = ui->d_f_2->value();
  range_x = ui->e_f_1->value();
  range_y = ui->e_f_2->value();

  xBegin = x_min_num;
  xEnd = x_max_num;

  ui->widget->xAxis->setRange(-1 * range_x, range_x);
  ui->widget->yAxis->setRange(-1 * range_y, range_y);

  h = 0.1;
  int error = 0;
  double pre_y = 0.0;
  for (X = xBegin; X < xEnd; X += h) {
    pre_y = s21_calc(&tmp, &src, dstq, 1, X, &error);
    x.push_back(X);
    if (pre_y < -1 * range_y || pre_y > range_y) {
      y.push_back(std::numeric_limits<double>::quiet_NaN());
      // x.push_back(std::numeric_limits<double>::quiet_NaN());
    } else {
      y.push_back(pre_y);
    }

    if (tmp != NULL) {
      freeList(&tmp);
      tmp = NULL;
    }
    dstq = s21_copy_list(&src);

    // s21_print_list(dstq);
  }
  freeList(&src);
  src = NULL;
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDot, 50));
  ui->widget->xAxis->setRange(-1 * range_x, range_x);
  ui->widget->yAxis->setRange(-1 * range_y, range_y);

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);

  ui->widget->replot();

  x.clear();
  y.clear();
}

void GraphWindow::graph() { GraphWindow::graph(dstq); }

void GraphWindow::on_d_f_1_valueChanged(double arg1) {
  x_min_num = ui->d_f_1->value();
  node_calc* src = NULL;
  src = s21_copy_list(&dstq);
  // s21_print_list(src);
  if (dstq != NULL) {
    freeList(&dstq);
    dstq = NULL;
  }
  graph(src);
  if (src != NULL) {
    // freeList(&src);
    // src = NULL;
  }
}

void GraphWindow::on_d_f_2_valueChanged(double arg1) {
  x_max_num = ui->d_f_2->value();
  node_calc* src = NULL;
  src = s21_copy_list(&dstq);
  if (dstq != NULL) {
    freeList(&dstq);
    dstq = NULL;
  }
  graph(src);
  if (src != NULL) {
    // freeList(&src);
    // src = NULL;
  }
}

void GraphWindow::on_e_f_1_valueChanged(double arg1) {
  range_x = ui->e_f_1->value();
  node_calc* src = NULL;
  src = s21_copy_list(&dstq);
  if (dstq != NULL) {
    freeList(&dstq);
    dstq = NULL;
  }
  graph(src);
  if (src != NULL) {
    // freeList(&src);
    //  src = NULL;
  }
}

void GraphWindow::on_e_f_2_valueChanged(double arg1) {
  range_y = ui->e_f_2->value();
  node_calc* src = NULL;
  src = s21_copy_list(&dstq);
  if (dstq != NULL) {
    freeList(&dstq);
    dstq = NULL;
  }
  graph(src);
  if (src != NULL) {
    // freeList(&src);
    // src = NULL;
  }
}

void GraphWindow::on_GraphWindow_rejected() {
  ui->widget->clearGraphs();
  freeList(&dstq);
  dstq = NULL;
  x.clear();
  y.clear();
}
