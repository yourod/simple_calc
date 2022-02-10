#include "cstmstyle.h"

void cstmStyle::polish(QWidget *pwgt){
    if(qobject_cast<QPushButton*>(pwgt)){
        pwgt->setAttribute(Qt::WA_Hover,true);
    }
}
void cstmStyle::unpolish(QWidget *pwgt){
    if(qobject_cast<QPushButton*>(pwgt)){
        pwgt->setAttribute(Qt::WA_Hover,false);
    }
}

void cstmStyle::drawPrimitive(PrimitiveElement elem, const QStyleOption *popt, QPainter *ppainter, const QWidget *pwgt) const{
    switch (elem) {
    case PE_PanelButtonCommand:{
        const QStyleOptionButton* pOptionButton= qstyleoption_cast<const QStyleOptionButton*>(popt);
        if(pOptionButton){
            bool bDown = (pOptionButton->state & State_Sunken)||(pOptionButton->state & State_MouseOver);

            QPixmap pix = bDown ? QPixmap("//images//btnprs.bmp") : QPixmap("://images//btn.bmp");

            ppainter->drawPixmap(pOptionButton->rect,pix);

            bool bHover = (pOptionButton->state & State_Enabled) && (pOptionButton->state & State_MouseOver);

            if(bHover){
                ppainter->fillRect(pOptionButton->rect,QColor(173, 216, 230,83));
            }
        }
        break;
    }
    default:{
        QCommonStyle::drawPrimitive(elem,popt,ppainter,pwgt);
        break;
    }
    }
    return;
}
