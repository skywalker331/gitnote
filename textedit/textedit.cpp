#include <QAction>
#include <QtGui/QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "textedit.h"

Textedit::Textedit(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);

  actionOpen = new QAction(tr("&Open"), this);
  actionOpen->setShortcut(QKeySequence::Open);
  actionOpen->setStatusTip(tr("Open a file."));

  QMenu *file = menuBar()->addMenu(tr("&File"));
  file->addAction(actionOpen);

  QToolBar *toolBar = addToolBar(tr("&File"));
  toolBar->addAction(actionOpen);
}

Textedit::~Textedit() {}
