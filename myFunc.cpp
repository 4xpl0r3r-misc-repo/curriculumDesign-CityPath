#include "stdpfx.h"
#include "data.h"
#include "myFunc.h"

#include <queue>

void drawGV(QGraphicsScene *scene, Data &myData)
{
    scene->clear();
    for (std::vector<QGraphicsLineItem *>::iterator it = myData.paths.begin(); it != myData.paths.end(); it++)
    {
        scene->addItem(*it);
    }
    for (std::vector<QGraphicsTextItem *>::iterator it = myData.texts.begin(); it != myData.texts.end(); it++)
    {
        scene->addItem(*it);
    }
    QPixmap pixmap(":/Citys.png");
    scene->addPixmap(pixmap.scaled(500, 500, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void choosePath(QGraphicsLineItem *line, QGraphicsTextItem *text)
{
    QPen redPen = QPen(Qt::red, 4); //设置路径颜色
    line->setPen(redPen);
    text->setDefaultTextColor(QColor(Qt::red)); //设置文字颜色
}

int minPathMain(QGraphicsScene *scene, Data &myData, enum City origin, enum City destination)
{
    int myMap[citySum][citySum];
    memcpy_s(myMap, sizeof(myMap), myData.pathsValueMap, sizeof(myData.pathsValueMap));
    //Algo
    int dis[citySum];
    int preMap[citySum];
    bool used[citySum];
    std::memset(dis, 127, sizeof(dis));
    std::memset(used, 0, sizeof(used));
    dis[origin] = 0;
    for (int i = 0; i < citySum; i++)
    {
        City cuCity;
        int t = INT_MAX;
        for (int i = 0; i < citySum; i++)
        {
            if (!used[i] && dis[i] < t)
            {
                t = dis[i];
                cuCity = (City)i;
            }
        }
        if (cuCity == destination)
            break;
        used[cuCity] = true;
        for (int i = 0; i < citySum; i++)
        {
            if (myMap[cuCity][i] && dis[i] > myMap[cuCity][i] + dis[cuCity])
            {
                dis[i] = myMap[cuCity][i] + dis[cuCity];
                preMap[i] = cuCity;
            }
        }
    }
    //Choose
    int cuCity = destination;
    while (cuCity != origin)
    {
        choosePath(myData.pathsMap[cuCity][preMap[cuCity]], myData.pathsTextMap[cuCity][preMap[cuCity]]);
        cuCity = preMap[cuCity];
    }
    drawGV(scene, myData);
    return dis[destination];
}

int minTreeMain(QGraphicsScene *scene, Data &myData, bool selectedCity[citySum])
{
    struct cmpVertex
    {
        City id;
        int value;
        City from;
        bool operator>(const cmpVertex tar) const
        {
            return value > tar.value;
        }
        cmpVertex(int t_id, int t_value, int t_from)
        {
            id = (City)t_id;
            value = t_value;
            from = (City)t_from;
        }
    };
    int myMap[citySum][citySum];
    memcpy_s(myMap, sizeof(myMap), myData.pathsValueMap, sizeof(myData.pathsValueMap));
    //Algo&Choose
    int vertexSum = [](bool selectedCity[citySum]) {int t=0;for(int i=0;i<citySum;i++)if(selectedCity[i])t++;return t; }(selectedCity);
    if (!vertexSum)
        return -1; //无法生成返回
    City cuVertex;
    int res = 0;
    std::priority_queue<cmpVertex, std::vector<cmpVertex>, std::greater<cmpVertex>> que;
    que.push(cmpVertex([](bool selectedCity[citySum]) {for(int i=0;i<citySum;i++)if(selectedCity[i])return i;return 0; }(selectedCity), 0, 0));
    for (int i = 0; i < vertexSum - 1; i++)
    {
        cuVertex = (City)que.top().id;
        res += que.top().value;
        if (que.top().value)
            choosePath(myData.pathsMap[que.top().id][que.top().from], myData.pathsTextMap[que.top().id][que.top().from]);
        que.pop();
        selectedCity[cuVertex] = false;
        for (int j = 0; j < citySum; j++)
        {
            if (selectedCity[j] && myMap[cuVertex][j])
            {
                que.push(cmpVertex(j, myMap[cuVertex][j], cuVertex));
            }
        }
        if (que.empty())
            return -1;
    }
    cuVertex = (City)que.top().id;
    res += que.top().value;
    if (que.top().value)
        choosePath(myData.pathsMap[que.top().id][que.top().from], myData.pathsTextMap[que.top().id][que.top().from]);
    drawGV(scene, myData);
    return res;
}

enum City string2enum(QString str)
{
    QString City[] = {"湖州市", "嘉兴市", "杭州市", "绍兴市", "宁波市", "舟山市", "衢州市", "金华市", "丽水市", "温州市", "台州市"};
    int i = -1;
    while (City[++i] != str)
        ;
    return (enum City)i;
}

void geneSelectedCitys(Ui::MainWindow *ui, bool toGene[citySum])
{
    if (ui->city1->isChecked())
        toGene[Huzhou] = true;
    if (ui->city2->isChecked())
        toGene[Jiaxing] = true;
    if (ui->city3->isChecked())
        toGene[Hangzhou] = true;
    if (ui->city4->isChecked())
        toGene[Shaoxing] = true;
    if (ui->city5->isChecked())
        toGene[Ningbo] = true;
    if (ui->city6->isChecked())
        toGene[Zhoushan] = true;
    if (ui->city7->isChecked())
        toGene[Quzhou] = true;
    if (ui->city8->isChecked())
        toGene[Jinhua] = true;
    if (ui->city9->isChecked())
        toGene[Lishui] = true;
    if (ui->city10->isChecked())
        toGene[Wenzhou] = true;
    if (ui->city11->isChecked())
        toGene[Taizhou] = true;
}
