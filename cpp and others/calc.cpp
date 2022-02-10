#include "calc.h"

CALC::CALC(QWidget *parent) : QWidget(parent),m_settings("yorod","CALCulator")
{
    const int N=20;
    buttons = new QList<QPushButton*>();
    QFont font;
    font.setBold(true);
    font.setFamily("Helvetica");
    font.setItalic(true);
    font.setPointSize(15);
    ld=new QLabel;
    ld->setFont(font);
    lst<<"1"<<"2"<<"3"<<"<-"<<"4"<<"5"<<"6"<<"-"<<"7"<<"8"<<"9"<<"+"<<"new"<<"0"<<"/"<<"*"<<"CE"<<"."<<"%"<<"=";


    for(int i=0;i<N;++i) {
        buttons->append(new QPushButton(lst[i]));
        buttons->at(i)->setFont(font);
        buttons->at(i)->setFixedSize(50,50);
        //buttons->at(i)->setStyle(QStyleFactory::create("QFusionStyle"));
        /*QRegion reg(QRect(40,40,40,40),QRegion::Ellipse);
        reg.boundingRect().size();
        buttons->at(i)->setMask(reg);*/
        /*buttons->at(i)->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 115, 255);"
                                                        "border-radius: 5px;"
                                                        "padding: 6px;"));*/
    }
    /*buttons->append(new QPushButton("new",this));
    buttons->at(19)->setFixedSize(40,40);*/

    QWidget::connect(buttons->at(0),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(1),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(2),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(16),SIGNAL(clicked()),this,SLOT(clickCE()));
    QWidget::connect(buttons->at(4),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(5),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(6),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(7),SIGNAL(clicked()),this,SLOT(clickSign()));
    QWidget::connect(buttons->at(8),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(9),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(10),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(11),SIGNAL(clicked()),this,SLOT(clickSign()));
    QWidget::connect(buttons->at(19),SIGNAL(clicked()),this,SLOT(clickEq()));
    QWidget::connect(buttons->at(13),SIGNAL(clicked()),this,SLOT(clickDigit()));
    QWidget::connect(buttons->at(14),SIGNAL(clicked()),this,SLOT(clickSign()));
    QWidget::connect(buttons->at(15),SIGNAL(clicked()),this,SLOT(clickSign()));
    QWidget::connect(buttons->at(3),SIGNAL(clicked()),this,SLOT(clickBack()));
    QWidget::connect(buttons->at(17),SIGNAL(clicked()),this,SLOT(clickSign()));
    QWidget::connect(buttons->at(18),SIGNAL(clicked()),this,SLOT(clickPercent()));
    QWidget::connect(buttons->at(12),SIGNAL(clicked()),this,SLOT(changeSize()));


    QWidget::connect(this,SIGNAL(clickFromDigit(const QString&)),ld,SLOT(setText(const QString&)));
    pgrdLayout = new QGridLayout;
    auto iter = buttons->begin();
    for(int i=0;i<5;++i) {
        for(int j=0;j<4;++j) {
           pgrdLayout->addWidget(*iter,i,j);
           ++iter;
        }
    }

    pgrbBox = new QGroupBox;
    pgrbBox->setLayout(pgrdLayout);


    pcmbx = new QComboBox;
    pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmbx);
    pvbxLayout->addWidget(ld);
    pvbxLayout->addWidget(pgrbBox);


   //QRegExp rxp("[0-9.+*/=-]+");
   // pvld = new CALC_validator(ld);
   // ld->setValidator(new QRegExpValidator(rxp,this));


    setLayout(pvbxLayout);
    setMinimumSize(300,300);
    readSettings();
   /* QStateMachine* psm = new QStateMachine;
    QState* pStateOn = new QState(psm);
    pStateOn->assignProperty(buttons->at(1),"visible",false);
    psm->setInitialState(pStateOn);

    QState* pStateOff = new QState(psm);
    pStateOn->assignProperty(buttons->at(1),"visible",true);
    psm->setInitialState(pStateOff);

    pStateOff->addTransition(buttons->at(19),SIGNAL(clicked()),pStateOn);

    pStateOn->addTransition(buttons->at(19),SIGNAL(clicked()),pStateOff);

    psm->start();*/
}
void CALC::clickDigit()
{
    QPushButton* pbtn = (QPushButton *)sender();
    emit clickFromDigit(ld->text()+pbtn->text());
}
void CALC::clickSign()
{
    QPushButton* pbtn = (QPushButton *)sender();
    if(ld->text().size()!=0)
    {
        if((ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='*')||(ld->text()[ld->text().size()-1]=='-'))
        {
            QString temp =ld->text();
            temp[temp.size()-1]=pbtn->text().at(0);
            emit clickFromDigit(temp);
            return;
        }
        emit clickFromDigit(ld->text()+pbtn->text());
    }
}
void CALC::clickCE(){
    emit clickFromDigit("");
}
void CALC::clickPlus(){
    if(ld->text().size()!=0)
    {
        if((ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='*')||(ld->text()[ld->text().size()-1]=='-'))
        {
            QString temp =ld->text();
            temp[temp.size()-1]='+';
            emit clickFromDigit(temp);
            return;
        }
        emit clickFromDigit(ld->text()+"+");
    }
}
void CALC::clickMinus(){
    if(ld->text().size()==0)
    {
        emit clickFromDigit(ld->text()+"-");
        return;
    }
    if((ld->text()[ld->text().size()-1]=='-')||(ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='*'))
        {
            QString temp =ld->text();
            temp[temp.size()-1]='-';
            emit clickFromDigit(temp);
            return;
        }
    emit clickFromDigit(ld->text()+"-");
}
void CALC::clickDiv(){
    if(ld->text().size()!=0)
    {
        if((ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='*')||(ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='-'))
        {
            QString temp =ld->text();
            temp[temp.size()-1]='/';
            emit clickFromDigit(temp);
            return;
        }
        emit clickFromDigit(ld->text()+"/");
    }
}
void CALC::clickMult(){
    if(ld->text().size()!=0)
    {
        if((ld->text()[ld->text().size()-1]=='*')||(ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='-'))
        {
            QString temp =ld->text();
            temp[temp.size()-1]='*';
            emit clickFromDigit(temp);
            return;
        }
        emit clickFromDigit(ld->text()+"*");
    }
}
void CALC::clickEq(){
    if(ld->text().size()!=0)
    {
        QString sample = ld->text();
        if(pcmbx->findText(sample)==-1){
        pcmbx->insertItem(0,sample);
        pcmbx->setCurrentIndex(0);
        }
        int check=0;
        calculate ex;
        double result=0;
        QString temp =ld->text();
        if((ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='-')||(ld->text()[ld->text().size()-1]=='*'))
        {
            temp[temp.size()-1]='=';

            ex.calculate_this(result,temp.toUtf8().constData(),check);


            if(check)
            {
                emit clickFromDigit(temp+"Error we cant dev on 0");
                sample+="Error we cant dev on 0";
                if(pcmbx->findText(sample)!=-1)
                pcmbx->addItem(sample);
                return;
            }
            emit clickFromDigit(temp+QString::number(result));
            sample += QString::number(result);
            if(pcmbx->findText(sample)!=-1)
            pcmbx->addItem(sample);
            return;
        }
        temp+="=";
        ex.calculate_this(result,temp.toUtf8().constData(),check);

        if(check)
        {
            emit clickFromDigit(temp+"Error we cant dev on 0");
            return;
        }
        emit clickFromDigit(/*temp+*/QString::number(result));

    }
}
void CALC::clickDot()
{
    if((ld->text()[ld->text().size()-1]=='/')||(ld->text()[ld->text().size()-1]=='+')||(ld->text()[ld->text().size()-1]=='-')||(ld->text()[ld->text().size()-1]=='*'))
    {
        QString temp =ld->text();
        temp[temp.size()-1]='.';
        emit clickFromDigit(temp);
        return;
    }
    emit clickFromDigit(ld->text()+".");
}
void CALC::clickSquare()
{

}
void CALC::clickPercent()
{
    ld->setText(pcmbx->currentText());
    clickEq();
}
void CALC::clickBack()
{
    QString temp;
    for(int i=0;i<ld->text().size()-1;++i)
        temp+=ld->text()[i];
    emit clickFromDigit(temp);
}
void CALC::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case(Qt::Key_Plus):
        buttons->at(11)->click();
        break;
    case(Qt::Key_Minus):
        buttons->at(7)->click();
        break;
    case(Qt::Key_Period):
        buttons->at(17)->click();
        break;
    case(Qt::Key_Delete):
        buttons->at(3)->click();
        break;
    case(Qt::Key_Equal):
        buttons->at(12)->click();
        break;
    case(Qt::Key_Enter):
        buttons->at(12)->click();
        break;
    case(Qt::Key_Return):
        buttons->at(12)->click();
        break;
    case(Qt::Key_Backspace):
        buttons->at(16)->click();
        break;
    case(Qt::Key_Slash):
        buttons->at(14)->click();
        break;
    case(Qt::Key_Asterisk):
        buttons->at(15)->click();
        break;
    case(Qt::Key_0):
        buttons->at(13)->click();
        break;
    case(Qt::Key_1):
        buttons->at(0)->click();
        break;
    case(Qt::Key_2):
        buttons->at(1)->click();
        break;
    case(Qt::Key_3):
        buttons->at(2)->click();
        break;
    case(Qt::Key_4):
        buttons->at(4)->click();
        break;
    case(Qt::Key_5):
        buttons->at(5)->click();
        break;
    case(Qt::Key_6):
        buttons->at(6)->click();
        break;
    case(Qt::Key_7):
        buttons->at(8)->click();
        break;
    case(Qt::Key_8):
        buttons->at(9)->click();
        break;
    case(Qt::Key_9):
        buttons->at(10)->click();
        break;
    }
}

void CALC::readSettings(){
    m_settings.beginGroup("/Settings");

    int nWidth = m_settings.value("/width",width()).toInt();
    int nHeight = m_settings.value("/height",height()).toInt();

    resize(nWidth,nHeight);

    m_settings.endGroup();
}
void CALC::writeSettings(){
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/width",width());
    m_settings.setValue("/height",height());
    m_settings.endGroup();
}

CALC::~CALC(){
   writeSettings();
}

void CALC::changeSize(){
    if(size == minimal){
        ++size;
        for(int i=0;i<19;++i) {
            buttons->append(new QPushButton(lst[i]));
            buttons->at(i)->setFixedSize(80,80);
        }
        QRect rect = QApplication::desktop()->screenGeometry();
        resize(rect.width()/2,rect.height());
        //resize(); заресайзить на пол экрана найти характеристики монитора сделать прилегание к
        //одной стороне экрана
    }
    else if(size == half_past){
        ++size;
        for(int i=0;i<19;++i) {
            buttons->append(new QPushButton(lst[i]));
            buttons->at(i)->setFixedSize(100,100);
            //resize(); заресайзить на весь экран найти характеристики монитора сделать прилегание к
            //одной стороне экрана
        }
        QRect rect = QApplication::desktop()->screenGeometry();
        resize(rect.width(),rect.height());
    }
    else if(size == full){
        size=1;
        for(int i=0;i<19;++i) {
            buttons->append(new QPushButton(lst[i]));
            buttons->at(i)->setFixedSize(60,60);
            //resize(); заресайзить на минимум экрана ,найти характеристики монитора сделать прилегание к
            //одной стороне экрана
        }
        resize(300,300);
    }
}










