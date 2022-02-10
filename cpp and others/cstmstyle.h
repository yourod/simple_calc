
#include <QtWidgets>
class cstmStyle : public QCommonStyle
{
public:
    virtual void polish(QWidget *pwgt) override;
    virtual void unpolish(QWidget *pwgt) override;
    virtual void drawPrimitive(PrimitiveElement elem, const QStyleOption *popt, QPainter *ppainter, const QWidget *pwgt = 0) const override;
};
