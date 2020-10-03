#ifndef HANDLESORT_H
#define HANDLESORT_H

#include <QObject>
#include <QDebug>
#include <sstream>
#include <vector>
#include <iostream>

class HandleSort : public QObject
{
    Q_OBJECT
public:
    explicit HandleSort(QObject *parent = 0);

public slots:
    void handleSubmitTextField(const QString& in);
signals:
    void setTextField(QVariant text);
};

#endif // HANDLESORT_H
