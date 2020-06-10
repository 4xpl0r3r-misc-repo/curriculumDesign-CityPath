#ifndef MYFUNC_H
#define MYFUNC_H
#include "stdpfx.h"
#include "data.h"
void drawGV(QGraphicsScene *scene,Data& myData);
void reInitGV(QGraphicsScene *scene,Data& myData);
int minPathMain(QGraphicsScene *scene,Data& myData,enum City origin,enum City destination);
int minTreeMain(QGraphicsScene *scene,Data& myData,bool selectedCity[citySum]);
enum City string2enum(QString str);
void geneSelectedCitys(Ui::MainWindow* ui,bool toGene[citySum]);
#endif // MYFUNC_H
