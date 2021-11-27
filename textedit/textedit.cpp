#include <QAction>
#include <QtGui/QKeySequence>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include "textedit.h"

Textedit::Textedit(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);

  // connect signal and slot
  connect(ui.actionOpenFile, &QAction::triggered, this,
          &Textedit::openFile);
  connect(ui.actionSaveFile, &QAction::triggered, this, &Textedit::saveFile);
  connect(ui.actionNewFile, &QAction::triggered, this, &Textedit::newFile);

  // var init
  this->path = "Untitled.txt";
  this->info = QFileInfo(path);
  this->isFileDefault = true;
  

  // set window
  this->setWindowTitle(this->info.fileName());
 }

Textedit::~Textedit() {}

void Textedit::openFile() { 
	QString path =
      QFileDialog::getOpenFileName(this, tr("Open file"), ".", tr("Text files(*.txt)"));

	if (!path.isEmpty()) {
          QFile file(path);
          if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
              // Warning: cannot open file
            QMessageBox::warning(this, tr("Read file"),
                                 tr("Cannot open file: \n%1").arg(path));
            return;
          }

          this->path = path;
          this->info = QFileInfo(path);
          this->setWindowTitle(this->info.fileName());
          this->isFileDefault = false;
          QTextStream in(&file);
          ui.textEdit->setText(in.readAll());
          file.close();
    } else {
          QMessageBox::warning(this, tr("Path"),
                               tr("You didn't select any file. "));
    }
}

void Textedit::saveFile() {
  if (this->isFileDefault) {
    QString path = QFileDialog::getSaveFileName(this, tr("Select file"), ".",
                                                tr("Text files(*.txt)"));

    if (!path.isEmpty()) {
      QFile file(path);
      file.open(QIODevice::WriteOnly | QIODevice::Text);
      QTextStream out(&file);
      out << ui.textEdit->toPlainText();
      file.close();
    } else {
      QMessageBox::warning(this, tr("Path"),
                           tr("You didn't select any file. "));
    }
  } else {
    QFile file(this->path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << ui.textEdit->toPlainText();
    file.close();
  }
}
  

void Textedit::newFile() {
  QString path = QFileDialog::getSaveFileName(this, tr("Create new file"), ".",
                                              tr("Text files(*.txt)"));
  if (!path.isEmpty()) {
    this->path = path;
    this->info = QFileInfo(path);
    this->setWindowTitle(this->info.fileName());
    this->isFileDefault = false;

    // empty textEdit
    ui.textEdit->setText(NULL);
  }
}
