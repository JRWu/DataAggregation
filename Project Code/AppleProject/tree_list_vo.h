#ifndef TreeListVO_H
#define TreeListVO_H

#include <QStringList>
#include <QString>

class TreeListVO
{

public:

    QStringList dates; // dates for combo boxes

    // tree view objects
    QString root;
    QStringList children;
    QStringList grandchildren;

    TreeListVO();
    ~TreeListVO();
};

#endif // TreeListVO_H
