#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize (300,400);
}

void Widget::paintEvent (QPaintEvent *)
{
//    QPainterPath path;
//    path.lineTo(100,200);
//        path.addEllipse(100,200,50,50);     //向path中添加图形
//        QPainter painter(this);
//    painter.setPen(Qt:: blue);
//    painter.setBrush(Qt::red);
//        painter.drawPath(path);   //绘制前面创建的path
//        QPainterPath path2;
//    path2.addPath(path);   //将前面的path添加到新创建的path中
//    path2.translate(200,100);
//        painter.drawPath(path2);
    int radius = 73.5;
    QPainter *painter=new QPainter(this);
    painter->save();
    painter->setWindow (-150,-200,300,400);
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);

    QPainterPath bigCircle;
    bigCircle.addEllipse(0-radius, -35-radius, radius * 2, radius * 2);
    radius = 66.5;
    QPainterPath smallCircle;
    smallCircle.addEllipse(0-radius, -35-radius, radius * 2, radius * 2);
    QPainterPath path1 = bigCircle - smallCircle;
    painter->drawPath(path1);


    QPainterPath path2;
    path2.addPath (path1);
    path2.translate (0,70);
    painter->drawPath(path2);

    painter->restore();
}

Widget::~Widget()
{

}
