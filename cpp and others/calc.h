#ifndef CALC_H
#define CALC_H

#include <QtWidgets>
#include <calculate.h>
class CALC : public QWidget
{
    Q_OBJECT
public:
   CALC(QWidget *parent = nullptr);
   virtual ~CALC();
   void readSettings();
   void writeSettings();
public slots:
   void clickDigit();
   void clickSign();
   void clickCE();
   void clickPlus();
   void clickMinus();
   void clickDiv();
   void clickMult();
   void clickEq();
   void clickBack();
   void clickPercent();
   void clickDot();
   void clickSquare();
   void changeSize();
   void keyPressEvent(QKeyEvent *event) override;
signals:
   void clickFromDigit(const QString& text);
private:
   enum sizes{
       minimal = 1,
       half_past,
       full
   };
   int size = minimal;
   QList<QPushButton*>* buttons;
   QStringList lst;
   QLabel* ld;
   QGridLayout *pgrdLayout;
   QGroupBox* pgrbBox;
   QVBoxLayout *pvbxLayout;
  //CALC_validator* pvld;
   QSettings m_settings;
   QComboBox* pcmbx;
};

#endif // CALC_H
