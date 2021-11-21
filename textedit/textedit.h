#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_textedit.h"

// forward declaration
class QAction;

class Textedit : public QMainWindow {
  Q_OBJECT

 public:
  Textedit(QWidget *parent = Q_NULLPTR);
  ~Textedit();

 private:
  Ui::TexteditClass ui;
};
