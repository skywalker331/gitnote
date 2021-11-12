#include <QAction>
#include <QtGui/QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "textedit.h"

Textedit::Textedit(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);

  /*
  *	exp code
  * DO NOT UNCOMMENT!
  
  //init of actions
  actionOpen = new QAction(tr("&Open"), this);
  actionOpen->setShortcut(QKeySequence::Open);
  actionOpen->setStatusTip(tr("Open a file."));

  //init of menu bar
  QMenu *file = menuBar()->addMenu(tr("&File"));
  file->addAction(actionOpen);

  //init of tool bar
  QToolBar *toolBar = addToolBar(tr("&File"));
  toolBar->addAction(actionOpen);

  statusBar();
  */
}

Textedit::~Textedit() {}
