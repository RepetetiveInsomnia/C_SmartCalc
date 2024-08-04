#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  window2 = new GraphWindow(this);
}

MainWindow::~MainWindow() {
  delete ui;
  delete window2;
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void MainWindow::on_pushButton_del_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void MainWindow::on_pushButton_umn_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void MainWindow::on_pushButton_minus_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void MainWindow::on_pushButton_plus_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() = "");
}

void MainWindow::on_pushButton_0_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void MainWindow::on_pushButton_1_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::on_pushButton_2_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::on_pushButton_3_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::on_pushButton_4_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::on_pushButton_5_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::on_pushButton_6_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::on_pushButton_7_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::on_pushButton_8_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::on_pushButton_9_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void MainWindow::on_pushButton_x_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "x");
}

void MainWindow::on_pushButton_sin_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
}

void MainWindow::on_pushButton_cos_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
}

void MainWindow::on_pushButton_tan_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
}

void MainWindow::on_pushButton_asin_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
}

void MainWindow::on_pushButton_acos_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
}

void MainWindow::on_pushButton_atan_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}

void MainWindow::on_pushButton_pow_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "^");
}

void MainWindow::on_pushButton_mod_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "mod");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
}

void MainWindow::on_pushButton_log_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "log(");
}

void MainWindow::on_pushButton_ln_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
}

void MainWindow::on_pushButton_Os_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "(");
}

void MainWindow::on_pushButton_Cs_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void MainWindow::on_pushButton_end_clicked() {
  char input[256];
  QByteArray barr = ui->lineEdit->text().toLocal8Bit();

  strlcpy(input, barr.data(), 256);

  if (s21_check_string(input) == 1) {
    ui->lineEdit->setText("Invalid Input");
  } else {
    node_calc* dst = NULL;
    node_calc* src = NULL;
    node_calc* res = NULL;
    int is_x = 0;
    double result = 0.0;
    is_x = s21_stack_maker(input, &dst);
    if (is_x == 2) {
      ui->lineEdit->setText("Invalid Input");
    } else if (is_x == 0) {
      int error = 0;
      result = s21_calc(&dst, &res, src, 0, 0, &error);
      if (error == 1) {
        ui->lineEdit->setText("Invalid Input ZERO DELIM");
      } else {
        QString numberResult = QString::number(result);
        ui->lineEdit->setText(numberResult);
        // freeList(&dst);
        // dst = NULL;
      }
    } else if (is_x == 1) {
      node_calc* inverse = NULL;
      inverse = s21_inverse(&dst);
      // s21_print_list(src);
      s21_to_postfix(inverse, &res);

      // src = s21_inverse(&res);
      // freeList(&res);
      // res = NULL;
      // s21_print_list(src);
      window2->setModal(true);
      window2->show();

      window2->graph(res);

      // freeList(&inverse);
      // inverse = NULL;
    }
  }
  // free(*input);
}

void MainWindow::on_pushButton_empty_clicked() {
  window2->setModal(true);
  window2->exec();
}
