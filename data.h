#ifndef DATA_H
#define DATA_H
#include "stdpfx.h"
#include <vector>
#include <cstring>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
class Data
{
public:
    Data();
    std::vector<QGraphicsLineItem*> paths;
    std::vector<QGraphicsTextItem*> texts;
    std::vector<QGraphicsLineItem*> pathsChoosed;
    std::vector<QGraphicsTextItem*> textsChoosed;

    QGraphicsLineItem* pathsMap[11][11];
    QGraphicsTextItem* pathsTextMap[11][11];
    int pathsValueMap[11][11];

};
#endif // DATA_H
