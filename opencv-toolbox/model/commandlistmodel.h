#ifndef COMMANDLISTMODEL_H
#define COMMANDLISTMODEL_H

#include <QAbstractListModel>

class ACommand;
class QVariant;
class QModelIndex;

class CommandListModel : public QAbstractListModel
{
//    Q_OBJECT

public:
    CommandListModel(QObject *parent = 0);

    QList<ACommand *> &CommandList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

private:
    QList<ACommand *> commandList;
};

#endif // COMMANDLISTMODEL_H
