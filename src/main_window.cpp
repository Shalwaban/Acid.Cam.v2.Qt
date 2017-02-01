#include "main_window.h"

std::unordered_map<std::string, int> filter_map;

void generate_map() {
    for(unsigned int i = 0; i < ac::draw_max; ++i )
        filter_map[ac::draw_strings[i]] = i;
}

void custom_filter(cv::Mat &frame) {
    
}

AC_MainWindow::AC_MainWindow(QWidget *parent) : QMainWindow(parent) {
    generate_map();
    setGeometry(0, 0, 800, 600);
    setWindowTitle("Acid Cam v2 - Qt");
    createControls();
    createMenu();
}

void AC_MainWindow::createControls() {
    
    filters = new QListWidget(this);
    filters->setGeometry(10, 10, 390, 200);
    filters->show();
    
    custom_filters = new QListWidget(this);
    custom_filters->setGeometry(400, 10, 390, 200);
    custom_filters->show();
    
    for(int i = 0; i < ac::draw_max-4; ++i) {
        filters->addItem(ac::draw_strings[i].c_str());
    }
    
    btn_add = new QPushButton("Add", this);
    btn_remove = new QPushButton("Remove", this);
    btn_moveup = new QPushButton("Move Up", this);
    btn_movedown = new QPushButton("Move Down", this);
    
    btn_add->setGeometry(10, 215, 100, 20);
    btn_remove->setGeometry(400, 215, 100, 20);
    btn_moveup->setGeometry(500, 215, 100, 20);
    btn_movedown->setGeometry(600, 215, 100, 20);
    
    connect(btn_add, SIGNAL(clicked()), this, SLOT(addClicked()));
    connect(btn_remove, SIGNAL(clicked()), this, SLOT(rmvClicked()));
    connect(btn_moveup, SIGNAL(clicked()), this, SLOT(upClicked()));
    connect(btn_movedown, SIGNAL(clicked()), this, SLOT(downClicked()));
    
    log_text = new QTextEdit(this);
    log_text->setGeometry(10, 250, 780,310);
    log_text->setReadOnly(true);
    
    QString text = "Acid Cam v";
    text += ac::version.c_str();
    text += " loaded.\n";
    log_text->setText(text);
    
    filters->setCurrentRow(0);
    
    chk_negate = new QCheckBox("Negate", this);
    chk_negate->setGeometry(120,215,100, 20);
    chk_negate->setCheckState(Qt::Unchecked);
    
    combo_rgb = new QComboBox(this);
    combo_rgb->setGeometry(200,215, 180, 25);
    combo_rgb->addItem("RGB");
    combo_rgb->addItem("BGR");
    combo_rgb->addItem("BRG");
    combo_rgb->addItem("GRB");
    
    setWindowIcon(QPixmap(":/images/icon.png"));
    
}

void AC_MainWindow::createMenu() {
    
}

void AC_MainWindow::addClicked() {
    
    
    int row = filters->currentRow();
    if(row != -1) {
        custom_filters->addItem(ac::draw_strings[row].c_str());
    }
    
}

void AC_MainWindow::rmvClicked() {
    int item = custom_filters->currentRow();
    if(item != -1) {
        custom_filters->takeItem(item);
    }
}

void AC_MainWindow::upClicked() {
    int item = custom_filters->currentRow();
    if(item > 0) {
        QListWidgetItem *i = custom_filters->takeItem(item);
        custom_filters->insertItem(item-1, i->text());
        custom_filters->setCurrentRow(item-1);
    }
}

void AC_MainWindow::downClicked() {
    int item = custom_filters->currentRow();
    if(item < custom_filters->count()-1) {
    	QListWidgetItem *i = custom_filters->takeItem(item);
    	custom_filters->insertItem(item+1, i->text());
    	custom_filters->setCurrentRow(item+1);
    }
  
}

void AC_MainWindow::Log(const QString &s) {
    QString text;
    text = log_text->toPlainText();
    text += "\n";
    text += s;
    log_text->setText(text);
    QTextCursor tmpCursor = log_text->textCursor();
    tmpCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    log_text->setTextCursor(tmpCursor);
}



