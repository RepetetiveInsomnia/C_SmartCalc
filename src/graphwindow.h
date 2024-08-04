#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QVector>

#include "./ui_graphwindow.h"
extern "C" {
#include "s21_calc_stack.h"
#include "s21_calculator.h"
#include "s21_check_string.h"
#include "s21_lexemme.h"
#include "s21_postfix.h"
#include "s21_wise.h"
}

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  void graph(node_calc *src);
  void setParam();
  ~GraphWindow();

 public slots:
  void graph();

 private slots:
  void on_d_f_1_valueChanged(double arg1);

  void on_d_f_2_valueChanged(double arg1);

  void on_e_f_1_valueChanged(double arg1);

  void on_e_f_2_valueChanged(double arg1);

  void on_GraphWindow_rejected();

 public:
  node_calc *dstq = NULL;
  double x_min_num, x_max_num, range_x, range_y;
  Ui::GraphWindow *ui;
  double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;
};

#endif  // GRAPHWINDOW_H
