#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileInfo>

#include "ui_textedit.h"

// forward declaration
class QAction;

class Textedit : public QMainWindow {
  Q_OBJECT

 public:
  Textedit(QWidget *parent = Q_NULLPTR);
  ~Textedit();

  // File operations
  void openFile();
  void saveFile();
  void newFile();

 private:
  Ui::TexteditClass ui;
  QString path;
  QFileInfo info;

  // check if file path is default
  bool isFileDefault;
};
