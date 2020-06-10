#include "data.h"

Data::Data()
{
    //设置路径值并设置Line
    std::memset(this->pathsValueMap, 0, sizeof(this->pathsValueMap));
    std::memset(this->pathsMap, 0, sizeof(this->pathsMap));
    std::memset(this->pathsTextMap, 0, sizeof(this->pathsTextMap));
    auto geneText = [](QString str, int posx, int posy) {auto tmp=new QGraphicsTextItem(str);tmp->setFont(QFont("Consolas",12));tmp->setPos(posx,posy);return tmp; };

    this->pathsValueMap[Hangzhou][Huzhou] = 32;
    this->pathsMap[Hangzhou][Huzhou] = new QGraphicsLineItem(195, 40, 200, 130);
    this->pathsTextMap[Hangzhou][Huzhou] = geneText("32", 200, 65);

    this->pathsValueMap[Hangzhou][Shaoxing] = 20;
    this->pathsMap[Hangzhou][Shaoxing] = new QGraphicsLineItem(248, 164, 200, 130);
    this->pathsTextMap[Hangzhou][Shaoxing] = geneText("20", 225, 123);

    this->pathsValueMap[Hangzhou][Jinhua] = 43;
    this->pathsMap[Hangzhou][Jinhua] = new QGraphicsLineItem(134, 303, 200, 130);
    this->pathsTextMap[Hangzhou][Jinhua] = geneText("43", 134, 206);

    this->pathsValueMap[Hangzhou][Jiaxing] = 32;
    this->pathsMap[Hangzhou][Jiaxing] = new QGraphicsLineItem(278, 57, 200, 130);
    this->pathsTextMap[Hangzhou][Jiaxing] = geneText("32", 235, 90);

    this->pathsValueMap[Ningbo][Shaoxing] = 33;
    this->pathsMap[Ningbo][Shaoxing] = new QGraphicsLineItem(378, 184, 256, 168);
    this->pathsTextMap[Ningbo][Shaoxing] = geneText("33", 300, 150);

    this->pathsValueMap[Ningbo][Taizhou] = 55;
    this->pathsMap[Ningbo][Taizhou] = new QGraphicsLineItem(378, 184, 365, 363);
    this->pathsTextMap[Ningbo][Taizhou] = geneText("55", 375, 270);

    this->pathsValueMap[Ningbo][Zhoushan] = 89;
    this->pathsMap[Ningbo][Zhoushan] = new QGraphicsLineItem(378, 184, 460, 162);
    this->pathsTextMap[Ningbo][Zhoushan] = geneText("89", 404, 150);

    this->pathsValueMap[Lishui][Jinhua] = 52;
    this->pathsMap[Lishui][Jinhua] = new QGraphicsLineItem(170, 392, 134, 303);
    this->pathsTextMap[Lishui][Jinhua] = geneText("52", 150, 330);

    this->pathsValueMap[Lishui][Wenzhou] = 34;
    this->pathsMap[Lishui][Wenzhou] = new QGraphicsLineItem(170, 392, 272, 462);
    this->pathsTextMap[Lishui][Wenzhou] = geneText("34", 216, 400);

    this->pathsValueMap[Quzhou][Jinhua] = 21;
    this->pathsMap[Quzhou][Jinhua] = new QGraphicsLineItem(134, 303, 40, 322);
    this->pathsTextMap[Quzhou][Jinhua] = geneText("21", 68, 288);

    this->pathsValueMap[Wenzhou][Taizhou] = 42;
    this->pathsMap[Wenzhou][Taizhou] = new QGraphicsLineItem(272, 462, 365, 363);
    this->pathsTextMap[Wenzhou][Taizhou] = geneText("42", 290, 390);

    //复制成无向图
    for (int i = 0; i < citySum; i++)
    {
        for (int j = 0; j < citySum; j++)
        {
            if (this->pathsValueMap[i][j])
            {
                this->pathsValueMap[j][i] = this->pathsValueMap[i][j];
            }
            if (this->pathsMap[i][j])
            {
                this->pathsMap[j][i] = this->pathsMap[i][j];
            }
            if (this->pathsTextMap[i][j])
            {
                this->pathsTextMap[j][i] = this->pathsTextMap[i][j];
            }
        }
    }
    QPen myPen = QPen(Qt::black, 4); //设置路径颜色
    //初始化路径对象
    for (int i = 0; i < citySum; i++)
    {
        for (int j = i + 1; j < citySum; j++)
        {
            if (this->pathsMap[i][j])
            {
                pathsMap[i][j]->setPen(myPen);
                this->paths.push_back(this->pathsMap[i][j]);
            }
            if (this->pathsTextMap[i][j])
            {
                this->pathsTextMap[i][j]->setDefaultTextColor(QColor(Qt::black)); //设置文字颜色
                this->texts.push_back(this->pathsTextMap[i][j]);
            }
        }
    }
    //自定义的文字
}
