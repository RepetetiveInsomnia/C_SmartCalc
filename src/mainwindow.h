#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QPrinter>
#include <QString>

#include "./ui_mainwindow.h"
#include "graphwindow.h"
extern "C" {
#include "s21_calc_stack.h"
#include "s21_calculator.h"
#include "s21_check_string.h"
#include "s21_lexemme.h"
#include "s21_postfix.h"
#include "s21_wise.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  GraphWindow *window2;

 private slots:

  void on_pushButton_dot_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_umn_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_0_clicked();
  void on_pushButton_1_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_pow_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_Os_clicked();
  void on_pushButton_Cs_clicked();
  void on_pushButton_end_clicked();
  void on_pushButton_empty_clicked();
};
#endif  // MAINWINDOW_H
